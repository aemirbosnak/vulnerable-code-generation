//FormAI DATASET v1.0 Category: Hotel Management System ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_GUESTS 100

// Structure to hold guest information
typedef struct {
    int guest_id;
    char name[50];
    char gender;
    int age;
    char phone_number[15];
    char address[100];
    char email[50];
    float room_rate;
    int number_of_nights;
    float total_bill;
} Guest;

// Global array of guests
Guest guests[MAX_GUESTS];

// Count of guests in the system
int guest_count = 0;

// Function to add a guest to the system
void add_guest() {
    printf("Enter guest details:\n");

    // Prompt user for guest information
    Guest new_guest;
    printf("Name: ");
    fgets(new_guest.name, 50, stdin);
    printf("Gender (M/F): ");
    scanf(" %c", &new_guest.gender);
    printf("Age: ");
    scanf("%d", &new_guest.age);
    printf("Phone Number: ");
    scanf(" %s", new_guest.phone_number);
    printf("Address: ");
    scanf(" %[^\n]", new_guest.address);
    printf("Email: ");
    scanf(" %s", new_guest.email);
    printf("Room Rate: ");
    scanf("%f", &new_guest.room_rate);
    printf("Number of Nights: ");
    scanf("%d", &new_guest.number_of_nights);

    // Auto-generate guest ID
    new_guest.guest_id = guest_count + 1;

    // Calculate total bill
    new_guest.total_bill = new_guest.room_rate * new_guest.number_of_nights;

    // Add guest to global array and increment guest count
    guests[guest_count] = new_guest;
    guest_count++;

    printf("Guest added successfully.\n");
}

// Function to list all guests in the system
void list_guests() {
    printf("Guests in the system:\n");

    // Loop through all guests and print their information
    for (int i = 0; i < guest_count; i++) {
        Guest curr_guest = guests[i];
        printf("Guest ID: %d, Name: %s, Gender: %c, Age: %d, Phone Number: %s, Address: %s, Email: %s, Room Rate: %.2f, Number of Nights: %d, Total Bill: %.2f\n",
               curr_guest.guest_id, curr_guest.name, curr_guest.gender, curr_guest.age, curr_guest.phone_number, curr_guest.address, curr_guest.email, curr_guest.room_rate, curr_guest.number_of_nights, curr_guest.total_bill);
    }
}

// Function to search for a guest by name or ID
void search_guest() {
    printf("Enter the name or ID of the guest you want to search for: ");
    char search_string[100];
    scanf(" %[^\n]", search_string);

    // Loop through all guests and print their information if they match the search string
    for (int i = 0; i < guest_count; i++) {
        Guest curr_guest = guests[i];

        // Check if guest ID or name match the search string
        if (curr_guest.guest_id == atoi(search_string) || strstr(curr_guest.name, search_string) != NULL) {
            printf("Guest found:\n");
            printf("Guest ID: %d, Name: %s, Gender: %c, Age: %d, Phone Number: %s, Address: %s, Email: %s, Room Rate: %.2f, Number of Nights: %d, Total Bill: %.2f\n",
                   curr_guest.guest_id, curr_guest.name, curr_guest.gender, curr_guest.age, curr_guest.phone_number, curr_guest.address, curr_guest.email, curr_guest.room_rate, curr_guest.number_of_nights, curr_guest.total_bill);
            return;
        }
    }

    printf("Guest not found.\n");
}

// Function to generate a bill for a guest
void generate_bill() {
    printf("Enter the guest ID of the guest for whom you want to generate a bill: ");
    int guest_id;
    scanf("%d", &guest_id);

    // Loop through all guests and generate bill if guest ID matches
    for (int i = 0; i < guest_count; i++) {
        Guest curr_guest = guests[i];
        if (curr_guest.guest_id == guest_id) {
            printf("Total Bill for Guest %d: %.2f\n", curr_guest.guest_id, curr_guest.total_bill);
            return;
        }
    }

    printf("Guest not found.\n");
}

int main() {
    int choice;
    do {
        printf("\nWelcome to C Hotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. List Guests\n");
        printf("3. Search Guest\n");
        printf("4. Generate Bill\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_guest();
                break;
            case 2:
                list_guests();
                break;
            case 3:
                search_guest();
                break;
            case 4:
                generate_bill();
                break;
            case 5:
                printf("Thank you for using C Hotel Management System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}