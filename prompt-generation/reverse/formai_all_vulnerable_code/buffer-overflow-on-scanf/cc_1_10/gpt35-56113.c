//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 10 // Maximum number of appointments that can be scheduled
#define MAX_NAME_LENGTH 50 // Maximum length allowed for the name of the person who is scheduling the appointment

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hour;
    int minute;
} Appointment;

void printMenu(void);
bool isValidTime(int hour, int minute);
void scheduleAppointment(Appointment *appointments, int *numAppointments);
void cancelAppointment(Appointment *appointments, int *numAppointments);
void listAppointments(Appointment *appointments, int numAppointments);

int main(void) {
    int numAppointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    bool keepRunning = true;
    int choice;

    printf("Welcome to Retro Appointment Scheduler!\n");

    while (keepRunning) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scheduleAppointment(appointments, &numAppointments);
                break;
            case 2:
                cancelAppointment(appointments, &numAppointments);
                break;
            case 3:
                listAppointments(appointments, numAppointments);
                break;
            case 4:
                keepRunning = false;
                printf("Bye bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Prints menu options
void printMenu(void) {
    printf("\n");
    printf("1. Schedule an appointment\n");
    printf("2. Cancel an appointment\n");
    printf("3. List appointments\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

// Validates whether the input time is a valid time or not
bool isValidTime(int hour, int minute) {
    return ((hour >= 0 && hour < 24) && (minute >= 0 && minute < 60));
}

// Lets user schedule a new appointment
void scheduleAppointment(Appointment *appointments, int *numAppointments) {
    if (*numAppointments == MAX_APPOINTMENTS) {
        printf("Cannot schedule any more appointments. Maximum limit has been reached.\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter name of person scheduling appointment: ");
    scanf("%s", newAppointment.name);
    printf("Enter hour (0-23): ");
    scanf("%d", &newAppointment.hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &newAppointment.minute);

    if (!isValidTime(newAppointment.hour, newAppointment.minute)) {
        printf("Invalid time entered.\n");
        return;
    }

    appointments[*numAppointments] = newAppointment;
    (*numAppointments)++;
    printf("Appointment scheduled successfully!.\n");
}

// Lets user cancel an existing appointment
void cancelAppointment(Appointment *appointments, int *numAppointments) {
    if (*numAppointments == 0) {
        printf("No appointments to cancel.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    int hour, minute;
    bool isFound = false;

    printf("Enter name of person who scheduled the appointment: ");
    scanf("%s", name);
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &minute);

    if (!isValidTime(hour, minute)) {
        printf("Invalid time entered.\n");
        return;
    }

    for (int i = 0; i < *numAppointments; i++) {
        if ((strcmp(name, appointments[i].name) == 0) && (hour == appointments[i].hour) && (minute == appointments[i].minute)) {
            isFound = true;
            for (int j = i; j < *numAppointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            (*numAppointments)--;
            printf("Appointment canceled successfully!\n");
            break;
        }
    }

    if (!isFound) {
        printf("No appointment found with the given details.\n");
    }
}

// Lists all the appointments scheduled
void listAppointments(Appointment *appointments, int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n");
    printf("Appointments scheduled:\n");
    printf("-----------------------\n");

    for (int i = 0; i < numAppointments; i++) {
        printf("%d:%02d - %s\n", appointments[i].hour, appointments[i].minute, appointments[i].name);
    }
}