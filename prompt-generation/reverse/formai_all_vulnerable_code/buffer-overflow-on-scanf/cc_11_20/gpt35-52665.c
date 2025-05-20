//FormAI DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diary_entry {
    char date[20];
    char entry[1000];
} DiaryEntry;

int main() {
    int choice, num_entries = 0;
    DiaryEntry *diary_entries = NULL;
    char date[20], entry[1000];

    do {
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Search entries by date\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter date (DD/MM/YYYY): ");
                scanf("%s", date);

                printf("Enter diary entry (Max 1000 characters): ");
                scanf("%s", entry);

                if (num_entries == 0) {
                    diary_entries = (DiaryEntry*) malloc(sizeof(DiaryEntry));
                } else {
                    diary_entries = (DiaryEntry*) realloc(diary_entries, (num_entries+1) * sizeof(DiaryEntry));
                }

                strcpy(diary_entries[num_entries].date, date);
                strcpy(diary_entries[num_entries].entry, entry);

                num_entries++;
                printf("\n");
                break;
            
            case 2:
                if (num_entries == 0) {
                    printf("No entries found!\n\n");
                } else {
                    printf("\n---DIARY ENTRIES---\n");
                    for (int i=0; i<num_entries; i++) {
                        printf("Date: %s\n", diary_entries[i].date);
                        printf("Entry: %s\n", diary_entries[i].entry);
                        printf("--------------------\n");
                    }
                }
                break;
            
            case 3:
                if (num_entries == 0) {
                    printf("No entries found!\n\n");
                } else {
                    printf("Enter date to search (DD/MM/YYYY): ");
                    scanf("%s", date);
                    int found = 0;

                    for (int i=0; i<num_entries; i++) {
                        if (strcmp(diary_entries[i].date, date) == 0) {
                            printf("\n---ENTRY FOUND---\n");
                            printf("Date: %s\n", diary_entries[i].date);
                            printf("Entry: %s\n", diary_entries[i].entry);
                            printf("--------------------\n");
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("No entries found for the given date!\n\n");
                    }
                }
                break;
            
            case 4:
                printf("Exiting program...");
                break;
            
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(choice != 4);

    free(diary_entries);

    return 0;
}