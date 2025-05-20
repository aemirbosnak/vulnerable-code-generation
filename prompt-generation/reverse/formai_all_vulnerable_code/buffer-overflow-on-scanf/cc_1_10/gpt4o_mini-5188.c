//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_FILE_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_NAME_LENGTH];
} Person;

void addPerson(FILE *file);
void displayPersons(FILE *file);
void searchPerson(FILE *file);
void deletePerson(FILE *file);
void generateSampleData(FILE *file);

int main() {
    int choice;
    FILE *file;

    file = fopen("people.txt", "a+");
    if (file == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    do {
        printf("\n===== Person Management System =====\n");
        printf("1. Add Person\n");
        printf("2. Display All Persons\n");
        printf("3. Search Person by Name\n");
        printf("4. Delete Person by Name\n");
        printf("5. Generate Sample Data\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPerson(file);
                break;
            case 2:
                displayPersons(file);
                break;
            case 3:
                searchPerson(file);
                break;
            case 4:
                deletePerson(file);
                break;
            case 5:
                generateSampleData(file);
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        rewind(file); // Reset file pointer to beginning
    } while (choice != 6);

    fclose(file);
    return EXIT_SUCCESS;
}

void addPerson(FILE *file) {
    Person person;
    printf("Enter Name: ");
    scanf("%s", person.name);
    printf("Enter Age: ");
    scanf("%d", &person.age);
    printf("Enter Email: ");
    scanf("%s", person.email);

    fwrite(&person, sizeof(Person), 1, file);
    fflush(file); // Ensure data is written
    printf("Person added successfully!\n");
}

void displayPersons(FILE *file) {
    Person person;
    rewind(file);
    printf("\n=== List of Persons ===\n");
    while (fread(&person, sizeof(Person), 1, file) == 1) {
        printf("Name: %s, Age: %d, Email: %s\n", person.name, person.age, person.email);
    }
}

void searchPerson(FILE *file) {
    char searchName[MAX_NAME_LENGTH];
    Person person;
    int found = 0;

    printf("Enter the name to search: ");
    scanf("%s", searchName);

    rewind(file);
    while (fread(&person, sizeof(Person), 1, file) == 1) {
        if (strcmp(person.name, searchName) == 0) {
            printf("Found Person - Name: %s, Age: %d, Email: %s\n", person.name, person.age, person.email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Person with name '%s' not found.\n", searchName);
    }
}

void deletePerson(FILE *file) {
    char deleteName[MAX_NAME_LENGTH];
    Person persons[MAX_FILE_ENTRIES];
    int count = 0;
    int found = 0;

    printf("Enter the name to delete: ");
    scanf("%s", deleteName);

    rewind(file);
    while (fread(&persons[count], sizeof(Person), 1, file) == 1 && count < MAX_FILE_ENTRIES) {
        if (strcmp(persons[count].name, deleteName) == 0) {
            found = 1;
            printf("Deleted Person - Name: %s, Age: %d, Email: %s\n", persons[count].name, persons[count].age, persons[count].email);
            continue; // Skip this person
        }
        count++;
    }

    if (found) {
        file = fopen("people.txt", "w");
        if (file == NULL) {
            perror("Unable to open file");
            return;
        }
        fwrite(persons, sizeof(Person), count, file);
        printf("Person deleted successfully!\n");
        fclose(file);
    } else {
        printf("Person with name '%s' not found for deletion.\n", deleteName);
    }
}

void generateSampleData(FILE *file) {
    Person sampleData[] = {
        {"Alice", 30, "alice@example.com"},
        {"Bob", 25, "bob@example.com"},
        {"Charlie", 35, "charlie@example.com"}
    };

    fseek(file, 0, SEEK_END);
    fwrite(sampleData, sizeof(Person), sizeof(sampleData) / sizeof(sampleData[0]), file);
    fflush(file);
    printf("Sample data generated successfully!\n");
}