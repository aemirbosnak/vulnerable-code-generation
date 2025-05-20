//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

struct appointment {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    time_t appointment_time;
    int duration;
};

void print_appointment(struct appointment *appointment) {
    printf("%s (%s)\n", appointment->name, appointment->phone_number);
    printf("Appointment time: %s\n", ctime(&appointment->appointment_time));
    printf("Duration: %d minutes\n\n", appointment->duration);
}

int main() {
    struct appointment *appointments = malloc(MAX_APPOINTMENTS * sizeof(struct appointment));
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name (or 'done' to finish): ");
        scanf("%s", appointments[num_appointments].name);
        if (strcmp(appointments[num_appointments].name, "done") == 0) {
            break;
        }

        printf("Enter phone number: ");
        scanf("%s", appointments[num_appointments].phone_number);

        printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[num_appointments].phone_number);

        printf("Enter duration (in minutes): ");
        scanf("%d", &appointments[num_appointments].duration);

        num_appointments++;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    free(appointments);
    return 0;
}