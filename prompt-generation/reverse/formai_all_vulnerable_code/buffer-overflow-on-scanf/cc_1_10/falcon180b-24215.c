//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct entry {
    char date[10];
    char time[10];
    char content[1000];
};

int main() {
    FILE *diary;
    char filename[20];
    int choice, i;
    time_t now;
    struct tm *tm;
    struct entry entry;

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter a filename (without extension): ");
    scanf("%s", filename);

    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("File not found. Creating new file...\n");
        diary = fopen(filename, "w");
        fprintf(diary, "Digital Diary\n");
        fprintf(diary, "--------------------\n");
    }

    do {
        printf("\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                time(&now);
                tm = localtime(&now);
                strftime(entry.date, 10, "%m/%d/%Y", tm);
                strftime(entry.time, 10, "%H:%M:%S", tm);
                printf("Enter your entry:\n");
                fgets(entry.content, 1000, stdin);
                fprintf(diary, "%s %s - %s\n", entry.date, entry.time, entry.content);
                printf("Entry saved!\n");
                break;
            case 2:
                rewind(diary);
                while (fgets(entry.content, 1000, diary)!= NULL) {
                    printf("%s %s - %s\n", entry.date, entry.time, entry.content);
                }
                break;
            case 3:
                fclose(diary);
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice!= 3);

    return 0;
}