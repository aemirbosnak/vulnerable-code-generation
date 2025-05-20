//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_AGE_LENGTH 3
#define MAX_OCCUPATION_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_OCCUPATION_LENGTH];
} Person;

Person database[MAX_ENTRIES];
int current_count = 0;

void add_person(const char *name, int age, const char *occupation) {
    if (current_count >= MAX_ENTRIES) {
        printf("Database is full. Can't add more entries.\n");
        return;
    }
    strncpy(database[current_count].name, name, MAX_NAME_LENGTH);
    database[current_count].age = age;
    strncpy(database[current_count].occupation, occupation, MAX_OCCUPATION_LENGTH);
    current_count++;
    printf("Added %s to the database.\n", name);
}

void search_by_name(const char *name) {
    printf("Searching for people named %s...\n", name);
    int found = 0;
    for (int i = 0; i < current_count; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Found: %s, Age: %d, Occupation: %s\n",
                    database[i].name, database[i].age, database[i].occupation);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found for %s.\n", name);
    }
}

void search_by_age(int age) {
    printf("Searching for people aged %d...\n", age);
    int found = 0;
    for (int i = 0; i < current_count; i++) {
        if (database[i].age == age) {
            printf("Found: %s, Age: %d, Occupation: %s\n",
                    database[i].name, database[i].age, database[i].occupation);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found for age %d.\n", age);
    }
}

void search_by_occupation(const char *occupation) {
    printf("Searching for people with occupation %s...\n", occupation);
    int found = 0;
    for (int i = 0; i < current_count; i++) {
        if (strcmp(database[i].occupation, occupation) == 0) {
            printf("Found: %s, Age: %d, Occupation: %s\n",
                   database[i].name, database[i].age, database[i].occupation);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found for occupation %s.\n", occupation);
    }
}

void print_database() {
    printf("Current database entries:\n");
    for (int i = 0; i < current_count; i++) {
        printf("Entry %d: %s, Age: %d, Occupation: %s\n",
               i + 1, database[i].name, database[i].age, database[i].occupation);
    }
}

int main() {
    int choice, age;
    char name[MAX_NAME_LENGTH];
    char occupation[MAX_OCCUPATION_LENGTH];

    while (1) {
        printf("\nData Mining Database\n");
        printf("1. Add Person\n");
        printf("2. Search by Name\n");
        printf("3. Search by Age\n");
        printf("4. Search by Occupation\n");
        printf("5. Print All Entries\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                printf("Enter Age: ");
                scanf("%d", &age);
                getchar(); // Consume new line character
                printf("Enter Occupation: ");
                fgets(occupation, MAX_OCCUPATION_LENGTH, stdin);
                occupation[strcspn(occupation, "\n")] = 0; // Remove newline character
                add_person(name, age, occupation);
                break;
            case 2:
                printf("Enter Name to search: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                search_by_name(name);
                break;
            case 3:
                printf("Enter Age to search: ");
                scanf("%d", &age);
                search_by_age(age);
                break;
            case 4:
                printf("Enter Occupation to search: ");
                fgets(occupation, MAX_OCCUPATION_LENGTH, stdin);
                occupation[strcspn(occupation, "\n")] = 0; // Remove newline character
                search_by_occupation(occupation);
                break;
            case 5:
                print_database();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}