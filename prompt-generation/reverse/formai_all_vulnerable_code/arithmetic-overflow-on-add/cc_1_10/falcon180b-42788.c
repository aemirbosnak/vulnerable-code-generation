//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
    int priority;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(char* name, char* email, time_t appointment_time, int priority) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    strncpy(appointments[num_appointments].email, email, MAX_EMAIL_LENGTH);
    appointments[num_appointments].appointment_time = appointment_time;
    appointments[num_appointments].priority = priority;

    num_appointments++;
}

void print_appointments() {
    if (num_appointments == 0) {
        printf("No appointments.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s <%s> (%s) Priority: %d\n", appointments[i].name, appointments[i].email, ctime(&appointments[i].appointment_time), appointments[i].priority);
    }
}

int main() {
    add_appointment("John Doe", "john@example.com", time(NULL) + 3600, 1);
    add_appointment("Jane Smith", "jane@example.com", time(NULL) + 7200, 2);

    print_appointments();

    return 0;
}