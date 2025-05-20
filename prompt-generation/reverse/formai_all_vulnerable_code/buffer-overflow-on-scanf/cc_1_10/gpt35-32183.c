//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Declare global constants
#define MAX_APPOINTMENTS 100
const int WORKING_HOURS_START = 9;
const int WORKING_HOURS_END = 17;

// Declare global variables
struct Appointment {
    int hour;
    int minutes;
    char name[50];
    char reminder[30];
};

int numberOfAppointments = 0;
struct Appointment Schedule[MAX_APPOINTMENTS];

// Declare functions
void AddAppointment();
void ViewSchedule();
void RemindAppointment();

int main() {
    char choice;
    printf("\nWelcome to the Funny Appointment Scheduler!\n\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Appointment\n");
        printf("2. View Schedule\n");
        printf("3. Check Appointment Reminder\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%c", &choice);
        fflush(stdin);

        switch (choice) {
            case '1':
                AddAppointment();
                break;
            case '2':
                ViewSchedule();
                break;
            case '3':
                RemindAppointment();
                break;
            case '4':
                printf("\nGoodbye and thanks for using the Funny Appointment Scheduler!\n\n");
                break;
            default:
                printf("\nInvalid choice entered! Please try again.\n\n");
                break;
        }

    } while (choice != '4');

    return 0;
}

void AddAppointment() {
    printf("\nAdding an appointment:\n");

    if (numberOfAppointments >= MAX_APPOINTMENTS) {
        printf("\nNo more appointments can be added!\n\n");
        return;
    }

    printf("\nEnter name of appointment holder (max 50 characters): ");
    scanf("%[^\n]s", &Schedule[numberOfAppointments].name);
    fflush(stdin);

    printf("Enter hour of appointment (in 24-hours format, e.g. 13 for 1PM): ");
    scanf("%d", &Schedule[numberOfAppointments].hour);
    fflush(stdin);

    printf("Enter minutes of appointment (e.g. 30 for half past the hour): ");
    scanf("%d", &Schedule[numberOfAppointments].minutes);
    fflush(stdin);

    printf("Enter a reminder of appointment (max 30 characters): ");
    scanf("%[^\n]s", &Schedule[numberOfAppointments].reminder);
    fflush(stdin);

    if (Schedule[numberOfAppointments].hour < WORKING_HOURS_START ||
        Schedule[numberOfAppointments].hour > WORKING_HOURS_END) {
        printf("\nYou are trying to schedule outside working hours! Appointment not added.\n\n");
        return;
    }

    printf("\nAppointment successfully added!\n\n");

    numberOfAppointments++;
}

void ViewSchedule() {
    printf("\nViewing the appointment schedule:\n");

    if (numberOfAppointments == 0) {
        printf("\nNo appointments scheduled!\n\n");
        return;
    }

    printf("\nHere is the appointment schedule:\n");
    printf("+---+------------+---------+----------------------+--------------+\n");
    printf("| # | Time       | Name    | Reminder             | Status       |\n");
    printf("+---+------------+---------+----------------------+--------------+\n");

    for (int i = 0; i < numberOfAppointments; i++) {
        printf("| %d | %02d:%02d     | %-7s | %-20s | Scheduled    |\n",
            i+1, Schedule[i].hour, Schedule[i].minutes, Schedule[i].name, Schedule[i].reminder);
    }

    printf("+---+------------+---------+----------------------+--------------+\n\n");
}

void RemindAppointment() {
    printf("\nChecking any appointment reminders:\n");

    if (numberOfAppointments == 0) {
        printf("\nNo appointments scheduled!\n\n");
        return;
    }

    printf("\nHere are the appointment reminders:\n");
    printf("+---+------------+---------+----------------------+\n");
    printf("| # | Time       | Name    | Reminder             |\n");
    printf("+---+------------+---------+----------------------+\n");

    for (int i = 0; i < numberOfAppointments; i++) {
        printf("| %d | %02d:%02d     | %-7s | %-20s |\n",
            i+1, Schedule[i].hour, Schedule[i].minutes, Schedule[i].name, Schedule[i].reminder);
    }

    printf("+---+------------+---------+----------------------+\n");

    for (int i = 0; i < numberOfAppointments; i++) {
        int minutesRemaining = (Schedule[i].hour - WORKING_HOURS_START) * 60 + Schedule[i].minutes;
        if (minutesRemaining < 0) {
            continue;
        }
        printf("\nReminder for %s's appointment in %d minute(s): %s\n",
            Schedule[i].name, minutesRemaining, Schedule[i].reminder);
    }

    printf("\nThat's all the reminders for now. No funny stories this time. Goodbye!\n\n");
}