//FormAI DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define structure for database
struct database {
    int id;
    char name[20];
    int age;
    char occupation[20];
};

// Function to add a new record to the database
void addRecord(struct database *db, int *n) {
    printf("Enter id: ");
    scanf("%d", &db[*n].id);
    printf("Enter name: ");
    scanf("%s", db[*n].name);
    printf("Enter age: ");
    scanf("%d", &db[*n].age);
    printf("Enter occupation: ");
    scanf("%s", db[*n].occupation);
    (*n)++;
    printf("Record added successfully!\n");
}

// Function to remove a record from the database
void removeRecord(struct database *db, int *n) {
    int id, i, j;
    printf("Enter id to remove record: ");
    scanf("%d", &id);
    for (i = 0; i < *n; i++) {
        if (db[i].id == id) {
            for (j = i; j < *n - 1; j++) {
                db[j] = db[j + 1];
            }
            (*n)--;
            printf("Record removed successfully!\n");
            return;
        }
    }
    printf("Record not found.\n");
}

// Function to print all records in the database
void printRecords(struct database *db, int n) {
    int i;
    printf("ID\tName\tAge\tOccupation\n");
    printf("=====================================\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%s\n", db[i].id, db[i].name, db[i].age, db[i].occupation);
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    struct database db[100]; // Allocate memory for database
    int n = 0; // Initialize the number of records to 0
    int choice;
    do {
        printf("SELECT AN OPTION:\n");
        printf("1. Add record\n");
        printf("2. Remove record\n");
        printf("3. Print all records\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(db, &n);
                break;
            case 2:
                removeRecord(db, &n);
                break;
            case 3:
                printRecords(db, n);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        int chance = rand() % 101; // Generate a random number between 0 and 100
        if (chance >= 80) {
            printf("ALERT! DATABASE MALFUNCTION DETECTED.\n");
            printf("PLEASE EVACUATE TO A SAFE LOCATION.\n");
            return 0; // Exit program if disaster occurs
        }
    } while (choice != 4);
    return 0;
}