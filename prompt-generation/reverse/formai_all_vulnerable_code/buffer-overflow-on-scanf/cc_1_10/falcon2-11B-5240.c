//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to search for a specific string in the database
int search_string(char* db, char* query) {
    int i;
    for (i = 0; i < strlen(db); i++) {
        if (strcmp(db + i, query) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to insert a new entry into the database
void insert_entry(char* db, char* entry) {
    int i;
    for (i = 0; i < strlen(db); i++) {
        if (strcmp(db + i, entry) == 0) {
            printf("Entry already exists\n");
            return;
        }
    }
    strcat(db, "\n");
    strcat(db, entry);
}

// Main function
int main() {
    char db[10000];
    char entry[100];
    char query[100];

    printf("Enter the initial database content:\n");
    scanf("%s", db);

    printf("Enter the query string:\n");
    scanf("%s", query);

    int position = search_string(db, query);

    if (position!= -1) {
        printf("Query string found at position %d\n", position);
    } else {
        printf("Query string not found\n");
    }

    printf("Enter the new entry to be inserted:\n");
    scanf("%s", entry);

    insert_entry(db, entry);

    printf("Updated database content:\n%s", db);

    return 0;
}