//FormAI DATASET v1.0 Category: Hotel Management System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declare the structure for storing hotel information
struct hotel {
    int room_num;
    char guest_name[20];
    char check_in_date[20];
    char check_out_date[20];
};

// Declare the main function
int main() {

    // Declare an array of struct hotel to store hotel rooms
    struct hotel h[50];

    int choice;
    int room_count = 0;

    do {
        // Display the menu options
        printf("\n\n\n\t\t***** HOTEL MANAGEMENT SYSTEM *****\n\n");
        printf("\t\t\t1. Book Room\n");
        printf("\t\t\t2. Display Booked Rooms\n");
        printf("\t\t\t3. Exit\n");

        printf("\n\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // Case 1: Book a Room
            case 1:
                printf("\n\t\t\tEnter the Room Number: ");
                scanf("%d", &h[room_count].room_num);

                printf("\n\t\t\tEnter Guest Name: ");
                scanf("%s", h[room_count].guest_name);

                printf("\n\t\t\tEnter Check-in Date (dd/mm/yyyy): ");
                scanf("%s", h[room_count].check_in_date);

                printf("\n\t\t\tEnter Check-out Date (dd/mm/yyyy): ");
                scanf("%s", h[room_count].check_out_date);

                room_count++;
                printf("\n\t\t\tRoom successfully booked!\n");
                break;

            // Case 2: Display Booked Rooms
            case 2:
                if(room_count == 0) {
					printf("\n\t\t\tNo rooms have been booked yet.\n");
				}
				else {
					printf("\n\t\t***LIST OF BOOKED ROOMS***\n");
		            printf("\nRoom Number\tGuest Name\tCheck-in Date\tCheck-out Date\n");
		            for(int i=0; i<room_count; i++) {
		                printf("%d\t\t%s\t\t%s\t\t%s\n", h[i].room_num, h[i].guest_name, h[i].check_in_date, h[i].check_out_date);
		            }
				}
                break;

            // Case 3: Exit
            case 3:
                printf("\n\t\t\tThanks for using the Hotel Management System. Bye!\n");
                exit(0);
                break;

            default:
                printf("\n\t\tInvalid Choice. Please try again.\n");
                break;
        }
    } while(choice != 3);

    return 0;
}