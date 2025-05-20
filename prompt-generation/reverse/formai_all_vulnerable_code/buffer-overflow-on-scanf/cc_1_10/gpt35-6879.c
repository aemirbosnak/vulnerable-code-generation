//FormAI DATASET v1.0 Category: Database querying ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD ""
#define DATABASE "testdb"

void display_menu();
void execute_query(MYSQL *conn, char *query);

int main()
{
    MYSQL *conn;
    char query[1000];
    int choice;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        exit(1);
    }

    printf("Connected to database successfully!\n");

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(query, "SELECT * FROM customers");
                execute_query(conn, query);
                break;

            case 2:
                printf("\nEnter customer's ID: ");
                int id;
                scanf("%d", &id);

                sprintf(query, "SELECT * FROM customers WHERE customer_id = %d", id);
                execute_query(conn, query);
                break;

            case 3:
                printf("\nEnter customer's name: ");
                char name[50];
                scanf("%s", name);

                sprintf(query, "SELECT * FROM customers WHERE name = '%s'", name);
                execute_query(conn, query);
                break;

            case 4:
                printf("\nEnter customer's email: ");
                char email[50];
                scanf("%s", email);

                sprintf(query, "SELECT * FROM customers WHERE email = '%s'", email);
                execute_query(conn, query);
                break;

            default:
                printf("\nInvalid choice! Try again.\n\n");
        }

    } while (choice != 0);

    mysql_close(conn);

    return 0;
}

void display_menu()
{
    printf("\nMenu:\n");
    printf("1. Display all customers\n");
    printf("2. Search customer by ID\n");
    printf("3. Search customer by name\n");
    printf("4. Search customer by email\n");
    printf("0. Exit\n\n");
    printf("Enter your choice: ");
}

void execute_query(MYSQL *conn, char *query)
{
    if (mysql_query(conn, query)) {
        printf("Error: %s\n", mysql_error(conn));
    }

    MYSQL_RES *result = mysql_store_result(conn);
    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result))) {

        for (int i = 0; i < num_fields; i++) {
            printf("%-15s", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
}