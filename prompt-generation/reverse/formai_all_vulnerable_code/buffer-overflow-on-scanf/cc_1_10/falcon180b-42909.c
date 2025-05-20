//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

void addEntry(Entry *entries, int numEntries, char *date, char *entry) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    strcpy(entries[numEntries].date, date);
    strcpy(entries[numEntries].entry, entry);

    numEntries++;
}

int main() {
    Entry entries[MAX_ENTRIES];
    int numEntries = 0;
    char input[MAX_ENTRY_LENGTH];
    char date[20];

    time_t now = time(NULL);
    strftime(date, sizeof(date), "%d/%m/%Y", localtime(&now));

    while (1) {
        printf("Digital Diary - %s\n", date);
        printf("1. Add entry\n2. View entries\n3. Exit\n");
        scanf("%d", &numEntries);

        switch (numEntries) {
        case 1:
            printf("Enter date (dd/mm/yyyy): ");
            scanf("%s", date);
            printf("Enter entry: ");
            fgets(input, MAX_ENTRY_LENGTH, stdin);
            input[strcspn(input, "\n")] = '\0';
            addEntry(entries, numEntries, date, input);
            break;

        case 2:
            printf("Entries:\n");
            for (int i = 0; i < numEntries; i++) {
                printf("%s - %s\n", entries[i].date, entries[i].entry);
            }
            break;

        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid option!\n");
        }
    }

    return 0;
}