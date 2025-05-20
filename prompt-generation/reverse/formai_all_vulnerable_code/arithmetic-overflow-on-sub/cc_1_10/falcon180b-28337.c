//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char name[50];
    int room_no;
    int arrival_date, departure_date;
    int days;
    float cost;

    printf("Welcome to Hotel Management System!\n");
    printf("Please select an option:\n");
    printf("1. Book a Room\n");
    printf("2. View Reservations\n");
    printf("3. Check-out\n");
    printf("4. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1: // Book a room
            printf("Enter your name: ");
            scanf("%s", name);

            printf("Enter room number: ");
            scanf("%d", &room_no);

            printf("Enter arrival date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &arrival_date, &arrival_date+1, &arrival_date+3);

            printf("Enter departure date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &departure_date, &departure_date+1, &departure_date+3);

            days = (departure_date - arrival_date) / (24 * 60 * 60);
            cost = days * 100;

            printf("Room booked for %d days at a cost of $%.2f\n", days, cost);

            break;

        case 2: // View reservations
            printf("Sorry, this feature is not yet implemented.\n");
            break;

        case 3: // Check-out
            printf("Sorry, this feature is not yet implemented.\n");
            break;

        case 4: // Exit
            printf("Thank you for using Hotel Management System!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}