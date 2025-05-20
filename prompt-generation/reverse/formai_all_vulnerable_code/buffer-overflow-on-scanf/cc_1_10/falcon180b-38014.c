//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int appointment_time;
} Appointment;

int main() {
    int num_appointments, i, j;
    Appointment appointments[MAX_APPOINTMENTS];
    char input[100];
    time_t current_time;
    struct tm *current_tm;

    printf("Welcome to the Alan Turing Appointment Scheduler!\n\n");

    while (1) {
        printf("Enter the current time (HH:MM): ");
        scanf("%s", input);
        current_time = mktime(strptime(input, "%H:%M"));
        current_tm = localtime(&current_time);

        printf("\n");
        printf("Current time: %s\n", asctime(current_tm));

        printf("\n");
        printf("Enter the number of appointments for the day (up to %d): ", MAX_APPOINTMENTS);
        scanf("%d", &num_appointments);

        for (i = 0; i < num_appointments; i++) {
            printf("\n");
            printf("Enter appointment %d (name and time in HH:MM format): ", i+1);
            scanf("%s", input);

            strcpy(appointments[i].name, input);
            appointments[i].appointment_time = mktime(strptime(input, "%H:%M"));
        }

        printf("\n");
        printf("Appointments for the day:\n");
        for (i = 0; i < num_appointments; i++) {
            printf("Appointment %d: %s at %s\n", i+1, appointments[i].name, ctime(&appointments[i].appointment_time));
        }

        printf("\n");
        printf("Do you want to schedule another day? (y/n): ");
        scanf(" %c", &input[0]);
        if (input[0] == 'n') {
            break;
        }
    }

    return 0;
}