//FormAI DATASET v1.0 Category: Database querying ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// Define the database path
#define DB_PATH "example.db"

// Define the query statement
#define QUERY "SELECT * FROM customers WHERE age > "

// Callback function for handling the query results
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[100];
    int age;

    // Prompt the user to enter an age
    printf("Enter an age: ");
    scanf("%d", &age);

    // Open the database
    rc = sqlite3_open(DB_PATH, &db);
    if(rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Construct the query statement
    sprintf(sql, "%s%d", QUERY, age);

    // Execute the query
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        sqlite3_close(db);
        return 1;
    }

    // Close the database
    sqlite3_close(db);
    return 0;
}