//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct Appointment {
    char *name;
    char *description;
    int start_time;
    int end_time;
} Appointment;

Appointment *appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

int compare_appointments(const void *a, const void *b) {
    Appointment *appt1 = (Appointment *)a;
    Appointment *appt2 = (Appointment *)b;

    return appt1->start_time - appt2->start_time;
}

bool is_overlapping(Appointment *appt1, Appointment *appt2) {
    return appt1->start_time < appt2->end_time && appt2->start_time < appt1->end_time;
}

void add_appointment(char *name, char *description, int start_time, int end_time) {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Error: No more appointments can be added.\n");
        return;
    }

    for (int i = 0; i < num_appointments; i++) {
        if (is_overlapping(appointments[i], &appointments[num_appointments])) {
            printf("Error: Appointment overlaps with an existing appointment.\n");
            return;
        }
    }

    appointments[num_appointments] = malloc(sizeof(Appointment));
    appointments[num_appointments]->name = strdup(name);
    appointments[num_appointments]->description = strdup(description);
    appointments[num_appointments]->start_time = start_time;
    appointments[num_appointments]->end_time = end_time;
    num_appointments++;

    qsort(appointments, num_appointments, sizeof(Appointment *), compare_appointments);

    printf("Appointment added successfully.\n");
}

void print_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%d-%d): %s\n",
            appointments[i]->name,
            appointments[i]->start_time,
            appointments[i]->end_time,
            appointments[i]->description);
    }
}

void free_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        free(appointments[i]->name);
        free(appointments[i]->description);
        free(appointments[i]);
    }

    num_appointments = 0;
}

int main() {
    char name[100];
    char description[100];
    int start_time;
    int end_time;

    while (true) {
        printf("Enter appointment name: ");
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Enter appointment description: ");
        scanf("%s", description);

        printf("Enter appointment start time (hhmm): ");
        scanf("%d", &start_time);

        printf("Enter appointment end time (hhmm): ");
        scanf("%d", &end_time);

        add_appointment(name, description, start_time, end_time);

        print_appointments();
    }

    free_appointments();

    return 0;
}