//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: retro
// Welcome to the Retro Database Oasis, traveler!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty steed - the Database
typedef struct {
    char name[50];
    int age;
    char city[50];
} Person;

// Our dusty tomes of knowledge
static Person database[100];
static int num_records = 0;

// A script from an ancient sage - the Input Handler
static void input(Person *person) {
    printf("Enter name: ");
    scanf("%s", person->name);

    printf("Enter age: ");
    scanf("%d", &person->age);

    printf("Enter city: ");
    scanf("%s", person->city);
}

// A spell to summon a record - the Add Record Invocation
static void add_record() {
    database[num_records].age = -1;  // Mark empty slot
    input(&database[num_records]);
    num_records++;
    printf("Record added, traveler.\n");
}

// A ritual to find the wise - the Search Invocation
static void search_record() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_records; i++) {
        if (!strcmp(database[i].name, name)) {
            printf(
                "\nName: %s\nAge: %d\nCity: %s\n",
                database[i].name, database[i].age, database[i].city
            );
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Name not found, traveler.\n");
    }
}

// A swift exit from the Oasis - the Quit Invocation
static void quit() {
    printf("Farewell, traveler. May your journey be fruitful.\n");
    exit(0);
}

// Our main adventure - the Menu
int main() {
    int choice;
    do {
        printf(
            "\n=============================\n"
            "RETRO DATABASE OASIS\n"
            "=============================\n"
            "[1] Add a Record\n"
            "[2] Search for a Record\n"
            "[3] Quit\n"
            "=============================\n"
            "Choice: "
        );
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                quit();
                break;
            default:
                printf("Invalid choice, traveler.\n");
        }
    } while (choice != 3);

    return 0;
}