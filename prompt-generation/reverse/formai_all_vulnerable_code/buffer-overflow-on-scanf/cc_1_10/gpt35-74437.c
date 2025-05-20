//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10

// Define appointment structure
typedef struct {
    int day;
    int month;
    int year;
    char time[6];
    char description[50];
} Appointment;

// Define function prototypes
void addAppointment(Appointment* appointments, int* count);
void viewAppointments(Appointment* appointments, int count);

int main()
{
    // Initialize variables
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    // Display welcome message and menu options
    printf("Welcome to the Appointment Scheduler!\n");
    printf("\nMENU\n");
    printf("1. Add an appointment\n");
    printf("2. View appointments\n");
    printf("3. Exit\n");

    // Loop until user chooses to exit
    while (true) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAppointment(appointments, &count);
            break;
        case 2:
            viewAppointments(appointments, count);
            break;
        case 3:
            printf("\nThank you for using the Appointment Scheduler!\n");
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addAppointment(Appointment* appointments, int* count)
{
    // Check if there is space for another appointment
    if (*count == MAX_APPOINTMENTS) {
        printf("\nNo more appointments can be scheduled.\n");
        return;
    }

    // Prompt user for appointment details
    printf("\nEnter appointment details:\n");

    printf("Day: ");
    scanf("%d", &appointments[*count].day);

    printf("Month: ");
    scanf("%d", &appointments[*count].month);

    printf("Year: ");
    scanf("%d", &appointments[*count].year);

    printf("Time (HH:MM): ");
    scanf("%s", appointments[*count].time);

    printf("Description: ");
    scanf("%s", appointments[*count].description);

    // Increment appointment count and display success message
    (*count)++;
    printf("\nAppointment added!\n");
}

void viewAppointments(Appointment* appointments, int count)
{
    // Check if there are no appointments
    if (count == 0) {
        printf("\nThere are no appointments scheduled.\n");
        return;
    }

    // Display appointments
    printf("\nAppointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d/%d/%d\t%s\t%s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].time, appointments[i].description);
    }
}