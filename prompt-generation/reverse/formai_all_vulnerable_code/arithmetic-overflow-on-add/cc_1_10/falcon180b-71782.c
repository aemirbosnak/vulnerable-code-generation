//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int appointment_id;
    time_t start_time;
    time_t end_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void add_appointment(char* name, int appointment_id, time_t start_time, time_t end_time) {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return;
    }

    strncpy(appointments[appointment_count].name, name, MAX_NAME_LENGTH);
    appointments[appointment_count].appointment_id = appointment_id;
    appointments[appointment_count].start_time = start_time;
    appointments[appointment_count].end_time = end_time;

    appointment_count++;
}

void print_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%s: %d (%s - %s)\n", appointments[i].name, appointments[i].appointment_id, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

void remove_appointment(int appointment_id) {
    for (int i = 0; i < appointment_count; i++) {
        if (appointments[i].appointment_id == appointment_id) {
            for (int j = i; j < appointment_count - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            appointment_count--;
            return;
        }
    }

    printf("Error: Appointment not found.\n");
}

int main() {
    add_appointment("John Doe", 1, time(NULL), time(NULL) + 60 * 60);
    add_appointment("Jane Doe", 2, time(NULL) + 60 * 60, time(NULL) + 60 * 60 * 2);

    print_appointments();

    remove_appointment(1);

    print_appointments();

    return 0;
}