//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void printMenu() {
    printf("\n\n--------------------\n");
    printf("Appointment Scheduler\n");
    printf("--------------------\n\n");
    printf("1. View Appointments\n");
    printf("2. Schedule Appointment\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n\n");
}

void viewAppointments() {
    printf("\n\n------------\n");
    printf("Appointments\n");
    printf("------------\n\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Appointment %d: %s (%d/%d/%d)\n", i+1, appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year);
    }
    printf("\n");
}

void scheduleAppointment() {
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("\n\nMaximum number of appointments reached. Unable to schedule new appointment.\n\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    int day, month, year;
    printf("\n\n----------\n");
    printf("New Appointment\n");
    printf("----------\n\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Day: ");
    scanf("%d", &day);
    printf("Month: ");
    scanf("%d", &month);
    printf("Year: ");
    scanf("%d", &year);
    appointments[numAppointments].day = day;
    appointments[numAppointments].month = month;
    appointments[numAppointments].year = year;
    strcpy(appointments[numAppointments].name, name);
    numAppointments++;
    printf("\nAppointment scheduled successfully.\n\n");
}

void cancelAppointment() {
    char name[MAX_NAME_LENGTH];
    int day, month, year;
    printf("\n\n-----------\n");
    printf("Cancel Appointment\n");
    printf("-----------\n\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Day: ");
    scanf("%d", &day);
    printf("Month: ");
    scanf("%d", &month);
    printf("Year: ");
    scanf("%d", &year);
    bool appointmentFound = false;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0 && appointments[i].day == day && appointments[i].month == month && appointments[i].year == year) {
            for (int j = i; j < numAppointments-1; j++) {
                appointments[j] = appointments[j+1];
            }
            numAppointments--;
            appointmentFound = true;
            printf("\nAppointment cancelled successfully.\n\n");
            break;
        }
    }
    if (!appointmentFound) {
        printf("\nAppointment not found. Unable to cancel.\n\n");
    }
}

int main() {
    int choice;
    do {
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                viewAppointments();
                break;
            case 2:
                scheduleAppointment();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("\n\nExiting program.\n\n");
                break;
            default:
                printf("\n\nInvalid choice. Please try again.\n\n");
        }
    } while (choice != 4);
    return 0;
}