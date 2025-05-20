//FormAI DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Declare variables
Record database[MAX_SIZE];
int numRecords = 0;

// Declare functions
void addRecord();
void printDatabase();
void deleteRecord();

int main(){
    int choice;
    bool running = true;

    printf("***DATABASE SIMULATION***\n\n");

    while(running){
        printf("1. Add Record\n");
        printf("2. Print Database\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addRecord();
                break;
            case 2:
                printDatabase();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                running = false;
                break;
            default:
                printf("Invalid choice. Try Again.\n");
        }
    }

    return 0;
}

void addRecord(){
    if(numRecords == MAX_SIZE){
        printf("Database full. Cannot add new records.\n");
        return;
    }

    Record rec;

    printf("Enter record details:\n");
    printf("ID: ");
    scanf("%d", &rec.id);
    
    printf("Name: ");
    scanf("%s", rec.name);

    printf("Age: ");
    scanf("%d", &rec.age);

    database[numRecords++] = rec;

    printf("Record added to database.\n");
}

void printDatabase(){
    if(numRecords == 0){
        printf("Database is empty.\n");
        return;
    }

    printf("ID\t\tName\tAge\n");

    for(int i=0; i<numRecords; i++){
        printf("%d\t\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

void deleteRecord(){
    if(numRecords == 0){
        printf("Database is empty. Cannot delete record.\n");
        return;
    }

    int delId;
    printf("Enter ID of record to delete: ");
    scanf("%d", &delId);

    bool found = false;

    for(int i=0; i<numRecords; i++){
        if(database[i].id == delId){
            found = true;
            for(int j=i; j<numRecords-1; j++){
                database[j] = database[j+1];
            }
            numRecords--;
            printf("Record deleted.\n");
            break;
        }
    }

    if(!found){
        printf("Record not found.\n");
    }
}