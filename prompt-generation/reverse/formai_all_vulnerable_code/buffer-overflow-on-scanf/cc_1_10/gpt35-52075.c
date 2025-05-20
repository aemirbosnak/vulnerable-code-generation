//FormAI DATASET v1.0 Category: Digital Diary ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//defining the structure for a diary entry
struct DiaryEntry{
    char date[20];
    char time[10];
    char title[50];
    char description[500];
    struct DiaryEntry* next;
};

//function to add a new entry to the diary
void addEntry(struct DiaryEntry** head, char* date, char* time, char* title, char* description){
    struct DiaryEntry* newEntry = (struct DiaryEntry*)malloc(sizeof(struct DiaryEntry)); //allocating memory for new entry
    strcpy(newEntry->date, date);
    strcpy(newEntry->time, time);
    strcpy(newEntry->title, title);
    strcpy(newEntry->description, description);
    newEntry->next = NULL;

    if(*head == NULL){
        *head = newEntry;
        return;
    }

    struct DiaryEntry* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newEntry;
}

//function to print all the entries in the diary
void printEntries(struct DiaryEntry* head){
    if(head == NULL){
        printf("No entries found!\n");
        return;
    }

    while(head != NULL){
        printf("\nDate: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("Title: %s\n", head->title);
        printf("Description: %s\n", head->description);
        printf("\n");

        head = head->next;
    }
}

int main(){
    struct DiaryEntry* head = NULL;
    int choice;

    printf("Welcome to your Digital Diary!\n");

    do{
        printf("\n1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                char date[20], time[10], title[50], description[500];
                printf("\nEnter date (DD/MM/YYYY): ");
                scanf("%s", date);
                printf("Enter time (HH:MM): ");
                scanf("%s", time);
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter a description: ");
                scanf("%s", description);

                addEntry(&head, date, time, title, description);
                break;
            }
            case 2:{
                printf("\nAll Entries:\n");
                printEntries(head);
                break;
            }
            case 3:{
                printf("\nThank you for using Digital Diary!\n");
                break;
            }
            default:{
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
            }
        }

    }while(choice != 3);

    return 0;
}