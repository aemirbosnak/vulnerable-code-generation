//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MINUTES_IN_HOUR 60
#define MINUTES_IN_DAY (24 * MINUTES_IN_HOUR)

typedef struct {
    char name[50];
    int start_hour;
    int start_minute;
    int duration;
} appointment;

void print_appointment(appointment a) {
    printf("%s: %02d:%02d - %02d:%02d\n", a.name, a.start_hour, a.start_minute, a.start_hour + a.duration / MINUTES_IN_HOUR, (a.start_minute + a.duration % MINUTES_IN_HOUR) % MINUTES_IN_HOUR);
}

int compare_appointments(const void *a, const void *b) {
    const appointment *app1 = a;
    const appointment *app2 = b;

    if (app1->start_hour < app2->start_hour) {
        return -1;
    } else if (app1->start_hour > app2->start_hour) {
        return 1;
    } else {
        if (app1->start_minute < app2->start_minute) {
            return -1;
        } else if (app1->start_minute > app2->start_minute) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    int num_appointments;
    appointment appointments[MAX_APPOINTMENTS];

    printf("How many appointments do you want to schedule? (up to %d): ", MAX_APPOINTMENTS);
    scanf("%d", &num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter appointment %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", appointments[i].name);
        printf("Start time (HH:MM): ");
        scanf("%d:%d", &appointments[i].start_hour, &appointments[i].start_minute);
        printf("Duration (in minutes): ");
        scanf("%d", &appointments[i].duration);
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    printf("\nSchedule:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    return 0;
}