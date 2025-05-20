//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
/*
 * A unique C Appointment Scheduler example program in a standalone style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 128

struct appointment {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
};

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    // Get input from user
    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter the name of appointment %d: ", i + 1);
        scanf("%s", appointments[i].name);

        printf("Enter the description of appointment %d: ", i + 1);
        scanf("%s", appointments[i].description);

        printf("Enter the start time of appointment %d: ", i + 1);
        scanf("%ld", &appointments[i].start_time);

        printf("Enter the end time of appointment %d: ", i + 1);
        scanf("%ld", &appointments[i].end_time);
    }

    // Print the appointments
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%s): %ld - %ld\n", appointments[i].name, appointments[i].description, appointments[i].start_time, appointments[i].end_time);
    }

    return 0;
}