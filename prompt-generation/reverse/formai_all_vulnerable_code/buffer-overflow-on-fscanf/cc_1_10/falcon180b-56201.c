//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[16];
    char time[8];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    char filename[20] = "diary.txt";
    char choice;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    time_t now;

    // Open the diary file
    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    // Read in existing entries
    rewind(diary);
    while (fscanf(diary, "%s %s %s", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content)!= EOF) {
        num_entries++;
    }

    // Main menu loop
    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Search for an entry\n");
        printf("4. Save and exit\n");
        printf("5. Exit without saving\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                // Write an entry
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter time (HH:MM:SS): ");
                scanf("%s", entries[num_entries].time);
                printf("Enter content:\n");
                fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0'; // Remove newline character
                num_entries++;
                break;
            case '2':
                // Read entries
                printf("\nEntries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s %s %s\n", entries[i].date, entries[i].time, entries[i].content);
                }
                break;
            case '3':
                // Search for an entry
                printf("Enter keyword to search for: ");
                scanf("%s", entries[num_entries].content);
                num_entries++;
                break;
            case '4':
                // Save and exit
                fclose(diary);
                return 0;
            case '5':
                // Exit without saving
                fclose(diary);
                return 1;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}