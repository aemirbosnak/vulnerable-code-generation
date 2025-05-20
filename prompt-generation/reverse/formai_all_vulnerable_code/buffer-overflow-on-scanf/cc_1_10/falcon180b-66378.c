//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} Entry;

int main() {
    FILE* diary;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char date[20];
    strftime(date, 20, "%Y-%m-%d", tm);

    diary = fopen("diary.txt", "a");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }

    while (1) {
        system("clear");
        printf("Digital Diary\n");
        printf("--------------------\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter your entry:\n");
            fgets(entries[num_entries].entry, MAX_LENGTH, stdin);
            strcpy(entries[num_entries].date, date);
            num_entries++;
            fprintf(diary, "%s - %s\n", entries[num_entries-1].date, entries[num_entries-1].entry);
            printf("Entry saved.\n");
            break;
        case '2':
            rewind(diary);
            while (fgets(entries[num_entries].date, 20, diary)!= NULL) {
                fgets(entries[num_entries].entry, MAX_LENGTH, diary);
                printf("%s - %s\n", entries[num_entries].date, entries[num_entries].entry);
                num_entries++;
            }
            break;
        case '3':
            fclose(diary);
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}