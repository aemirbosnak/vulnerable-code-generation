//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

struct Diary_entry {
    char date[20];
    char time[10];
    char content[500];
};

void main() {
    struct Diary_entry entry;
    int choice = 0;
    char filename[100] = "diary.txt";
    FILE *fp;
    fp = fopen(filename, "a");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }

    while (choice!= 4) {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nWrite a new entry:\n");
            printf("Enter the date (YYYY-MM-DD): ");
            scanf("%s", entry.date);
            printf("Enter the time (HH:MM:SS): ");
            scanf("%s", entry.time);
            printf("Enter the content:\n");
            scanf("%[^\n]", entry.content);

            fprintf(fp, "%s %s\n%s\n", entry.date, entry.time, entry.content);

            printf("\nEntry saved successfully.\n");
            break;
        case 2:
            rewind(fp);
            while (fscanf(fp, "%s %s %[^\n]", entry.date, entry.time, entry.content)!= EOF) {
                printf("%s %s\n%s\n", entry.date, entry.time, entry.content);
            }
            break;
        case 3:
            printf("\nEnter the date to search for (YYYY-MM-DD): ");
            scanf("%s", entry.date);

            rewind(fp);
            while (fscanf(fp, "%s %s %[^\n]", entry.date, entry.time, entry.content)!= EOF) {
                if (strcmp(entry.date, entry.date) == 0) {
                    printf("%s %s\n%s\n", entry.date, entry.time, entry.content);
                }
            }
            break;
        case 4:
            printf("\nExiting program...\n");
            fclose(fp);
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
}