//FormAI DATASET v1.0 Category: Phone Book ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct PhoneBook{
    char name[50];
    char phone_number[15];
}PhoneBook;

PhoneBook* phoneBook[MAX_SIZE];

void createEntry(){
    PhoneBook* entry = (PhoneBook*)malloc(sizeof(PhoneBook));
    printf("Enter Name: ");
    scanf("%s",(entry->name));
    printf("Enter Phone Number: ");
    scanf("%s",(entry->phone_number));

    for(int i=0;i<MAX_SIZE;i++){
        if(phoneBook[i] == NULL){
            phoneBook[i] = entry;
            printf("Entry Created!\n");
            return;
        }
    }
    printf("PhoneBook is full!\n");
}

void searchEntry(){
    char query[50];
    printf("Enter Name to search: ");
    scanf("%s",query);
    for(int i=0;i<MAX_SIZE;i++){
        if(phoneBook[i] != NULL && strcmp(query,phoneBook[i]->name) == 0){
            printf("Name: %s\nPhone Number:%s\n",phoneBook[i]->name,phoneBook[i]->phone_number);
            return;
        }
    }
    printf("Contact not found!\n");
}

void deleteEntry(){
    char query[50];
    printf("Enter Name to delete: ");
    scanf("%s",query);
    for(int i=0;i<MAX_SIZE;i++){
        if(phoneBook[i] != NULL && strcmp(query,phoneBook[i]->name) == 0){
            free(phoneBook[i]);
            phoneBook[i] = NULL;
            printf("Contact deleted\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void showAllEntries(){
    printf("All Entries: \n");
    for(int i=0;i<MAX_SIZE;i++){
        if(phoneBook[i] != NULL){
            printf("Name: %s\nPhone Number:%s\n",phoneBook[i]->name,phoneBook[i]->phone_number);
        }
    }
}

int main(){
    int choice;
    printf("Welcome to C Phone Book\n");
    do{
        printf("Menu:\n");
        printf("1. Create Entry\n");
        printf("2. Search Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Show All Entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                createEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                showAllEntries();
                break;
            case 5:
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }while(choice != 5);
    return 0;
}