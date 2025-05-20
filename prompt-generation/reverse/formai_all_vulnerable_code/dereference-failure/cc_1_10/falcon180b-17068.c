//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_TIME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

int compare_appointments(const void* a, const void* b) {
    const Appointment* app1 = a;
    const Appointment* app2 = b;
    return strcmp(app1->time, app2->time);
}

int main() {
    int num_appointments, i;
    Appointment appointments[MAX_APPOINTMENTS];
    char input[MAX_NAME_LENGTH + MAX_TIME_LENGTH + 2];
    time_t current_time;

    // Get current time
    time(&current_time);

    // Get number of appointments
    printf("Enter number of appointments: ");
    scanf("%d", &num_appointments);

    // Get appointments
    for (i = 0; i < num_appointments; i++) {
        printf("Enter appointment #%d (name and time): ", i + 1);
        scanf("%s", input);

        // Split name and time
        char* name = strtok(input, " ");
        strncpy(appointments[i].name, name, MAX_NAME_LENGTH);
        char* time_str = strtok(NULL, " ");
        strncpy(appointments[i].time, time_str, MAX_TIME_LENGTH);
    }

    // Sort appointments by time
    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

    // Print appointments
    printf("\nAppointments:\n");
    for (i = 0; i < num_appointments; i++) {
        printf("%s - %s\n", appointments[i].name, appointments[i].time);
    }

    // Check if any appointments are due
    for (i = 0; i < num_appointments; i++) {
        struct tm appointment_time;
        strptime(appointments[i].time, "%H:%M", &appointment_time);
        time_t appointment_seconds = mktime(&appointment_time);

        if (difftime(appointment_seconds, current_time) <= 0) {
            printf("\n%s is due!\n", appointments[i].name);
        }
    }

    return 0;
}