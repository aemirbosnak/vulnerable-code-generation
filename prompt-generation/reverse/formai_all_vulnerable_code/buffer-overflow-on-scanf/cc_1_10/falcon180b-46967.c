//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int appointment_id;
    time_t appointment_time;
} appointment;

void display_appointments(appointment* appointments, int num_appointments) {
    printf("Upcoming Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s has an appointment at %s", appointments[i].name, ctime(&appointments[i].appointment_time));
    }
}

int main() {
    int num_appointments = 0;
    appointment appointments[MAX_APPOINTMENTS];

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name for appointment (or type 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
        time_t appointment_time;
        if (scanf("%s", ctime(&appointment_time))!= 1) {
            printf("Invalid appointment time\n");
            continue;
        }

        if (num_appointments >= MAX_APPOINTMENTS) {
            printf("Maximum number of appointments reached\n");
            continue;
        }

        strcpy(appointments[num_appointments].name, name);
        appointments[num_appointments].appointment_id = num_appointments + 1;
        appointments[num_appointments].appointment_time = appointment_time;
        num_appointments++;
    }

    display_appointments(appointments, num_appointments);

    return 0;
}