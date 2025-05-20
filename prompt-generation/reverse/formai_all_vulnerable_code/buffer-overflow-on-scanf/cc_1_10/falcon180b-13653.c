//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    time_t start_time;
    time_t end_time;
};

void print_appointments(struct appointment appointments[], int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name for appointment (or press enter to finish): ");
        scanf("%s", appointments[num_appointments].name);

        if (appointments[num_appointments].name[0] == '\0') {
            break;
        }

        printf("Enter start time (yyyy-mm-dd hh:mm:ss): ");
        scanf("%s", appointments[num_appointments].name);

        if (appointments[num_appointments].start_time == 0) {
            printf("Invalid start time.\n");
        } else {
            num_appointments++;
        }

        printf("Enter end time (yyyy-mm-dd hh:mm:ss): ");
        scanf("%s", appointments[num_appointments - 1].end_time);

        if (appointments[num_appointments - 1].end_time == 0) {
            printf("Invalid end time.\n");
            num_appointments--;
        } else {
            appointments[num_appointments - 1].end_time = appointments[num_appointments - 1].start_time + 60 * 60; // add one hour to end time
        }
    }

    print_appointments(appointments, num_appointments);

    return 0;
}