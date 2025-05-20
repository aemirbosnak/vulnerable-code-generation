//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char appointment[MAX_APPOINTMENT_LENGTH];
    time_t appointment_time;
} appointment_t;

void add_appointment(appointment_t appointments[], int num_appointments, char* name, char* appointment, time_t appointment_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].appointment, appointment);
    appointments[num_appointments].appointment_time = appointment_time;

    num_appointments++;
}

void display_appointments(appointment_t appointments[], int num_appointments) {
    printf("Appointments:\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].appointment, ctime(&appointments[i].appointment_time));
    }
}

int main() {
    appointment_t appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[MAX_NAME_LENGTH];
    char appointment[MAX_APPOINTMENT_LENGTH];
    time_t appointment_time;

    while (1) {
        printf("Enter name (leave blank to exit): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter appointment: ");
        scanf("%s", appointment);

        if (strlen(appointment) > MAX_APPOINTMENT_LENGTH) {
            printf("Error: Appointment is too long.\n");
            continue;
        }

        printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointment);

        if (strptime(appointment, "%Y-%m-%d %H:%M:%S", &appointment_time) == NULL) {
            printf("Error: Invalid appointment time.\n");
            continue;
        }

        add_appointment(appointments, num_appointments, name, appointment, appointment_time);
    }

    display_appointments(appointments, num_appointments);

    return 0;
}