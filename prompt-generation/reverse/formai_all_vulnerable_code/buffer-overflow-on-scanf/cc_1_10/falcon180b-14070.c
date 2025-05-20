//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t appointment_time;
    int is_booked;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%s, %s, %s)\n", appointments[i].name, appointments[i].email, appointments[i].phone, ctime(&appointments[i].appointment_time));
    }
}

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    printf("Enter your name:\n");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter your email:\n");
    scanf("%s", appointments[num_appointments].email);

    printf("Enter your phone number:\n");
    scanf("%s", appointments[num_appointments].phone);

    printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS):\n");
    scanf("%s", appointments[num_appointments].appointment_time);

    appointments[num_appointments].is_booked = 1;
    num_appointments++;
}

void cancel_appointment() {
    printf("Enter the name of the appointment you want to cancel:\n");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            appointments[i].is_booked = 0;
            printf("Appointment cancelled.\n");
            return;
        }
    }

    printf("Appointment not found.\n");
}

void schedule_appointment() {
    printf("Enter the name of the appointment:\n");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("Appointment already scheduled.\n");
            return;
        }
    }

    printf("Enter the appointment time (YYYY-MM-DD HH:MM:SS):\n");
    scanf("%s", appointments[num_appointments].appointment_time);

    appointments[num_appointments].is_booked = 1;
    num_appointments++;
}

void main() {
    srand(time(0));

    int choice;
    do {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Cancel appointment\n");
        printf("3. Schedule appointment\n");
        printf("4. Print appointments\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                cancel_appointment();
                break;
            case 3:
                schedule_appointment();
                break;
            case 4:
                print_appointments();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);
}