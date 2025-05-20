//FormAI DATASET v1.0 Category: Database simulation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1024

// Defining the database structure
typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
    float salary;
}employee;

// Function to insert a new record into the database
void insert(employee db[], int *count) {
    printf("\nEnter employee name: ");
    scanf("%s", db[*count].name);
    printf("\nEnter employee age: ");
    scanf("%d", &db[*count].age);
    printf("\nEnter employee salary: ");
    scanf("%f", &db[*count].salary);
    db[*count].id = *count + 1;
    *count += 1;
}

// Function to delete a record from the database
void delete(employee db[], int *count) {
    int id;
    printf("\nEnter the employee ID you want to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (db[i].id == id) {
            *count -= 1;
            found = 1;
            for (int j = i; j < *count; j++) {
                db[j].id = db[j+1].id - 1;
                strcpy(db[j].name, db[j+1].name);
                db[j].age = db[j+1].age;
                db[j].salary = db[j+1].salary;
            }
            break;
        }
    }
    if (found == 0) {
        printf("\nRecord not found!\n");
    }
}

// Function to display all the records in the database
void display(employee db[], int count) {
    if (count == 0) {
        printf("\nNo records found in the database!\n");
        return;
    }
    printf("\nID\tName\tAge\tSalary\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", db[i].id, db[i].name, db[i].age, db[i].salary);
    }
}

int main() {
    employee db[MAX_SIZE];
    int count = 0;
    int choice = 0;

    while (1) {
        printf("\n1. Insert record\n2. Delete record\n3. Display records\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(db, &count);
                    break;
            case 2: delete(db, &count);
                    break;
            case 3: display(db, count);
                    break;
            case 4: printf("\nExiting the program...\n");
                    exit(0);
            default: printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}