//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50

struct Person {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

void add_person(struct Person people[], int count);
void delete_person(struct Person people[], int count, int id);
void update_person(struct Person people[], int count, int id);
void display_people(struct Person people[], int count);

int main() {
    struct Person people[100]; // array of 100 people
    int count = 0; // number of people currently in the database
    char choice; // user's menu choice

    printf("Welcome to the database simulator!\n");

    do {
        // display options menu
        printf("\nChoose an option:\n");
        printf("a) Add a new person\n");
        printf("d) Delete an existing person\n");
        printf("u) Update an existing person's information\n");
        printf("s) Show list of all people\n");
        printf("q) Quit\n");

        // get user's choice
        scanf(" %c", &choice);

        // execute corresponding function based on user's choice
        switch (choice) {
            case 'a':
                add_person(people, count);
                count++;
                break;
            case 'd':
                if (count == 0) {
                    printf("There are no people in the database!\n");
                } else {
                    int id;
                    printf("Enter the ID of the person you want to delete: ");
                    scanf("%d", &id);
                    delete_person(people, count, id);
                    count--;
                }
                break;
            case 'u':
                if (count == 0) {
                    printf("There are no people in the database!\n");
                } else {
                    int id;
                    printf("Enter the ID of the person you want to update: ");
                    scanf("%d", &id);
                    update_person(people, count, id);
                }
                break;
            case 's':
                if (count == 0) {
                    printf("There are no people in the database!\n");
                } else {
                    display_people(people, count);
                }
                break;
            case 'q':
                // do nothing - program will exit
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 'q');

    printf("Goodbye!\n");

    return 0;
}

// function to add a new person to the array
void add_person(struct Person people[], int count) {
    struct Person person;

    printf("Enter the person's name: ");
    scanf("%s", person.name);
    printf("Enter the person's email: ");
    scanf("%s", person.email);

    person.id = count + 1;
    people[count] = person;

    printf("Person added with ID %d.\n", person.id);
}

// function to delete a person from the array
void delete_person(struct Person people[], int count, int id) {
    int i;
    int found = 0;

    for (i = 0; i < count; i++) {
        if (people[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < count - 1; i++) {
            people[i] = people[i + 1];
        }

        printf("Person with ID %d deleted.\n", id);
    } else {
        printf("No person found with ID %d.\n", id);
    }
}

// function to update a person's information in the array
void update_person(struct Person people[], int count, int id) {
    int i;
    int found = 0;

    for (i = 0; i < count; i++) {
        if (people[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Enter the person's new name: ");
        scanf("%s", people[i].name);
        printf("Enter the person's new email: ");
        scanf("%s", people[i].email);

        printf("Person with ID %d updated.\n", id);
    } else {
        printf("No person found with ID %d.\n", id);
    }
}

// function to display all people in the array
void display_people(struct Person people[], int count) {
    int i;

    printf("ID\tName\t\tEmail\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%s\t\t%s\n", people[i].id, people[i].name, people[i].email);
    }
}