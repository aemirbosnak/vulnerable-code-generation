//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// define struct for database
struct Database {
    char name[20];
    int age;
    char occupation[20];
};

// function to add new record to database
void addNewRecord(struct Database *database, int *count) {
    printf("Enter name: ");
    scanf("%s", database[*count].name);
    printf("Enter age: ");
    scanf("%d", &database[*count].age);
    printf("Enter occupation: ");
    scanf("%s", database[*count].occupation);
    *count += 1;
    printf("New record added to database.\n\n");
}

// function to view all records in database
void viewAllRecords(struct Database *database, int count) {
    printf("\nAll records in database:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", database[i].name);
        printf("Age: %d\n", database[i].age);
        printf("Occupation: %s\n", database[i].occupation);
        printf("------------------------\n");
    }
}

// function to search for a record by name
void searchByName(struct Database *database, int count) {
    char searchName[20];
    printf("Enter name to search for: ");
    scanf("%s", searchName);
    for (int i = 0; i < count; i++) {
        if (strcmp(database[i].name, searchName) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Occupation: %s\n\n", database[i].occupation);
            return;
        }
    }
    printf("Record not found.\n\n");
}

// main function
int main() {
    struct Database database[100];
    int count = 0;
    while (1) {
        printf("1. Add new record\n");
        printf("2. View all records\n");
        printf("3. Search for record by name\n");
        printf("4. Exit program\n\n");
        printf("Enter choice (1-4): ");
        int choice;
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                addNewRecord(database, &count);
                break;
            case 2:
                viewAllRecords(database, count);
                break;
            case 3:
                searchByName(database, count);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
        }
    }
    return 0;
}