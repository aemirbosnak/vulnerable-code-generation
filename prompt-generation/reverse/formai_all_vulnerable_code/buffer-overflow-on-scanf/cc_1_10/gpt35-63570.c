//FormAI DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

struct PhoneBookEntry{
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

struct PhoneBook{
    struct PhoneBookEntry entries[MAX_ENTRIES];
    int numEntries;
};

void addEntry(struct PhoneBook* book){
    if(book->numEntries < MAX_ENTRIES){
        printf("Enter name: ");
        scanf("%s", book->entries[book->numEntries].name);
        printf("Enter number: ");
        scanf("%s", book->entries[book->numEntries].number);
        book->numEntries ++;
        printf("Entry added successfully!\n");
    }
    else{
        printf("Cannot add entry. Phone book is full.\n");
    }
}

void removeEntry(struct PhoneBook* book){
    char name[MAX_NAME_LENGTH];
    printf("Enter name: ");
    scanf("%s", name);
    int found = -1;
    for(int i=0;i<book->numEntries;i++){
        if(strcmp(book->entries[i].name, name) == 0){
            found = i;
            break;
        }
    }
    if(found == -1){
        printf("Entry not found.\n");
    }
    else{
        for(int i=found;i<book->numEntries-1;i++){
            strcpy(book->entries[i].name, book->entries[i+1].name);
            strcpy(book->entries[i].number, book->entries[i+1].number);
        }
        book->numEntries --;
        printf("Entry removed successfully!\n");
    }
}

void searchName(struct PhoneBook* book){
    char name[MAX_NAME_LENGTH];
    printf("Enter name: ");
    scanf("%s", name);
    int found = -1;
    for(int i=0;i<book->numEntries;i++){
        if(strcmp(book->entries[i].name, name) == 0){
            found = i;
            break;
        }
    }
    if(found == -1){
        printf("Entry not found.\n");
    }
    else{
        printf("Found: %s %s\n", book->entries[found].name, book->entries[found].number);
    }
}

void searchNumber(struct PhoneBook* book){
    char number[MAX_NUMBER_LENGTH];
    printf("Enter number: ");
    scanf("%s", number);
    int found = -1;
    for(int i=0;i<book->numEntries;i++){
        if(strcmp(book->entries[i].number, number) == 0){
            found = i;
            break;
        }
    }
    if(found == -1){
        printf("Entry not found.\n");
    }
    else{
        printf("Found: %s %s\n", book->entries[found].name, book->entries[found].number);
    }
}

void printEntries(struct PhoneBook* book){
    printf("%-20s %s\n", "Name", "Number");
    for(int i=0;i<book->numEntries;i++){
        printf("%-20s %s\n", book->entries[i].name, book->entries[i].number);
    }
}

int main(){
    struct PhoneBook book = {.numEntries = 0};
    int choice;
    do{
        printf("Phone Book\n");
        printf("1. Add Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Search by Name\n");
        printf("4. Search by Number\n");
        printf("5. Print All Entries\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addEntry(&book);
                break;
            case 2:
                removeEntry(&book);
                break;
            case 3:
                searchName(&book);
                break;
            case 4:
                searchNumber(&book);
                break;
            case 5:
                printEntries(&book);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }while(choice != 6);
    return 0;
}