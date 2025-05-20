//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_DURATION 120

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int duration;
    time_t start_time;
} Appointment;

void print_appointment(Appointment appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Description: %s\n", appointment.description);
    printf("Duration: %d minutes\n", appointment.duration);
    printf("Start Time: %s\n", ctime(&appointment.start_time));
}

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name of appointment (or 'done' to finish): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter description of appointment: ");
        char description[MAX_DESCRIPTION_LENGTH];
        scanf("%s", description);

        printf("Enter duration of appointment (in minutes): ");
        int duration;
        scanf("%d", &duration);

        if (duration < 1 || duration > MAX_DURATION) {
            printf("Invalid duration.\n");
            continue;
        }

        time_t now = time(NULL);
        appointments[num_appointments].start_time = now + (duration * 60);
        strcpy(appointments[num_appointments].name, name);
        strcpy(appointments[num_appointments].description, description);
        appointments[num_appointments].duration = duration;
        num_appointments++;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}