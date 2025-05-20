//FormAI DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to hold record values
struct Record {
    int id;
    char name[20];
    int age;
    char gender[10];
};

//Function to add a new record to the database
void addRecord(struct Record *database, int num_records) {
    printf("\nAdding new record...\n");
    printf("Enter ID: ");
    scanf("%d", &(database[num_records].id));
    printf("Enter name: ");
    scanf("%s", database[num_records].name);
    printf("Enter age: ");
    scanf("%d", &(database[num_records].age));
    printf("Enter gender (M/F): ");
    scanf("%s", database[num_records].gender);
    printf("Record added successfully!\n");
}

//Function to search for a record in the database by ID
void findRecord(struct Record *database, int num_records) {
    int id;
    printf("\nEnter ID to search for: ");
    scanf("%d", &id);
    for (int i=0; i<num_records; i++) {
        if (database[i].id == id) {
            printf("\nRecord found!\nID: %d\nName: %s\nAge: %d\nGender: %s\n", 
                   database[i].id, database[i].name, database[i].age, database[i].gender);
            return;
        }
    }
    printf("\nRecord not found.\n");
}

int main() {
    int num_records = 0;
    struct Record database[50];
    int choice;
    do {
        printf("\nDATABASE MENU:\n");
        printf("1. Add new record\n");
        printf("2. Find record by ID\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addRecord(database, num_records);
                num_records++;
                break;
            case 2:
                findRecord(database, num_records);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}