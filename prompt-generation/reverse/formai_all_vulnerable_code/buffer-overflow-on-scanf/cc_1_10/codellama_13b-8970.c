//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: funny
/*
 * 🚨 WARNING 🚨
 *
 * This is a funny simulation of a C database.
 * It is not meant to be taken seriously.
 *
 * 😜😜😜
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_AGE_LEN 3
#define MAX_PHONE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char phone[MAX_PHONE_LEN];
} Person;

void print_menu() {
    printf("Welcome to the funny C database simulation!\n");
    printf("Here are your options:\n");
    printf("1. Add a new person to the database\n");
    printf("2. Print all people in the database\n");
    printf("3. Search for a person by name\n");
    printf("4. Quit\n");
}

void add_person(Person *people, int *count) {
    printf("Enter name: ");
    scanf("%s", people[*count].name);
    printf("Enter age: ");
    scanf("%d", &people[*count].age);
    printf("Enter phone number: ");
    scanf("%s", people[*count].phone);
    *count += 1;
}

void print_all_people(Person *people, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Phone: %s\n\n", people[i].phone);
    }
}

void search_by_name(Person *people, int count) {
    char name[MAX_NAME_LEN];
    printf("Enter name to search for: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found a match!\n");
            printf("Name: %s\n", people[i].name);
            printf("Age: %d\n", people[i].age);
            printf("Phone: %s\n", people[i].phone);
            break;
        }
    }
}

int main() {
    Person people[10];
    int count = 0;
    int choice;

    print_menu();

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_person(people, &count);
                break;
            case 2:
                print_all_people(people, count);
                break;
            case 3:
                search_by_name(people, count);
                break;
            case 4:
                printf("Quitting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}