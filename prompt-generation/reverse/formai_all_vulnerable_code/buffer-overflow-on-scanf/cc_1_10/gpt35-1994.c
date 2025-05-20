//FormAI DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATABASE_SIZE 1000

typedef struct{
    int id;
    char name[50];
    int age;
}Record;

typedef struct{
    Record data[MAX_DATABASE_SIZE];
    int size;
}Database;

// Function to add a record to the database
void add_record(Database* db, Record record){
    if(db->size >= MAX_DATABASE_SIZE){
        printf("Database is full. Cannot add more records.\n");
        return;
    }
    db->data[db->size] = record;
    db->size++;
    printf("Record added successfully.\n");
}

// Function to print all the records in the database
void print_records(Database* db){
    for(int i=0; i<db->size; i++){
        printf("ID: %d\tName: %s\tAge: %d\n", db->data[i].id, db->data[i].name, db->data[i].age);
    }
}

int main(){
    Database db;
    db.size = 0;
    int choice;
    do{
        printf("\n\nWelcome to the Database Simulation Program!\n");
        printf("1. Add a record\n");
        printf("2. Print all records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:{
                Record record;
                printf("Enter the ID: ");
                scanf("%d", &record.id);
                printf("Enter the Name: ");
                scanf("%s", record.name);
                printf("Enter the Age: ");
                scanf("%d", &record.age);
                add_record(&db, record);
                break;
            }
            case 2:{
                printf("\n\nPrinting all the records in the database:\n");
                print_records(&db);
                break;
            }
            case 3:{
                printf("Exiting the program. Thank you for using the Database Simulation Program!");
                return 0;
            }
            default:{
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
            }
        }
    }while(1);
    return 0;
}