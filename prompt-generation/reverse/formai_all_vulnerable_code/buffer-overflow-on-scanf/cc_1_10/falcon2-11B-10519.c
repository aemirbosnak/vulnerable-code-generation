//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int appointment_time;
    char description[200];
} Appointment;

void print_menu() {
    printf("Welcome to the Appointment Scheduler!\n");
    printf("1. Schedule an Appointment\n");
    printf("2. View Upcoming Appointments\n");
    printf("3. View All Appointments\n");
    printf("4. Exit\n");
}

void schedule_appointment() {
    Appointment appointment;
    printf("Enter the name of the appointment: ");
    fgets(appointment.name, sizeof(appointment.name), stdin);
    appointment.name[strcspn(appointment.name, "\n")] = '\0';

    printf("Enter the appointment time (hh:mm): ");
    scanf("%d", &appointment.appointment_time);

    printf("Enter the description of the appointment (max 200 characters): ");
    fgets(appointment.description, sizeof(appointment.description), stdin);
    appointment.description[strcspn(appointment.description, "\n")] = '\0';

    printf("Appointment scheduled successfully!\n");
}

void view_upcoming_appointments() {
    printf("Upcoming Appointments:\n");
    for (int i = 0; i < 10; i++) {
        Appointment appointment;
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointment.name);
        printf("Time: %d\n", appointment.appointment_time);
        printf("Description: %s\n", appointment.description);
        printf("\n");
    }
}

void view_all_appointments() {
    printf("All Appointments:\n");
    for (int i = 0; i < 20; i++) {
        Appointment appointment;
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointment.name);
        printf("Time: %d\n", appointment.appointment_time);
        printf("Description: %s\n", appointment.description);
        printf("\n");
    }
}

void main() {
    Appointment appointments[20];
    srand(time(NULL));
    int choice = 0;

    while (choice!= 4) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_upcoming_appointments();
                break;
            case 3:
                view_all_appointments();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Thank you for using the Appointment Scheduler! Goodbye.\n");
}