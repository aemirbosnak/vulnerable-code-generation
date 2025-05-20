//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE* diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50] = "diary.txt";
    char choice;

    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error opening diary file.\n");
        return 1;
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. New entry\n");
        printf("2. View entries\n");
        printf("3. Search entry\n");
        printf("4. Save and exit\n");
        printf("5. Exit without saving\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Diary is full.\n");
                } else {
                    printf("Enter date (YYYY-MM-DD): ");
                    scanf("%s", entries[num_entries].date);
                    printf("Enter entry:\n");
                    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                    num_entries++;
                    printf("Entry saved.\n");
                }
                break;
            case '2':
                printf("Viewing entries...\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s: %s\n", entries[i].date, entries[i].entry);
                }
                break;
            case '3':
                printf("Enter keyword to search: ");
                char keyword[MAX_ENTRY_LENGTH];
                scanf("%s", keyword);
                for (int i = 0; i < num_entries; i++) {
                    if (strstr(entries[i].entry, keyword)!= NULL) {
                        printf("%s: %s\n", entries[i].date, entries[i].entry);
                    }
                }
                break;
            case '4':
                fclose(diary);
                diary = fopen(filename, "w");
                for (int i = 0; i < num_entries; i++) {
                    fprintf(diary, "%s: %s\n", entries[i].date, entries[i].entry);
                }
                fclose(diary);
                printf("Diary saved and exited.\n");
                return 0;
            case '5':
                printf("Exiting without saving...\n");
                fclose(diary);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}