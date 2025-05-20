//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    char name[20], date[11], time[5];
    int hour, minute, slot, available = 1;

    printf("Welcome to the Galactic Appointment Scheduler!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Enter the date (MM/DD/YY): ");
    scanf("%s", date);

    printf("Choose the time (HH:MM): ");
    scanf("%s", time);

    printf("Enter the hour: ");
    scanf("%d", &hour);

    printf("Enter the minute: ");
    scanf("%d", &minute);

    printf("Select a slot (1-10): ");
    scanf("%d", &slot);

    switch (slot)
    {
        case 1:
            if (hour == 9 && minute == 0)
            {
                available = 0;
                printf("Sorry, that slot is not available.");
            }
            else
            {
                printf("Your appointment is scheduled for: ");
                printf("%s, %s, %s, slot %d", name, date, time, slot);
            }
            break;
        case 2:
            if (hour == 10 && minute == 0)
            {
                available = 0;
                printf("Sorry, that slot is not available.");
            }
            else
            {
                printf("Your appointment is scheduled for: ");
                printf("%s, %s, %s, slot %d", name, date, time, slot);
            }
            break;
        case 3:
            if (hour == 11 && minute == 0)
            {
                available = 0;
                printf("Sorry, that slot is not available.");
            }
            else
            {
                printf("Your appointment is scheduled for: ");
                printf("%s, %s, %s, slot %d", name, date, time, slot);
            }
            break;
        default:
            printf("Invalid slot number.");
    }

    if (available)
    {
        printf("Thank you, %s, for scheduling your appointment. We look forward to seeing you!", name);
    }

    return 0;
}