//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments, char* name, char* phone_number, char* email, time_t appointment_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].phone_number, phone_number);
    strcpy(appointments[num_appointments].email, email);
    appointments[num_appointments].appointment_time = appointment_time;

    num_appointments++;
}

void print_appointments(Appointment* appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Phone number: %s\n", appointments[i].phone_number);
        printf("Email: %s\n", appointments[i].email);
        printf("Appointment time: %s\n\n", ctime(&appointments[i].appointment_time));
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name (or type 'done' to finish):\n");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter phone number:\n");
        char phone_number[MAX_PHONE_NUMBER_LENGTH];
        scanf("%s", phone_number);

        printf("Enter email:\n");
        char email[MAX_EMAIL_LENGTH];
        scanf("%s", email);

        printf("Enter appointment time (YYYY-MM-DD HH:MM:SS):\n");
        time_t appointment_time;
        if (scanf("%s", ctime_r(&appointment_time, " "))!= 1) {
            printf("Error: Invalid appointment time.\n");
            continue;
        }

        add_appointment(appointments, num_appointments, name, phone_number, email, appointment_time);
        num_appointments++;
    }

    printf("Appointments:\n");
    print_appointments(appointments, num_appointments);

    return 0;
}