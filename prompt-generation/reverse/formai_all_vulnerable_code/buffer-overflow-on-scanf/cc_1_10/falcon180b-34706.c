//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 100
#define TIME_FORMAT "%I:%M %p"

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

void add_appointment(appointment* appointments, int num_appointments, char* name, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_APPOINTMENT_LENGTH);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void print_appointments(appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    time_t current_time = time(NULL);
    struct tm* time_info = localtime(&current_time);

    printf("Current time: %s\n", asctime(time_info));

    char name[MAX_APPOINTMENT_LENGTH];
    while (1) {
        printf("Enter name for appointment: ");
        scanf("%s", name);

        time_t start_time, end_time;
        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", name);
        start_time = mktime(time_info);

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", name);
        end_time = mktime(time_info);

        add_appointment(appointments, num_appointments, name, start_time, end_time);
        num_appointments++;
    }

    return 0;
}