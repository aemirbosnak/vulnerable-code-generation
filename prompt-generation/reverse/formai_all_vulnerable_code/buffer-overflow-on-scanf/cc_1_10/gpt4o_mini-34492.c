//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "your_username"
#define PASSWORD "your_password"
#define DATABASE "your_database"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(EXIT_FAILURE);
}

void display_results(MYSQL_RES *result, MYSQL *conn) {
    MYSQL_ROW row;
    unsigned int num_fields = mysql_num_fields(result);
    
    while ((row = mysql_fetch_row(result))) {
        for (unsigned int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        if (mysql_field_count(conn) == 0) {
            printf("%lld rows affected\n", (long long)mysql_affected_rows(conn));
        } else {
            finish_with_error(conn);
        }
    } else {
        printf("Query Result:\n");
        display_results(result, conn);
        mysql_free_result(result);
    }
}

void insert_data(MYSQL *conn) {
    char query[256];
    char name[50];
    int age;
    
    printf("Enter name: ");
    scanf("%49s", name);
    
    printf("Enter age: ");
    scanf("%d", &age);

    snprintf(query, sizeof(query), "INSERT INTO users (name, age) VALUES ('%s', %d)", name, age);
    execute_query(conn, query);
}

void delete_data(MYSQL *conn) {
    int id;
    char query[256];

    printf("Enter user ID to delete: ");
    scanf("%d", &id);

    snprintf(query, sizeof(query), "DELETE FROM users WHERE id = %d", id);
    execute_query(conn, query);
}

void update_data(MYSQL *conn) {
    int id, new_age;
    char query[256];

    printf("Enter user ID to update: ");
    scanf("%d", &id);
    
    printf("Enter new age: ");
    scanf("%d", &new_age);
    
    snprintf(query, sizeof(query), "UPDATE users SET age = %d WHERE id = %d", new_age, id);
    execute_query(conn, query);
}

void read_all_data(MYSQL *conn) {
    const char *query = "SELECT * FROM users";
    execute_query(conn, query);
}

int main() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Data\n");
        printf("2. Update Data\n");
        printf("3. Delete Data\n");
        printf("4. Read All Data\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_data(conn);
                break;
            case 2:
                update_data(conn);
                break;
            case 3:
                delete_data(conn);
                break;
            case 4:
                read_all_data(conn);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
    
    mysql_close(conn);
    return EXIT_SUCCESS;
}