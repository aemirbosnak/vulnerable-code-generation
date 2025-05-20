//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "your_password"
#define DATABASE "test_db"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        finish_with_error(conn);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
}

void list_students(MYSQL *conn) {
    printf("Listing all students:\n");
    execute_query(conn, "SELECT * FROM students;");
}

void insert_student(MYSQL *conn, const char *name, int age) {
    char query[256];
    sprintf(query, "INSERT INTO students(name, age) VALUES('%s', %d);", name, age);
    execute_query(conn, query);
}

void delete_student(MYSQL *conn, int id) {
    char query[256];
    sprintf(query, "DELETE FROM students WHERE id = %d;", id);
    execute_query(conn, query);
}

void update_student(MYSQL *conn, int id, const char *name, int age) {
    char query[256];
    sprintf(query, "UPDATE students SET name = '%s', age = %d WHERE id = %d;", name, age, id);
    execute_query(conn, query);
}

void display_menu() {
    printf("Database Menu:\n");
    printf("1. List Students\n");
    printf("2. Insert Student\n");
    printf("3. Update Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    int choice;
    char name[100];
    int age, id;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_students(conn);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                insert_student(conn, name, age);
                break;
            case 3:
                printf("Enter student ID to update: ");
                scanf("%d", &id);
                printf("Enter new name: ");
                scanf("%s", name);
                printf("Enter new age: ");
                scanf("%d", &age);
                update_student(conn, id, name, age);
                break;
            case 4:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                delete_student(conn, id);
                break;
            case 5:
                mysql_close(conn);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    mysql_close(conn);
    return 0;
}