//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 100

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    int start_time;
    int end_time;
} Appointment;

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    char input[MAX_APPOINTMENT_LENGTH];
    int start_time, end_time;
    int i, j;

    printf("Welcome to the Appointment Scheduler!\n");

    // Get number of appointments from user
    printf("Enter number of appointments: ");
    scanf("%d", &num_appointments);

    // Get appointment details from user
    for (i = 0; i < num_appointments; i++) {
        printf("Enter name for appointment %d: ", i + 1);
        scanf("%s", appointments[i].name);

        printf("Enter start time (24-hour format): ");
        scanf("%d", &start_time);

        printf("Enter end time (24-hour format): ");
        scanf("%d", &end_time);

        appointments[i].start_time = start_time;
        appointments[i].end_time = end_time;
    }

    // Print schedule
    printf("\nSchedule:\n");
    for (i = 0; i < num_appointments; i++) {
        printf("%s: ", appointments[i].name);
        for (j = appointments[i].start_time; j <= appointments[i].end_time; j++) {
            if (j == 12) {
                printf("12:00 PM");
            } else if (j > 12) {
                printf("%02d:00 PM", j - 12);
            } else {
                printf("%02d:00 AM", j);
            }
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}