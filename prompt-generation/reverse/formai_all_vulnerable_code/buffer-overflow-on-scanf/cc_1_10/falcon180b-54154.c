//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
    int duration;
} Appointment;

void print_appointment(Appointment appt) {
    printf("Name: %s\n", appt.name);
    printf("Phone: %s\n", appt.phone);
    printf("Email: %s\n", appt.email);
    printf("Appointment Time: %s\n", ctime(&appt.appointment_time));
    printf("Duration: %d minutes\n\n", appt.duration);
}

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    printf("Welcome to the appointment scheduler!\n\n");
    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter the name of the person you want to schedule an appointment for (or 'done' to finish):\n");
        scanf("%s", appointments[num_appointments].name);

        if (strcmp(appointments[num_appointments].name, "done") == 0) {
            break;
        }

        printf("Enter the phone number of %s:\n", appointments[num_appointments].name);
        scanf("%s", appointments[num_appointments].phone);

        printf("Enter the email address of %s:\n", appointments[num_appointments].name);
        scanf("%s", appointments[num_appointments].email);

        printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS):\n");
        scanf("%s", appointments[num_appointments].appointment_time);

        printf("Enter the duration of the appointment in minutes:\n");
        scanf("%d", &appointments[num_appointments].duration);

        num_appointments++;
    }

    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}