//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define QUERY_BUFFER_SIZE 1024

void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void execute_query(MYSQL *con, const char *query) {
    if (mysql_query(con, query)) {
        finish_with_error(con);
    }
}

void show_all_users(MYSQL *con) {
    if (mysql_query(con, "SELECT id, name, email FROM users")) {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    printf("\nUser List:\n");
    while ((row = mysql_fetch_row(result))) {
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(result);
}

void add_user(MYSQL *con) {
    char name[50];
    char email[50];
    char query[QUERY_BUFFER_SIZE];

    printf("Enter user name: ");
    scanf("%s", name);
    printf("Enter user email: ");
    scanf("%s", email);

    snprintf(query, QUERY_BUFFER_SIZE, "INSERT INTO users (name, email) VALUES ('%s', '%s')", name, email);
    execute_query(con, query);
    printf("User added successfully.\n");
}

void delete_user(MYSQL *con) {
    int id;
    char query[QUERY_BUFFER_SIZE];

    printf("Enter user ID to delete: ");
    scanf("%d", &id);

    snprintf(query, QUERY_BUFFER_SIZE, "DELETE FROM users WHERE id=%d", id);
    execute_query(con, query);
    printf("User deleted successfully.\n");
}

void init_database(MYSQL *con) {
    if (mysql_query(con, "CREATE TABLE IF NOT EXISTS users(id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(100), email VARCHAR(100))")) {
        finish_with_error(con);
    }
}

int main() {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    if (mysql_real_connect(con, "localhost", "user", "password", "testdb", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }

    init_database(con);
    int choice;
    do {
        printf("\n1. Show All Users\n");
        printf("2. Add User\n");
        printf("3. Delete User\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                show_all_users(con);
                break;
            case 2:
                add_user(con);
                break;
            case 3:
                delete_user(con);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    mysql_close(con);
    return EXIT_SUCCESS;
}