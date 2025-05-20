//FormAI DATASET v1.0 Category: Hotel Management System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ROOMS 100
#define MAX_NAME 50
#define MAX_DAYS 30

struct guest {
    char name[MAX_NAME];
    int room_number;
    int days;
    float total_bill;
};

int main() {
    struct guest guests[MAX_ROOMS];
    int num_guests = 0;

    printf("Welcome to the C Hotel Management System version 1.0 - Post Apocalyptic Edition!\n");

    while (1) {
        char choice;

        printf("\nPlease select an option:\n");
        printf("1. Check in a guest\n");
        printf("2. Check out a guest\n");
        printf("3. View guest list\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (num_guests == MAX_ROOMS) {
                    printf("\nError: Maximum number of guests reached.\n");
                    break;
                }

                struct guest new_guest;

                printf("\nEnter guest name: ");
                scanf("%s", new_guest.name);

                printf("Enter room number: ");
                scanf("%d", &new_guest.room_number);

                printf("Enter days stayed: ");
                scanf("%d", &new_guest.days);

                new_guest.total_bill = (float) new_guest.days * 50;

                guests[num_guests++] = new_guest;

                printf("\nGuest checked in successfully!\n");
                break;

            case '2':
                if (num_guests == 0) {
                    printf("\nError: No guests to check out.\n");
                    break;
                }

                int room_number;

                printf("\nEnter room number: ");
                scanf("%d", &room_number);

                for (int i = 0; i < num_guests; i++) {
                    if (guests[i].room_number == room_number) {
                        printf("Guest '%s' checked out successfully.\n", guests[i].name);

                        // Remove guest from array and shuffle remaining guests back
                        for (int j = i + 1; j < num_guests; j++) {
                            guests[j - 1] = guests[j];
                        }

                        num_guests--; // Reduce number of guests to account for removed guest
                        break;
                    }

                    if (i == num_guests - 1) {
                        printf("\nError: No guest found with that room number.\n");
                    }
                }

                break;

            case '3':
                if (num_guests == 0) {
                    printf("\nGuest list is empty.\n");
                    break;
                }

                printf("\nGuest List:\n");
                printf("Name\t\tRoom Number\tDays Stayed\tTotal Bill\n");

                for (int i = 0; i < num_guests; i++) {
                    printf("%-10s\t%4d\t\t%3d\t\t%.2f\n", guests[i].name, guests[i].room_number, guests[i].days, guests[i].total_bill);
                }

                break;

            case '4':
                printf("\nThank you for using the C Hotel Management System version 1.0 - Post Apocalyptic Edition!\n");
                exit(0);
                break;

            default:
                printf("\nError: Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}