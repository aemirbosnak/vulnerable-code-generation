//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 4096

struct entry {
    char date[20];
    char time[10];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    char choice;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    time_t current_time;
    struct tm *time_info;

    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Cannot open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter your entry:\n");
                fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0'; // Remove newline character
                time(&current_time);
                time_info = localtime(&current_time);
                strftime(entries[num_entries].date, 20, "%Y-%m-%d", time_info);
                strftime(entries[num_entries].time, 10, "%H:%M:%S", time_info);
                num_entries++;
                break;

            case '2':
                printf("\nEntries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s %s %s\n", entries[i].date, entries[i].time, entries[i].content);
                }
                break;

            case '3':
                printf("Enter keyword to search: ");
                char keyword[MAX_ENTRY_LENGTH];
                fgets(keyword, MAX_ENTRY_LENGTH, stdin);
                keyword[strcspn(keyword, "\n")] = '\0'; // Remove newline character
                for (int i = 0; i < num_entries; i++) {
                    if (strstr(entries[i].content, keyword)!= NULL) {
                        printf("%s %s %s\n", entries[i].date, entries[i].time, entries[i].content);
                    }
                }
                break;

            case '4':
                printf("Exiting...\n");
                fclose(diary);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}