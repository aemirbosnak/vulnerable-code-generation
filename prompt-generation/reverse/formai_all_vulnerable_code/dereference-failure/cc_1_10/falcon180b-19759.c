//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MINUTES_IN_HOUR 60

typedef struct {
    char name[MAX_NAME_LENGTH];
    int appointment_time;
    int appointment_duration;
} appointment;

int main() {
    int num_appointments = 0;
    appointment appointments[MAX_APPOINTMENTS];
    char input_buffer[100];
    time_t current_time;

    // Get current time
    time(&current_time);
    struct tm *current_time_struct = localtime(&current_time);
    int current_hour = current_time_struct->tm_hour;
    int current_minute = current_time_struct->tm_min;

    // Prompt user for appointments
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Enter appointments in the format 'Name Time Duration':\n");

    // Read appointments from input
    while (fgets(input_buffer, sizeof(input_buffer), stdin)!= NULL) {
        char *token = strtok(input_buffer, " ");
        if (token == NULL) {
            continue;
        }
        strcpy(appointments[num_appointments].name, token);
        appointments[num_appointments].appointment_time = atoi(strtok(NULL, " "));
        appointments[num_appointments].appointment_duration = atoi(strtok(NULL, " "));
        num_appointments++;
    }

    // Print schedule for the day
    printf("\nSchedule for the day:\n");
    printf("----------------------\n");
    printf("|  Time  | Appointments |\n");
    printf("----------------------\n");

    // Print header row
    for (int i = current_hour * MINUTES_IN_HOUR; i < 24 * MINUTES_IN_HOUR; i += MINUTES_IN_HOUR) {
        printf("| %02d:%02d |", i / MINUTES_IN_HOUR, i % MINUTES_IN_HOUR);
    }
    printf("\n");

    // Print appointments
    for (int i = 0; i < num_appointments; i++) {
        int appointment_start_time = appointments[i].appointment_time * MINUTES_IN_HOUR;
        int appointment_end_time = appointment_start_time + appointments[i].appointment_duration;
        for (int j = appointment_start_time; j < appointment_end_time; j += MINUTES_IN_HOUR) {
            printf("| %s |", appointments[i].name);
        }
    }

    return 0;
}