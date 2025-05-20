//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_STR_LENGTH 256
#define ARRAY_SIZE 10

typedef struct {
    char name[MAX_STR_LENGTH];
    int age;
} Person;

void handleError(const char* msg) {
    fprintf(stderr, "Error: %s - %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

void readPersonData(Person* person) {
    printf("Enter name: ");
    if (fgets(person->name, sizeof(person->name), stdin) == NULL) {
        handleError("Failed to read name");
    }
    person->name[strcspn(person->name, "\n")] = '\0'; // Remove newline character

    printf("Enter age: ");
    if (scanf("%d", &person->age) != 1) {
        handleError("Invalid input for age");
    }
    while (getchar() != '\n'); // Clear input buffer
}

void writePersonDataToFile(const char* filename, Person* person) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        handleError("Failed to open file for writing");
    }

    if (fprintf(file, "Name: %s, Age: %d\n", person->name, person->age) < 0) {
        fclose(file);
        handleError("Failed to write data to file");
    }

    if (fclose(file) != 0) {
        handleError("Failed to close file");
    }
}

void readPersonDataFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        handleError("Failed to open file for reading");
    }

    char buffer[MAX_STR_LENGTH];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    if (fclose(file) != 0) {
        handleError("Failed to close file");
    }
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Add a new person\n");
    printf("2. Display all persons\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Person persons[ARRAY_SIZE];
    int choice;
    int personCount = 0;
    const char* filename = "persons.txt";

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            handleError("Invalid input for choice");
        }
        while (getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                if (personCount >= ARRAY_SIZE) {
                    printf("Person limit reached. Cannot add more persons.\n");
                    break;
                }
                readPersonData(&persons[personCount]);
                writePersonDataToFile(filename, &persons[personCount]);
                personCount++;
                break;
            case 2:
                readPersonDataFromFile(filename);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}