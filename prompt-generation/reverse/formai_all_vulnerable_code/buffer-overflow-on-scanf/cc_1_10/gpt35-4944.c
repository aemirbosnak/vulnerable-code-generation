//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a struct to store appointments
typedef struct {
    int day;
    int month;
    int year;
    char description[100];
} Appointment;

// Define global variables
Appointment appointments[100];
int numAppointments = 0;

// Function to add an appointment to the schedule
void addAppointment() {
    // Prompt the user for appointment details
    printf("Please enter the date of the appointment (DD MM YYYY):\n");
    scanf("%d %d %d", &appointments[numAppointments].day, &appointments[numAppointments].month, &appointments[numAppointments].year);
    printf("Please enter a description of the appointment:\n");
    scanf(" %[^\n]", appointments[numAppointments].description);
    numAppointments++;
    printf("Appointment added to schedule.\n");
}

// Function to display the schedule
void displaySchedule() {
    if (numAppointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d/%d/%d - %s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].description);
    }
}

// Function to search for appointments on a certain date
void searchAppointments() {
    int searchDay, searchMonth, searchYear;
    printf("Please enter the date you want to search for (DD MM YYYY):\n");
    scanf("%d %d %d", &searchDay, &searchMonth, &searchYear);
    bool foundAppointment = false;
    for (int i = 0; i < numAppointments; i++) {
        if (appointments[i].day == searchDay && appointments[i].month == searchMonth && appointments[i].year == searchYear) {
            printf("%d/%d/%d - %s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].description);
            foundAppointment = true;
        }
    }
    if (!foundAppointment) {
        printf("No appointments scheduled on that day.\n");
    }
}

int main() {
    int choice;
    while (true) {
        printf("\nAppointment Scheduler\n");
        printf("========================\n");
        printf("Please select an option:\n");
        printf("1. Add an Appointment\n");
        printf("2. Display Schedule\n");
        printf("3. Search Appointments\n");
        printf("4. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                displaySchedule();
                break;
            case 3:
                searchAppointments();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}