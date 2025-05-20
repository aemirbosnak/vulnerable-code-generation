//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment
{
    char name[50];
    char time[50];
    char date[50];
} Appointment;

Appointment appointments[MAX_Appointments];

void displayAppointments()
{
    for (int i = 0; i < MAX_Appointments; i++)
    {
        if (appointments[i].name[0] != '\0')
        {
            printf("Name: %s, Time: %s, Date: %s\n", appointments[i].name, appointments[i].time, appointments[i].date);
        }
    }
}

void addAppointment()
{
    int i = 0;
    for (; appointments[i].name[0] != '\0'; i++) {}

    printf("Enter name: ");
    scanf("%s", appointments[i].name);

    printf("Enter time: ");
    scanf("%s", appointments[i].time);

    printf("Enter date: ");
    scanf("%s", appointments[i].date);

    appointments[i].name[0] = '\0';
}

void main()
{
    int choice;

    printf("Welcome to the Future Appointment Scheduler!\n");

    displayAppointments();

    printf("Enter 1 to add an appointment, 2 to display appointments, or 3 to exit: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            addAppointment();
            break;
        case 2:
            displayAppointments();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid input.\n");
    }

    main();
}