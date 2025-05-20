//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
    int appointment_duration;
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void add_appointment(char* name, char* email, time_t appointment_time, int appointment_duration) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    strncpy(appointments[num_appointments].email, email, MAX_EMAIL_LENGTH);
    appointments[num_appointments].appointment_time = appointment_time;
    appointments[num_appointments].appointment_duration = appointment_duration;

    num_appointments++;
}

void print_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Upcoming appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%s) at %s for %d minutes\n", appointments[i].name, appointments[i].email, ctime(&appointments[i].appointment_time), appointments[i].appointment_duration);
    }
}

int main() {
    add_appointment("John Doe", "johndoe@example.com", time(NULL) + 60*60*2, 30);
    add_appointment("Jane Smith", "janesmith@example.com", time(NULL) + 60*60*4, 60);

    print_appointments();

    return 0;
}