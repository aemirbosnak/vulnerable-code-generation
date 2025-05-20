//FormAI DATASET v1.0 Category: Database simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
} Person;

void addPerson(Person* person);
void searchPersonById(char* id);
void removePersonById(char* id);

int main() {
    int option = 0;
    char id[MAX_ID_LENGTH];

    do {
        printf("\nDatabase Simulation Menu\n");
        printf("1. Add Person\n");
        printf("2. Search Person by ID\n");
        printf("3. Remove Person by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addPerson(NULL);
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%s", id);
                searchPersonById(id);
                break;
            case 3:
                printf("Enter ID to remove: ");
                scanf("%s", id);
                removePersonById(id);
                break;
            case 4:
                printf("Exiting program.");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(option != 4);

    return 0;
}

void addPerson(Person* person) {
    Person newPerson;

    if (person == NULL) {
        printf("Enter First Name: ");
        scanf("%s", newPerson.firstName);

        printf("Enter Last Name: ");
        scanf("%s", newPerson.lastName);

        printf("Enter ID: ");
        scanf("%s", newPerson.id);

        printf("New person added successfully.\n");
    } else {
        newPerson = *person;
    }

    FILE* file = fopen("database.txt", "a");

    if(file == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    fprintf(file, "%s,%s,%s\n", newPerson.firstName, newPerson.lastName, newPerson.id);

    fclose(file);
}

void searchPersonById(char* id) {
    FILE* file = fopen("database.txt", "r");

    if(file == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    char line[100];

    while(fgets(line, sizeof(line), file)) {
        line[strlen(line)-1] = '\0';
        char* token = strtok(line, ",");

        if(strcmp(token, id) == 0) {
            printf("%s %s (%s)\n", token, strtok(NULL, ","), strtok(NULL, ","));
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Person with ID %s not found.\n", id);
}

void removePersonById(char* id) {
    FILE* file = fopen("database.txt", "r");
    FILE* tempFile = fopen("temp.txt", "w");

    if(file == NULL || tempFile == NULL) {
        printf("Error opening database file.\n");
        return;
    }

    char line[100];

    while(fgets(line, sizeof(line), file)) {
        line[strlen(line)-1] = '\0';
        char* token = strtok(line, ",");

        if(strcmp(token, id) != 0) {
            fprintf(tempFile, "%s\n", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("database.txt");
    rename("temp.txt", "database.txt");

    printf("Person with ID %s removed successfully.\n", id);
}