//FormAI DATASET v1.0 Category: Hotel Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 30

struct guest {
    char name[MAX_NAME_LENGTH];
    int room_number;
};

int main() {
    int menu_choice = 0;
    int room_number = 0;
    char guest_name[MAX_NAME_LENGTH];
    struct guest hotel_guests[MAX_ROOMS];
    int num_guests = 0;

    while (menu_choice != 4) {
        printf("Welcome to the C Hotel Management System\n");
        printf("----------------------------------------\n");
        printf("1. Add guest\n");
        printf("2. Remove guest\n");
        printf("3. Print guest list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &menu_choice);
        switch (menu_choice) {
            case 1: // Add guest
                if (num_guests == MAX_ROOMS) {
                    printf("The hotel is full\n");
                    break;
                }

                printf("Enter guest name: ");
                scanf("%s", guest_name);

                printf("Enter room number: ");
                scanf("%d", &room_number);

                // Check if room is already occupied
                for (int i = 0; i < num_guests; i++) {
                    if (hotel_guests[i].room_number == room_number) {
                        printf("Room %d is already occupied by %s\n", room_number, hotel_guests[i].name);
                        break;
                    }
                }

                struct guest new_guest;
                strcpy(new_guest.name, guest_name);
                new_guest.room_number = room_number;
                hotel_guests[num_guests] = new_guest;
                num_guests++;

                printf("Added %s to room %d\n", new_guest.name, new_guest.room_number);
                break;

            case 2: // Remove guest
                printf("Enter room number: ");
                scanf("%d", &room_number);

                for (int i = 0; i < num_guests; i++) {
                    if (hotel_guests[i].room_number == room_number) {
                        printf("Removed guest %s from room %d\n", hotel_guests[i].name, hotel_guests[i].room_number);
                        // Shift all guests above the removed one down by one
                        for (int j = i; j < num_guests - 1; j++) {
                            hotel_guests[j] = hotel_guests[j + 1];
                        }
                        num_guests--;
                        break;
                    }
                }
                break;

            case 3: // Print guest list
                printf("Guest List:\n");
                for (int i = 0; i < num_guests; i++) {
                    printf("%s\t%d\n", hotel_guests[i].name, hotel_guests[i].room_number);
                }
                break;

            case 4: // Quit
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice, please select 1-4.\n");
                break;
        }
    }

    return 0;
}