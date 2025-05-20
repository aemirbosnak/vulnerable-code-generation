//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    time_t start_time;
    time_t end_time;
} appointment_t;

int main() {
    int num_appointments = 0;
    appointment_t appointments[MAX_APPOINTMENTS];
    char input_buffer[1024];
    char *token;
    time_t current_time;

    time(&current_time);

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter appointment details (name, description, start time, end time):\n");
        fgets(input_buffer, sizeof(input_buffer), stdin);

        token = strtok(input_buffer, " ");
        strncpy(appointments[num_appointments].name, token, MAX_NAME_LEN);

        token = strtok(NULL, " ");
        strncpy(appointments[num_appointments].description, token, MAX_DESC_LEN);

        token = strtok(NULL, " ");
        appointments[num_appointments].start_time = strtol(token, NULL, 10) + current_time;

        token = strtok(NULL, " ");
        appointments[num_appointments].end_time = strtol(token, NULL, 10) + current_time;

        num_appointments++;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %s\n", appointments[i].name, appointments[i].description);
        printf("Start time: %s\n", ctime(&appointments[i].start_time));
        printf("End time: %s\n\n", ctime(&appointments[i].end_time));
    }

    return 0;
}