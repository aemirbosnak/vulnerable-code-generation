//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }
    
    Appointment newAppointment;
    printf("Enter the name of the appointment: ");
    scanf(" %[^\n]", newAppointment.name);
    printf("Enter a brief description: ");
    scanf(" %[^\n]", newAppointment.description);
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &newAppointment.day, &newAppointment.month, &newAppointment.year);
    printf("Enter time (HH MM): ");
    scanf("%d %d", &newAppointment.hour, &newAppointment.minute);

    appointments[*count] = newAppointment;
    (*count)++;
    printf("Appointment added!\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled!\n");
        return;
    }

    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Date: %02d/%02d/%04d\n", appointments[i].day, appointments[i].month, appointments[i].year);
        printf("Time: %02d:%02d\n", appointments[i].hour, appointments[i].minute);
        printf("------------------------------\n");
    }
}

void deleteAppointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("No appointments to delete!\n");
        return;
    }

    int index;
    printf("Enter appointment number to delete (1-%d): ", *count);
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    (*count)--;
    printf("Appointment deleted!\n");
}

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int appointmentCount = 0;
    int choice;

    while(1) {
        displayMenu();
        printf("Enter your choice: ");
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
                printf("Thank you for using the Appointment Scheduler! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}