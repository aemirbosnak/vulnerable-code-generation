//FormAI DATASET v1.0 Category: Database querying ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main()
{
    MYSQL *con = mysql_init(NULL);
    
    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    
    if (mysql_real_connect(con, "localhost", "username", "password", NULL, 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    if (mysql_query(con, "CREATE DATABASE database_name"))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    if (mysql_query(con, "USE database_name"))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    if (mysql_query(con, "CREATE TABLE people (id INT PRIMARY KEY, name VARCHAR(50), age INT)"))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    if (mysql_query(con, "INSERT INTO people (id, name, age) VALUES(1, 'John', 25)"))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    if (mysql_query(con, "INSERT INTO people (id, name, age) VALUES(2, 'Mary', 37)"))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    if (mysql_query(con, "SELECT * FROM people WHERE age > 30"))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    MYSQL_RES *result = mysql_store_result(con);
    
    if (result == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;
    
    while ((row = mysql_fetch_row(result)))
    {
        for(int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    
    mysql_free_result(result);
    mysql_close(con);
    
    return 0;
}