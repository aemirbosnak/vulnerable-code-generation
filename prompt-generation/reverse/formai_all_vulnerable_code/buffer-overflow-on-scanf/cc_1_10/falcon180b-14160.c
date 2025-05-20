//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

struct appointment {
    char name[MAX_LENGTH];
    char date[MAX_LENGTH];
    char time[MAX_LENGTH];
    int duration;
    int priority;
};

int compare_appointments(const void *a, const void *b) {
    struct appointment *appointment1 = (struct appointment *)a;
    struct appointment *appointment2 = (struct appointment *)b;

    if (appointment1->priority > appointment2->priority) {
        return -1;
    } else if (appointment1->priority < appointment2->priority) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_appointments, i;
    struct appointment appointments[100];

    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    for (i = 0; i < num_appointments; i++) {
        printf("Enter the name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter the date for appointment %d (DD/MM/YYYY): ", i+1);
        scanf("%s", appointments[i].date);

        printf("Enter the time for appointment %d (HH:MM): ", i+1);
        scanf("%s", appointments[i].time);

        appointments[i].duration = 0;
        appointments[i].priority = 0;
    }

    qsort(appointments, num_appointments, sizeof(struct appointment), compare_appointments);

    for (i = 0; i < num_appointments; i++) {
        printf("Appointment %d: %s on %s at %s (duration: %d minutes, priority: %d)\n",
               i+1, appointments[i].name, appointments[i].date, appointments[i].time,
               appointments[i].duration, appointments[i].priority);
    }

    return 0;
}