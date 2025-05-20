//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char text[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

int main() {
    FILE *diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    diary = fopen("diary.txt", "a+");
    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        return 1;
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Error: Diary is full.\n");
                } else {
                    printf("Enter your entry:\n");
                    fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
                    entries[num_entries].timestamp = time(NULL);
                    num_entries++;
                    fprintf(diary, "%s - %s\n", ctime(&entries[num_entries-1].timestamp), entries[num_entries-1].text);
                    printf("Entry saved.\n");
                }
                break;
            case '2':
                if (num_entries == 0) {
                    printf("No entries yet.\n");
                } else {
                    printf("Diary entries:\n");
                    for (int i = 0; i < num_entries; i++) {
                        fprintf(stdout, "%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
                    }
                }
                break;
            case '3':
                printf("Goodbye!\n");
                fclose(diary);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}