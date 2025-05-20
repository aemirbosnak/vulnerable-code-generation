//FormAI DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000
#define MAX_QUERY 500

typedef struct {
    int id;
    char name[20];
    int age;
    char country[20];
} Person;

Person database[MAX_SIZE];
int size = 0;

void print_menu() {
    printf("Database Commands:\n");
    printf("1. Add Person\n");
    printf("2. Remove Person\n");
    printf("3. Search by ID\n");
    printf("4. Search by Name\n");
    printf("5. Search by Age\n");
    printf("6. Search by Country\n");
    printf("7. Print Database\n");
    printf("8. Quit\n");
}

int get_input(char* prompt) {
    int choice = -1;
    while (choice < 0 || choice > 8) {
        printf("%s", prompt);
        scanf("%d", &choice);
    }
    return choice;
}

void add_person() {
    Person new_person;
    printf("Enter ID: ");
    scanf("%d", &new_person.id);

    printf("Enter Name: ");
    scanf("%s", new_person.name);

    printf("Enter Age: ");
    scanf("%d", &new_person.age);

    printf("Enter Country: ");
    scanf("%s", new_person.country);

    database[size++] = new_person;
    printf("Person added successfully.\n");
}

void remove_person() {
    int id;
    printf("Enter ID of the person to remove: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Person with ID %d not found.\n", id);
        return;
    }

    for (int j = index; j < size - 1; j++) {
        database[j] = database[j + 1];
    }

    size--;
    printf("Person with ID %d removed successfully.\n", id);
}

void search_by_id() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < size; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Person with ID %d not found.\n", id);
        return;
    }

    printf("ID: %d, Name: %s, Age: %d, Country: %s\n", database[index].id, database[index].name, database[index].age, database[index].country);
}

void search_by_name() {
    char name[20];
    printf("Enter name to search: ");
    scanf("%s", name);

    printf("Results for %s:\n", name);
    for (int i = 0; i < size; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("ID: %d, Name: %s, Age: %d, Country: %s\n", database[i].id, database[i].name, database[i].age, database[i].country);
        }
    }
}

void search_by_age() {
    int age;
    printf("Enter age to search: ");
    scanf("%d", &age);

    printf("Results for %d:\n", age);
    for (int i = 0; i < size; i++) {
        if (database[i].age == age) {
            printf("ID: %d, Name: %s, Age: %d, Country: %s\n", database[i].id, database[i].name, database[i].age, database[i].country);
        }
    }
}

void search_by_country() {
    char country[20];
    printf("Enter country to search: ");
    scanf("%s", country);

    printf("Results for %s:\n", country);
    for (int i = 0; i < size; i++) {
        if (strcmp(database[i].country, country) == 0) {
            printf("ID: %d, Name: %s, Age: %d, Country: %s\n", database[i].id, database[i].name, database[i].age, database[i].country);
        }
    }
}

void print_database() {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Country: %s\n", database[i].id, database[i].name, database[i].age, database[i].country);
    }
}

int main() {
    int choice = -1;

    while (choice != 8) {
        print_menu();
        choice = get_input("Enter choice: ");

        switch (choice) {
            case 1:
                add_person();
                break;
            case 2:
                remove_person();
                break;
            case 3:
                search_by_id();
                break;
            case 4:
                search_by_name();
                break;
            case 5:
                search_by_age();
                break;
            case 6:
                search_by_country();
                break;
            case 7:
                print_database();
                break;
            case 8:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}