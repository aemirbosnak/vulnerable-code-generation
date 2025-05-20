//FormAI DATASET v1.0 Category: Database simulation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

typedef struct Record{
    int id;
    char name[20];
    char address[30];
}Record;

void addRecord(Record *database, int *count);
void deleteRecord(Record *database, int *count);
void searchRecord(Record *database, int *count);
void displayDatabase(Record *database, int *count);

int main()
{
    int option, count=0;
    Record database[SIZE];
    do{
        printf("Welcome to paranoid database simulation\n");
        printf("------------------------------------------------------------\n");
        printf("Choose an option:\n 1.Add a record\n 2.Delete a record\n 3.Search a record\n 4.Display the database\n 5.Exit\n");
        printf("------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1: addRecord(database, &count); break;
            case 2: deleteRecord(database, &count); break;
            case 3: searchRecord(database, &count); break;
            case 4: displayDatabase(database, &count); break;
            case 5: printf("Exiting the paranoid database simulation...\n"); break;
            default: printf("Invalid choice!\n");
        }
        printf("------------------------------------------------------------\n");
    } while(option != 5);
    return 0;
}

void addRecord(Record *database, int *count){
    int id;
    printf("Enter the ID of the record to be added: ");
    scanf("%d", &id);
    for(int i=0; i<*count; i++){
        if(database[i].id == id){
            printf("Record with ID %d already exists!\n", id);
            return;
        }
    }
    if(*count < SIZE){
        database[*count].id = id;
        printf("Enter the name of the person: ");
        scanf("%s", database[*count].name);
        printf("Enter the address of the person: ");
        scanf("%s", database[*count].address);
        (*count)++;
    }
    else{
        printf("Database is full!\n");
    }
}

void deleteRecord(Record *database, int *count){
    int id, index=-1;
    printf("Enter the ID of the record to be deleted: ");
    scanf("%d", &id);
    for(int i=0; i<*count; i++){
        if(database[i].id == id){
            index = i;
            break;
        }
    }
    if(index != -1){
        for(int i=index; i<(*count)-1; i++){
            database[i] = database[i+1];
        }
        (*count)--;
        printf("Record with ID %d deleted successfully!\n", id);
    }
    else{
        printf("Record with ID %d does not exist!\n", id);
    }
}

void searchRecord(Record *database, int *count){
    int id, index=-1;
    printf("Enter the ID of the record to be searched: ");
    scanf("%d", &id);
    for(int i=0; i<*count; i++){
        if(database[i].id == id){
            index = i;
            break;
        }
    }
    if(index != -1){
        printf("Record found:\n");
        printf("ID: %d\n", database[index].id);
        printf("Name: %s\n", database[index].name);
        printf("Address: %s\n", database[index].address);
    }
    else{
        printf("Record with ID %d does not exist!\n", id);
    }
}

void displayDatabase(Record *database, int *count){
    if(*count == 0){
        printf("Database is empty!\n");
    }
    else{
        printf("ID\tName\t\tAddress\n");
        for(int i=0; i<*count; i++){
            printf("%d\t%s\t\t%s\n", database[i].id, database[i].name, database[i].address);
        }
    }
}