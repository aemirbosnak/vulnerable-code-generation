//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 50
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    int start_hour;
    int start_min;
    int end_hour;
    int end_min;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments) {
    Appointment new_appointment;
    printf("Enter the name of the appointment: ");
    scanf("%s", new_appointment.name);

    printf("Enter the start time (HH:MM): ");
    scanf("%d:%d", &new_appointment.start_hour, &new_appointment.start_min);

    printf("Enter the end time (HH:MM): ");
    scanf("%d:%d", &new_appointment.end_hour, &new_appointment.end_min);

    int i;
    for (i = 0; i < num_appointments; i++) {
        if (appointments[i].name[0] == '\0') {
            strcpy(appointments[i].name, new_appointment.name);
            appointments[i].start_hour = new_appointment.start_hour;
            appointments[i].start_min = new_appointment.start_min;
            appointments[i].end_hour = new_appointment.end_hour;
            appointments[i].end_min = new_appointment.end_min;
            return;
        }
    }

    printf("Sorry, the appointment list is full.\n");
}

void display_appointments(Appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    int i;
    for (i = 0; i < num_appointments; i++) {
        if (appointments[i].name[0]!= '\0') {
            printf("%s - %d:%d to %d:%d\n", appointments[i].name, appointments[i].start_hour, appointments[i].start_min, appointments[i].end_hour, appointments[i].end_min);
        }
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        int choice;
        printf("1. Add appointment\n2. Display appointments\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                break;
            case 2:
                display_appointments(appointments, num_appointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}