//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdbool.h>

struct Appointment
{
    int day;
    int month;
    int year;
    char name[50];
    char description[200];
};

bool isDateValid(int day, int month, int year)
{
    if (year < 1900 || year > 2100)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    if (month == 2)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            return day <= 29;
        else
            return day <= 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return day <= 30;
    return day <= 31;
}

void printAppointment(struct Appointment* appointment)
{
    printf("Name: %s\n", appointment->name);
    printf("Date: %02d/%02d/%d\n", appointment->day, appointment->month, appointment->year);
    printf("Description: %s\n", appointment->description);
}

int main()
{
    int count;
    printf("Enter the number of appointments: ");
    scanf("%d", &count);

    struct Appointment appointments[count];
    int appointmentCount = 0;

    while (appointmentCount < count)
    {
        int day, month, year;
        printf("\nEnter appointment date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &day, &month, &year);
        if (!isDateValid(day, month, year))
        {
            printf("Invalid date! Please try again\n");
            continue;
        }

        bool alreadyScheduled = false;
        for (int i = 0; i < appointmentCount; i++)
        {
            if (appointments[i].day == day && appointments[i].month == month && appointments[i].year == year)
            {
                alreadyScheduled = true;
                break;
            }
        }

        if (alreadyScheduled)
        {
            printf("There is already an appointment scheduled for this date! Please select a different date.\n");
            continue;
        }

        printf("Enter name: ");
        scanf(" %[^\n]s", appointments[appointmentCount].name);

        printf("Enter description: ");
        scanf(" %[^\n]s", appointments[appointmentCount].description);

        appointments[appointmentCount].day = day;
        appointments[appointmentCount].month = month;
        appointments[appointmentCount].year = year;

        appointmentCount++;
    }

    printf("\nAll Appointments:\n");
    for (int i = 0; i < appointmentCount; i++)
    {
        printf("\n%d)\n", i+1);
        printAppointment(&appointments[i]);
    }

    return 0;
}