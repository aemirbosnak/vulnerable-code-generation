//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

// Struct for Appointment
typedef struct {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

// Global variables
Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

// Function to display menu
void displayMenu() {
    printf("\nWelcome to the Appointment Scheduler!\n\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n\n");
}

// Function to add appointment
void addAppointment() {
    Appointment a;

    printf("\nPlease enter the following information:\n");
    printf("Name: ");
    scanf("%s", a.name);

    printf("Day (1-31): ");
    scanf("%d", &a.day);

    printf("Month (1-12): ");
    scanf("%d", &a.month);

    printf("Year: ");
    scanf("%d", &a.year);

    printf("Hour (0-23): ");
    scanf("%d", &a.hour);

    printf("Minute (0-59): ");
    scanf("%d", &a.minute);

    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    if (a.year < timeinfo->tm_year + 1900) {
        printf("Error: You cannot add an appointment for a past year.\n\n");
    } else if (a.year == timeinfo->tm_year + 1900) {
        if (a.month < timeinfo->tm_mon + 1) {
            printf("Error: You cannot add an appointment for a past month.\n\n");
        } else if (a.month == timeinfo->tm_mon + 1) {
            if (a.day < timeinfo->tm_mday) {
                printf("Error: You cannot add an appointment for a past day.\n\n");
            } else if (a.day == timeinfo->tm_mday) {
                if (a.hour < timeinfo->tm_hour) {
                    printf("Error: You cannot add an appointment for a past hour.\n\n");
                } else if (a.hour == timeinfo->tm_hour) {
                    if (a.minute < timeinfo->tm_min) {
                        printf("Error: You cannot add an appointment for a past minute.\n\n");
                    } else {
                        appointments[numAppointments++] = a;
                        printf("\nAppointment added successfully!\n\n");
                    }
                } else {
                    appointments[numAppointments++] = a;
                    printf("\nAppointment added successfully!\n\n");
                }
            } else {
                appointments[numAppointments++] = a;
                printf("\nAppointment added successfully!\n\n");
            }
        } else {
            appointments[numAppointments++] = a;
            printf("\nAppointment added successfully!\n\n");
        }
    } else {
        appointments[numAppointments++] = a;
        printf("\nAppointment added successfully!\n\n");
    }
}

// Function to view appointments
void viewAppointments() {
    if (numAppointments == 0) {
        printf("\nNo appointments scheduled!\n\n");
    } else {
        printf("\nAppointment\t\tDate/Time\n");
        printf("----------------------------------------\n");
        for (int i = 0; i < numAppointments; i++) {
            printf("%s\t\t", appointments[i].name);
            printf("%d/%d/%d ", appointments[i].day, appointments[i].month, appointments[i].year);
            printf("%02d:%02d\n", appointments[i].hour, appointments[i].minute);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("\nExiting program. Thank you for using Appointment Scheduler!\n\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n\n");
                break;
        }

    } while (choice != 3);

    return 0;
}