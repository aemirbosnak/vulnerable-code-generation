//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct entry {
    char date[20];
    char time[20];
    char content[200];
};

int main() {
    FILE *fp;
    struct entry entry;
    int choice;

    fp = fopen("diary.txt", "a");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter your choice:\n");
    printf("1. Write a new entry\n");
    printf("2. Read previous entries\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", entry.date);

            printf("Enter the time (HH:MM:SS): ");
            scanf("%s", entry.time);

            printf("Enter your entry:\n");
            fgets(entry.content, 200, stdin);

            fprintf(fp, "%s %s\n%s\n", entry.date, entry.time, entry.content);

            printf("Entry saved successfully!\n");
            break;

        case 2:
            rewind(fp);

            printf("Previous entries:\n");
            while (!feof(fp)) {
                fscanf(fp, "%s %s %s", entry.date, entry.time, entry.content);
                printf("%s %s\n%s\n", entry.date, entry.time, entry.content);
            }

            break;

        case 3:
            printf("Goodbye!\n");
            fclose(fp);
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}