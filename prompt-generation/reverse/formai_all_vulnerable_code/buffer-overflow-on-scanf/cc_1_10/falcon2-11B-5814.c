//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
struct User {
    int id;
    char name[50];
    int age;
};

// Function to query the database
void queryDatabase() {
    // Connect to the database
    printf("Connecting to the database...\n");

    // Query the database
    printf("Querying the database...\n");

    // Loop through the results
    while (1) {
        char query[100];
        int result = scanf("%s", query);
        if (result!= 1) {
            break;
        }

        // Parse the query
        char *token = strtok(query, " ");
        int id;
        char name[50];
        int age;
        while (token!= NULL) {
            if (strcmp(token, "ID") == 0) {
                sscanf(token, "%d", &id);
                token = strtok(NULL, " ");
            } else if (strcmp(token, "NAME") == 0) {
                sscanf(token, "%s", name);
                token = strtok(NULL, " ");
            } else if (strcmp(token, "AGE") == 0) {
                sscanf(token, "%d", &age);
                token = strtok(NULL, " ");
            }
        }

        // Print the result
        printf("%d, %s, %d\n", id, name, age);
    }

    // Close the database connection
    printf("Closing the database connection...\n");

    // Exit the program
    exit(0);
}

int main() {
    queryDatabase();
    return 0;
}