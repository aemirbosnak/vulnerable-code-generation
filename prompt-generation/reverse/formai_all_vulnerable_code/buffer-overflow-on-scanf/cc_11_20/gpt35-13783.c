//FormAI DATASET v1.0 Category: Database querying ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "password"
#define DATABASE "mydb"

int main()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char query[200];
    int offset = 0;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    printf("\nWelcome to the C Database querying example program\n");

    while (1) 
    {   
        int choice, id;
        char name[50];

        printf("\n1. Insert a record\n2. Retrieve all records\n3. Retrieve a record by id\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);

                sprintf(query, "INSERT INTO users(name) values ('%s')", name);
                if(mysql_query(conn, query))
                {
                    fprintf(stderr, "%s\n", mysql_error(conn));
                }
                break;

            case 2:
                sprintf(query, "SELECT * FROM users");
                mysql_query(conn, query);
                res = mysql_store_result(conn);
                    
                printf("\nAll records:\n");
                while ((row = mysql_fetch_row(res)) != NULL)
                {
                    printf("%s\n", row[0]);
                }
                mysql_free_result(res);
                break;

            case 3:
                printf("\nEnter ID: ");
                scanf("%d", &id);

                sprintf(query, "SELECT * FROM users WHERE id=%d", id);
                mysql_query(conn, query);
                res = mysql_store_result(conn);
                    
                if (mysql_num_rows(res) == 0) 
                {
                    printf("\nNo record found with id %d\n", id);
                }
                else 
                {
                    printf("\nRecord with id %d:\n", id);
                    while ((row = mysql_fetch_row(res)) != NULL)
                    {
                        printf("%s\n", row[0]);
                    }
                }
                mysql_free_result(res);
                break;

            case 4:
                mysql_close(conn);
                printf("\nExiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}