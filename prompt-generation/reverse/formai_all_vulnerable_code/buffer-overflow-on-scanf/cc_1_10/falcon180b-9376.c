//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_WEEK 7
#define MAX_APPOINTMENTS 50

typedef struct {
    char name[50];
    char description[100];
    time_t start_time;
    time_t end_time;
} Appointment;

void print_appointment(Appointment appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Description: %s\n", appointment.description);
    printf("Start time: %s\n", ctime(&appointment.start_time));
    printf("End time: %s\n\n", ctime(&appointment.end_time));
}

int compare_appointments(const void* a, const void* b) {
    const Appointment* appointment1 = a;
    const Appointment* appointment2 = b;

    if (appointment1->start_time < appointment2->start_time) {
        return -1;
    } else if (appointment1->start_time > appointment2->start_time) {
        return 1;
    } else {
        return 0;
    }
}

void add_appointment(Appointment* appointments, int num_appointments, char* name, char* description, time_t start_time, time_t end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, you cannot add more appointments.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].description, description);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    num_appointments++;
}

void delete_appointment(Appointment* appointments, int num_appointments, int index) {
    if (index < 0 || index >= num_appointments) {
        printf("Invalid appointment index.\n");
        return;
    }

    for (int i = index; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    num_appointments--;
}

void display_appointments(Appointment* appointments, int num_appointments) {
    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }
}

int main() {
    srand(time(NULL));

    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[50];
    char description[100];

    while (1) {
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter description: ");
        scanf("%s", description);

        time_t start_time = time(NULL) + rand() % 86400; // Random start time within 24 hours
        time_t end_time = start_time + 3600; // 1 hour duration

        add_appointment(appointments, num_appointments, name, description, start_time, end_time);

        printf("Appointment added.\n");
    }

    return 0;
}