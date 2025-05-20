//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50

typedef struct{
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Record;

void printMenu(){
    printf("Welcome to the Database Indexing System\n");
    printf("-----------------Menu-----------------\n");
    printf("1. Add a record\n");
    printf("2. Search for a record\n");
    printf("3. Delete a record\n");
    printf("4. Display all records\n");
    printf("5. Exit\n");
}

void addRecord(Record database[], int *numRecords, int *nextID){
    if(*numRecords >= MAX_RECORDS){
        printf("Error: Maximum number of records reached\n");
        return;
    }
    Record newRecord;
    newRecord.id = (*nextID)++;
    printf("Enter the name: ");
    scanf("%s", newRecord.name);
    printf("Enter the address: ");
    scanf("%s", newRecord.address);
    database[*numRecords] = newRecord;
    printf("Record added successfully with ID %d\n", newRecord.id);
    (*numRecords)++;
}

void searchRecord(Record database[], int numRecords){
    int id;
    printf("Enter the ID of the record you want to search for: ");
    scanf("%d", &id);
    for(int i = 0; i < numRecords; i++){
        if(database[i].id == id){
            printf("Record found: %s, %s\n", database[i].name, database[i].address);
            return;
        }
    }
    printf("Record not found\n");
}

void deleteRecord(Record database[], int *numRecords){
    int id;
    printf("Enter the ID of the record you want to delete: ");
    scanf("%d", &id);
    for(int i = 0; i < *numRecords; i++){
        if(database[i].id == id){
            for(int j = i; j < *numRecords-1; j++){
                database[j] = database[j+1];
            }
            printf("Record deleted successfully\n");
            (*numRecords)--;
            return;
        }
    }
    printf("Record not found\n");
}

void displayRecords(Record database[], int numRecords){
    printf("ID\tName\tAddress\n");
    for(int i = 0; i < numRecords; i++){
        printf("%d\t%s\t%s\n", database[i].id, database[i].name, database[i].address);
    }
}

int main(){
    Record database[MAX_RECORDS];
    int numRecords = 0;
    int nextID = 1;

    int choice;
    do{
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addRecord(database, &numRecords, &nextID);
                break;
            case 2:
                searchRecord(database, numRecords);
                break;
            case 3:
                deleteRecord(database, &numRecords);
                break;
            case 4:
                displayRecords(database, numRecords);
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 5);
    return 0;
}