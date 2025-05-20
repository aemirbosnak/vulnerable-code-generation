//FormAI DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100    // Maximum number of entries in the database
#define MAX_NAME_LEN 25    // Maximum length of a name
#define MAX_AGE 120        // Maximum age of a person
#define MAX_CITY_LEN 30    // Maximum length of a city name

struct Person {
    char name[MAX_NAME_LEN];
    int age;
    char city[MAX_CITY_LEN];
};

int main() {
    struct Person database[MAX_ENTRIES];
    int num_entries = 0;

    // Prompt user to enter data for database
    printf("Enter data for the database:\n");
    while (num_entries < MAX_ENTRIES) {
        // Allocate memory for a new person
        struct Person* new_person = malloc(sizeof(struct Person));
        if (!new_person) {
            printf("Out of memory. Exiting program.\n");
            return 1;
        }

        // Prompt user to enter data for the new person
        printf("Enter name: ");
        scanf("%s", new_person->name);
        printf("Enter age: ");
        scanf("%d", &new_person->age);
        printf("Enter city: ");
        scanf("%s", new_person->city);

        // Add the new person to the database
        database[num_entries++] = *new_person;
        free(new_person);

        // Prompt user to add another entry or exit
        printf("Enter 'y' to add another entry or 'n' to exit: ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    // Create index arrays for name, age, and city
    int name_index[MAX_ENTRIES];
    int age_index[MAX_ENTRIES];
    int city_index[MAX_ENTRIES];

    // Populate index arrays
    for (int i = 0; i < num_entries; i++) {
        name_index[i] = i;
        age_index[i] = i;
        city_index[i] = i;
        for (int j = i-1; j >= 0; j--) {
            if (strcmp(database[i].name, database[name_index[j]].name) < 0) {
                int temp = name_index[j+1];
                name_index[j+1] = name_index[j];
                name_index[j] = temp;
            }
            if (database[i].age < database[age_index[j]].age) {
                int temp = age_index[j+1];
                age_index[j+1] = age_index[j];
                age_index[j] = temp;
            }
            if (strcmp(database[i].city, database[city_index[j]].city) < 0) {
                int temp = city_index[j+1];
                city_index[j+1] = city_index[j];
                city_index[j] = temp;
            }
        }
    }

    // Print sorted index arrays
    printf("\nName Index:");
    for (int i = 0; i < num_entries; i++) {
        printf(" %s,", database[name_index[i]].name);
    }
    printf("\nAge Index:");
    for (int i = 0; i < num_entries; i++) {
        printf(" %d,", database[age_index[i]].age);
    }
    printf("\nCity Index:");
    for (int i = 0; i < num_entries; i++) {
        printf(" %s,", database[city_index[i]].city);
    }
    printf("\n");

    return 0;
}