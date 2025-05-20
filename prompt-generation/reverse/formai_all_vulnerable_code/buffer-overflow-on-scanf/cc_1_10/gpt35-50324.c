//FormAI DATASET v1.0 Category: Password management ; Style: distributed
// This is a distributed password management program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char website[50];
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Record;

// Function to save a new record
void saveRecord(Record record, Record* records, int* numRecords) {
    // Check if the array is full
    if (*numRecords >= MAX_RECORDS) {
        printf("Error: max number of records reached.\n");
    }
    else {
        records[*numRecords] = record;
        (*numRecords)++;
    }
}

// Function to search for a record by website name
void searchRecords(char* websiteName, Record* records, int numRecords) {
    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].website, websiteName) == 0) {
            printf("Website: %s\n", records[i].website);
            printf("Username: %s\n", records[i].username);
            printf("Password: %s\n", records[i].password);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No records found for website %s\n", websiteName);
    }
}

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;

    while (1) {
        int choice;
        printf("Select an option:\n");
        printf("1. Add a new record\n");
        printf("2. Search for a record by website name\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        getchar(); // consume new line character

        if (choice == 1) {
            // Prompt user for website, username, and password
            Record record;
            printf("Enter website name: ");
            fgets(record.website, sizeof(record.website), stdin);
            record.website[strcspn(record.website, "\n")] = 0; // remove new line character
            printf("Enter username: ");
            fgets(record.username, sizeof(record.username), stdin);
            record.username[strcspn(record.username, "\n")] = 0; // remove new line character
            printf("Enter password: ");
            fgets(record.password, sizeof(record.password), stdin);
            record.password[strcspn(record.password, "\n")] = 0; // remove new line character

            saveRecord(record, records, &numRecords);
        }
        else if (choice == 2) {
            // Prompt user for website name to search for
            char websiteName[50];
            printf("Enter website name to search for: ");
            fgets(websiteName, sizeof(websiteName), stdin);
            websiteName[strcspn(websiteName, "\n")] = 0; // remove new line character

            searchRecords(websiteName, records, numRecords);
        }
        else if (choice == 3) {
            // Exit the program
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}