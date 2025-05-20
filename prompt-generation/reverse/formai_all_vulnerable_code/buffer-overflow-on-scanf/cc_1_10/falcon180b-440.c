//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct appointment {
    char name[50];
    char phone[15];
    time_t appointment_time;
    int duration;
} appointment_t;

void add_appointment(appointment_t* appointments, int num_appointments) {
    appointment_t new_appointment;
    printf("Enter name: ");
    scanf("%s", new_appointment.name);
    printf("Enter phone number: ");
    scanf("%s", new_appointment.phone);
    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", new_appointment.appointment_time);
    printf("Enter duration in minutes: ");
    scanf("%d", &new_appointment.duration);

    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments.\n");
        return;
    }

    appointments[num_appointments] = new_appointment;
    num_appointments++;
}

void view_appointments(appointment_t* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s - %d minutes\n", appointments[i].name, appointments[i].phone, ctime(&appointments[i].appointment_time), appointments[i].duration);
    }
}

int main() {
    appointment_t appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char choice;
    do {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_appointment(appointments, num_appointments);
                break;
            case '2':
                view_appointments(appointments, num_appointments);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');

    return 0;
}