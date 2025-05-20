//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    char date[20];
    char time[20];
};

struct appointment appointment_list[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the maximum number of appointments has been reached.\n");
        return;
    }
    struct appointment new_appointment;
    printf("Enter the patient's name: ");
    fgets(new_appointment.name, 50, stdin);
    printf("Enter the date (MM/DD/YYYY): ");
    fgets(new_appointment.date, 20, stdin);
    printf("Enter the time (HH:MM): ");
    fgets(new_appointment.time, 20, stdin);
    appointment_list[num_appointments] = new_appointment;
    num_appointments++;
    printf("Appointment added successfully!\n");
}

void display_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("%-20s %-20s %-20s\n", "Name", "Date", "Time");
    for (int i = 0; i < num_appointments; i++) {
        printf("%-20s %-20s %-20s\n", appointment_list[i].name, appointment_list[i].date, appointment_list[i].time);
    }
}

int main() {
    int choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("--------------------\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                display_appointments();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}