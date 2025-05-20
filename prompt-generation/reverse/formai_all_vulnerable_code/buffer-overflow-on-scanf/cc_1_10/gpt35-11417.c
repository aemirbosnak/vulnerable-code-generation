//FormAI DATASET v1.0 Category: Database querying ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining structure to store database record
typedef struct record {
    int id;
    char name[50];
    char address[100];
    int age;
    char gender[10];
    float salary;
} Record;

// global variables to access the database
Record *database;
int record_count = 0;

void add_record() {
    printf("Enter name: ");
    char name[50];
    scanf("%s", name);
    printf("Enter address: ");
    char address[100];
    scanf("%s", address);
    printf("Enter age: ");
    int age;
    scanf("%d", &age);
    printf("Enter gender: ");
    char gender[10];
    scanf("%s", gender);
    printf("Enter salary: ");
    float salary;
    scanf("%f", &salary);
    
    record_count++;
    // allocating memory for new record in database
    database = (Record*)realloc(database, record_count*sizeof(Record));
    // adding new record to database
    database[record_count-1].id = record_count;
    strcpy(database[record_count-1].name, name);
    strcpy(database[record_count-1].address, address);
    database[record_count-1].age = age;
    strcpy(database[record_count-1].gender, gender);
    database[record_count-1].salary = salary;
    printf("Record added successfully!\n");
}

void print_record(Record rec) {
    printf("ID: %d\n", rec.id);
    printf("Name: %s\n", rec.name);
    printf("Address: %s\n", rec.address);
    printf("Age: %d\n", rec.age);
    printf("Gender: %s\n", rec.gender);
    printf("Salary: %.2f\n", rec.salary);
}

void display_all_records() {
    printf("Total Records: %d\n", record_count);
    for(int i=0; i<record_count; i++) {
        printf("\nRecord %d:\n", database[i].id);
        print_record(database[i]);
    }
}

void search_by_id() {
    printf("Enter Record ID to search: ");
    int id;
    scanf("%d", &id);
    int found = 0;
    for(int i=0; i<record_count; i++) {
        if(database[i].id == id) {
            printf("Record found!\n");
            print_record(database[i]);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Record with ID %d not found.\n", id);
}

// main function
int main() {
    int option;
    while(1) {
        // displaying menu
        printf("\n-------DATABASE MENU-------\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_record();
                break;
            case 2:
                display_all_records();
                break;
            case 3:
                search_by_id();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}