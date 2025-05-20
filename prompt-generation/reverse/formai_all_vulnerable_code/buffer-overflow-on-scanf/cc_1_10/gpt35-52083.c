//FormAI DATASET v1.0 Category: Database querying ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Function to handle errors with MySQL functions
void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

int main()
{
    printf("Connecting to database...\n\n");
    MYSQL *con = mysql_init(NULL);
    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "root", "password", NULL, 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }
    printf("Successfully connected to database!\n\n");
    
    MYSQL_STMT *stmt;
    MYSQL_RES *res;
    MYSQL_BIND param[1];
    char name[20];
    
    // Get user input for name parameter
    printf("Please enter a name to search for: ");
    scanf("%s", name);
    
    // Prepare statement to query database
    stmt = mysql_stmt_init(con);
    if (!stmt)
    {
        printf("Failed to initialize statement!\n");
        finish_with_error(con);
    }
    if (mysql_stmt_prepare(stmt, "SELECT * FROM users WHERE name = ?", strlen("SELECT * FROM users WHERE name = ?")))
    {
        printf("Failed to prepare statement!\n");
        finish_with_error(con);
    }
    
    // Bind parameter to statement
    memset(param, 0, sizeof(param));
    param[0].buffer_type = MYSQL_TYPE_STRING;
    param[0].buffer = name;
    param[0].buffer_length = strlen(name);
    if (mysql_stmt_bind_param(stmt, param))
    {
        printf("Failed to bind parameter!\n");
        finish_with_error(con);
    }
    
    // Execute statement and get results
    if (mysql_stmt_execute(stmt))
    {
        printf("Failed to execute statement!\n");
        finish_with_error(con);
    }
    res = mysql_stmt_result_metadata(stmt);
    if (!res)
    {
        printf("Failed to get result metadata!\n");
        finish_with_error(con);
    }
    
    // Get number of columns in result set
    int num_fields = mysql_num_fields(res);
    
    // Print out results
    printf("Results:\n");
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res)))
    {
        for(int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(res);
    mysql_stmt_close(stmt);
    mysql_close(con);
    return 0;
}