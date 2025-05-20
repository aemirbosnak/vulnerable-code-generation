//FormAI DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

typedef struct PhoneBookEntry {
    char name[MAX_LENGTH];
    char number[MAX_LENGTH];
} Entry;

int menu();
void display(Entry*, int);
void addEntry(Entry*, int*);
void searchEntry(Entry*, int);
void saveData(Entry*, int);

int main() {
    int option, count = 0;
    Entry phoneBook[50];
    
    printf("Welcome to the Phone Book!\n");
    
    FILE* fp;
    fp = fopen("phonebook.dat", "rb");
    
    if(fp != NULL) {
        count = fread(phoneBook, sizeof(Entry), 50, fp);
        printf("%d entries loaded!\n", count);
        fclose(fp);
    } else {
        printf("No phone book data found!\n");
    }
    
    do {
        option = menu();
        
        switch(option) {
            case 1:
                display(phoneBook, count);
                break;
            case 2:
                addEntry(phoneBook, &count);
                break;
            case 3:
                searchEntry(phoneBook, count);
                break;
            case 4:
                saveData(phoneBook, count);
                printf("Phone book data saved!\n");
                break;
            case 5:
                printf("Exiting phone book...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while(option != 5);
    
    return 0;
}

int menu() {
    int option;
    
    printf("\n--- Main Menu ---\n");
    printf("1. Display phone book entries\n");
    printf("2. Add a new phone book entry\n");
    printf("3. Search for a phone book entry\n");
    printf("4. Save phone book data to file\n");
    printf("5. Exit\n");
    printf("Select an option: ");
    scanf("%d", &option);
    
    return option;
}

void display(Entry* phoneBook, int count) {
    if(count == 0) {
        printf("The phone book is empty!\n");
        return;
    }
    
    printf("\n--- Phone Book Entries ---\n");
    
    for(int i = 0; i < count; i++) {
        printf("Name: %s | Number: %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

void addEntry(Entry* phoneBook, int* count) {
    if(*count == 50) {
        printf("The phone book is full! Cannot add more entries.\n");
        return;
    }
    
    printf("\n--- Add New Entry ---\n");
    printf("Enter name (max %d characters): ", MAX_LENGTH);
    fflush(stdin);
    fgets(phoneBook[*count].name, sizeof(phoneBook[*count].name), stdin);
    phoneBook[*count].name[strlen(phoneBook[*count].name) - 1] = '\0';
    printf("Enter number (max %d characters): ", MAX_LENGTH);
    fflush(stdin);
    fgets(phoneBook[*count].number, sizeof(phoneBook[*count].number), stdin);
    phoneBook[*count].number[strlen(phoneBook[*count].number) - 1] = '\0';
    
    printf("New entry added!\n");
    
    (*count)++;
}

void searchEntry(Entry* phoneBook, int count) {
    char query[MAX_LENGTH];
    int found = 0;
    
    printf("\n--- Search for Entry ---\n");
    printf("Enter name or number to search for: ");
    fflush(stdin);
    fgets(query, sizeof(query), stdin);
    query[strlen(query) - 1] = '\0';
    
    for(int i = 0; i < count; i++) {
        if(strcmp(phoneBook[i].name, query) == 0 || strcmp(phoneBook[i].number, query) == 0) {
            printf("Match found! Name: %s | Number: %s\n", phoneBook[i].name, phoneBook[i].number);
            found = 1;
        }
    }
    
    if(!found) {
        printf("No matching entries found!\n");
    }
}

void saveData(Entry* phoneBook, int count) {
    FILE* fp;
    fp = fopen("phonebook.dat", "wb");
    
    if(fp != NULL) {
        fwrite(phoneBook, sizeof(Entry), count, fp);
        fclose(fp);
    } else {
        printf("Failed to save phone book data!\n");
    }
}