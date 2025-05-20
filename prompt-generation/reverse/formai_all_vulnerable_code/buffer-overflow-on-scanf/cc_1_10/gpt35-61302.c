//FormAI DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for hotel guest information
typedef struct {
    char name[30];
    int duration;
    int room_number;
} guest;

// Function to check if room is already occupied
int isOccupied(guest* guests, int room_number, int num_guests) {
    for(int i = 0; i < num_guests; i++) {
        if(guests[i].room_number == room_number)
            return 1;
    }
    return 0;
}

int main() {
    int num_guests = 0;
    guest* guests = malloc(num_guests * sizeof(guest)); // Initialize memory for guests

    // Hotel management options loop
    while(1) {
        printf("\nWelcome to the Hotel Management System!\n");
        printf("1) Check In\n");
        printf("2) Check Out\n");
        printf("3) View Occupancy\n");
        printf("4) Exit\n");
        printf("Enter option number: ");

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1: // Check In
                guests = realloc(guests, (num_guests + 1) * sizeof(guest)); // Allocate memory for new guest

                // Get guest's name and room number
                printf("Enter guest name: ");
                scanf(" %[^\n]s", guests[num_guests].name);
                printf("Enter room number: ");
                scanf("%d", &guests[num_guests].room_number);

                // Check if room is already occupied
                while(isOccupied(guests, guests[num_guests].room_number, num_guests)) {
                    printf("This room is already occupied, please choose another: ");
                    scanf("%d", &guests[num_guests].room_number);
                }

                // Get guest's duration of stay
                printf("Enter duration of stay (in days): ");
                scanf("%d", &guests[num_guests].duration);

                printf("%s has successfully checked in to room %d for %d days.\n", guests[num_guests].name, guests[num_guests].room_number, guests[num_guests].duration);

                num_guests++;
                break;

            case 2: // Check Out
                if(num_guests == 0) {
                    printf("There are no guests to check out.\n");
                    break;
                }

                // Get room number of guest checking out
                int room_number;
                printf("Enter room number of guest checking out: ");
                scanf("%d", &room_number);

                // Search for guest by room number and remove them from the list
                for(int i = 0; i < num_guests; i++) {
                    if(guests[i].room_number == room_number) {
                        printf("%s has successfully checked out of room %d after staying for %d days.\n", guests[i].name, guests[i].room_number, guests[i].duration);
                        for(int j = i; j < num_guests - 1; j++)
                            guests[j] = guests[j + 1];
                        guests = realloc(guests, (num_guests - 1) * sizeof(guest));
                        num_guests--;
                        break;
                    }

                    if(i == num_guests - 1)
                        printf("There is no guest who has checked in to room %d.\n", room_number);
                }
                break;

            case 3: // View Occupancy
                if(num_guests == 0) {
                    printf("The hotel is currently empty.\n");
                    break;
                }

                printf("The hotel occupancy is as follows:\n");
                for(int i = 1; i <= 50; i++) {
                    int occupied = 0;
                    for(int j = 0; j < num_guests; j++) {
                        if(guests[j].room_number == i) {
                            printf("%d -> %s (Stay Duration: %d days)\n", i, guests[j].name, guests[j].duration);
                            occupied = 1;
                            break;
                        }
                    }
                    if(!occupied)
                        printf("%d -> Empty\n", i);
                }
                break;

            case 4: // Exit
                printf("Thank you for using the Hotel Management System.\n");
                free(guests); // Free memory before exiting
                return 0;

            default: // Invalid option
                printf("Invalid option, please try again.\n");
        }
    }
}