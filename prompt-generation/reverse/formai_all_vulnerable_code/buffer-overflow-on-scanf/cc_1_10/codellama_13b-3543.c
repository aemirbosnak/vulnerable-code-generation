//Code Llama-13B DATASET v1.0 Category: Phone Book ; Style: funny
/*
 * Phone Book
 *
 * A funny program that allows you to store and search for people's names,
 * addresses, and phone numbers.
 *
 * Written in C.
 */

#include <stdio.h>
#include <string.h>

// Structure to store a person's information
struct person {
    char name[50];
    char address[50];
    char phone_number[15];
};

// Function to add a person to the phone book
void add_person(struct person *people, int *num_people) {
    printf("Enter the person's name: ");
    scanf("%s", people[*num_people].name);
    printf("Enter the person's address: ");
    scanf("%s", people[*num_people].address);
    printf("Enter the person's phone number: ");
    scanf("%s", people[*num_people].phone_number);
    (*num_people)++;
}

// Function to search for a person in the phone book
void search_person(struct person *people, int num_people) {
    char name[50];
    printf("Enter the name of the person you are looking for: ");
    scanf("%s", name);
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Name: %s\nAddress: %s\nPhone Number: %s\n", people[i].name, people[i].address, people[i].phone_number);
            return;
        }
    }
    printf("Person not found.\n");
}

int main() {
    struct person people[100];
    int num_people = 0;
    char choice;
    do {
        printf("Welcome to the Phone Book\n");
        printf("1. Add a person\n2. Search for a person\n3. Quit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                add_person(people, &num_people);
                break;
            case '2':
                search_person(people, num_people);
                break;
            case '3':
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice != '3');
    return 0;
}