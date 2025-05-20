//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing guest information
struct guest {
    char name[50];
    char gender;
    int age;
    char address[100];
    char email[50];
    char phone[15];
    int room_number;
    int check_in;
    int check_out;
};

int main() {
    int guest_count = 0, room_count = 100;
    struct guest* guests = malloc(room_count * sizeof(struct guest));
    
    // Display main menu options
    int choice = 0;
    while (choice < 4) {
        printf("\nC Hotel Management System Main Menu\n");
        printf("1. Register New Guest\n");
        printf("2. View Guest Information\n");
        printf("3. Edit Guest Information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Register new guest
        if (choice == 1) {
            // Check if there is enough space in array for new guest
            if (guest_count >= room_count) {
                room_count *= 2;
                guests = realloc(guests, room_count * sizeof(struct guest));
            }
            // Get guest information from user
            struct guest new_guest;
            printf("\nEnter guest information:\n");
            printf("Name: ");
            scanf(" %[^\n]s", new_guest.name);
            printf("Gender (M/F): ");
            scanf(" %c", &new_guest.gender);
            printf("Age: ");
            scanf("%d", &new_guest.age);
            printf("Address: ");
            scanf(" %[^\n]s", new_guest.address);
            printf("Email: ");
            scanf(" %s", new_guest.email);
            printf("Phone Number: ");
            scanf(" %s", new_guest.phone);
            printf("Room Number: ");
            scanf("%d", &new_guest.room_number);
            printf("Check-In Date (YYYYMMDD): ");
            scanf("%d", &new_guest.check_in);
            printf("Check-Out Date (YYYYMMDD): ");
            scanf("%d", &new_guest.check_out);
            // Add new guest to array
            guests[guest_count] = new_guest;
            guest_count++;
            printf("\nNew guest registered.\n");
        }
        // View guest information
        else if (choice == 2) {
            // Get room number from user
            int room_number;
            printf("\nEnter room number: ");
            scanf("%d", &room_number);
            // Find guest with matching room number
            for (int i = 0; i < guest_count; i++) {
                if (guests[i].room_number == room_number) {
                    // Display guest information
                    printf("\nGuest Information:\n");
                    printf("Name: %s\n", guests[i].name);
                    printf("Gender: %c\n", guests[i].gender);
                    printf("Age: %d\n", guests[i].age);
                    printf("Address: %s\n", guests[i].address);
                    printf("Email: %s\n", guests[i].email);
                    printf("Phone Number: %s\n", guests[i].phone);
                    printf("Room Number: %d\n", guests[i].room_number);
                    printf("Check-In Date: %d\n", guests[i].check_in);
                    printf("Check-Out Date: %d\n", guests[i].check_out);
                    break;
                }
                // If room number not found, display error message
                if (i == guest_count - 1) {
                    printf("\nError: Room number not found.\n");
                }
            }
        }
        // Edit guest information
        else if (choice == 3) {
            // Get room number from user
            int room_number;
            printf("\nEnter room number: ");
            scanf("%d", &room_number);
            // Find guest with matching room number
            for (int i = 0; i < guest_count; i++) {
                if (guests[i].room_number == room_number) {
                    // Get new information from user
                    printf("\nEnter new information:\n");
                    printf("Name: ");
                    scanf(" %[^\n]s", guests[i].name);
                    printf("Gender (M/F): ");
                    scanf(" %c", &guests[i].gender);
                    printf("Age: ");
                    scanf("%d", &guests[i].age);
                    printf("Address: ");
                    scanf(" %[^\n]s", guests[i].address);
                    printf("Email: ");
                    scanf(" %s", guests[i].email);
                    printf("Phone Number: ");
                    scanf(" %s", guests[i].phone);
                    printf("Room Number: ");
                    scanf("%d", &guests[i].room_number);
                    printf("Check-In Date (YYYYMMDD): ");
                    scanf("%d", &guests[i].check_in);
                    printf("Check-Out Date (YYYYMMDD): ");
                    scanf("%d", &guests[i].check_out);
                    printf("\nGuest information updated.\n");
                    break;
                }
                // If room number not found, display error message
                if (i == guest_count - 1) {
                    printf("\nError: Room number not found.\n");
                }
            }
        }
        // Exit program
        else if (choice == 4) {
            printf("\nThank you for using C Hotel Management System!\n");
        }
        // Invalid choice
        else {
            printf("\nError: Invalid choice.\n");
        }
    }
    
    free(guests);
    return 0;
}