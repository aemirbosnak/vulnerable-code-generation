//FormAI DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char date[11];  //dd/mm/yyyy format
    char content[101];  //maximum 100 characters for content
} Diary;

void appendToDiary(Diary *diary, int *length, char *content) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[*length].date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(diary[*length].content, content);
    (*length)++;
}

void displayDiary(Diary *diary, int length) {
    if(length == 0) {
        printf("Diary is empty!\n");
        return;
    }
    printf("------------------------------\n");
    for(int i = 0; i < length; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].content);
        printf("------------------------------\n");
    }
}

void saveDiaryToFile(Diary *diary, int length, char *filename) {
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Failed to save diary to file!\n");
        return;
    }
    for(int i = 0; i < length; i++) {
        fprintf(fp, "%s\n%s\n", diary[i].date, diary[i].content);
        fprintf(fp, "------------------------------\n");
    }
    printf("Diary saved to file '%s' successfully!\n", filename);
    fclose(fp);
}

int main() {
    Diary diary[50];
    int length = 0;
    int choice;
    char content[101];
    char filename[21];
    printf("Welcome to Digital Diary!\n");
    while(1) {
        printf("\n1. Add an entry\n");
        printf("2. Display all entries\n");
        printf("3. Save diary to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter your entry (100 characters max): ");
                scanf(" %[^\n]", content);
                appendToDiary(diary, &length, content);
                printf("Entry added successfully!\n");
                break;
            case 2:
                displayDiary(diary, length);
                break;
            case 3:
                printf("Enter a filename to save diary to: ");
                scanf("%s", filename);
                saveDiaryToFile(diary, length, filename);
                break;
            case 4:
                printf("Exiting Digital Diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}