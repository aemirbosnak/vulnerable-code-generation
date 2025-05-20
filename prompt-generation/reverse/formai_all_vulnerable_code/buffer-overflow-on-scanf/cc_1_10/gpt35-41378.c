//FormAI DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUM_LENGTH 15
#define MAX_ENTRY_NUM 100

struct entry{
    char name[MAX_NAME_LENGTH];
    char phoneNum[MAX_PHONE_NUM_LENGTH];
};

struct phoneBook{
    struct entry entries[MAX_ENTRY_NUM];
    int size;
};

void printMenu(void);
int addEntry(struct phoneBook* book);
void searchEntry(struct phoneBook* book);
int deleteEntry(struct phoneBook* book);
void printEntries(struct phoneBook* book);
void saveEntries(struct phoneBook* book, char* fileName);
int loadEntries(struct phoneBook* book, char* fileName);
void clearBuffer(void);

int main(void){
    struct phoneBook book;
    book.size = 0;
    int input = 0;
    char fileName[MAX_NAME_LENGTH] = "phoneBook.txt";
    
    int loadedNum = loadEntries(&book, fileName);
    if(loadedNum != -1){
        printf("%d entries have been loaded from %s.\n", loadedNum, fileName);
    }
    
    while(input != 6){
        printMenu();
        scanf("%d", &input);
        switch(input){
            case 1:
                addEntry(&book);
                break;
            case 2:
                searchEntry(&book);
                break;
            case 3:
                deleteEntry(&book);
                break;
            case 4:
                printEntries(&book);
                break;
            case 5:
                saveEntries(&book, fileName);
                break;
            case 6:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid input.\n");
                clearBuffer();
        }
    }
    
    return 0;
}

void printMenu(){
    printf("\n1. Add Entry\n");
    printf("2. Search Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Print All Entries\n");
    printf("5. Save Entries\n");
    printf("6. Exit\n");
    printf("\nEnter your selection: ");
}

int addEntry(struct phoneBook* book){
    if(book->size >= MAX_ENTRY_NUM){
        printf("Cannot add more entries.\n");
        return 0;
    }
    
    struct entry newEntry;
    printf("\nEnter Name: ");
    scanf("%s", newEntry.name);
    printf("Enter Phone Number: ");
    scanf("%s", newEntry.phoneNum);
    
    book->entries[book->size++] = newEntry;
    printf("The entry has been added successfully.\n");
    
    return 1;
}

void searchEntry(struct phoneBook* book){
    char queryName[MAX_NAME_LENGTH];
    printf("\nEnter a Name to search: ");
    scanf("%s", queryName);
    
    int found = 0;
    for(int i=0; i<book->size; i++){
        if(strcmp(queryName, book->entries[i].name) == 0){
            printf("%s: %s\n", book->entries[i].name, book->entries[i].phoneNum);
            found = 1;
        }
    }
    
    if(!found){
        printf("No match found.\n");
    }
}

int deleteEntry(struct phoneBook* book){
    char queryName[MAX_NAME_LENGTH];
    printf("\nEnter a Name to delete: ");
    scanf("%s", queryName);
    
    int found = 0;
    for(int i=0; i<book->size; i++){
        if(strcmp(queryName, book->entries[i].name) == 0){
            for(int j=i; j<book->size-1; j++){
                book->entries[j] = book->entries[j+1];
            }
            book->size--;
            printf("The entry has been deleted successfully.\n");
            found = 1;
            break;
        }
    }
    
    if(!found){
        printf("No match found.\n");
    }
    
    return found;
}

void printEntries(struct phoneBook* book){
    printf("Printing all entries...\n");
    for(int i=0; i<book->size; i++){
        printf("%s: %s\n", book->entries[i].name, book->entries[i].phoneNum);
    }
}

void saveEntries(struct phoneBook* book, char* fileName){
    FILE* fp = fopen(fileName, "w");
    if(fp == NULL){
        printf("Failed to save the entries.\n");
        return;
    }
    
    for(int i=0; i<book->size; i++){
        fprintf(fp, "%s %s\n", book->entries[i].name, book->entries[i].phoneNum);
    }
    fclose(fp);
    printf("%d entries have been saved to %s.\n", book->size, fileName);
}

int loadEntries(struct phoneBook* book, char* fileName){
    FILE* fp = fopen(fileName, "r");
    if(fp == NULL){
        printf("Cannot open the file.\n");
        return -1;
    }
    
    int numLoaded = 0;
    char line[MAX_NAME_LENGTH + MAX_PHONE_NUM_LENGTH + 2];
    while(fgets(line, sizeof(line), fp)){
        int len = strlen(line);
        if(line[len-1] == '\n'){
            line[len-1] = '\0';
        }
        char* name = strtok(line, " ");
        char* phoneNum = strtok(NULL, " ");
        if(name != NULL && phoneNum != NULL){
            strcpy(book->entries[book->size].name, name);
            strcpy(book->entries[book->size].phoneNum, phoneNum);
            book->size++;
            numLoaded++;
        }
    }
    
    fclose(fp);
    return numLoaded;
}

void clearBuffer(){
    while(getchar() != '\n');
}