//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 80

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

int main() {
    int num_appointments, i;
    appointment *appointments;
    char input[MAX_APPOINTMENT_LENGTH];

    // prompt user for number of appointments
    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    // allocate memory for appointments
    appointments = (appointment *) malloc(num_appointments * sizeof(appointment));

    // prompt user for appointment details
    for (i = 0; i < num_appointments; i++) {
        printf("Enter the name for appointment #%d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter the start time for appointment #%d (YYYY-MM-DD HH:MM:SS): ", i+1);
        scanf("%s", input);
        appointments[i].start_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);

        printf("Enter the end time for appointment #%d (YYYY-MM-DD HH:MM:SS): ", i+1);
        scanf("%s", input);
        appointments[i].end_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);
    }

    // sort appointments by start time
    for (i = 0; i < num_appointments-1; i++) {
        if (appointments[i].start_time > appointments[i+1].start_time) {
            appointment temp = appointments[i];
            appointments[i] = appointments[i+1];
            appointments[i+1] = temp;
        }
    }

    // print appointments
    printf("\nAppointments:\n");
    for (i = 0; i < num_appointments; i++) {
        printf("%s: %s - %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }

    // free memory
    free(appointments);

    return 0;
}