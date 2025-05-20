//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[30];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

Appointment appArray[MAX_APPOINTMENTS];
int numAppointments = 0;

void displayAppointments() {
    if(numAppointments == 0) {
        printf("No appointments scheduled\n");
    } else {
        printf("Your scheduled appointments:\n");
        printf("Name\t\tDate\t\tTime\n");
        for(int i = 0; i < numAppointments; i++) {
            printf("%-15s %02d/%02d/%4d %02d:%02d\n", appArray[i].name, appArray[i].day, appArray[i].month, appArray[i].year, appArray[i].hour, appArray[i].minute);
        }
    }
}

void scheduleAppointment() {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("No more appointments can be scheduled.\n");
        return;
    }

    Appointment newApp;

    printf("Enter name:\n");
    scanf("%s", newApp.name);

    printf("Enter date (dd/mm/yyyy):\n");
    scanf("%d/%d/%d", &newApp.day, &newApp.month, &newApp.year);

    printf("Enter time (hh:mm):\n");
    scanf("%d:%d", &newApp.hour, &newApp.minute);

    if (newApp.day < 1 || newApp.day > 31 || newApp.month < 1 || newApp.month > 12 || newApp.year < 2021) {
        printf("Invalid date. Appointment not scheduled.\n");
        return;
    }

    if (newApp.hour < 0 || newApp.hour > 23 || newApp.minute < 0 || newApp.minute > 59) {
        printf("Invalid time. Appointment not scheduled.\n");
        return;
    }

    appArray[numAppointments] = newApp;
    numAppointments++;

    printf("Appointment scheduled successfully.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\nAppointments Scheduler\n");
        printf("1. Schedule appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3):\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}