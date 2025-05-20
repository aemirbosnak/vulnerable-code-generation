//FormAI DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>

// Defining the structure of the database 
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Defining the array to store the records
Record database[100];

// Defining the variable to keep track of the number of records in the database
int num_records = 0;

// Function to add a record to the database
void add_record() {
    Record new_record;
    printf("Enter ID: ");
    scanf("%d", &new_record.id);
    printf("Enter Name: ");
    scanf("%s", new_record.name);
    printf("Enter Age: ");
    scanf("%d", &new_record.age);
    database[num_records] = new_record;
    num_records++;
}

// Function to display all records in the database
void display_records() {
    printf("========================================\n");
    printf("| ID\t| Name\t| Age\t|\n");
    printf("========================================\n");
    for (int i = 0; i < num_records; i++) {
        printf("| %d\t| %s\t| %d\t|\n", database[i].id, database[i].name, database[i].age);
    }
    printf("========================================\n");
}

int main() {
    int choice;
    do {
        printf("\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice! Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}