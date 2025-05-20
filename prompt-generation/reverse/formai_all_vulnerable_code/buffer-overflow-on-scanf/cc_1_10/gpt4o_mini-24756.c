//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DATE_LENGTH 20

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char date[MAX_DATE_LENGTH];
} Appointment;

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }

    printf("Enter appointment title: ");
    scanf(" %[^\n]", appointments[*count].title);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf(" %[^\n]", appointments[*count].date);
    (*count)++;
    printf("Appointment added!\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, appointments[i].title, appointments[i].date);
    }
    printf("\n");
}

void deleteAppointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter the number of the appointment to delete: ");
    scanf("%d", &index);
    index--; // Adjust for 0-based index

    if (index < 0 || index >= *count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift appointments left
    }
    (*count)--; // Reduce count of appointments
    printf("Appointment deleted!\n");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int appointmentCount = 0;
    int choice;

    while (1) {
        printf("\n--- Appointment Scheduler ---\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment(appointments, &appointmentCount);
                break;
            case 2:
                viewAppointments(appointments, appointmentCount);
                break;
            case 3:
                deleteAppointment(appointments, &appointmentCount);
                break;
            case 4:
                printf("Exiting the scheduler. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}