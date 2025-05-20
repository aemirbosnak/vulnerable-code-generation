//FormAI DATASET v1.0 Category: Digital Diary ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_CHAR 1024
#define MAX_ENTRIES 50

typedef struct {
    char date[15];
    char time[10];
    char entry[MAX_CHAR];
} DiaryEntry;

void showMenu();
void showAllEntries(int entryCount, DiaryEntry diary[]);
void addNewEntry(int *entryCount, DiaryEntry diary[]);
void writeToFile(int entryCount, DiaryEntry diary[]);
void readFromFile(int *entryCount, DiaryEntry diary[]);

int main(){
    DiaryEntry diary[MAX_ENTRIES];
    int entryCount = 0, choice;
    readFromFile(&entryCount, diary);
    while(1){
        showMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addNewEntry(&entryCount, diary);
                break;
            case 2:
                showAllEntries(entryCount, diary);
                break;
            case 3:
                writeToFile(entryCount, diary);
                printf("Successfully saved to file!\n");
                break;
            case 4:
                readFromFile(&entryCount, diary);
                printf("Successfully read from file!\n");
                break;
            case 0:
                printf("Exiting from diary...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void showMenu(){
    printf("----------------------------\n");
    printf("------- DIGITAL DIARY ------\n");
    printf("----------------------------\n");
    printf("1. Add new entry\n");
    printf("2. Show all entries\n");
    printf("3. Write to file\n");
    printf("4. Read from file\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void showAllEntries(int entryCount, DiaryEntry diary[]){
    if(entryCount == 0){
        printf("Diary is empty. No entries to display.\n");
        return;
    }
    printf("Showing all entries:\n");
    for(int i=0; i<entryCount; i++){
        printf("Entry %d:\n", i+1);
        printf("Date: %s\n", diary[i].date);
        printf("Time: %s\n", diary[i].time);
        printf("Entry: %s\n", diary[i].entry);
        printf("---------------------------\n");
    }
}

void addNewEntry(int *entryCount, DiaryEntry diary[]){
    if(*entryCount == MAX_ENTRIES){
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }
    DiaryEntry newEntry;
    time_t rawtime;
    struct tm *timestamp;
    time(&rawtime);
    timestamp = localtime(&rawtime);
    strftime(newEntry.date, 15, "%m/%d/%Y", timestamp);
    strftime(newEntry.time, 10, "%I:%M %p", timestamp);
    printf("Enter your diary entry: ");
    scanf("%*c%[^\n]", newEntry.entry);
    diary[*entryCount] = newEntry;
    (*entryCount)++;
    printf("New entry added successfully!\n");
}

void writeToFile(int entryCount, DiaryEntry diary[]){
    FILE *fp;
    fp = fopen("diary.txt", "w");
    if(fp == NULL){
        printf("Unable to open file.\n");
        return;
    }
    fwrite(&entryCount, sizeof(int), 1, fp);
    for(int i=0; i<entryCount; i++){
        fwrite(&diary[i], sizeof(DiaryEntry), 1, fp);
    }
    fclose(fp);
}

void readFromFile(int *entryCount, DiaryEntry diary[]){
    FILE *fp;
    fp = fopen("diary.txt", "r");
    if(fp == NULL){
        printf("Unable to open file.\n");
        return;
    }
    fread(entryCount, sizeof(int), 1, fp);
    for(int i=0; i<*entryCount; i++){
        fread(&diary[i], sizeof(DiaryEntry), 1, fp);
    }
    fclose(fp);
}