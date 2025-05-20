//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>

int main()
{
    int num_rooms = 10;
    int num_guests = 0;
    int check_in_date = 1;
    int check_out_date = 0;
    int price_per_night = 100;

    while (num_guests < num_rooms)
    {
        printf("Check-in date (enter -1 to exit): ");
        scanf("%d", &check_in_date);

        printf("Check-out date (enter -1 to exit): ");
        scanf("%d", &check_out_date);

        if (check_in_date!= -1 && check_out_date!= -1)
        {
            if (check_out_date < check_in_date)
            {
                printf("Invalid check-out date. Please enter a date after the check-in date.\n");
            }
            else
            {
                int total_nights = check_out_date - check_in_date + 1;
                int total_price = total_nights * price_per_night;

                printf("Check-in date: %d\n", check_in_date);
                printf("Check-out date: %d\n", check_out_date);
                printf("Total nights: %d\n", total_nights);
                printf("Total price: %d\n", total_price);

                num_guests++;
            }
        }
        else if (check_in_date == -1)
        {
            printf("No more rooms available. Please try again later.\n");
        }
        else
        {
            printf("Invalid input. Please enter a valid date.\n");
        }
    }

    printf("Total guests: %d\n", num_guests);

    return 0;
}