//LLAMA2-13B DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GUESTS 10

// Structure to store information about guests
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} guest_t;

// Function to create a new guest
void create_guest(guest_t *g) {
    printf("Please enter the guest's name: ");
    fgets(g->name, MAX_NAME_LENGTH, stdin);
    printf("Please enter the guest's age: ");
    scanf("%d", &g->age);
}

// Function to print a list of all guests
void print_guests(guest_t *guests) {
    int i;
    for (i = 0; i < MAX_GUESTS; i++) {
        if (guests[i].name[0] != '\0') {
            printf("%d. %s (%d years old)\n", i + 1, guests[i].name, guests[i].age);
        }
    }
}

// Function to add a guest to the list
void add_guest(guest_t *guests, int num_guests) {
    int i;
    for (i = 0; i < num_guests; i++) {
        if (guests[i].name[0] == '\0') {
            break;
        }
    }
    if (i == num_guests) {
        printf("Sorry, the list is full!\n");
        return;
    }
    strcpy(guests[i].name, " ");
    guests[i].age = 0;
}

int main() {
    guest_t guests[MAX_GUESTS];
    int num_guests = 0;

    // Create some guests
    create_guest(&guests[0]);
    create_guest(&guests[1]);
    create_guest(&guests[2]);

    // Add more guests
    add_guest(guests, MAX_GUESTS - num_guests);

    // Print the list of guests
    print_guests(guests);

    return 0;
}