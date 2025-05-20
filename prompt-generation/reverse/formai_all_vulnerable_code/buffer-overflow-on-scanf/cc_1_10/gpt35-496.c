//FormAI DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10 // simulation limit
#define MAX_NAME_LENGTH 20 // maximum length of a name for entry
#define MAX_FILE_NAME_LENGTH 100 // maximum length of a file name

struct Entry {
    int id;
    char name[MAX_NAME_LENGTH];
};

void addEntry(struct Entry *entry, int index) {
    printf("\nEnter name for entry %d: ", index+1);
    scanf("%s", entry[index].name);
    entry[index].id = index+1;
    printf("Entry %d added successfully!\n\n", index+1);
}

void displayDatabase(struct Entry *entry, int numEntries) {
    printf("\n");
    printf("ID\tName\n");
    for(int i = 0; i < numEntries; i++) {
        printf("%d\t%s\n", entry[i].id, entry[i].name);
    }
    printf("\n");
}

void saveDatabase(struct Entry *entry, int numEntries, char *fileName) {
    FILE *fp;
    fp = fopen(fileName, "w");
    if(fp) {
        fprintf(fp, "ID,Name\n");
        for(int i = 0; i < numEntries; i++) {
            fprintf(fp, "%d,%s\n", entry[i].id, entry[i].name);
        }
        printf("\nDatabase saved to %s!\n\n", fileName);
    } else {
        printf("\nFailed to open file for writing.\n\n");
    }
    fclose(fp);
}

int main() {
    struct Entry entry[MAX_ENTRIES];
    char fileName[MAX_FILE_NAME_LENGTH];
    int numEntries = 0;
    char input[10];

    while(1) {
        printf("Welcome to the Database Simulator!\n\n");
        printf("Choose an option:\n");
        printf("1) Add Entry\n");
        printf("2) Display Database\n");
        printf("3) Save Database\n");
        printf("4) Exit\n\n");

        scanf("%s", input);

        if(strcmp(input, "1") == 0) {
            if(numEntries >= MAX_ENTRIES) {
                printf("\nDatabase is at capacity. Cannot add new entries.\n\n");
            } else {
                addEntry(entry, numEntries);
                numEntries++;
            }
        } else if(strcmp(input, "2") == 0) {
            if(numEntries == 0) {
                printf("\nDatabase is empty. No entries to display.\n\n");
            } else {
                displayDatabase(entry, numEntries);
            }
        } else if(strcmp(input, "3") == 0) {
            if(numEntries == 0) {
                printf("\nDatabase is empty. Cannot save empty database.\n\n");
            } else {
                printf("\nEnter filename to save database to (including extension): ");
                scanf("%s", fileName);
                saveDatabase(entry, numEntries, fileName);
            }
        } else if(strcmp(input, "4") == 0) {
            printf("\nThank you for using the Database Simulator. Have a great day!\n\n");
            break;
        } else {
            printf("\nInvalid input. Please enter a number corresponding to an option in the menu.\n\n");
        }
    }
    return 0;
}