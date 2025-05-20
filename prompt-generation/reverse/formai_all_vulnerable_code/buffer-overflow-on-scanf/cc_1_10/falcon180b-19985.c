//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct entry {
    char date[20];
    char time[20];
    char mood[50];
    char content[500];
};

int main() {
    int choice = 0;
    char filename[50] = "diary.txt";
    FILE *fp;
    struct entry entry;

    fp = fopen(filename, "a");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    do {
        system("clear");
        printf("Digital Diary\n\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter date (dd/mm/yyyy): ");
            scanf("%s", entry.date);
            printf("Enter time (hh:mm:ss): ");
            scanf("%s", entry.time);
            printf("Enter your mood: ");
            scanf("%s", entry.mood);
            printf("Write your entry:\n");
            fgets(entry.content, sizeof(entry.content), stdin);
            fprintf(fp, "Date: %s\n", entry.date);
            fprintf(fp, "Time: %s\n", entry.time);
            fprintf(fp, "Mood: %s\n", entry.mood);
            fprintf(fp, "Content:\n%s", entry.content);
            fprintf(fp, "\n");
            printf("Entry saved!\n");
            break;
        case 2:
            rewind(fp);
            printf("Your entries:\n");
            while (fgets(entry.content, sizeof(entry.content), fp)!= NULL) {
                printf("%s", entry.content);
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    fclose(fp);
    return 0;
}