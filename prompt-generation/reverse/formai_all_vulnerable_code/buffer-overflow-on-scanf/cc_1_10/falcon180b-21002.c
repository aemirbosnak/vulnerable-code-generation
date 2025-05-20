//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_DURATION 24*60 // 24 hours * 60 minutes = 1440 minutes

struct appointment {
    char name[MAX_NAME_LENGTH];
    int duration;
    int start_time;
};

int compare_appointments(const void *a, const void *b) {
    struct appointment *appointment1 = (struct appointment *)a;
    struct appointment *appointment2 = (struct appointment *)b;

    if (appointment1->start_time < appointment2->start_time) {
        return -1;
    } else if (appointment1->start_time > appointment2->start_time) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_appointments, i;
    char input[100];
    struct appointment appointments[MAX_APPOINTMENTS];

    printf("Enter number of appointments: ");
    scanf("%d", &num_appointments);

    for (i = 0; i < num_appointments; i++) {
        printf("Enter name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter duration in minutes for appointment %d: ", i+1);
        scanf("%d", &appointments[i].duration);

        printf("Enter start time in minutes for appointment %d: ", i+1);
        scanf("%d", &appointments[i].start_time);
    }

    qsort(appointments, num_appointments, sizeof(struct appointment), compare_appointments);

    printf("\nAppointments:\n");
    for (i = 0; i < num_appointments; i++) {
        printf("%s - %d minutes - starts at %d minutes\n", appointments[i].name, appointments[i].duration, appointments[i].start_time);
    }

    return 0;
}