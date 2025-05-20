//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_DATE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    int time;
} Appointment;

int compare_appointments(const void *a, const void *b) {
    const Appointment *appointment_a = a;
    const Appointment *appointment_b = b;

    int result = strcmp(appointment_a->date, appointment_b->date);
    if (result == 0) {
        result = appointment_a->time - appointment_b->time;
    }

    return result;
}

void print_appointments(Appointment *appointments, int num_appointments) {
    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("%s on %s at %d\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char input[MAX_DATE_LENGTH];
    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter an appointment (name date time): ");
        scanf("%s %s %d", appointments[num_appointments].name, appointments[num_appointments].date, &appointments[num_appointments].time);
        num_appointments++;
    }

    print_appointments(appointments, num_appointments);

    return 0;
}