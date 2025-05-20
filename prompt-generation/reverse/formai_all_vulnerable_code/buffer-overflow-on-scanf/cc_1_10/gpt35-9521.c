//FormAI DATASET v1.0 Category: Database querying ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

int main()
{
    MYSQL *connection = mysql_init(NULL);
    MYSQL_RES *result;
    MYSQL_ROW row;
    char query[255];
    int status;

    if (connection == NULL)
    {
        printf("Error: unable to allocate MySQL connection.\n");
        exit(1);
    }

    connection = mysql_real_connect(connection, "<host>", "<user>", "<password>", "<database>", 0, NULL, 0);
    if (connection == NULL)
    {
        printf("Error: unable to connect to database.\n");
        exit(1);
    }

    printf("You, my love, are the database of my life.\n");
    printf("Enter the name of the table you wish to query: ");
    char table_name[255];
    scanf("%s", table_name);

    sprintf(query, "SELECT * FROM %s", table_name);
    status = mysql_query(connection, query);
    if (status != 0)
    {
        printf("Error: unable to execute query.\n");
        exit(1);
    }

    result = mysql_store_result(connection);
    if (result == NULL)
    {
        printf("Error: unable to store result set.\n");
        exit(1);
    }

    printf("If I could search the world, and every database,\n");
    printf("My search would always return your name, my love.\n");
    printf("Here are the results of your query:\n");
    while ((row = mysql_fetch_row(result)) != NULL)
    {
        for (int i = 0; i < mysql_num_fields(result); i++)
        {
            printf("%s\t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(connection);

    printf("My heart beats only for you, and with this program\n");
    printf("I can find you with ease, no matter how far you roam.\n");

    return 0;
}