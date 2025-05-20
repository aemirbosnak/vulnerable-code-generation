//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1024

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    char entry[MAX_ENTRY_LENGTH];

    diary = fopen("diary.txt", "a+");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    while (1) {
        printf("Digital Diary\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter your entry: ");
            fgets(entry, MAX_ENTRY_LENGTH, stdin);
            entries[num_entries].timestamp = time(NULL);
            strcpy(entries[num_entries].entry, entry);
            num_entries++;
            if (num_entries == MAX_ENTRIES) {
                printf("Error: Maximum number of entries reached.\n");
            } else {
                fprintf(diary, "%s\n", entry);
            }
            break;

        case 2:
            rewind(diary);
            printf("Your entries:\n");
            while (fgets(entry, MAX_ENTRY_LENGTH, diary)!= NULL) {
                printf("%s", entry);
            }
            break;

        case 3:
            fclose(diary);
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}