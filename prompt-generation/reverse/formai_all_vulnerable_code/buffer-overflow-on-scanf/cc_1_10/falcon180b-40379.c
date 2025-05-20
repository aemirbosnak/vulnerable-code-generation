//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    for (int i = 0; i < numEntries; i++) {
        printf("%s:\n%s\n\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to your digital diary!\n\n");

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter your entry:\n");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        entry[strcspn(entry, "\n")] = '\0'; // remove newline character

        addEntry(date, entry);

        printf("Entry added!\n");

        printf("Do you want to add another entry? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    printEntries();

    return 0;
}