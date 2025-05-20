//FormAI DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main()
{
    char dbUser[20], dbPass[20], dbName[20], query[100];
    int choice, id;

    printf("Enter MySQL database user: ");
    scanf("%s", dbUser);
    printf("Enter MySQL database password: ");
    scanf("%s", dbPass);
    printf("Enter MySQL database name to connect to: ");
    scanf("%s", dbName);

    MYSQL *conn = mysql_init(NULL);
    if (!conn)
    {
        fprintf(stderr, "Error: mysql_init failed\n");
        return EXIT_FAILURE;
    }
    if (!mysql_real_connect(conn, "localhost", dbUser, dbPass, dbName, 0, NULL, 0))
    {
        fprintf(stderr, "Error: mysql_real_connect failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    printf("*** Welcome to the database querying program ***\n");
    printf("1. Query by ID\n");
    printf("2. Query by Name\n");
    printf("3. Query by Age\n");
    printf("4. Exit\n\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter ID to query: ");
            scanf("%d", &id);
            sprintf(query, "SELECT * FROM users WHERE id=%d", id);
            break;

        case 2:
            printf("Enter Name to query: ");
            scanf("%s", query);
            sprintf(query, "SELECT * FROM users WHERE name='%s'", query);
            break;

        case 3:
            printf("Enter Age to query: ");
            scanf("%s", query);
            sprintf(query, "SELECT * FROM users WHERE age=%s", query);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

        if (mysql_query(conn, query))
        {
            fprintf(stderr, "Error: mysql_query failed: %s\n", mysql_error(conn));
        }
        else
        {
            MYSQL_RES *result = mysql_store_result(conn);
            if (!result)
            {
                fprintf(stderr, "Error: mysql_store_result failed: %s\n", mysql_error(conn));
            }
            else
            {
                MYSQL_ROW row;
                while ((row = mysql_fetch_row(result)))
                {
                    printf("ID: %d, Name: %s, Age: %s\n", atoi(row[0]), row[1], row[2]);
                }
                mysql_free_result(result);
            }
        }

    } while (choice != 4);

    mysql_close(conn);
    return 0;
}