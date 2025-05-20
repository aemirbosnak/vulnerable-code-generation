//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int year, month, day, hour, minute;
} Appointment;

int compare_appointments(const void *a, const void *b) {
    const Appointment *appointment1 = a;
    const Appointment *appointment2 = b;

    if (appointment1->year < appointment2->year) {
        return -1;
    } else if (appointment1->year > appointment2->year) {
        return 1;
    } else if (appointment1->month < appointment2->month) {
        return -1;
    } else if (appointment1->month > appointment2->month) {
        return 1;
    } else if (appointment1->day < appointment2->day) {
        return -1;
    } else if (appointment1->day > appointment2->day) {
        return 1;
    } else if (appointment1->hour < appointment2->hour) {
        return -1;
    } else if (appointment1->hour > appointment2->hour) {
        return 1;
    } else if (appointment1->minute < appointment2->minute) {
        return -1;
    } else {
        return 0;
    }
}

void print_appointment(const Appointment *appointment) {
    printf("%s on %04d-%02d-%02d %02d:%02d\n", appointment->name, appointment->year, appointment->month, appointment->day, appointment->hour, appointment->minute);
}

int main() {
    int num_appointments = 0;
    Appointment *appointments = NULL;

    printf("Welcome to the Appointment Scheduler!\n");

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter the name for the appointment (or type 'done' to finish): ");
        scanf("%s", appointments[num_appointments].name);

        if (strcmp(appointments[num_appointments].name, "done") == 0) {
            break;
        }

        printf("Enter the year, month, day, hour, and minute for the appointment (in the format YYYY-MM-DD HH:MM): ");
        scanf("%d-%d-%d %d:%d", &appointments[num_appointments].year, &appointments[num_appointments].month, &appointments[num_appointments].day, &appointments[num_appointments].hour, &appointments[num_appointments].minute);
        num_appointments++;
    }

    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

    printf("Your appointments are:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    free(appointments);
    return 0;
}