//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    int hour;
    int minute;
} Appointment;

void display_menu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void add_appointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Cannot add more appointments.\n");
        return;
    }
    
    printf("Enter name of the appointment: ");
    scanf(" %[^\n]s", appointments[*count].name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf(" %[^\n]s", appointments[*count].date);
    printf("Enter hour (0-23): ");
    scanf("%d", &appointments[*count].hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &appointments[*count].minute);
    
    (*count)++;
    printf("Appointment added successfully!\n");
}

void view_appointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s on %s at %02d:%02d\n", i + 1, appointments[i].name, appointments[i].date, 
               appointments[i].hour, appointments[i].minute);
    }
}

void delete_appointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    view_appointments(appointments, *count);
    printf("Select the number of the appointment to delete: ");
    int index;
    scanf("%d", &index);

    if (index < 1 || index > *count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    (*count)--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int appointment_count = 0;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, &appointment_count);
                break;
            case 2:
                view_appointments(appointments, appointment_count);
                break;
            case 3:
                delete_appointment(appointments, &appointment_count);
                break;
            case 4:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}