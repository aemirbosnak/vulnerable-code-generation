//FormAI DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Entry{
    char date[15];
    char time[15];
    char title[50];
    char content[500];
};

void writeEntry(struct Entry *diary, int *count){
    printf("Enter today's date(mm/dd/yyyy): ");
    scanf("%s", (diary[*count]).date);
    printf("Enter the time(hh:mm AM/PM): ");
    scanf("%s", (diary[*count]).time);
    printf("Enter a title for the entry: ");
    scanf(" %[^\n]s", (diary[*count]).title);
    printf("Type your entry here:\n");
    scanf(" %[^\n]s", (diary[*count]).content);
    (*count)++;
}

void viewEntries(struct Entry *diary, int *count){
    if(*count == 0){
        printf("No entries found in diary\n");
    }
    else{
        printf("DIARY ENTRIES:\n");
        for(int i=0; i<*count; i++){
            printf("\nEntry %d:\n", i+1);
            printf("Date: %s\n", (diary[i]).date);
            printf("Time: %s\n", (diary[i]).time);
            printf("Title: %s\n", (diary[i]).title);
            printf("Content: %s\n", (diary[i]).content);
        }
    }
}

void deleteEntry(struct Entry *diary, int *count){
    if(*count==0){
        printf("No entries found in diary\n");
    }
    else{
        int choice;
        printf("Enter entry number to delete: ");
        scanf("%d", &choice);
        if(choice<=0 || choice>*count){
            printf("Invalid choice. Please try again\n");
        }
        else{
            for(int i=choice-1; i<*count-1; i++){
                strcpy(diary[i].date, diary[i+1].date);
                strcpy(diary[i].time, diary[i+1].time);
                strcpy(diary[i].title, diary[i+1].title);
                strcpy(diary[i].content, diary[i+1].content);
            }
            (*count)--;
            printf("Entry %d deleted successfully\n", choice);
        }
    }
}

int main(){
    struct Entry diary[100];
    int count=0;
    int ch;
    while(1){
        printf("\nDIARY MENU:\n");
        printf("1. Write a new entry\n");
        printf("2. View all entries\n");
        printf("3. Delete an entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                writeEntry(diary, &count);
                break;
            case 2:
                viewEntries(diary, &count);
                break;
            case 3:
                deleteEntry(diary, &count);
                break;
            case 4:
                printf("Exiting diary...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again\n");
        }
    }
    return 0;
}