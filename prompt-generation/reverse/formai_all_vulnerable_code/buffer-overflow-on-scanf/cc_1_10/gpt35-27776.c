//FormAI DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We will create a decentralized database as an array of structures
struct Data {
    int id;
    char name[20];
    int age;
};

struct Data database[100]; // Maximum of 100 records

void addData() {
    static int nextId = 1;
    int i = 0;
    while (database[i].id != 0) { // Find first empty record
        i++;
        if (i >= 100) {
            printf("Database full!\n");
            return;
        }
    }
    database[i].id = nextId++;
    printf("Enter name: ");
    scanf("%s", database[i].name);
    printf("Enter age: ");
    scanf("%d", &database[i].age);
    printf("Data added successfully\n");
}

void displayData() {
    printf("ID\tName\tAge\n");
    for (int i = 0; database[i].id != 0; i++) { // Loop through all records
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

int main() {
    int option;
    do {
        printf("\n1. Add Data\n2. Display Data\n3. Exit\nEnter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addData();
                break;
            case 2:
                displayData();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    } while (option != 3);
    return 0;
}