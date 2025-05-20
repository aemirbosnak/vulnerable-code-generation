//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
    int appointment_duration;
} Appointment;

void add_appointment(Appointment *appointments, int num_appointments, char *name, char *phone, char *email, time_t appointment_time, int appointment_duration) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].phone, phone);
    strcpy(appointments[num_appointments].email, email);
    appointments[num_appointments].appointment_time = appointment_time;
    appointments[num_appointments].appointment_duration = appointment_duration;

    num_appointments++;
}

void print_appointment(Appointment appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Phone: %s\n", appointment.phone);
    printf("Email: %s\n", appointment.email);
    printf("Appointment time: %s\n", ctime(&appointment.appointment_time));
    printf("Appointment duration: %d minutes\n", appointment.appointment_duration);
    printf("\n");
}

void print_appointments(Appointment *appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments, "John Doe", "555-1234", "johndoe@example.com", time(NULL) + (60 * 15), 30);
    add_appointment(appointments, num_appointments, "Jane Doe", "555-5678", "janedoe@example.com", time(NULL) + (60 * 30), 45);

    print_appointments(appointments, num_appointments);

    return 0;
}