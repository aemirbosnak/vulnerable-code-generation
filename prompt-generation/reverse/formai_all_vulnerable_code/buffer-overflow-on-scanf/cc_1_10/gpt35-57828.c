//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 //maximum number of records

//structure definition for the database
struct Record {
    int id;
    char name[50];
    char address[100];
    int age;
    float salary;
};

//function declarations
int menu();
void insertRecord(struct Record[], int*);
void updateRecord(struct Record[], int);
void deleteRecord(struct Record[], int*);
void displayRecord(struct Record[], int);
void queryDatabase(struct Record[], int);
void getQueryInput(char*);

int main() {
    struct Record database[MAX_SIZE]; //initializing database array
    int size = 0; //size of the database
    
    int choice = 0;
    while (choice != 6) {
        choice = menu();
        switch (choice) {
            case 1:
                insertRecord(database, &size);
                break;
            case 2:
                updateRecord(database, size);
                break;
            case 3:
                deleteRecord(database, &size);
                break;
            case 4:
                displayRecord(database, size);
                break;
            case 5:
                queryDatabase(database, size);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

//displays the menu of operations and takes input
int menu() {
    printf("\nWhat operation would you like to perform?\n");
    printf("1. Insert a new record\n");
    printf("2. Update an existing record\n");
    printf("3. Delete a record\n");
    printf("4. Display all records\n");
    printf("5. Query the database\n");
    printf("6. Exit\n");
    printf("\nEnter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    return choice;
}

//inserts a new record in the database
void insertRecord(struct Record database[], int* size) {
    if (*size == MAX_SIZE) {
        printf("Sorry, the database is full.\n");
        return;
    }
    
    struct Record r;
    printf("\nEnter the details of the record to be added:\n");
    printf("ID: ");
    scanf("%d", &r.id);
    printf("Name: ");
    getchar();
    fgets(r.name, 50, stdin);
    strtok(r.name, "\n");
    printf("Address: ");
    fgets(r.address, 100, stdin);
    strtok(r.address, "\n");
    printf("Age: ");
    scanf("%d", &r.age);
    printf("Salary: ");
    scanf("%f", &r.salary);
    
    database[*size] = r;
    (*size)++;
    
    printf("Record added successfully.\n");
}

//updates an existing record in the database
void updateRecord(struct Record database[], int size) {
    if (size == 0) {
        printf("Sorry, the database is empty.\n");
        return;
    }
    
    int id;
    printf("\nEnter the ID of the record to be updated: ");
    scanf("%d", &id);
    
    int i;
    for (i = 0; i < size; i++) {
        if (database[i].id == id) {
            struct Record r;
            r.id = id;
            printf("Enter the new details of the record:\n");
            printf("Name: ");
            getchar();
            fgets(r.name, 50, stdin);
            strtok(r.name, "\n");
            printf("Address: ");
            fgets(r.address, 100, stdin);
            strtok(r.address, "\n");
            printf("Age: ");
            scanf("%d", &r.age);
            printf("Salary: ");
            scanf("%f", &r.salary);
            
            database[i] = r;
            printf("Record updated successfully.\n");
            return;
        }
    }
    
    printf("Record not found with ID %d.\n", id);
}

//deletes an existing record from the database
void deleteRecord(struct Record database[], int* size) {
    if (*size == 0) {
        printf("Sorry, the database is empty.\n");
        return;
    }
    
    int id;
    printf("\nEnter the ID of the record to be deleted: ");
    scanf("%d", &id);
    
    int i;
    for (i = 0; i < *size; i++) {
        if (database[i].id == id) {
            int j;
            for (j = i; j < *size - 1; j++) {
                database[j] = database[j+1];
            }
            (*size)--;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    
    printf("Record not found with ID %d.\n", id);
}

//displays all records in the database
void displayRecord(struct Record database[], int size) {
    if (size == 0) {
        printf("Sorry, the database is empty.\n");
        return;
    }
    
    int i;
    printf("\nID\tName\t\tAddress\t\tAge\tSalary\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%s\t%s\t%d\t%.2f\n", database[i].id, database[i].name, database[i].address, database[i].age, database[i].salary);
    }
}

//lets the user query the database based on name, address, or age
void queryDatabase(struct Record database[], int size) {
    if (size == 0) {
        printf("Sorry, the database is empty.\n");
        return;
    }
    
    char query[100];
    getQueryInput(query);
    int qLength = strlen(query);
    
    int i;
    printf("\nID\tName\t\tAddress\t\tAge\tSalary\n");
    for (i = 0; i < size; i++) {
        if (strncmp(database[i].name, query, qLength) == 0 || strncmp(database[i].address, query, qLength) == 0 || database[i].age == atoi(query)) {
            printf("%d\t%s\t%s\t%d\t%.2f\n", database[i].id, database[i].name, database[i].address, database[i].age, database[i].salary);
        }
    }
}

//gets input from the user for a query term
void getQueryInput(char* query) {
    printf("\nEnter the name, address, or age to query: ");
    getchar();
    fgets(query, 100, stdin);
    strtok(query, "\n");
}