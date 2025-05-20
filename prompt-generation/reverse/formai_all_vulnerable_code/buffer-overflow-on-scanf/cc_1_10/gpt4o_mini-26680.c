//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_ATTEMPTS 5

typedef struct {
    char name[50];
    int age;
} Person;

void handleError(const char* msg) {
    fprintf(stderr, "Error: %s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

void inputPersonData(Person* p) {
    printf("Enter name: ");
    if (fgets(p->name, sizeof(p->name), stdin) == NULL) {
        handleError("Failed to read name");
    }

    printf("Enter age: ");
    if (scanf("%d", &p->age) != 1) {
        handleError("Invalid input for age");
    }
    // Clear newline character left in the buffer
    while (getchar() != '\n');
}

void displayPersonData(const Person* p) {
    printf("Name: %s", p->name);
    printf("Age: %d\n", p->age);
}

void writePersonToFile(const Person* p, const char* filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        handleError("Unable to open file for writing");
    }

    if (fprintf(file, "Name: %sAge: %d\n", p->name, p->age) < 0) {
        fclose(file);
        handleError("Failed to write data to file");
    }

    fclose(file);
}

void readPersonsFromFile(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handleError("Unable to open file for reading");
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main() {
    Person people[MAX_ATTEMPTS];
    int count = 0;

    printf("Person Data Entry\n");
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("\nEntering data for person %d:\n", i + 1);
        inputPersonData(&people[count]);
        displayPersonData(&people[count]);
        writePersonToFile(&people[count], "people.txt");
        count++;
        
        printf("\nContinue to enter more data? (Y/N): ");
        char choice;
        scanf(" %c", &choice);
        while (getchar() != '\n');  // Clear buffer
        if (choice != 'Y' && choice != 'y') {
            break;
        }
    }
    
    printf("\nData saved to file. Reading from file...\n");
    readPersonsFromFile("people.txt");
    
    return 0;
}