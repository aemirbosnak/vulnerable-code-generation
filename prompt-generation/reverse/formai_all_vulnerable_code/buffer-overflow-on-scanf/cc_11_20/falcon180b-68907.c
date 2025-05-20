//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary_file;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int menu_choice;
    char search_query[MAX_ENTRY_LENGTH];

    diary_file = fopen("diary.txt", "r");
    if (diary_file == NULL) {
        printf("Diary file not found. Creating a new one.\n");
        diary_file = fopen("diary.txt", "w");
        if (diary_file == NULL) {
            printf("Error creating diary file.\n");
            return 1;
        }
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Search for a specific entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
        case 1:
            printf("Enter your new entry:\n");
            fgets(search_query, MAX_ENTRY_LENGTH, stdin);
            strcpy(entries[num_entries].text, search_query);
            time(&entries[num_entries].timestamp);
            num_entries++;
            break;

        case 2:
            printf("Previous entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
            }
            break;

        case 3:
            printf("Enter search query:\n");
            fgets(search_query, MAX_ENTRY_LENGTH, stdin);
            for (int i = 0; i < num_entries; i++) {
                if (strstr(entries[i].text, search_query)) {
                    printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
                }
            }
            break;

        case 4:
            fclose(diary_file);
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}