//FormAI DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

void displayMenu();
void createEntry();
void viewEntry();

int main(){
    char choice;
    do{
        displayMenu();
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        switch(choice){
            case '1':
                createEntry();
                break;
            case '2':
                viewEntry();
                break;
            case '3':
                printf("\nExiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid input. Try again.\n");
        }
    }while(choice != '3');
    return 0;
}

void displayMenu(){
    printf("------- Digital Diary -------\n");
    printf("1. Create Entry\n");
    printf("2. View Entry\n");
    printf("3. Exit\n");
}

void createEntry(){
    char title[MAX_SIZE], entry[MAX_SIZE], date[MAX_SIZE];
    getchar();
    printf("\nEnter the entry title: ");
    fgets(title, MAX_SIZE, stdin);
    printf("Enter the date of the entry (dd-mm-yyyy): ");
    fgets(date, MAX_SIZE, stdin);
    printf("Enter the entry:\n");
    fgets(entry, MAX_SIZE, stdin);
    strcat(title, date);
    FILE *file = fopen(title, "w");
    if(file){
        fputs(entry, file);
        printf("\nEntry created successfully!\n");
        fclose(file);
    }
    else {
        printf("\nFailed to create entry. Try again.\n");
    }
}

void viewEntry(){
    char title[MAX_SIZE], ch;
    getchar();
    printf("\nEnter the entry title and date (dd-mm-yyyy): ");
    fgets(title, MAX_SIZE, stdin);
    FILE *file = fopen(title, "r");
    if(file){
        printf("\n%s\n", title);
        while((ch = fgetc(file)) != EOF){
            printf("%c", ch);
        }
        fclose(file);
    }
    else {
        printf("\nEntry not found. Try again.\n");
    }
}