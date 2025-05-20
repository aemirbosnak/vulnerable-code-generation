//FormAI DATASET v1.0 Category: Hotel Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum string lengths
#define MAX_NAME_LEN 50
#define MAX_ADDRESS_LEN 100

// Define structure for hotel guest data
typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    int room_number;
    int stay_length;
    float bill_amount;
} Guest;

// Define function to add guest to system
void add_guest(Guest *guests, int *num_guests) {
    // Prompt user for guest information
    printf("Enter guest name: ");
    scanf("%s", guests[*num_guests].name);
    printf("Enter guest address: ");
    scanf("%s", guests[*num_guests].address);
    printf("Enter room number: ");
    scanf("%d", &guests[*num_guests].room_number);
    printf("Enter length of stay (in days): ");
    scanf("%d", &guests[*num_guests].stay_length);
    printf("Enter bill amount: ");
    scanf("%f", &guests[*num_guests].bill_amount);
    
    // Increment number of guests in system
    (*num_guests)++;
    
    // Print confirmation message
    printf("Guest added to system.\n");
}

// Define function to print all guests in system
void print_guests(Guest *guests, int num_guests) {
    printf("Guests in system:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("%s\n", guests[i].name);
    }
}

int main() {
    // Initialize variables
    Guest guests[100];
    int num_guests = 0;
    int option;
    
    // Print welcome message
    printf("Welcome to the Hotel Management System!\n");
    
    // Loop for user options
    while (1) {
        // Print menu options
        printf("Menu:\n1. Add guest\n2. Print all guests\n3. Exit\n");
        printf("Enter option number: ");
        scanf("%d", &option);
        
        // Handle user option
        if (option == 1) {
            add_guest(guests, &num_guests);
        } else if (option == 2) {
            print_guests(guests, num_guests);
        } else if (option == 3) {
            // Exit program
            printf("Exiting program...");
            exit(0);
        } else {
            // Invalid option
            printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}