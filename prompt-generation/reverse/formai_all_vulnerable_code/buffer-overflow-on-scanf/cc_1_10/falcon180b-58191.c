//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* date, char* entry) {
    strcpy(diary[numEntries].date, date);
    strcpy(diary[numEntries].entry, entry);
    numEntries++;
}

void printEntries() {
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
    int choice;
    int i;

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter your entry:\n");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            entry[strcspn(entry, "\n")] = '\0';
            addEntry(date, entry);
            break;

        case 2:
            printf("\n");
            printEntries();
            break;

        case 3:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}