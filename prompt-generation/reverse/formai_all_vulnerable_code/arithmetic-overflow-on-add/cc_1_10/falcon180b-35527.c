//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t appointment_time;
    int duration;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);
    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);
    appointments[num_appointments].duration = 0;
    num_appointments++;
}

void display_appointments(Appointment* appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s (%d minutes)\n", appointments[i].name, appointments[i].phone, appointments[i].duration);
    }
}

void schedule_appointment(Appointment* appointments, int num_appointments) {
    printf("\nEnter duration of appointment in minutes: ");
    scanf("%d", &appointments[num_appointments].duration);
    time_t now = time(NULL);
    appointments[num_appointments].appointment_time = now + appointments[num_appointments].duration * 60;
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\nEnter 1 to add an appointment, 2 to display appointments, or 3 to schedule an appointment: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                break;
            case 2:
                display_appointments(appointments, num_appointments);
                break;
            case 3:
                schedule_appointment(appointments, num_appointments);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}