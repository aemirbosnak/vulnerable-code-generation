//FormAI DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure for a database entry
struct Entry {
    int id;
    char name[20];
    int age;
    float salary;
};

int main() {
    // Initialize the database with three entries
    struct Entry database[3];
    database[0].id = 1001;
    strcpy(database[0].name, "John");
    database[0].age = 30;
    database[0].salary = 50000.0;

    database[1].id = 1002;
    strcpy(database[1].name, "Mary");
    database[1].age = 25;
    database[1].salary = 60000.0;

    database[2].id = 1003;
    strcpy(database[2].name, "Bob");
    database[2].age = 35;
    database[2].salary = 70000.0;

    // Print out the database
    printf("Initial Database:\n");
    printf("------------------\n");
    for(int i = 0; i < 3; i++) {
        printf("ID: %d\nName: %s\nAge: %d\nSalary: $%.2f\n\n", 
            database[i].id, database[i].name, database[i].age, database[i].salary);
    }

    // Add a new entry to the database
    struct Entry newEntry;
    newEntry.id = 1004;
    strcpy(newEntry.name, "Alice");
    newEntry.age = 28;
    newEntry.salary = 80000.0;
    database[3] = newEntry;

    // Print out the updated database
    printf("Updated Database:\n");
    printf("------------------\n");
    for(int i = 0; i < 4; i++) {
        printf("ID: %d\nName: %s\nAge: %d\nSalary: $%.2f\n\n", 
            database[i].id, database[i].name, database[i].age, database[i].salary);
    }

    // Remove an entry from the database
    for(int i = 0; i < 4; i++) {
        if(database[i].id == 1002) {
            for(int j = i; j < 3; j++) {
                database[j] = database[j+1];
            }
            break;
        }
    }

    // Print out the updated database
    printf("Updated Database:\n");
    printf("------------------\n");
    for(int i = 0; i < 3; i++) {
        printf("ID: %d\nName: %s\nAge: %d\nSalary: $%.2f\n\n", 
            database[i].id, database[i].name, database[i].age, database[i].salary);
    }

    return 0;
}