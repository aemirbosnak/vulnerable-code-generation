//FormAI DATASET v1.0 Category: Digital Diary ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_LENGTH 1024
#define DATE_LENGTH 10
#define THE_YEAR 2021

struct Entry {
    char date[DATE_LENGTH];
    char content[MAX_ENTRY_LENGTH];
};

char *getCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char *currentDate = (char *) malloc(DATE_LENGTH * sizeof(char));
    sprintf(currentDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, THE_YEAR);

    return currentDate;
}

void writeEntry(struct Entry entry) {
    FILE *fp;
    fp = fopen("diary.txt", "a");
    if(fp == NULL) {
        printf("Unable to open file!");
        exit(1);
    }

    fputs(entry.date, fp);
    fputs("\n", fp);
    fputs(entry.content, fp);
    fputs("\n\n", fp);

    fclose(fp);
}

void readDiary() {
    FILE *fp;
    fp = fopen("diary.txt", "r");
    if(fp == NULL) {
        printf("Unable to open file!");
        exit(1);
    }

    char c = fgetc(fp);

    while(c != EOF) {
        printf("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);
}

void clearDiary() {
    FILE *fp;
    fp = fopen("diary.txt", "w");
    if(fp == NULL) {
        printf("Unable to open file!");
        exit(1);
    }

    fclose(fp);
}

int main() {
    int option;
    struct Entry newEntry;
    char *currentDate;

    do {
        currentDate = getCurrentDate();
        printf("\nDIARY MENU\n");
        printf("1. Write new entry\n");
        printf("2. Read diary\n");
        printf("3. Clear diary\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nWrite entry for %s:\n", currentDate);
                getchar();
                fgets(newEntry.content, MAX_ENTRY_LENGTH, stdin);
                
                strcpy(newEntry.date, currentDate);
                writeEntry(newEntry);

                printf("\nEntry written successfully.\n");
                break;
            
            case 2:
                printf("\nDIARY ENTRIES\n\n");
                readDiary();
                break;

            case 3:
                clearDiary();
                printf("\nDiary cleared successfully.\n");
                break;

            case 4:
                printf("\nExiting C Digital Diary...");
                break;

            default:
                printf("\nInvalid option. Please choose a valid option.\n");
                break;
        }

    } while(option != 4);

    return 0;
}