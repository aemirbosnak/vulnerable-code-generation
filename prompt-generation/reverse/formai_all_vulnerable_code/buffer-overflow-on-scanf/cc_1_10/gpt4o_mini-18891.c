//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

void addPerson(const char *filename);
void displayPeople(const char *filename);
void searchPerson(const char *filename);

int main() {
    int choice;
    const char *filename = "people.dat";

    while (1) {
        printf("\n*** Personal Record System ***\n");
        printf("1. Add Person\n");
        printf("2. Display All People\n");
        printf("3. Search for a Person\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPerson(filename);
                break;
            case 2:
                displayPeople(filename);
                break;
            case 3:
                searchPerson(filename);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addPerson(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    Person person;

    printf("Enter name: ");
    scanf(" %[^\n]s", person.name);
    printf("Enter age: ");
    scanf("%d", &person.age);

    fwrite(&person, sizeof(Person), 1, file);
    fclose(file);
    printf("Person added successfully!\n");
}

void displayPeople(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    Person person;
    int count = 0;

    printf("\n*** List of People ***\n");
    while (fread(&person, sizeof(Person), 1, file)) {
        printf("Name: %s, Age: %d\n", person.name, person.age);
        count++;
    }
    if (count == 0) {
        printf("No entries found.\n");
    }
    fclose(file);
}

void searchPerson(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    Person person;
    char nameToSearch[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter name to search: ");
    scanf(" %[^\n]s", nameToSearch);

    while (fread(&person, sizeof(Person), 1, file)) {
        if (strcmp(person.name, nameToSearch) == 0) {
            printf("Found: Name: %s, Age: %d\n", person.name, person.age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No entry found for name: %s\n", nameToSearch);
    }
    fclose(file);
}