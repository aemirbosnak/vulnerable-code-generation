//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "people.txt"
#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

// Function declarations
void addPerson();
void viewPeople();
void searchPerson();
void deletePerson();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    do {
        printf("\n--- Person Management System ---\n");
        printf("1. Add Person\n");
        printf("2. View People\n");
        printf("3. Search Person\n");
        printf("4. Delete Person\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addPerson();
                break;
            case 2:
                viewPeople();
                break;
            case 3:
                searchPerson();
                break;
            case 4:
                deletePerson();
                break;
            case 5:
                printf("Exiting. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 5);
}

void addPerson() {
    FILE *file;
    Person newPerson;

    file = fopen(FILENAME, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        return;
    }

    printf("Enter name: ");
    fgets(newPerson.name, MAX_NAME_LENGTH, stdin);
    newPerson.name[strcspn(newPerson.name, "\n")] = 0; // Remove newline

    printf("Enter age: ");
    scanf("%d", &newPerson.age);
    getchar(); // Consume newline

    fwrite(&newPerson, sizeof(Person), 1, file);
    fclose(file);

    printf("Person added successfully!\n");
}

void viewPeople() {
    FILE *file;
    Person people[MAX_PEOPLE];
    int count = 0;

    file = fopen(FILENAME, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }

    while (fread(&people[count], sizeof(Person), 1, file) == 1 && count < MAX_PEOPLE) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No people found.\n");
    } else {
        printf("\n--- People List ---\n");
        for (int i = 0; i < count; i++) {
            printf("%d. Name: %s, Age: %d\n", i + 1, people[i].name, people[i].age);
        }
    }
}

void searchPerson() {
    FILE *file;
    Person person;
    char searchName[MAX_NAME_LENGTH];
    int found = 0;

    file = fopen(FILENAME, "rb");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for reading.\n");
        return;
    }

    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove newline

    while (fread(&person, sizeof(Person), 1, file) == 1) {
        if (strcmp(person.name, searchName) == 0) {
            printf("Found: Name: %s, Age: %d\n", person.name, person.age);
            found = 1;
            break;
        }
    }
    fclose(file);

    if (!found) {
        printf("Person not found.\n");
    }
}

void deletePerson() {
    FILE *file, *tempFile;
    Person person;
    char deleteName[MAX_NAME_LENGTH];
    int found = 0;

    file = fopen(FILENAME, "rb");
    tempFile = fopen("temp.txt", "wb");

    if (file == NULL || tempFile == NULL) {
        fprintf(stderr, "Could not open file for reading/writing.\n");
        return;
    }

    printf("Enter name to delete: ");
    fgets(deleteName, MAX_NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = 0; // Remove newline

    while (fread(&person, sizeof(Person), 1, file) == 1) {
        if (strcmp(person.name, deleteName) != 0) {
            fwrite(&person, sizeof(Person), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Person deleted successfully!\n");
    } else {
        printf("Person not found.\n");
    }
}