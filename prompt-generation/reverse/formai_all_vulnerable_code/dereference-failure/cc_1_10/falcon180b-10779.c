//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int appointment_time;
    int duration;
    int status;
} appointment;

appointment *appointments = NULL;
int num_appointments = 0;

void add_appointment(char *name, int appointment_time, int duration) {
    appointment *new_appointment = (appointment *)malloc(sizeof(appointment));
    strcpy(new_appointment->name, name);
    new_appointment->appointment_time = appointment_time;
    new_appointment->duration = duration;
    new_appointment->status = 0;
    appointments = (appointment *)realloc(appointments, sizeof(appointment) * (num_appointments + 1));
    appointments[num_appointments] = *new_appointment;
    num_appointments++;
}

void remove_appointment(int index) {
    if (index >= 0 && index < num_appointments) {
        free(appointments[index].name);
        appointments[index] = appointments[num_appointments - 1];
        num_appointments--;
        appointments = (appointment *)realloc(appointments, sizeof(appointment) * num_appointments);
    }
}

void display_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %d (%d min)\n", appointments[i].name, appointments[i].appointment_time, appointments[i].duration);
    }
}

int main() {
    appointments = (appointment *)malloc(sizeof(appointment));
    num_appointments = 0;

    add_appointment("John Doe", 900, 30);
    add_appointment("Jane Smith", 1200, 60);
    add_appointment("Bob Johnson", 1500, 45);

    display_appointments();

    remove_appointment(1);

    display_appointments();

    return 0;
}