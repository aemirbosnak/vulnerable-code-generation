//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct appointment {
    char* name;
    char* description;
    int start_time;
    int end_time;
    int duration;
    int status;
} appointment;

int main() {
    int num_appointments;
    char* appointment_name[10];
    char* appointment_description[10];
    int appointment_start_time[10];
    int appointment_end_time[10];
    int appointment_duration[10];
    int appointment_status[10];

    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    appointment appointments[num_appointments];

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter the name of appointment %d: ", i+1);
        scanf("%s", appointment_name[i]);

        printf("Enter the description of appointment %d: ", i+1);
        scanf("%s", appointment_description[i]);

        printf("Enter the start time of appointment %d: ", i+1);
        scanf("%d", &appointment_start_time[i]);

        printf("Enter the end time of appointment %d: ", i+1);
        scanf("%d", &appointment_end_time[i]);

        printf("Enter the duration of appointment %d: ", i+1);
        scanf("%d", &appointment_duration[i]);

        printf("Enter the status of appointment %d (1 - confirmed, 0 - pending): ", i+1);
        scanf("%d", &appointment_status[i]);
    }

    srand(time(NULL));

    for (int i = 0; i < num_appointments; i++) {
        appointment current_appointment = appointments[i];

        if (appointment_status[i] == 1) {
            printf("Appointment %s - %s has been confirmed and will take place from %02d:%02d to %02d:%02d for %d minutes.\n", current_appointment.name, current_appointment.description, current_appointment.start_time / 100, current_appointment.start_time % 100, current_appointment.end_time / 100, current_appointment.end_time % 100, current_appointment.duration);
        } else if (appointment_status[i] == 0) {
            printf("Appointment %s - %s is pending.\n", current_appointment.name, current_appointment.description);
        }
    }

    return 0;
}