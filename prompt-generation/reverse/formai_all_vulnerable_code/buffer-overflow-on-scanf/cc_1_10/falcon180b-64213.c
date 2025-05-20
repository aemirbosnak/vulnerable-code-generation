//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments, char* name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_appointments(Appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[MAX_NAME_LENGTH];
    time_t start_time, end_time;

    while (1) {
        printf("Enter name (leave blank to exit): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime_r(&start_time, "YYYY-MM-DD HH:MM:SS"));

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime_r(&end_time, "YYYY-MM-DD HH:MM:SS"));

        add_appointment(appointments, num_appointments, name, start_time, end_time);
    }

    print_appointments(appointments, num_appointments);

    return 0;
}