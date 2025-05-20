//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_APPTS 5 //maximum number of appointments allowed in a day
#define MAX_NAME_LEN 20 //maximum length of name of an appointment holder
typedef struct appointment
{
    char name[MAX_NAME_LEN];
    int hour;
    int minute;
} appt_t;
typedef struct calendar_day
{
    appt_t appts[MAX_APPTS];
    int num_appts;
} calendar_day_t;
void print_calendar_day(calendar_day_t *day)
{
    printf("Number of appointments in the day: %d\n", day->num_appts);
    for (int i = 0; i < day->num_appts; i++)
    {
        printf("Appointment %d:\n", i + 1);
        printf("\tName: %s\n", day->appts[i].name);
        printf("\tTime: %d:%02d\n", day->appts[i].hour, day->appts[i].minute);
    }
}
int check_calendar_conflict(calendar_day_t *day, int hour, int minute)
{
    for (int i = 0; i < day->num_appts; i++)
    {
        if ((hour == day->appts[i].hour) && (minute == day->appts[i].minute))
            return 1;
    }
    return 0;
}
void add_appt_to_calendar_day(calendar_day_t *day, char *name, int hour, int minute)
{
    if (day->num_appts < MAX_APPTS)
    {
        int conflict = check_calendar_conflict(day, hour, minute);
        if (!conflict)
        {
            strcpy(day->appts[day->num_appts].name, name);
            day->appts[day->num_appts].hour = hour;
            day->appts[day->num_appts].minute = minute;
            day->num_appts++;
        }
        else
        {
            printf("There is an appointment at that time. Please choose a different time.\n");
        }
    }
    else
    {
        printf("Maximum number of appointments reached for this day.\n");
    }
}
int main()
{
    calendar_day_t day;
    day.num_appts = 0;

    printf("Welcome to the Appointment Scheduler.\n");
    printf("You can add up to %d appointments for the day.\n", MAX_APPTS);
    int finished = 0;
    while (!finished)
    {
        int choice;
        printf("Choose an option:\n");
        printf("1. Add an appointment\n");
        printf("2. View appointments\n");
        printf("3. Quit\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the name for the appointment: ");
            char name[MAX_NAME_LEN];
            scanf("%s", name);

            printf("Enter the hour for the appointment (0-23): ");
            int hour;
            scanf("%d", &hour);

            printf("Enter the minute for the appointment (0-59): ");
            int minute;
            scanf("%d", &minute);

            add_appt_to_calendar_day(&day, name, hour, minute);
            break;
        case 2:
            print_calendar_day(&day);
            break;
        case 3:
            finished = 1;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}