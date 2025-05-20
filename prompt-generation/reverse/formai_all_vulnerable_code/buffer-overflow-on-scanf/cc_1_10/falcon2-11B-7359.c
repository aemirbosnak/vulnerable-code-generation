//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char room_number[5];
    char phone[15];
    char email[50];
    char arrival_date[10];
    char departure_date[10];
} Guest;

void display_menu() {
    printf("1. Add new guest\n");
    printf("2. List all guests\n");
    printf("3. Check availability of room\n");
    printf("4. Update guest information\n");
    printf("5. Delete guest\n");
    printf("6. Quit\n");
}

int main() {
    Guest guests[10];
    int choice = 0;

    while (choice!= 6) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add new guest
                printf("Enter guest's name: ");
                scanf("%s", guests[choice].name);
                printf("Enter room number: ");
                scanf("%s", guests[choice].room_number);
                printf("Enter phone number: ");
                scanf("%s", guests[choice].phone);
                printf("Enter email address: ");
                scanf("%s", guests[choice].email);
                printf("Enter arrival date (YYYY-MM-DD): ");
                scanf("%s", guests[choice].arrival_date);
                printf("Enter departure date (YYYY-MM-DD): ");
                scanf("%s", guests[choice].departure_date);
                break;
            case 2: // List all guests
                printf("Guest list:\n");
                for (int i = 0; i < 10; i++) {
                    printf("Name: %s\n", guests[i].name);
                    printf("Room Number: %s\n", guests[i].room_number);
                    printf("Phone Number: %s\n", guests[i].phone);
                    printf("Email Address: %s\n", guests[i].email);
                    printf("Arrival Date: %s\n", guests[i].arrival_date);
                    printf("Departure Date: %s\n", guests[i].departure_date);
                    printf("\n");
                }
                break;
            case 3: // Check availability of room
                printf("Enter room number to check availability: ");
                scanf("%s", guests[choice].room_number);
                printf("Room %s is available\n", guests[choice].room_number);
                break;
            case 4: // Update guest information
                printf("Enter guest's name: ");
                scanf("%s", guests[choice].name);
                printf("Enter new room number: ");
                scanf("%s", guests[choice].room_number);
                printf("Enter new phone number: ");
                scanf("%s", guests[choice].phone);
                printf("Enter new email address: ");
                scanf("%s", guests[choice].email);
                printf("Enter new arrival date (YYYY-MM-DD): ");
                scanf("%s", guests[choice].arrival_date);
                printf("Enter new departure date (YYYY-MM-DD): ");
                scanf("%s", guests[choice].departure_date);
                break;
            case 5: // Delete guest
                printf("Enter guest's name to delete: ");
                scanf("%s", guests[choice].name);
                break;
            case 6: // Quit
                printf("Thank you for using the Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}