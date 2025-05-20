//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// structure representing an appointment
typedef struct appointment {
    int hour;
    int minute;
    char description[100];
} Appointment;

// function to display the menu
void display_menu() {
    printf("\n1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// function to get input for appointment time and description
void get_appointment_input(Appointment *appt) {
    printf("\nEnter appointment time (hh:mm): ");
    scanf("%d:%d", &appt->hour, &appt->minute);
    printf("Enter appointment description: ");
    scanf("%s", appt->description);
}

// function to check if a given appointment conflicts with existing appointments
bool check_conflict(Appointment *appt, Appointment *appointments, int n) {
    for (int i = 0; i < n; i++) {
        if (appt->hour == appointments[i].hour && appt->minute == appointments[i].minute) {
            return true;
        }
    }
    return false;
}

// function to add an appointment
void add_appointment(Appointment *appointments, int *n) {
    Appointment appt;
    get_appointment_input(&appt);
    if (check_conflict(&appt, appointments, *n)) {
        printf("Appointment conflict, cannot add.\n");
        return;
    }
    appointments[*n] = appt;
    (*n)++;
    printf("Appointment added successfully.\n");
}

// function to view all appointments
void view_appointments(Appointment *appointments, int n) {
    if (n == 0) {
        printf("No appointments.\n");
        return;
    }
    printf("\nAppointment Time\tDescription\n");
    for (int i = 0; i < n; i++) {
        printf("%02d:%02d\t\t%s\n", appointments[i].hour, appointments[i].minute, appointments[i].description);
    }
}

// function to cancel an appointment
void cancel_appointment(Appointment *appointments, int *n) {
    if (*n == 0) {
        printf("No appointments to cancel.\n");
        return;
    }
    Appointment appt;
    get_appointment_input(&appt);
    bool canceled = false;
    for (int i = 0; i < *n; i++) {
        if (strcmp(appt.description, appointments[i].description) == 0 && appt.hour == appointments[i].hour && appt.minute == appointments[i].minute) {
            for (int j = i; j < *n-1; j++) {
                appointments[j] = appointments[j+1];
            }
            (*n)--;
            canceled = true;
            break;
        }
    }
    if (canceled) {
        printf("Appointment canceled successfully.\n");
    } else {
        printf("Appointment not found.\n");
    }
}

int main() {
    Appointment appointments[100];
    int n = 0;
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment(appointments, &n);
                break;
            case 2:
                view_appointments(appointments, n);
                break;
            case 3:
                cancel_appointment(appointments, &n);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}