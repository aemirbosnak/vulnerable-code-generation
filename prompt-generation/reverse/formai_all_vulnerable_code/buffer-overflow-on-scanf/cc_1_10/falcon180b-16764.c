//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int start_time;
    int end_time;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter start time (HH:MM): ");
    scanf("%d:%d", &appointments[num_appointments].start_time, &appointments[num_appointments].end_time);
    num_appointments++;
}

void print_appointments(Appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %02d:%02d\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time);
    }
}

int compare_appointments(const void* a, const void* b) {
    const Appointment* app1 = a;
    const Appointment* app2 = b;
    return (app1->start_time - app2->start_time);
}

void schedule_appointments(Appointment* appointments, int num_appointments) {
    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);
    printf("Scheduled appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %02d:%02d\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(appointments, num_appointments);
    add_appointment(appointments, num_appointments);
    add_appointment(appointments, num_appointments);

    print_appointments(appointments, num_appointments);

    schedule_appointments(appointments, num_appointments);

    return 0;
}