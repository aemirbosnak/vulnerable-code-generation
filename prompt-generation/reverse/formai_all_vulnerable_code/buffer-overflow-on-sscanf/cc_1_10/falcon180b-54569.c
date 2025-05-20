//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NUM_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 50

typedef struct {
    char title[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

int main() {
    int num_appointments = 0;
    Appointment *appointments = NULL;

    // Initialize appointments array
    appointments = (Appointment*) malloc(MAX_NUM_APPOINTMENTS * sizeof(Appointment));
    if (appointments == NULL) {
        printf("Error: Unable to allocate memory for appointments.\n");
        return 1;
    }

    // Read appointments from file
    FILE *fp = fopen("appointments.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open appointments file.\n");
        return 1;
    }

    char line[MAX_APPOINTMENT_LENGTH];
    while (fgets(line, MAX_APPOINTMENT_LENGTH, fp)!= NULL) {
        if (num_appointments >= MAX_NUM_APPOINTMENTS) {
            printf("Error: Maximum number of appointments reached.\n");
            fclose(fp);
            return 1;
        }

        strcpy(appointments[num_appointments].title, line);
        sscanf(line, "%s %ld:%ld", appointments[num_appointments].title, &appointments[num_appointments].start_time, &appointments[num_appointments].end_time);
        num_appointments++;
    }

    fclose(fp);

    // Display appointments
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s %s - %s\n", ctime(&appointments[i].start_time), appointments[i].title, ctime(&appointments[i].end_time));
    }

    // Free memory
    free(appointments);

    return 0;
}