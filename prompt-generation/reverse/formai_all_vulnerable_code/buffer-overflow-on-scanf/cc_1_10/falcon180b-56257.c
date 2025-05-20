//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[500];
} DiaryEntry;

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int numEntries = 0;
    char choice;
    time_t now;
    struct tm* currentTime;

    srand(time(NULL));

    while (1) {
        printf("Digital Diary\n");
        printf("1. Write new entry\n2. Read entries\n3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (numEntries >= MAX_ENTRIES) {
                    printf("Diary is full. Please delete an entry.\n");
                } else {
                    printf("Enter new entry:\n");
                    scanf("%[^\n]", entries[numEntries].entry);
                    entries[numEntries].date[19] = '\0';
                    strcat(entries[numEntries].date, ctime(&now));
                    numEntries++;
                    printf("Entry saved.\n\n");
                }
                break;
            case '2':
                if (numEntries == 0) {
                    printf("No entries yet.\n\n");
                } else {
                    printf("Diary Entries:\n");
                    for (int i = 0; i < numEntries; i++) {
                        printf("%s - %s\n", entries[i].date, entries[i].entry);
                    }
                }
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}