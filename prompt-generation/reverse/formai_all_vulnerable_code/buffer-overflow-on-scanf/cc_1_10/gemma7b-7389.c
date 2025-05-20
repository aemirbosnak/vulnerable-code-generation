//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void shock_hotel_management_system()
{
    system("clear");
    printf("WELCOME TO THE SHOCKING HOTEL MANAGEMENT SYSTEM!\n");
    printf("----------------------------------------\n");
    printf("Please select an option:\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");
    printf("3. View Rooms\n");
    printf("4. Manage Reservations\n");
    printf("5. Exit\n");

    int choice = 0;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You have chosen to check in. Please provide your name, room number, and number of guests.\n");
            char name[20];
            int room_number;
            int num_guests;
            scanf("%s %d %d", name, &room_number, &num_guests);

            printf("Congratulations, %s! You have successfully checked in to room %d.\n", name, room_number);
            break;

        case 2:
            printf("You have chosen to check out. Please provide your name and room number.\n");
            char name_out[20];
            int room_number_out;
            scanf("%s %d", name_out, &room_number_out);

            printf("Goodbye, %s. We hope you enjoyed your stay at the Shocking Hotel.\n", name_out);
            break;

        case 3:
            printf("You have chosen to view rooms. Please select a room type:\n");
            printf("1. Standard Room\n");
            printf("2. Deluxe Room\n");
            printf("3. Suite\n");

            int room_type = 0;
            scanf("%d", &room_type);

            switch (room_type)
            {
                case 1:
                    printf("Standard Room: $50 per night.\n");
                    break;

                case 2:
                    printf("Deluxe Room: $75 per night.\n");
                    break;

                case 3:
                    printf("Suite: $100 per night.\n");
                    break;
            }
            break;

        case 4:
            printf("You have chosen to manage reservations. Please select an action:\n");
            printf("1. Create a reservation\n");
            printf("2. Modify a reservation\n");
            printf("3. Cancel a reservation\n");

            int action = 0;
            scanf("%d", &action);

            switch (action)
            {
                case 1:
                    printf("Please provide your name, room number, and the number of guests.\n");
                    char name_res[20];
                    int room_number_res;
                    int num_guests_res;
                    scanf("%s %d %d", name_res, &room_number_res, &num_guests_res);

                    printf("Your reservation has been created, %s. You have booked room %d for %d guests.\n", name_res, room_number_res, num_guests_res);
                    break;

                case 2:
                    printf("Please provide your name, room number, and the new number of guests.\n");
                    char name_mod[20];
                    int room_number_mod;
                    int num_guests_mod;
                    scanf("%s %d %d", name_mod, &room_number_mod, &num_guests_mod);

                    printf("Your reservation has been modified, %s. You have booked room %d for %d guests.\n", name_mod, room_number_mod, num_guests_mod);
                    break;

                case 3:
                    printf("Please provide your name and room number.\n");
                    char name_cancel[20];
                    int room_number_cancel;
                    scanf("%s %d", name_cancel, &room_number_cancel);

                    printf("Your reservation has been canceled, %s. We hope you had a pleasant stay.\n", name_cancel);
                    break;
            }
            break;

        case 5:
            printf("Thank you for using the Shocking Hotel Management System. Goodbye!\n");
            break;
    }

    shock_hotel_management_system();
}

int main()
{
    shock_hotel_management_system();

    return 0;
}