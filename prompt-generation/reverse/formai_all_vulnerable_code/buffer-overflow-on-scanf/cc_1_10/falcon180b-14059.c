//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 10
#define MAX_TIME_LENGTH 8

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

void print_appointment(Appointment* appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Date: %s\n", appointment->date);
    printf("Time: %s\n", appointment->time);
    printf("\n");
}

int compare_appointments(const void* a, const void* b) {
    Appointment* appointment_a = (Appointment*)a;
    Appointment* appointment_b = (Appointment*)b;

    int date_compare = strcmp(appointment_a->date, appointment_b->date);
    if (date_compare!= 0) {
        return date_compare;
    }

    int time_compare = strcmp(appointment_a->time, appointment_b->time);
    if (time_compare!= 0) {
        return time_compare;
    }

    return 0;
}

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name (or type 'done' to finish): ");
        scanf("%s", appointments[num_appointments].name);

        if (strcmp(appointments[num_appointments].name, "done") == 0) {
            break;
        }

        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", appointments[num_appointments].date);

        printf("Enter time (HH:MM): ");
        scanf("%s", appointments[num_appointments].time);

        num_appointments++;
    }

    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}