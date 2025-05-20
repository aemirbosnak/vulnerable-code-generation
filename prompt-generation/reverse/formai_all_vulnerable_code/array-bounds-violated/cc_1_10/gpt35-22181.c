//FormAI DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    This program simulates a simple database. It allows the user to add, edit, and delete records.
    Each record is a person with a name, age, and phone number.
*/

typedef struct {
    char name[50];
    int age;
    char phone[20];
} person;

void clearBuffer() {
    // Clear input buffer to prevent unexpected behavior
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void printPerson(person p) {
    printf("\nName: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Phone: %s\n", p.phone);
}

void printMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Add person\n");
    printf("2. Edit person\n");
    printf("3. Delete person\n");
    printf("4. Print all persons\n");
    printf("5. Quit\n");
}

int main() {
    int choice, index;
    char input[50];
    person* records = malloc(sizeof(person) * 10);
    int numRecords = 0;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        if (choice == 1) {
            // Add person
            printf("Enter name: ");
            fgets(input, 50, stdin);
            input[strlen(input)-1] = '\0'; // Remove newline character
            strcpy(records[numRecords].name, input);

            printf("Enter age: ");
            scanf("%d", &records[numRecords].age);
            clearBuffer();

            printf("Enter phone: ");
            fgets(input, 20, stdin);
            input[strlen(input)-1] = '\0'; // Remove newline character
            strcpy(records[numRecords].phone, input);

            numRecords++;
        }
        else if (choice == 2) {
            // Edit person
            printf("Enter index of person to edit: ");
            scanf("%d", &index);
            clearBuffer();
            if (index < 0 || index >= numRecords) {
                printf("Invalid index\n");
                continue;
            }

            printf("Enter new name (press enter to skip): ");
            fgets(input, 50, stdin);
            if (strlen(input) > 1) {
                input[strlen(input)-1] = '\0'; // Remove newline character
                strcpy(records[index].name, input);
            }

            printf("Enter new age (press enter to skip): ");
            fgets(input, 20, stdin);
            if (strlen(input) > 1) {
                records[index].age = atoi(input);
            }

            printf("Enter new phone (press enter to skip): ");
            fgets(input, 20, stdin);
            if (strlen(input) > 1) {
                input[strlen(input)-1] = '\0'; // Remove newline character
                strcpy(records[index].phone, input);
            }
        }
        else if (choice == 3) {
            // Delete person
            printf("Enter index of person to delete: ");
            scanf("%d", &index);
            clearBuffer();
            if (index < 0 || index >= numRecords) {
                printf("Invalid index\n");
                continue;
            }

            for (int i = index; i < numRecords-1; i++) {
                records[i] = records[i+1];
            }
            numRecords--;
        }
        else if (choice == 4) {
            // Print all persons
            if (numRecords == 0) {
                printf("No records\n");
            }
            else {
                for (int i = 0; i < numRecords; i++) {
                    printf("\nRecord %d:\n", i+1);
                    printPerson(records[i]);
                }
            }
        }
        else if (choice == 5) {
            // Quit
            free(records);
            return 0;
        }
        else {
            printf("Invalid choice\n");
        }
    }
}