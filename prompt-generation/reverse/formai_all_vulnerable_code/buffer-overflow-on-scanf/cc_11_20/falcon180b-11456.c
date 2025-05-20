//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50] = "diary.txt";
    char choice;

    diary = fopen(filename, "a");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nSherlock Holmes' Digital Diary\n");
        printf("---------------------------------\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Search for a specific entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Error: Diary is full.\n");
                } else {
                    printf("Enter date (YYYY-MM-DD): ");
                    scanf("%s", entries[num_entries].date);
                    printf("Enter time (HH:MM:SS): ");
                    scanf("%s", entries[num_entries].time);
                    printf("Enter content:\n");
                    fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, stdin);
                    fprintf(diary, "%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content);
                    num_entries++;
                    printf("Entry saved.\n");
                }
                break;
            case '2':
                rewind(diary);
                while (fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, diary)!= NULL) {
                    printf("%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content);
                    num_entries++;
                }
                break;
            case '3':
                printf("Enter keyword to search: ");
                scanf("%s", entries[num_entries].content);
                rewind(diary);
                while (fgets(entries[num_entries].content, MAX_ENTRY_LENGTH, diary)!= NULL) {
                    if (strstr(entries[num_entries].content, entries[num_entries].date)!= NULL || strstr(entries[num_entries].content, entries[num_entries].time)!= NULL || strstr(entries[num_entries].content, entries[num_entries].content)!= NULL) {
                        printf("%s %s %s\n", entries[num_entries].date, entries[num_entries].time, entries[num_entries].content);
                    }
                }
                break;
            case '4':
                fclose(diary);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}