//FormAI DATASET v1.0 Category: Digital Diary ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct entry{
    char date[20];
    char title[100];
    char content[500];
};

void new_entry(){
    struct entry e;
    printf("\nEnter the date in DD/MM/YYYY format: ");
    scanf("%s", e.date);
    getchar();
    printf("Enter the title of the entry: ");
    fgets(e.title, 100, stdin);
    printf("Enter your thoughts for the day:\n");
    fgets(e.content, 500, stdin);
    FILE *fptr;
    fptr = fopen("diary.txt", "ab");
    if(fptr == NULL){
        printf("\nError opening file!");
        exit(1);
    }
    fwrite(&e, sizeof(e), 1, fptr);
    fclose(fptr);
    printf("\nEntry added successfully.\n");

}

void view_entry(){
    struct entry e;
    FILE *fptr;
    fptr = fopen("diary.txt", "rb");
    if(fptr == NULL){
        printf("\nError opening file!");
        exit(1);
    }
    while(fread(&e, sizeof(e), 1, fptr)){
        printf("\n\nDate: %s\nTitle: %sThoughts:\n%s", e.date, e.title, e.content);
    }
    fclose(fptr);
}

int main(){
    char option;
    printf("\nWelcome to your Digital Diary!\n");
    printf("-----------------------------\n");
    printf("Press 'n' to add a new entry.\n");
    printf("Press 'v' to view all entries.\n");
    printf("Press 'q' to quit.\n\n");
    while(option != 'q'){
        printf("Enter your choice: ");
        scanf("%c", &option);
        switch(option){
            case 'n':
                new_entry();
                break;
            case 'v':
                view_entry();
                break;
            case 'q':
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}