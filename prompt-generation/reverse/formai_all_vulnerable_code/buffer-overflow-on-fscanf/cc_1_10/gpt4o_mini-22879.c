//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50
#define CITY_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    char city[CITY_LENGTH];
} Person;

Person database[MAX_ENTRIES];
int current_index = 0;

void addPerson() {
    if (current_index >= MAX_ENTRIES) {
        printf("Database is full. Can't add more entries.\n");
        return;
    }
    
    Person new_person;
    new_person.id = current_index + 1; // Start ID from 1
    printf("Enter name: ");
    scanf(" %[^\n]s", new_person.name);
    printf("Enter age: ");
    scanf("%d", &new_person.age);
    printf("Enter city: ");
    scanf(" %[^\n]s", new_person.city);
    
    database[current_index] = new_person;
    current_index++;
    
    printf("Person added successfully! ID: %d\n", new_person.id);
}

void updatePerson() {
    int id;
    printf("Enter ID of person to update: ");
    scanf("%d", &id);

    if (id < 1 || id > current_index) {
        printf("Invalid ID. Please try again.\n");
        return;
    }

    Person *person = &database[id - 1];
    printf("Updating ID %d - Name: %s, Age: %d, City: %s\n", 
           person->id, person->name, person->age, person->city);
    
    printf("Enter new name (leave blank to keep current): ");
    char new_name[NAME_LENGTH];
    scanf(" %[^\n]s", new_name);
    if (strlen(new_name) > 0) {
        strcpy(person->name, new_name);
    }

    printf("Enter new age (enter -1 to keep current): ");
    int new_age;
    scanf("%d", &new_age);
    if (new_age != -1) {
        person->age = new_age;
    }
    
    printf("Enter new city (leave blank to keep current): ");
    char new_city[CITY_LENGTH];
    scanf(" %[^\n]s", new_city);
    if (strlen(new_city) > 0) {
        strcpy(person->city, new_city);
    }

    printf("Person updated successfully!\n");
}

void deletePerson() {
    int id;
    printf("Enter ID of person to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > current_index) {
        printf("Invalid ID. Please try again.\n");
        return;
    }

    for (int i = id - 1; i < current_index - 1; i++) {
        database[i] = database[i + 1];
    }
    current_index--;
    printf("Person deleted successfully!\n");
}

void listPersons() {
    if (current_index == 0) {
        printf("No entries in the database.\n");
        return;
    }

    printf("\n--- Database Entries ---\n");
    for (int i = 0; i < current_index; i++) {
        printf("ID: %d, Name: %s, Age: %d, City: %s\n", 
               database[i].id, database[i].name, database[i].age, database[i].city);
    }
    printf("------------------------\n");
}

void saveDatabase() {
    FILE *file = fopen("database.txt", "w");
    if (!file) {
        printf("Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < current_index; i++) {
        fprintf(file, "%d,%s,%d,%s\n", database[i].id, database[i].name, database[i].age, database[i].city);
    }
    fclose(file);
    printf("Database saved successfully to 'database.txt'.\n");
}

void loadDatabase() {
    FILE *file = fopen("database.txt", "r");
    if (!file) {
        printf("No saved database found. Starting a fresh database.\n");
        return;
    }
    
    while (fscanf(file, "%d,%49[^,],%d,%49[^\n]\n", 
                  &database[current_index].id, 
                  database[current_index].name, 
                  &database[current_index].age, 
                  database[current_index].city) != EOF) {
        current_index++;
    }
    fclose(file);
    printf("Database loaded successfully with %d entries.\n", current_index);
}

int main() {
    loadDatabase();
    
    int choice;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Add Person\n");
        printf("2. Update Person\n");
        printf("3. Delete Person\n");
        printf("4. List Persons\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPerson(); break;
            case 2: updatePerson(); break;
            case 3: deletePerson(); break;
            case 4: listPersons(); break;
            case 5: saveDatabase(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid option. Try again.\n"); break;
        }
    } while (choice != 6);
    
    return 0;
}