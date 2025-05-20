//LLAMA2-13B DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_GUESTS 10

// Structure to store information about a guest
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_NAME_LENGTH];
} guest_t;

// Array to store information about guests
guest_t guests[MAX_GUESTS];

// Function to generate a random name for a guest
void generate_name() {
    char buffer[MAX_NAME_LENGTH];
    int i;

    for (i = 0; i < MAX_NAME_LENGTH; i++) {
        buffer[i] = 'a' + (rand() % 26);
    }

    strcpy(guests[0].name, buffer);
}

// Function to add a guest to the array
void add_guest(int age, char email[]) {
    int i;

    // Check if the array is full
    if (sizeof(guests) == MAX_GUESTS) {
        printf("The party is full! Sorry, we can't add any more guests.\n");
        return;
    }

    // Generate a random name for the guest
    generate_name();

    // Add the guest to the array
    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].name[0] == '\0') {
            break;
        }
    }

    guests[i].age = age;
    strcpy(guests[i].email, email);
}

// Function to print the list of guests
void print_guests() {
    int i;

    for (i = 0; i < MAX_GUESTS; i++) {
        printf("%d. %s (%d years old, %s)\n", i + 1, guests[i].name, guests[i].age, guests[i].email);
    }
}

int main() {
    int i, age, num_guests;
    char email[MAX_NAME_LENGTH];

    // Ask the user for the number of guests
    printf("How many guests would you like to invite? ");
    scanf("%d", &num_guests);

    // Loop to add guests
    for (i = 0; i < num_guests; i++) {
        printf("What is the age of guest %d? ", i + 1);
        scanf("%d", &age);

        printf("What is the email address of guest %d? ", i + 1);
        fgets(email, MAX_NAME_LENGTH, stdin);

        // Add the guest to the array
        add_guest(age, email);
    }

    // Print the list of guests
    print_guests();

    return 0;
}