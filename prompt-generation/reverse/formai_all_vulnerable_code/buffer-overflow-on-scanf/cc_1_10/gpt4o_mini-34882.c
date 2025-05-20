//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "your_username"
#define PASS "your_password"
#define DB "your_database"

void finish_with_error(MYSQL *conn) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void display_results(MYSQL_RES *result) {
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);

    // Print column names
    MYSQL_FIELD *fields = mysql_fetch_fields(result);
    for (int i = 0; i < num_fields; i++) {
        printf("%s\t", fields[i].name);
    }
    printf("\n");

    // Print rows
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

void execute_query(MYSQL *conn, const char *query) {
    if (mysql_query(conn, query)) {
        finish_with_error(conn);
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result) {
        display_results(result);
        mysql_free_result(result);
    } else {
        if (mysql_field_count(conn) == 0) {
            printf("Query OK, %lld rows affected\n", mysql_affected_rows(conn));
        } else {
            finish_with_error(conn);
        }
    }
}

void insert_data(MYSQL *conn) {
    char query[256];
    int id;
    char name[100];
    
    printf("Enter ID (integer): ");
    scanf("%d", &id);
    printf("Enter Name (string): ");
    scanf("%s", name);

    snprintf(query, sizeof(query), "INSERT INTO Users (ID, Name) VALUES (%d, '%s')", id, name);
    execute_query(conn, query);
}

void select_data(MYSQL *conn) {
    char query[256];

    printf("Enter SQL SELECT statement (example: SELECT * FROM Users): ");
    scanf(" %[^\n]", query);

    execute_query(conn, query);
}

void delete_data(MYSQL *conn) {
    char query[256];
    
    printf("Enter SQL DELETE statement (example: DELETE FROM Users WHERE ID = 1): ");
    scanf(" %[^\n]", query);

    execute_query(conn, query);
}

void update_data(MYSQL *conn) {
    char query[256];

    printf("Enter SQL UPDATE statement (example: UPDATE Users SET Name='NewName' WHERE ID=1): ");
    scanf(" %[^\n]", query);

    execute_query(conn, query);
}

int main() {
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(conn, HOST, USER, PASS, DB, 0, NULL, 0) == NULL) {
        finish_with_error(conn);
    }

    while (1) {
        int choice;
        printf("\nDatabase Operations:\n");
        printf("1. Insert Data\n");
        printf("2. Select Data\n");
        printf("3. Update Data\n");
        printf("4. Delete Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_data(conn);
                break;
            case 2:
                select_data(conn);
                break;
            case 3:
                update_data(conn);
                break;
            case 4:
                delete_data(conn);
                break;
            case 5:
                mysql_close(conn);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    mysql_close(conn);
    return EXIT_SUCCESS;
}