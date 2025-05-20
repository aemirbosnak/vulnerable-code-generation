//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_GUESTS 10

// Struct to store information about a guest
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_NAME_LENGTH];
} guest_t;

// Function to print a menu for the guests
void print_menu(guest_t *guests, int num_guests) {
    int i;
    for (i = 0; i < num_guests; i++) {
        printf("%d. %s (%d years old)\n", i + 1, guests[i].name, guests[i].age);
    }
}

// Function to randomly select a guest and print their name
void pick_guest(guest_t *guests, int num_guests) {
    int i = rand() % num_guests;
    printf("The randomly selected guest is: %s\n", guests[i].name);
}

// Function to handle the main menu
void main_menu(guest_t *guests, int num_guests) {
    int choice;

    do {
        print_menu(guests, num_guests);
        printf("Enter your choice (1-10): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_menu(guests, num_guests);
                break;
            case 2:
                pick_guest(guests, num_guests);
                break;
            case 3:
                // Function to handle the third option
                // ...
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 10);
}

// Function to handle the third option
void option_3(guest_t *guests, int num_guests) {
    int i;
    for (i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, "John") == 0) {
            printf("John is the randomly selected guest!\n");
            break;
        }
    }
}

int main() {
    // Initialize array of guests
    guest_t guests[MAX_GUESTS] = {
        {"Alice", 25, "alice@example.com"},
        {"Bob", 30, "bob@example.com"},
        {"Charlie", 20, "charlie@example.com"},
        {"David", 35, "david@example.com"},
        {"Eve", 28, "eve@example.com"},
        {"Frank", 40, "frank@example.com"},
        {"George", 22, "george@example.com"},
        {"Helen", 32, "helen@example.com"},
        {"Ivan", 29, "ivan@example.com"},
        {"Jane", 27, "jane@example.com"}
    };

    int num_guests = sizeof(guests) / sizeof(guests[0]);

    main_menu(guests, num_guests);

    return 0;
}