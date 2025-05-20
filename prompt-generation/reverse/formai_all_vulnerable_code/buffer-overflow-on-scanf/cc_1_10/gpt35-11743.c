//FormAI DATASET v1.0 Category: Hotel Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about hotel guests
typedef struct Guest {
    char name[50];
    char room_number[5];
    int num_of_nights;
    int num_of_guests;
    float total_cost;
} Guest;

// Function to calculate the total cost of a guest's stay
float calculate_cost(int num_of_nights, int num_of_guests) {
    float room_cost = 100.00;
    float guest_cost = 25.00 * num_of_guests;
    float total_cost = (room_cost * num_of_nights) + guest_cost;
    return total_cost;
}

// Function to add a new guest to the system
void add_guest(Guest *guests, int *num_of_guests) {
    printf("Please enter guest name: ");
    char name[50];
    scanf("%s", name);
    strcpy(guests[*num_of_guests].name, name);
    
    printf("Please enter room number (ex.101): ");
    char room_number[5];
    scanf("%s", room_number);
    strcpy(guests[*num_of_guests].room_number, room_number);
    
    printf("Please enter number of nights: ");
    int num_of_nights;
    scanf("%d", &num_of_nights);
    guests[*num_of_guests].num_of_nights = num_of_nights;
    
    printf("Please enter number of guests: ");
    int num_of_guests_value;
    scanf("%d", &num_of_guests_value);
    guests[*num_of_guests].num_of_guests = num_of_guests_value;
    
    float total_cost = calculate_cost(num_of_nights, num_of_guests_value);
    guests[*num_of_guests].total_cost = total_cost;
    
    (*num_of_guests)++;
}

// Function to display information about all guests in the system
void display_guests(Guest *guests, int num_of_guests) {
    printf("\nGuest List:\n");
    printf("---------------------------------------\n");
    for(int i = 0; i < num_of_guests; i++) {
        printf("Name: %s\nRoom Number: %s\nNumber of Nights: %d\nNumber of Guests: %d\nTotal Cost: $%.2f\n",
               guests[i].name, guests[i].room_number, guests[i].num_of_nights, guests[i].num_of_guests, guests[i].total_cost);
        printf("---------------------------------------\n");
    }
}

// Main function to run the hotel management system
int main() {
    Guest guests[100];
    int num_of_guests = 0;
    int choice;
    
    do {
        printf("\nPlease choose an option:");
        printf("\n1. Add Guest");
        printf("\n2. Display Guest List");
        printf("\n3. Exit");
        printf("\nOption: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_guest(guests, &num_of_guests);
                break;
            case 2:
                display_guests(guests, num_of_guests);
                break;
            case 3:
                printf("\nThank you for using the hotel management system!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
        
    } while (choice != 3);
    
    return 0;
}