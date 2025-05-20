//FormAI DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Entry;

Entry mailingList[MAX_ENTRIES];
int numEntries = 0;

void printMenu() {
    printf("******************************\n");
    printf("*  Mailing List Manager      *\n");
    printf("******************************\n");
    printf("* 1. Add Entry               *\n");
    printf("* 2. View Entries            *\n");
    printf("* 3. Save Entries to File    *\n");
    printf("* 4. Load Entries from File  *\n");
    printf("* 5. Exit                    *\n");
    printf("******************************\n");
    printf("Enter your choice: ");
}

void addEntry() {
    Entry newEntry;
    printf("Enter name: ");
    scanf("%s", newEntry.name);
    printf("Enter email: ");
    scanf("%s", newEntry.email);
    mailingList[numEntries] = newEntry;
    numEntries++;
    printf("Entry added!\n");
}

void viewEntries() {
    printf("Mailing List:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%d. %s - %s\n", i+1, mailingList[i].name, mailingList[i].email);
    }
}

void saveEntriesToFile() {
    FILE *filePointer;
    filePointer = fopen("mailingList.txt", "w");
    if (filePointer == NULL) {
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < numEntries; i++) {
        fprintf(filePointer, "%s,%s\n", mailingList[i].name, mailingList[i].email);
    }
    fclose(filePointer);
    printf("Entries saved to file!\n");
}

void loadEntriesFromFile() {
    FILE *filePointer;
    filePointer = fopen("mailingList.txt", "r");
    if (filePointer == NULL) {
        printf("Error opening file\n");
        return;
    }
    numEntries = 0;
    char line[MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2];
    while (fgets(line, MAX_NAME_LENGTH + MAX_EMAIL_LENGTH + 2, filePointer)) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");
        strcpy(mailingList[numEntries].name, name);
        strcpy(mailingList[numEntries].email, email);
        numEntries++;
    }
    fclose(filePointer);
    printf("Entries loaded from file!\n");
}

int main() {
    int choice = 0;
    while (choice != 5) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: saveEntriesToFile(); break;
            case 4: loadEntriesFromFile(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    }
    return EXIT_SUCCESS;
}