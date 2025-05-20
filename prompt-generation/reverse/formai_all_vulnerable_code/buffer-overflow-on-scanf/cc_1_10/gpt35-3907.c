//FormAI DATASET v1.0 Category: Digital Diary ; Style: lively
#include<stdio.h>
#include<stdlib.h>

typedef struct diary{
    int day;
    int month;
    int year;
    char entry[500];
} Diary;

void addEntry(FILE *fp, Diary *entry){
    printf("Enter the date of your entry in the format DD/MM/YYYY: ");
    scanf("%d/%d/%d", &entry->day, &entry->month, &entry->year);
    fflush(stdin);
    printf("Write your entry: ");
    fgets(entry->entry, 500, stdin);
    fprintf(fp, "%d/%d/%d: %s\n", entry->day, entry->month, entry->year, entry->entry);
    printf("Entry added successfully!\n");
}

void displayEntries(FILE *fp){
    printf("All entries in the diary:\n");
    char buffer[512];
    while(fgets(buffer, 512, fp)){
        printf("%s\n", buffer);
    }
}

int main(){
    FILE *fp = fopen("MyDiary.txt", "a+");
    if(fp == NULL){
        printf("Error in opening file!");
        return -1;
    }

    Diary entry;
    int choice;

    do{
        printf("\n\n**** My Digital Diary ****\n");
        printf("1. Add Entry\n");
        printf("2. Display Previous Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addEntry(fp, &entry);
                break;
            case 2:
                displayEntries(fp);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try Again.\n");
                break;
        }
    }while(choice != 3);

    fclose(fp);
    return 0;
}