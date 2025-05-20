//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    char date[20];
    char time[20];
    char content[1000];
};

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    char choice;
    int entry_count = 0;
    struct entry entries[MAX_ENTRIES];

    diary = fopen(filename, "r+");

    if (diary == NULL) {
        printf("Diary file not found. Creating new file...\n");
        diary = fopen(filename, "w+");
        fprintf(diary, "Diary of a Medieval Programmer\n");
        fprintf(diary, "---------------------------------\n");
        fclose(diary);
        diary = fopen(filename, "r+");
    }

    while (1) {
        printf("Diary Menu:\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (entry_count >= MAX_ENTRIES) {
                    printf("Diary is full. Cannot write more entries.\n");
                } else {
                    time_t now = time(NULL);
                    struct tm *t = localtime(&now);
                    strftime(entries[entry_count].date, 20, "%d-%m-%Y", t);
                    strftime(entries[entry_count].time, 20, "%H:%M:%S", t);
                    printf("Enter your entry:\n");
                    fgets(entries[entry_count].content, 1000, stdin);
                    fprintf(diary, "%s %s - %s\n", entries[entry_count].date, entries[entry_count].time, entries[entry_count].content);
                    entry_count++;
                    printf("Entry saved.\n");
                }
                break;
            case '2':
                rewind(diary);
                printf("Diary Entries:\n");
                while (fgets(entries[entry_count].content, 1000, diary)!= NULL) {
                    printf("%s %s - %s\n", entries[entry_count].date, entries[entry_count].time, entries[entry_count].content);
                    entry_count++;
                }
                break;
            case '3':
                fclose(diary);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}