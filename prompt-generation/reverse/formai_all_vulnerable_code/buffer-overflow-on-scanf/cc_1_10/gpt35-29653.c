//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_APPOINTMENTS 10 // maximum number of appointments that can be scheduled
#define MAX_NAME_LENGTH 20 // maximum length of client names

// defining a structure for each appointment
typedef struct {
    char client_name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

// function prototypes
void printOptions();
void bookAppointment(Appointment appointments[], int* numAppointments);
bool isAvailable(Appointment appointments[], int day, int month, int year, int hour, int minute);
void displayAppointments(Appointment appointments[], int numAppointments);
void deleteAppointment(Appointment appointments[], int* numAppointments);

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice;

    // loop until user chooses to exit
    while (true) {
        printOptions();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookAppointment(appointments, &numAppointments);
                break;
            case 2:
                displayAppointments(appointments, numAppointments);
                break;
            case 3:
                deleteAppointment(appointments, &numAppointments);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// function to print the options menu
void printOptions() {
    printf("\n1. Book an appointment\n");
    printf("2. Display scheduled appointments\n");
    printf("3. Delete an appointment\n");
    printf("4. Exit program\n");
}

// function to book an appointment
void bookAppointment(Appointment appointments[], int* numAppointments) {
    char clientName[MAX_NAME_LENGTH];
    int day, month, year, hour, minute;

    printf("\nEnter client name: ");
    scanf("%s", clientName);

    printf("Enter appointment date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    printf("Enter appointment time (hh mm): ");
    scanf("%d %d", &hour, &minute);

    // check if appointment is available
    if (isAvailable(appointments, day, month, year, hour, minute)) {
        // add appointment to array
        Appointment newAppointment = {
            .day = day,
            .month = month,
            .year = year,
            .hour = hour,
            .minute = minute
        };
        strcpy(newAppointment.client_name, clientName);
        appointments[*numAppointments] = newAppointment;
        *numAppointments += 1;
        printf("\nAppointment booked for %s on %d/%d/%d at %02d:%02d.\n", clientName, day, month, year, hour, minute);
    } else {
        printf("\nAppointment unavailable. Please choose another time.\n");
    }
}

// function to check if appointment is available
bool isAvailable(Appointment appointments[], int day, int month, int year, int hour, int minute) {
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        // check if appointment exists on given date and time
        if (appointments[i].day == day && appointments[i].month == month && appointments[i].year == year &&
            appointments[i].hour == hour && appointments[i].minute == minute) {
            return false; // appointment is unavailable
        }
    }

    return true; // appointment is available
}

// function to display scheduled appointments
void displayAppointments(Appointment appointments[], int numAppointments) {
    printf("\nScheduled appointments:\n\n");
    printf("%-20s%-15s%-15s%-15s%-15s\n", "Client name", "Day", "Month", "Year", "Time");
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
    } else {
        for (int i = 0; i < numAppointments; i++) {
            printf("%-20s%-15d%-15d%-15d%02d:%02d\n", appointments[i].client_name, appointments[i].day, 
                appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
        }
    }
}

// function to delete an appointment
void deleteAppointment(Appointment appointments[], int* numAppointments) {
    int day, month, year, hour, minute;

    printf("\nEnter appointment date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    printf("Enter appointment time (hh mm): ");
    scanf("%d %d", &hour, &minute);

    // check if appointment exists
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].day == day && appointments[i].month == month && appointments[i].year == year &&
            appointments[i].hour == hour && appointments[i].minute == minute) {
            // shift remaining appointments up to fill gap
            for (int j = i; j < *numAppointments - 1; j++) {
                appointments[j] = appointments[j+1];
            }
            *numAppointments -= 1; // decrement number of appointments
            printf("\nAppointment deleted for %d/%d/%d at %02d:%02d.\n", day, month, year, hour, minute);
            return;
        }
    }

    printf("\nAppointment not found.\n");
}