//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_MESSAGE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    time_t appointment_time;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments, char* name, char* message, time_t appointment_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    strncpy(appointments[num_appointments].message, message, MAX_MESSAGE_LENGTH);
    appointments[num_appointments].appointment_time = appointment_time;

    printf("Appointment added for %s at %s.\n", name, ctime(&appointment_time));

    num_appointments++;
}

void remove_appointment(Appointment* appointments, int num_appointments, char* name) {
    int i;

    for (i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("Appointment removed for %s.\n", name);

            memmove(&appointments[i], &appointments[i + 1], sizeof(Appointment) * (num_appointments - i - 1));

            num_appointments--;

            return;
        }
    }

    printf("No appointment found for %s.\n", name);
}

void print_appointments(Appointment* appointments, int num_appointments) {
    int i;

    for (i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].message, ctime(&appointments[i].appointment_time));
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments, "John Doe", "Meeting with boss", time(NULL) + 3600);
    add_appointment(appointments, num_appointments, "Jane Smith", "Doctor's appointment", time(NULL) + 7200);

    print_appointments(appointments, num_appointments);

    remove_appointment(appointments, num_appointments, "John Doe");

    print_appointments(appointments, num_appointments);

    return 0;
}