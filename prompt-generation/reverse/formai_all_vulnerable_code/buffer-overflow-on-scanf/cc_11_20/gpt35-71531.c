//FormAI DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello and welcome to the Happy Hotel Management System!\n");
    printf("Please enter the number of rooms in the hotel: ");
    int num_rooms;
    scanf("%d", &num_rooms);

    int* room_numbers = (int*)malloc(num_rooms * sizeof(int));
    char** occupant_names = (char**)malloc(num_rooms * sizeof(char*));
    int* room_rates = (int*)malloc(num_rooms * sizeof(int));
    int* room_statuses = (int*)calloc(num_rooms, sizeof(int));

    for (int i = 0; i < num_rooms; i++) {
        printf("Enter the room number for room #%d: ", i+1);
        scanf("%d", &room_numbers[i]);
        printf("Enter the name of the occupant for room #%d: ", i+1);
        occupant_names[i] = (char*)malloc(50 * sizeof(char)); // assume max name length of 50 characters
        scanf("%s", occupant_names[i]);
        printf("Enter the nightly rate for room #%d: ", i+1);
        scanf("%d", &room_rates[i]);
        printf("\n");
    }

    printf("Thank you for entering the room information. Here are the available options:\n");
    printf("1. Check-in a guest\n");
    printf("2. Check-out a guest\n");
    printf("3. View room status\n");
    printf("4. View room charges\n");
    printf("5. Exit the program\n");

    int choice = 0;
    while (1) {
        printf("Please enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Please enter the room number for check-in: ");
            int room_num;
            scanf("%d", &room_num);

            int room_index = -1;
            for (int i = 0; i < num_rooms; i++) {
                if (room_numbers[i] == room_num) {
                    room_index = i;
                    break;
                }
            }

            if (room_index == -1) {
                printf("Sorry, we could not find a room with that number.\n");
            } else if (room_statuses[room_index] == 1) {
                printf("Sorry, that room is already occupied.\n");
            } else {
                printf("Please enter the name of the guest for check-in: ");
                scanf("%s", occupant_names[room_index]);
                printf("Please enter the number of nights for the stay: ");
                int num_nights;
                scanf("%d", &num_nights);
                room_statuses[room_index] = 1;
                printf("Thank you for checking in! Your total charges will be $%d.\n", num_nights * room_rates[room_index]);
            }
        } else if (choice == 2) {
            printf("Please enter the room number for check-out: ");
            int room_num;
            scanf("%d", &room_num);

            int room_index = -1;
            for (int i = 0; i < num_rooms; i++) {
                if (room_numbers[i] == room_num) {
                    room_index = i;
                    break;
                }
            }

            if (room_index == -1) {
                printf("Sorry, we could not find a room with that number.\n");
            } else if (room_statuses[room_index] == 0) {
                printf("Sorry, that room is not currently occupied.\n");
            } else {
                room_statuses[room_index] = 0;
                printf("Thank you for checking out! We hope you enjoyed your stay.\n");
            }
        } else if (choice == 3) {
            printf("Available rooms:\n");
            for (int i = 0; i < num_rooms; i++) {
                if (room_statuses[i] == 0) {
                    printf("Room #%d: Available\n", room_numbers[i]);
                } else {
                    printf("Room #%d: Occupied by %s\n", room_numbers[i], occupant_names[i]);
                }
            }
        } else if (choice == 4) {
            printf("Room charges:\n");
            for (int i = 0; i < num_rooms; i++) {
                printf("Room #%d: $%d per night\n", room_numbers[i], room_rates[i]);
            }
        } else if (choice == 5) {
            printf("Thank you for using the Happy Hotel Management System!\n");
            break;
        } else {
            printf("Invalid choice entered. Please try again.\n");
        }
    }

    free(room_numbers);
    for (int i = 0; i < num_rooms; i++) {
        free(occupant_names[i]);
    }
    free(occupant_names);
    free(room_rates);
    free(room_statuses);

    return 0;
}