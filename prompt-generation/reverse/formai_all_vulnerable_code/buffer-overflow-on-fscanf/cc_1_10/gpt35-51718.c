//FormAI DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_PHONE_LEN 50

// Structure to represent a single record in the database
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
} Record;

// Global array to store all the records in the database
Record database[MAX_RECORDS];

// Function to read the database from a file
int read_database(char *filename) {
    FILE *fp;
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    while (!feof(fp) && count < MAX_RECORDS) {
        fscanf(fp, "%s %s %s", database[count].name, database[count].email, database[count].phone);
        count++;
    }

    fclose(fp);
    return count;
}

// Function to search for records matching a given name
void search_database(char *name, int count) {
    int i, matches = 0;

    for (i = 0; i < count; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("%-25s %-25s %-25s\n", database[i].name, database[i].email, database[i].phone);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No records found\n");
    }
}

int main() {
    int count;

    // Read the database from a file
    count = read_database("database.txt");
    if (count == 0) {
        return 1;
    }

    // Search for records matching a given name
    search_database("John", count);

    return 0;
}