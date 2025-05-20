//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Declare a structure to store data fields
struct Record{
    int id;
    char name[MAX_SIZE];
    char address[MAX_SIZE];
    float salary;
};

// Declare function prototypes
void addRecord(struct Record *db[], int *size);
void deleteRecord(struct Record *db[], int *size);
void searchRecord(struct Record *db[], int size);
void displayAllRecords(struct Record *db[], int size);

int main()
{
    int choice, size = 0;
    struct Record *db[MAX_SIZE];
    while(1){
        printf("\n------Database Simulation Menu------\n");
        printf("1. Add a record\n");
        printf("2. Delete a record\n");
        printf("3. Search a record\n");
        printf("4. Display all records\n");
        printf("5. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: addRecord(db, &size); break;
            case 2: deleteRecord(db, &size); break;
            case 3: searchRecord(db, size); break;
            case 4: displayAllRecords(db, size); break;
            case 5: printf("Exiting the program..."); exit(0);
            default: printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}

void addRecord(struct Record *db[], int *size){
    if(*size == MAX_SIZE){
        printf("The database is full, cannot add any more records!\n");
        return;
    }
    db[*size] = (struct Record*)malloc(sizeof(struct Record));
    printf("\nEnter the following details:\n");
    printf("ID: ");
    scanf("%d", &db[*size]->id);
    printf("Name: ");
    scanf(" %[^\n]s", db[*size]->name);
    printf("Address: ");
    scanf(" %[^\n]s", db[*size]->address);
    printf("Salary: ");
    scanf("%f", &db[*size]->salary);
    (*size)++;
    printf("\nRecord added successfully!\n");
}

void deleteRecord(struct Record *db[], int *size){
    if(*size == 0){
        printf("The database is empty, cannot delete any records!\n");
        return;
    }
    int id, i;
    printf("Enter the ID of the record to be deleted: ");
    scanf("%d", &id);
    for(i=0; i<*size; i++){
        if(db[i]->id == id){
            free(db[i]);
            db[i] = db[*size-1];
            (*size)--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found in the database!\n");
}

void searchRecord(struct Record *db[], int size){
    if(size == 0){
        printf("The database is empty, cannot search any records!\n");
        return;
    }
    int id, i;
    printf("Enter the ID of the record to be searched: ");
    scanf("%d", &id);
    for(i=0; i<size; i++){
        if(db[i]->id == id){
            printf("\nRecord found in the database:\n");
            printf("ID: %d\n", db[i]->id);
            printf("Name: %s\n", db[i]->name);
            printf("Address: %s\n", db[i]->address);
            printf("Salary: %.2f\n", db[i]->salary);
            return;
        }
    }
    printf("Record not found in the database!\n");
}

void displayAllRecords(struct Record *db[], int size){
    if(size == 0){
        printf("The database is empty, cannot display any records!\n");
        return;
    }
    int i;
    printf("\nAll records in the database:\n");
    for(i=0; i<size; i++){
        printf("Record %d:\n", i+1);
        printf("ID: %d\n", db[i]->id);
        printf("Name: %s\n", db[i]->name);
        printf("Address: %s\n", db[i]->address);
        printf("Salary: %.2f\n", db[i]->salary);
    }
}