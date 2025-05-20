//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_APPOINTMENT_LENGTH 80

typedef struct {
    int id;
    char description[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment_t;

int main() {
    int num_appointments = 0;
    appointment_t appointments[MAX_APPOINTMENTS];

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter appointment ID (0 to quit): ");
        int id;
        scanf("%d", &id);

        if (id == 0) {
            break;
        }

        printf("Enter appointment description: ");
        char description[MAX_APPOINTMENT_LENGTH];
        scanf("%s", description);

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        time_t start_time;
        scanf("%s", &start_time);

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        time_t end_time;
        scanf("%s", &end_time);

        appointments[num_appointments].id = id;
        strcpy(appointments[num_appointments].description, description);
        appointments[num_appointments].start_time = start_time;
        appointments[num_appointments].end_time = end_time;

        num_appointments++;
    }

    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d: %s (%s - %s)\n", appointments[i].id, appointments[i].description, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }

    return 0;
}