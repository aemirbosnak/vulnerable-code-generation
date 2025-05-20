//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int date;
    int month;
    int year;
    int hour;
    int minute;
    int duration;
} Appointment;

int compare_dates(const void *a, const void *b) {
    const Appointment *appointment_a = a;
    const Appointment *appointment_b = b;

    if (appointment_a->date < appointment_b->date) {
        return -1;
    } else if (appointment_a->date > appointment_b->date) {
        return 1;
    } else if (appointment_a->month < appointment_b->month) {
        return -1;
    } else if (appointment_a->month > appointment_b->month) {
        return 1;
    } else if (appointment_a->year < appointment_b->year) {
        return -1;
    } else if (appointment_a->year > appointment_b->year) {
        return 1;
    } else {
        return 0;
    }
}

void print_appointments(Appointment appointments[], int num_appointments) {
    qsort(appointments, num_appointments, sizeof(Appointment), compare_dates);

    printf("Name\tDate\tTime\tDuration\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%d-%02d-%02d\t%02d:%02d\t%d minutes\n",
               appointments[i].name,
               appointments[i].date,
               appointments[i].month,
               appointments[i].year,
               appointments[i].hour,
               appointments[i].minute,
               appointments[i].duration);
    }
}

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name for appointment (leave blank to finish): ");
        scanf("%s", appointments[num_appointments].name);

        if (appointments[num_appointments].name[0] == '\0') {
            break;
        }

        printf("Enter date (dd-mm-yyyy): ");
        scanf("%d-%02d-%02d", &appointments[num_appointments].date,
               &appointments[num_appointments].month,
               &appointments[num_appointments].year);

        printf("Enter time (hh:mm): ");
        scanf("%d:%d", &appointments[num_appointments].hour,
               &appointments[num_appointments].minute);

        printf("Enter duration in minutes: ");
        scanf("%d", &appointments[num_appointments].duration);

        num_appointments++;
    }

    print_appointments(appointments, num_appointments);

    return 0;
}