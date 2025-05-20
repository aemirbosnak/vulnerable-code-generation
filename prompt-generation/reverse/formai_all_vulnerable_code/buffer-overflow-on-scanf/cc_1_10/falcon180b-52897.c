//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
};

void print_appointment(struct appointment appt) {
    printf("%s: %s - %s\n", appt.name, ctime(&appt.start_time), ctime(&appt.end_time));
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char input[MAX_NAME_LENGTH];
    time_t now, start_time, end_time;

    now = time(NULL);

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name of appointment (leave blank to finish): ");
        scanf("%s", input);

        if (input[0] == '\0') {
            break;
        }

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        start_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        end_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);

        if ((end_time - start_time) < 0) {
            printf("End time must be after start time.\n");
            continue;
        }

        appointments[num_appointments].name[0] = '\0';
        strncat(appointments[num_appointments].name, input, MAX_NAME_LENGTH - 1);
        appointments[num_appointments].start_time = start_time;
        appointments[num_appointments].end_time = end_time;

        num_appointments++;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}