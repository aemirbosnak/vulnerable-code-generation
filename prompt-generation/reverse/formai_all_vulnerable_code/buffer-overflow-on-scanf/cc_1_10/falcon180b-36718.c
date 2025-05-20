//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TIME 24*60 // 24 hours x 60 minutes

typedef struct {
    char name[50];
    int start_time;
    int end_time;
} appointment;

int compare_appointments(const void* a, const void* b) {
    const appointment* app1 = (const appointment*)a;
    const appointment* app2 = (const appointment*)b;

    if (app1->start_time < app2->start_time) {
        return -1;
    } else if (app1->start_time > app2->start_time) {
        return 1;
    } else {
        return 0;
    }
}

void print_appointments(appointment* appointments, int num_appointments) {
    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %02d:%02d - %02d:%02d\n", appointments[i].name, appointments[i].start_time/60, appointments[i].start_time%60, appointments[i].end_time/60, appointments[i].end_time%60);
    }
}

int main() {
    int num_appointments;
    printf("Enter number of appointments: ");
    scanf("%d", &num_appointments);

    appointment* appointments = malloc(num_appointments * sizeof(appointment));

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter start time (HH:MM): ");
        scanf("%d:%d", &appointments[i].start_time);

        printf("Enter end time (HH:MM): ");
        scanf("%d:%d", &appointments[i].end_time);

        if (appointments[i].start_time >= appointments[i].end_time) {
            printf("Invalid appointment times.\n");
            exit(1);
        }
    }

    print_appointments(appointments, num_appointments);

    free(appointments);
    return 0;
}