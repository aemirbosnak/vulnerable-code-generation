//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_APPOINTMENT_LENGTH 100

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    char description[MAX_APPOINTMENT_LENGTH];
    int duration;
    int start_time;
    int end_time;
} appointment;

int num_appointments = 0;
appointment appointments[MAX_APPOINTMENTS];

int add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return -1;
    }

    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter description: ");
    scanf("%s", appointments[num_appointments].description);

    printf("Enter duration (in minutes): ");
    scanf("%d", &appointments[num_appointments].duration);

    printf("Enter start time (in minutes from 8:00 AM): ");
    scanf("%d", &appointments[num_appointments].start_time);

    appointments[num_appointments].end_time = appointments[num_appointments].start_time + appointments[num_appointments].duration;
    num_appointments++;

    printf("Appointment added.\n");
    return 0;
}

int view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return 0;
    }

    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i+1);
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Duration: %d minutes\n", appointments[i].duration);
        printf("Start time: %d minutes from 8:00 AM\n", appointments[i].start_time);
        printf("End time: %d minutes from 8:00 AM\n\n", appointments[i].end_time);
    }

    return 0;
}

int main() {
    printf("Welcome to the appointment scheduler.\n");

    while (1) {
        printf("\nOptions:\n1. Add appointment\n2. View appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}