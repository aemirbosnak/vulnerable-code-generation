//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 100

struct appointment {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
};

void add_appointment(struct appointment *appointments, int num_appointments, char *name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    num_appointments++;
}

void display_appointments(struct appointment *appointments, int num_appointments) {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[MAX_NAME_LENGTH];
    time_t start_time, end_time;

    printf("Welcome to the appointment scheduler!\n\n");

    while (1) {
        printf("Enter name for appointment (leave blank to exit): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime(&start_time));

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime(&end_time));

        add_appointment(appointments, num_appointments, name, start_time, end_time);
    }

    printf("\nAppointments scheduled:\n");
    display_appointments(appointments, num_appointments);

    return 0;
}