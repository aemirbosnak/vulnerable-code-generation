//FormAI DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the Person structure representing an individual
typedef struct {
    char name[50];
    int age;
    char address[100];
} Person;

// Function to print the details of a Person
void print_person(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Address: %s\n", p.address);
}

int main() {
    // Define an array of Person objects to act as our database
    Person database[10];

    // Initialize the database with some test data
    strcpy(database[0].name, "John Doe");
    database[0].age = 25;
    strcpy(database[0].address, "123 Main St");

    strcpy(database[1].name, "Jane Smith");
    database[1].age = 31;
    strcpy(database[1].address, "456 Elm St");

    int num_records = 2;

    // Main loop for the program
    while (1) {
        // Display the menu options
        printf("1. Add a record\n");
        printf("2. View a record\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Adding a new record
                if (num_records < 10) {
                    printf("Enter the person's name: ");
                    scanf("%s", database[num_records].name);

                    printf("Enter the person's age: ");
                    scanf("%d", &database[num_records].age);

                    printf("Enter the person's address: ");
                    scanf("%s", database[num_records].address);

                    num_records++;
                } else {
                    printf("Database is full.\n");
                }
                break;
            case 2:
                // Viewing an existing record
                printf("Enter the record number to view (1-%d): ", num_records);
                int record_num;
                scanf("%d", &record_num);

                if (record_num >= 1 && record_num <= num_records) {
                    printf("Record details:\n");
                    print_person(database[record_num-1]);
                } else {
                    printf("Invalid record number.\n");
                }
                break;
            case 3:
                // Exiting the program
                printf("Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}