//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining the maximum number of appointments available per day
#define MAX_APPOINTMENTS 10

// Defining the number of possible appointment slots per hour
#define APPOINTMENT_SLOTS 4

// Defining the maximum number of hours available per day
#define MAX_HOURS 8

// Defining the maximum number of days available to schedule appointments
#define MAX_DAYS 30

int main()
{
    // Initializing variables for storing appointment data
    int appointments[MAX_APPOINTMENTS][3];
    int num_appointments = 0;

    // Initializing variables for scheduling
    int day, hour, minute, duration;
    char name[50];

    // Initializing variables for displaying schedule
    int num_slots[MAX_HOURS * APPOINTMENT_SLOTS] = {0};
    int total_slots = 0;

    // Generating seed value for random number generation
    srand(time(NULL));

    // Looping through each day to schedule appointments
    for(day = 1; day <= MAX_DAYS; day++)
    {
        // Determining the number of appointments to schedule for the day
        int max_appointments = rand() % (MAX_APPOINTMENTS + 1 - num_appointments);

        printf("\nScheduling for Day %d\n", day);

        // Looping through each appointment to be scheduled
        for(int i = 0; i < max_appointments; i++)
        {
            // Prompting user for appointment details
            printf("\nEnter appointment details:\n");
            printf("Name: ");
            scanf("%s", name);
            printf("Duration (minutes): ");
            scanf("%d", &duration);

            // Checking if duration is a multiple of appointment slots
            if(duration % (60/APPOINTMENT_SLOTS) != 0)
            {
                printf("Duration must be a multiple of %d minutes.\n", 60/APPOINTMENT_SLOTS);
                continue;
            }

            // Converting duration to appointment slots
            duration /= (60/APPOINTMENT_SLOTS);

            // Setting available appointment slots to 0 for scheduled time
            for(int j = 0; j < duration; j++)
            {
                int slot = -1;

                do
                {
                    // Determining a random available time slot
                    slot = rand() % (MAX_HOURS * APPOINTMENT_SLOTS);

                }while(num_slots[slot] != 0);

                // Storing appointment data for scheduled time slot
                appointments[num_appointments + i][0] = day;
                appointments[num_appointments + i][1] = slot / APPOINTMENT_SLOTS;
                appointments[num_appointments + i][2] = slot % APPOINTMENT_SLOTS;
                
                // Incrementing slots for scheduled time
                num_slots[slot] = 1;
                total_slots++;
            }

            // Incrementing number of scheduled appointments
            num_appointments++;

            // Displaying appointment confirmation
            printf("\nAppointment scheduled for %s on Day %d from %d:%02d to %d:%02d.\n", 
                name, day, appointments[num_appointments + i][1], appointments[num_appointments + i][2] * (60/APPOINTMENT_SLOTS),
                (appointments[num_appointments + i][1] + duration), appointments[num_appointments + i][2] * (60/APPOINTMENT_SLOTS));
        }
    }

    // Displaying appointment schedule
    printf("\nAppointment Schedule:\n");

    for(hour = 0; hour < MAX_HOURS; hour++)
    {
        for(int slot = 0; slot < APPOINTMENT_SLOTS; slot++)
        {
            char time_slot[10];
            sprintf(time_slot, "%d:%02d", hour, slot * (60/APPOINTMENT_SLOTS));

            printf("%-8s", time_slot);

            for(day = 1; day <= MAX_DAYS; day++)
            {
                int scheduled = 0;

                for(int i = 0; i < num_appointments; i++)
                {
                    if(appointments[i][0] == day &&
                       appointments[i][1] == hour && 
                       appointments[i][2] == slot)
                    {
                        printf("%-16s", "X");
                        scheduled = 1;
                        break;
                    }
                }

                if(scheduled == 0)
                {
                    printf("%-16s", "");
                }
            }

            printf("\n");
        }
    }

    // Displaying appointment statistics
    printf("\nTotal Appointments: %d\n", num_appointments);
    printf("Total Slots Available: %d\n", MAX_DAYS * MAX_HOURS * APPOINTMENT_SLOTS);
    printf("Total Slots Scheduled: %d\n", total_slots);
    printf("Percentage of Slots Filled: %.2f%%\n", ((float)total_slots / (MAX_DAYS * MAX_HOURS * APPOINTMENT_SLOTS)) * 100);

    return 0;
}