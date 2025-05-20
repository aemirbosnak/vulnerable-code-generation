//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to query the database
void queryDatabase(char* query, int* result) {
    // Connect to the database
    FILE* database = fopen("database.txt", "r");
    if (!database) {
        printf("Error: Unable to open the database\n");
        return;
    }
    
    // Read the query
    char* buffer = (char*)malloc(sizeof(char) * 100);
    fgets(buffer, 100, database);
    
    // Replace special characters in the query
    for (int i = 0; i < strlen(buffer); i++) {
        if (isalnum(buffer[i]) == 0) {
            buffer[i] = toupper(buffer[i]);
        }
    }
    
    // Execute the query
    char* resultString = NULL;
    int resultLength = 0;
    if (strcmp(buffer, "SELECT * FROM table") == 0) {
        resultLength = 5;
    } else if (strcmp(buffer, "INSERT INTO table VALUES ('value1', 'value2', 'value3')") == 0) {
        resultLength = 1;
    } else if (strcmp(buffer, "UPDATE table SET column1 = 'new value', column2 = 'new value2' WHERE condition") == 0) {
        resultLength = 1;
    } else if (strcmp(buffer, "DELETE FROM table WHERE condition") == 0) {
        resultLength = 1;
    }
    
    // Print the result
    if (resultLength > 0) {
        result[0] = resultLength;
        resultString = (char*)malloc(sizeof(char) * resultLength);
        for (int i = 0; i < resultLength; i++) {
            resultString[i] = 'a' + (i % 26);
        }
        printf("Result: %s\n", resultString);
        free(resultString);
    }
    
    // Close the database
    fclose(database);
}

int main() {
    // Query the database
    char query[100];
    int result;
    scanf("%s", query);
    queryDatabase(query, &result);
    
    return 0;
}