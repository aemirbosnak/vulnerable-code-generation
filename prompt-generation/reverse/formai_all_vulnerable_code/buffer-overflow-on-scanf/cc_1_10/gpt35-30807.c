//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// maximum number of appointments
#define MAX_APPNTS 10

// struct to hold appointment data
typedef struct {
    int day;
    int hour;
    char subject[50];
} Appointment;

// array to hold appointments
Appointment appnts[MAX_APPNTS];

// check if given day and time slot is already booked
bool isBooked(int day, int hour) {
    for (int i = 0; i < MAX_APPNTS; i++) {
        if (appnts[i].day == day && appnts[i].hour == hour) {
            return true;
        }
    }
    return false;
}

// schedule an appointment
void scheduleAppointment() {
    int day, hour;

    printf("Enter the day (1-30): ");
    scanf("%d", &day);
    while (day < 1 || day > 30) {
        printf("Invalid day. Enter again (1-30): ");
        scanf("%d", &day);
    }

    printf("Enter the hour (9-16): ");
    scanf("%d", &hour);
    while (hour < 9 || hour > 16) {
        printf("Invalid hour. Enter again (9-16): ");
        scanf("%d", &hour);
    }

    if (isBooked(day, hour)) {
        printf("Sorry, that time slot is already booked.\n");
        return;
    }

    Appointment appt;
    appt.day = day;
    appt.hour = hour;

    printf("Enter the subject of the appointment: ");
    scanf(" %[^\n]s", appt.subject);

    for (int i = 0; i < MAX_APPNTS; i++) {
        if (appnts[i].day == 0) {
            appnts[i] = appt;
            printf("Appointment scheduled successfully on day %d at hour %d.\n", day, hour);
            return;
        }
    }

    printf("Sorry, the maximum number of appointments have been reached.\n");
}

// cancel an appointment
void cancelAppointment() {
    int day, hour;

    printf("Enter the day (1-30) of the appointment to cancel: ");
    scanf("%d", &day);

    printf("Enter the hour (9-16) of the appointment to cancel: ");
    scanf("%d", &hour);

    bool found = false;
    for (int i = 0; i < MAX_APPNTS; i++) {
        if (appnts[i].day == day && appnts[i].hour == hour) {
            appnts[i].day = 0;
            appnts[i].hour = 0;
            printf("Appointment on day %d at hour %d has been cancelled.\n", day, hour);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Sorry, no appointment found on day %d at hour %d.\n", day, hour);
    }
}

// display all appointments
void displayAppointments() {
    printf("Upcoming Appointments:\n");

    bool hasAppnt = false;
    for (int i = 0; i < MAX_APPNTS; i++) {
        if (appnts[i].day != 0) {
            printf("Day %d at hour %d: %s\n", appnts[i].day, appnts[i].hour, appnts[i].subject);
            hasAppnt = true;
        }
    }

    if (!hasAppnt) {
        printf("No appointments scheduled.\n");
    }
}

// main function
int main() {
    int choice;

    while (1) {
        printf("\n1. Schedule Appointment\n2. Cancel Appointment\n3. Display Appointments\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scheduleAppointment();
                break;
            case 2:
                cancelAppointment();
                break;
            case 3:
                displayAppointments();
                break;
            case 4:
                printf("Thank you! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}