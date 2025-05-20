//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {

    int choice;
    int room[3] = {0, 0, 0};
    int guests[3] = {0, 0, 0};
    char room_type[3][10] = {"Single", "Double", "Suite"};
    float cost[3] = {1000.0, 1500.0, 2000.0};

    printf("Welcome to C Hotel Management System!\n");
    do {
        printf("\nWhat would you like to do today?\n");
        printf("1. Book a room\n");
        printf("2. Check-in guests\n");
        printf("3. Check-out guests\n");
        printf("4. Display room status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nChoose a room type:\n");
                printf("1. Single (%.2f per night)\n", cost[0]);
                printf("2. Double (%.2f per night)\n", cost[1]);
                printf("3. Suite (%.2f per night)\n", cost[2]);

                int room_choice;
                printf("\nEnter your choice: ");
                scanf("%d", &room_choice);

                if (room[room_choice - 1] == 1) {
                    printf("\nSorry, this room is already booked.\n");
                } else {
                    printf("\nRoom booking successful. Your room type is %s and your room number is %d.\n", room_type[room_choice - 1], room_choice);
                    room[room_choice - 1] = 1;
                }
                break;
            case 2:
                printf("\nEnter the room number for check-in: ");
                int checkin_room;
                scanf("%d", &checkin_room);

                if (room[checkin_room - 1] == 0) {
                    printf("\nThis room is not booked yet.\n");
                } else {
                    printf("\nEnter the number of guests: ");
                    scanf("%d", &guests[checkin_room - 1]);
                    printf("\nCheck-in successful. Enjoy your stay!\n");
                }
                break;
            case 3:
                printf("\nEnter the room number for check-out: ");
                int checkout_room;
                scanf("%d", &checkout_room);

                if (room[checkout_room - 1] == 0) {
                    printf("\nThis room is not booked yet.\n");
                } else {
                    printf("\nCheck-out successful. Your bill amount is %.2f.\n", cost[checkout_room - 1] * guests[checkout_room - 1]);
                    room[checkout_room - 1] = 0;
                    guests[checkout_room - 1] = 0;
                }
                break;
            case 4:
                printf("\nRoom\tType\tGuests\tCost\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d\t%s\t%d\t%.2f\n", i + 1, room_type[i], guests[i], cost[i]);
                }
                break;
            case 5:
                printf("\nThank you for using C Hotel Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}