//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[16];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    char filename[50];
    int i, j, choice, num_entries = 0;
    Entry entries[MAX_ENTRIES];
    time_t now;

    printf("Welcome to your digital diary!\n");
    printf("Please enter your name:\n");
    scanf("%s", entries[num_entries++].date);

    diary = fopen("diary.txt", "a");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Save and exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your entry:\n");
                fgets(entries[num_entries++].entry, MAX_ENTRY_LENGTH, stdin);
                fprintf(diary, "%s - %s\n", entries[num_entries-1].date, entries[num_entries-1].entry);
                break;
            case 2:
                rewind(diary);
                while (fgets(entries[num_entries].date, 16, diary)!= NULL) {
                    printf("%s - %s\n", entries[num_entries].date, entries[num_entries].entry);
                    num_entries++;
                }
                break;
            case 3:
                printf("Enter a keyword to search for:\n");
                scanf("%s", entries[num_entries].entry);
                rewind(diary);
                while (fgets(entries[num_entries].date, 16, diary)!= NULL) {
                    if (strstr(entries[num_entries].entry, entries[num_entries].date)!= NULL) {
                        printf("%s - %s\n", entries[num_entries].date, entries[num_entries].entry);
                    }
                    num_entries++;
                }
                break;
            case 4:
                fclose(diary);
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}