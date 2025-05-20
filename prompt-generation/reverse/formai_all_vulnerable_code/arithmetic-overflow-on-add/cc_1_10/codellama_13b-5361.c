//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
// Appointment Scheduler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 256

struct Appointment {
    char name[MAX_APPOINTMENT_LENGTH];
    char location[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
};

void add_appointment(struct Appointment appointments[], int *num_appointments, char *name, char *location, time_t start_time, time_t end_time) {
    if (*num_appointments < MAX_APPOINTMENTS) {
        strcpy(appointments[*num_appointments].name, name);
        strcpy(appointments[*num_appointments].location, location);
        appointments[*num_appointments].start_time = start_time;
        appointments[*num_appointments].end_time = end_time;
        *num_appointments += 1;
    } else {
        printf("Error: Maximum number of appointments reached.\n");
    }
}

void delete_appointment(struct Appointment appointments[], int *num_appointments, int index) {
    if (index >= 0 && index < *num_appointments) {
        for (int i = index; i < *num_appointments - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        *num_appointments -= 1;
    } else {
        printf("Error: Invalid index.\n");
    }
}

void print_appointments(struct Appointment appointments[], int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("\tName: %s\n", appointments[i].name);
        printf("\tLocation: %s\n", appointments[i].location);
        printf("\tStart Time: %s\n", ctime(&appointments[i].start_time));
        printf("\tEnd Time: %s\n", ctime(&appointments[i].end_time));
    }
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, &num_appointments, "Meeting", "Conference Room", time(NULL), time(NULL) + 3600);
    add_appointment(appointments, &num_appointments, "Lunch", "Cafeteria", time(NULL) + 3600, time(NULL) + 7200);
    add_appointment(appointments, &num_appointments, "Presentation", "Auditorium", time(NULL) + 7200, time(NULL) + 10800);
    add_appointment(appointments, &num_appointments, "Meeting", "Conference Room", time(NULL) + 10800, time(NULL) + 14400);

    print_appointments(appointments, num_appointments);

    delete_appointment(appointments, &num_appointments, 2);

    print_appointments(appointments, num_appointments);

    return 0;
}