//FormAI DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_QUERY_LEN 1024

MYSQL * connect_to_database()
{
    MYSQL * conn;
    char * server = "localhost";
    char * user = "root";
    char * password = "mypassword";
    char * database = "mydatabase";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
    {
        printf("Error connecting to database: %s\n", mysql_error(conn));
        return NULL;
    }

    return conn;
}

void disconnect_from_database(MYSQL * conn)
{
    mysql_close(conn);
}

void query_database(MYSQL * conn, char * query)
{
    int res;
    MYSQL_RES * result;
    MYSQL_ROW row;
    char * error = "";

    // Execute the query
    res = mysql_query(conn, query);

    if (res)
    {
        error = mysql_error(conn);
        printf("Error executing query: %s\n", error);
        return;
    }

    // Process the result
    result = mysql_store_result(conn);

    if (result)
    {
        int num_fields = mysql_num_fields(result);

        // Print the column headers
        MYSQL_FIELD * fields = mysql_fetch_fields(result);

        for (int i = 0; i < num_fields; i++)
        {
            printf("%s\t", fields[i].name);
        }

        printf("\n");

        // Print the rows
        while ((row = mysql_fetch_row(result)))
        {
            for (int i = 0; i < num_fields; i++)
            {
                printf("%s\t", row[i] ? row[i] : "NULL");
            }

            printf("\n");
        }

        mysql_free_result(result);
    }
    else
    {
        printf("No records found.\n");
    }
}

int main()
{
    MYSQL * conn = connect_to_database();

    if (!conn)
    {
        return 1;
    }

    char query[MAX_QUERY_LEN];

    // Get user input for the query
    printf("Enter SQL query: ");
    fgets(query, MAX_QUERY_LEN, stdin);

    // Remove the newline character from the input
    int len = strlen(query);

    if (query[len - 1] == '\n')
    {
        query[len - 1] = '\0';
    }

    // Execute the query
    query_database(conn, query);

    disconnect_from_database(conn);

    return 0;
}