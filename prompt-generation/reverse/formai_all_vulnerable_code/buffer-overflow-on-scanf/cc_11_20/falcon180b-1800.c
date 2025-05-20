//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char *text;
    size_t length;
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int entry_count = 0;
    int menu_choice;

    diary = fopen("diary.txt", "r");
    if (diary == NULL) {
        printf("No diary found. Creating new diary.\n");
        diary = fopen("diary.txt", "w");
        if (diary == NULL) {
            printf("Failed to create diary.\n");
            exit(1);
        }
    } else {
        printf("Loading diary...\n");
        while (fscanf(diary, "%ld %s\n", &entries[entry_count].timestamp, entries[entry_count].text) == 2) {
            entries[entry_count].length = strlen(entries[entry_count].text);
            entry_count++;
            if (entry_count >= MAX_ENTRIES) {
                printf("Diary is full. Overwriting oldest entry.\n");
                entry_count--;
            }
        }
        fclose(diary);
        diary = fopen("diary.txt", "a");
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write entry\n");
        printf("2. Read entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                printf("Enter your entry: ");
                char entry_text[MAX_ENTRY_LENGTH];
                fgets(entry_text, MAX_ENTRY_LENGTH, stdin);
                entries[entry_count].timestamp = time(NULL);
                entries[entry_count].text = strdup(entry_text);
                entries[entry_count].length = strlen(entry_text);
                entry_count++;
                if (entry_count >= MAX_ENTRIES) {
                    printf("Diary is full. Overwriting oldest entry.\n");
                    entry_count--;
                }
                fprintf(diary, "%ld %s\n", entries[entry_count - 1].timestamp, entries[entry_count - 1].text);
                fclose(diary);
                diary = fopen("diary.txt", "a");
                printf("Entry saved.\n");
                break;
            case 2:
                printf("Your diary:\n");
                for (int i = 0; i < entry_count; i++) {
                    printf("%s\n", entries[i].text);
                }
                break;
            case 3:
                printf("Enter search query: ");
                char search_query[MAX_ENTRY_LENGTH];
                fgets(search_query, MAX_ENTRY_LENGTH, stdin);
                int match_count = 0;
                for (int i = 0; i < entry_count; i++) {
                    if (strstr(entries[i].text, search_query)!= NULL) {
                        printf("%s\n", entries[i].text);
                        match_count++;
                    }
                }
                if (match_count == 0) {
                    printf("No matches found.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}