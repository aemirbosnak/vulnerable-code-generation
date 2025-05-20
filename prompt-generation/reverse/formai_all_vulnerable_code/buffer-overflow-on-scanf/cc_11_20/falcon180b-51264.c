//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t now;

    diary = fopen("diary.txt", "a");
    if (diary == NULL) {
        printf("Could not open diary file.\n");
        return 1;
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("A - Add entry\n");
        printf("R - Read entries\n");
        printf("S - Search entries\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                printf("Enter your entry: ");
                fflush(stdin);
                scanf("%[^\n]", entries[num_entries].entry);
                entries[num_entries].entry[strcspn(entries[num_entries].entry, "\n")] = '\0';
                time(&now);
                strftime(entries[num_entries].date, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
                num_entries++;
                break;
            case 'R':
                if (num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("Date\tEntry\n");
                    for (int i = 0; i < num_entries; i++) {
                        printf("%s\t%s\n", entries[i].date, entries[i].entry);
                    }
                }
                break;
            case 'S':
                printf("Enter search keyword: ");
                fflush(stdin);
                scanf("%s", entries[num_entries-1].entry);
                entries[num_entries-1].entry[strcspn(entries[num_entries-1].entry, "\n")] = '\0';
                for (int i = 0; i < num_entries-1; i++) {
                    if (strstr(entries[i].entry, entries[num_entries-1].entry)!= NULL) {
                        printf("%s\t%s\n", entries[i].date, entries[i].entry);
                    }
                }
                break;
            case 'Q':
                fclose(diary);
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}