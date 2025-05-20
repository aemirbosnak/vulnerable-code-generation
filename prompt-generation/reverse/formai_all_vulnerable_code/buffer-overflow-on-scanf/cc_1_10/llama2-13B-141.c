//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: introspective
// A Program that Ponders its Own Existence

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20

// Structure to hold a person's name and phone number
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} person;

// Array to store all the people in the phone book
person people[10];

// Function to add a person to the phone book
void add_person(char *name, char *phone) {
    int i;

    // Find an empty slot in the array
    for (i = 0; i < 10; i++) {
        if (people[i].name[0] == '\0') {
            break;
        }
    }

    // If no empty slot found, return an error message
    if (i == 10) {
        printf("Error: Phone book is full.\n");
        return;
    }

    // Copy the name and phone number into the array
    strcpy(people[i].name, name);
    strcpy(people[i].phone, phone);
}

// Function to print all the people in the phone book
void print_phone_book() {
    int i;

    printf("Phone Book:\n");

    for (i = 0; i < 10; i++) {
        printf("Name: %s\nPhone: %s\n", people[i].name, people[i].phone);
    }
}

// Main function
int main() {
    int choice;

    // Print the phone book
    print_phone_book();

    // Ask the user to add a person to the phone book
    printf("Would you like to add a new person to the phone book? (y/n)\n");
    scanf(" %c", &choice);

    // If the user chooses to add a person, prompt them for the name and phone number
    if (choice == 'y') {
        char name[MAX_NAME_LEN];
        char phone[MAX_PHONE_LEN];

        printf("Enter the person's name: ");
        scanf(" %s", name);

        printf("Enter the person's phone number: ");
        scanf(" %s", phone);

        // Add the person to the phone book
        add_person(name, phone);
    }

    return 0;
}