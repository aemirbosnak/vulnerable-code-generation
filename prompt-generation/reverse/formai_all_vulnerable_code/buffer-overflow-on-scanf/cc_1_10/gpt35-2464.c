//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_APPOINTMENTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hour;
    int minute;
} Appointment;

void printMenu();
bool isAvailable(Appointment appointments[MAX_APPOINTMENTS], int hour, int minute);
void printAppointments(Appointment appointments[MAX_APPOINTMENTS]);
void addAppointment(Appointment appointments[MAX_APPOINTMENTS]);
void removeAppointment(Appointment appointments[MAX_APPOINTMENTS]);

int main() {

    Appointment appointments[MAX_APPOINTMENTS] = {0};
    int choice = 0;

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printAppointments(appointments);
                break;
            case 2:
                addAppointment(appointments);
                break;
            case 3:
                removeAppointment(appointments);
                break;
            case 4:
                printf("Exiting scheduler...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void printMenu() {
    printf("\nFuturistic Appointment Scheduler\n");
    printf("----------------------------------\n");
    printf("1. View Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Remove Appointment\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
}

bool isAvailable(Appointment appointments[MAX_APPOINTMENTS], int hour, int minute) {
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if ((appointments[i].hour == hour) && (appointments[i].minute == minute)) {
            return false;
        }
    }
    return true;
}

void printAppointments(Appointment appointments[MAX_APPOINTMENTS]) {
    printf("\nAppointments:\n");
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].hour != 0) {
            printf("%s - %02d:%02d\n", appointments[i].name, appointments[i].hour, appointments[i].minute);
        }
    }
}

void addAppointment(Appointment appointments[MAX_APPOINTMENTS]) {
    char name[MAX_NAME_LENGTH];
    int hour = 0;
    int minute = 0;

    printf("\nEnter name for appointment: ");
    scanf("%s", name);

    printf("Enter the hour for the appointment (0-23): ");
    scanf("%d", &hour);

    printf("Enter the minute for the appointment (0-59): ");
    scanf("%d", &minute);

    if ((hour >= 0) && (hour <= 23) && (minute >= 0) && (minute <= 59)) {
        if (isAvailable(appointments, hour, minute)) {
            for (int i = 0; i < MAX_APPOINTMENTS; i++) {
                if (appointments[i].hour == 0) {
                    strcpy(appointments[i].name, name);
                    appointments[i].hour = hour;
                    appointments[i].minute = minute;
                    printf("Appointment added successfully!\n");
                    break;
                }
            }
        } else {
            printf("Appointment slot not available. Please try again.\n");
        }
    } else {
        printf("Invalid hour or minute. Please try again.\n");
    }
}

void removeAppointment(Appointment appointments[MAX_APPOINTMENTS]) {
    int hour = 0;
    int minute = 0;
    bool found = false;

    printf("\nEnter the hour for the appointment to remove (0-23): ");
    scanf("%d", &hour);

    printf("Enter the minute for the appointment to remove (0-59): ");
    scanf("%d", &minute);

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if ((appointments[i].hour == hour) && (appointments[i].minute == minute)) {
            strcpy(appointments[i].name, "");
            appointments[i].hour = 0;
            appointments[i].minute = 0;
            printf("Appointment removed successfully!\n");
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Appointment not found. Please try again.\n");
    }
}