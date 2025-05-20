//FormAI DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to hold data
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// define functions to perform queries
void insertPerson(Person *person, FILE *file) {
    fseek(file, 0, SEEK_END); // move to end of file
    if(fwrite(person, sizeof(Person), 1, file) != 1) { // write to file
        printf("Error writing to file.\n");
    } else {
        printf("Person inserted successfully.\n");
    }
}

void selectAll(FILE *file) {
    Person person;
    fseek(file, 0, SEEK_SET); // move to beginning of file
    while(fread(&person, sizeof(Person), 1, file)) { // read from file
        printf("ID: %d, Name: %s, Age: %d\n", person.id, person.name, person.age);
    }
}

void selectByID(int id, FILE *file) {
    Person person;
    fseek(file, 0, SEEK_SET); // move to beginning of file
    int found = 0;
    while(fread(&person, sizeof(Person), 1, file)) { // read from file
        if(person.id == id) {
            printf("ID: %d, Name: %s, Age: %d\n", person.id, person.name, person.age);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Person with ID %d not found.\n", id);
    }
}

void deleteByID(int id, FILE *file) {
    Person person;
    FILE *tempFile;
    tempFile = fopen("temp.dat", "wb"); // create temporary file
    fseek(file, 0, SEEK_SET); // move to beginning of file
    int found = 0;
    while(fread(&person, sizeof(Person), 1, file)) { // read from file
        if(person.id != id) {
            fwrite(&person, sizeof(Person), 1, tempFile); // write to temporary file
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);
    remove("data.dat"); // delete original file
    rename("temp.dat", "data.dat"); // rename temporary file
    file = fopen("data.dat", "rb+"); // reopen file
    if(found) {
        printf("Person with ID %d deleted successfully.\n", id);
    } else {
        printf("Person with ID %d not found.\n", id);
    }
}

// main function
int main() {
    FILE *file;
    file = fopen("data.dat", "rb+"); // open data file
    if(file == NULL) { // if file doesn't exist, create it
        file = fopen("data.dat", "wb");
        if(file == NULL) {
            printf("Error creating file.\n");
            return 1;
        }
    }
    // display main menu and run queries
    int choice, id, age;
    char name[50];
    Person person;
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Insert Person\n");
        printf("2. Select All Persons\n");
        printf("3. Select Person by ID\n");
        printf("4. Delete Person by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter person ID: ");
                scanf("%d", &person.id);
                printf("Enter person name: ");
                scanf("%s", person.name);
                printf("Enter person age: ");
                scanf("%d", &person.age);
                insertPerson(&person, file);
                break;
            case 2:
                selectAll(file);
                break;
            case 3:
                printf("\nEnter person ID: ");
                scanf("%d", &id);
                selectByID(id, file);
                break;
            case 4:
                printf("\nEnter person ID: ");
                scanf("%d", &id);
                deleteByID(id, file);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while(choice != 5);
    fclose(file); // close file
    return 0;
}