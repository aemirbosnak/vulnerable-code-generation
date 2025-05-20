//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct appointment {
    char date[15];
    char time[10];
    char description[100];
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

int is_date_valid(char *date) {
    // Implement your own date validation logic here
    return 1;
}

int is_time_valid(char *time) {
    // Implement your own time validation logic here
    return 1;
}

void schedule_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, you have reached the maximum number of appointments.");
        return;
    }
    printf("\nScheduling new appointment...\n");

    Appointment new_appointment;
    printf("Enter the date (in DD/MM/YYYY format): ");
    scanf("%s", new_appointment.date);
    if (!is_date_valid(new_appointment.date)) {
        printf("Invalid date format. Appointment not scheduled.\n");
        return;
    }
    printf("Enter the time (in HH:MM format): ");
    scanf("%s", new_appointment.time);
    if (!is_time_valid(new_appointment.time)) {
        printf("Invalid time format. Appointment not scheduled.\n");
        return;
    }
    printf("Enter the appointment description: ");
    scanf(" %[^\n]", new_appointment.description);

    appointments[num_appointments++] = new_appointment;
    printf("Appointment scheduled successfully!\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("\nYou have no appointments scheduled.\n");
        return;
    }
    printf("\nYour scheduled appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        Appointment app = appointments[i];
        printf("Date: %s\n", app.date);
        printf("Time: %s\n", app.time);
        printf("Description: %s\n\n", app.description);
    }
}

int main() {
    int choice;
    do {
        printf("\n------- APPOINTMENT SCHEDULER -------\n\n");
        printf("1. Schedule appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("\nExiting... Thank you for using the appointment scheduler.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}