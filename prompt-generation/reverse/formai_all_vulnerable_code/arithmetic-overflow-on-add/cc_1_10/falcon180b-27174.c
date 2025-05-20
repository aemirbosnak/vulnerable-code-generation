//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
    int appointment_duration;
} appointment_t;

void add_appointment(appointment_t *appointments, int num_appointments, char *name, char *phone, char *email, time_t appointment_time, int appointment_duration) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    strncpy(appointments[num_appointments].phone, phone, MAX_PHONE_LENGTH);
    strncpy(appointments[num_appointments].email, email, MAX_EMAIL_LENGTH);
    appointments[num_appointments].appointment_time = appointment_time;
    appointments[num_appointments].appointment_duration = appointment_duration;

    num_appointments++;
}

void display_appointments(appointment_t *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%s) - %s - %s\n",
            appointments[i].name,
            appointments[i].phone,
            appointments[i].email,
            ctime(&appointments[i].appointment_time));
    }
}

int main() {
    appointment_t appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments, "John Doe", "555-1234", "johndoe@example.com", time(NULL) + 60*60*24*2, 60*30);
    add_appointment(appointments, num_appointments, "Jane Smith", "555-5678", "janesmith@example.com", time(NULL) + 60*60*24*3, 60*60);

    display_appointments(appointments, num_appointments);

    return 0;
}