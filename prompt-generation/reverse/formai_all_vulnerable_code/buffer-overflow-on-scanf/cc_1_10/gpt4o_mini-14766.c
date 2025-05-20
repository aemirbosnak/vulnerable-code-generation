//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* Define a structure to hold information about a person */
typedef struct {
    char name[50];
    int age;
} Person;

/* Function prototypes */
void addPerson(Person *people, int *size);
void listPeople(const Person *people, int size);
void saveToFile(const Person *people, int size, const char *filename);
void loadFromFile(Person *people, int *size, const char *filename);

int main() {
    Person people[100];
    int size = 0;
    int choice;
    char filename[] = "people.dat";

    loadFromFile(people, &size, filename);

    while (1) {
        printf("\nPerson Database Menu:\n");
        printf("1. Add Person\n");
        printf("2. List People\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        // Check for valid input
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter an integer.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                addPerson(people, &size);
                break;
            case 2:
                listPeople(people, size);
                break;
            case 3:
                saveToFile(people, size, filename);
                break;
            case 4:
                loadFromFile(people, &size, filename);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                fprintf(stderr, "Invalid choice! Please choose a valid option.\n");
                break;
        }
    }
    return 0;
}

/* Function to add a new person to the array */
void addPerson(Person *people, int *size) {
    if (*size >= 100) {
        fprintf(stderr, "Database is full! Cannot add more people.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", people[*size].name);
    printf("Enter age: ");
    
    // Check for valid integer input
    while (1) {
        if (scanf("%d", &people[*size].age) != 1) {
            fprintf(stderr, "Invalid age! Please enter a valid integer for age.\n");
            while (getchar() != '\n'); // Clear invalid input
            printf("Enter age: ");
        } else {
            break;
        }
    }
    (*size)++;
}

/* Function to list all people in the array */
void listPeople(const Person *people, int size) {
    if (size == 0) {
        printf("No people to display.\n");
        return;
    }

    printf("\nList of People:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }
}

/* Function to save people to a binary file */
void saveToFile(const Person *people, int size, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing: %s\n", strerror(errno));
        return;
    }
    
    fwrite(people, sizeof(Person), size, file);
    fclose(file);
    printf("Data saved successfully to %s.\n", filename);
}

/* Function to load people from a binary file */
void loadFromFile(Person *people, int *size, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        if (errno == ENOENT) {
            printf("No existing data file found. A new file will be created when you save.\n");
        } else {
            fprintf(stderr, "Error opening file for reading: %s\n", strerror(errno));
        }
        return;
    }
    
    *size = fread(people, sizeof(Person), 100, file);
    fclose(file);
    printf("Loaded %d people from %s.\n", *size, filename);
}