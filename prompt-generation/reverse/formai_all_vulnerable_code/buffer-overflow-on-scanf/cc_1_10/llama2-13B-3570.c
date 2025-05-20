//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to represent a person
struct person {
    char name[50];
    char address[100];
    int age;
};

// Function to read a person's details from the user
void read_person(struct person *p) {
    printf("Enter name: ");
    fgets(p->name, 50, stdin);
    printf("Enter address: ");
    fgets(p->address, 100, stdin);
    printf("Enter age: ");
    scanf("%d", &p->age);
}

// Function to print a person's details
void print_person(struct person p) {
    printf("Name: %s\nAddress: %s\nAge: %d\n", p.name, p.address, p.age);
}

// Function to search for a person in the phone book
struct person *search_phone_book(struct person *phone_book, char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            return &phone_book[i];
        }
    }
    return NULL;
}

int main() {
    // Define the phone book
    struct person phone_book[10] = {
        {"Alice", "123 Main St", 25},
        {"Bob", "456 Elm St", 30},
        {"Charlie", "789 Oak St", 35},
        {"David", "111 Maple St", 20},
        {"Eve", "222 Broadway St", 25},
        {"Frank", "333 Spruce St", 30},
        {"Grace", "444 Oak St", 20},
        {"Helen", "555 Elm St", 35},
        {"Ivy", "666 Maple St", 25},
        {"Jane", "777 Broadway St", 30}
    };

    // Read a person's details
    struct person p;
    read_person(&p);

    // Search for the person in the phone book
    struct person *found_person = search_phone_book(phone_book, p.name);

    // Print the found person's details
    if (found_person != NULL) {
        print_person(*found_person);
    } else {
        printf("Person not found in the phone book.\n");
    }

    return 0;
}