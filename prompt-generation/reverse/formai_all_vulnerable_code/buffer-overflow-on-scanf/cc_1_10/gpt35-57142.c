//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for appointments
struct Appointment {
    char name[30];
    char date[20];
    char time[20];
};

// Function to add an appointment
void addAppointment(struct Appointment appointments[], int *numAppointments) {
    char name[30], date[20], time[20];
    printf("\nEnter name for appointment: ");
    scanf(" %[^\n]s", name);
    printf("Enter date for appointment (mm/dd/yyyy): ");
    scanf(" %[^\n]s", date);
    printf("Enter time for appointment (hh:mm): ");
    scanf(" %[^\n]s", time);
    strcpy(appointments[*numAppointments].name, name);
    strcpy(appointments[*numAppointments].date, date);
    strcpy(appointments[*numAppointments].time, time);
    *numAppointments += 1;
    printf("\nAppointment added!\n");
}

// Function to display all appointments
void displayAppointments(struct Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("\nNo appointments scheduled.\n");
    } else {
        printf("\n%-30s %-20s %-20s\n", "Name", "Date", "Time");
        for (int i = 0; i < numAppointments; i++) {
            printf("%-30s %-20s %-20s\n", appointments[i].name, appointments[i].date, appointments[i].time);
        }
    }
}

// Function to reschedule an appointment
void rescheduleAppointment(struct Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("\nNo appointments scheduled.\n");
        return;
    }
    int index = -1;
    char name[30], date[20], time[20];
    printf("\nEnter name of appointment to reschedule: ");
    scanf(" %[^\n]s", name);
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nAppointment not found.\n");
    } else {
        printf("Enter new date for appointment (mm/dd/yyyy): ");
        scanf(" %[^\n]s", date);
        printf("Enter new time for appointment (hh:mm): ");
        scanf(" %[^\n]s", time);
        strcpy(appointments[index].date, date);
        strcpy(appointments[index].time, time);
        printf("\nAppointment rescheduled!\n");
    }
}

// Function to cancel an appointment
void cancelAppointment(struct Appointment appointments[], int *numAppointments) {
    if (*numAppointments == 0) {
        printf("\nNo appointments scheduled.\n");
        return;
    }
    int index = -1;
    char name[30];
    printf("\nEnter name of appointment to cancel: ");
    scanf(" %[^\n]s", name);
    for (int i = 0; i < *numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nAppointment not found.\n");
    } else {
        for (int i = index; i < *numAppointments-1; i++) {
            appointments[i] = appointments[i+1];
        }
        *numAppointments -= 1;
        printf("\nAppointment cancelled!\n");
    }
}

// Driver function
int main() {
    struct Appointment appointments[20];
    int numAppointments = 0;
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Reschedule Appointment\n");
        printf("4. Cancel Appointment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                displayAppointments(appointments, numAppointments);
                break;
            case 3:
                rescheduleAppointment(appointments, numAppointments);
                break;
            case 4:
                cancelAppointment(appointments, &numAppointments);
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}