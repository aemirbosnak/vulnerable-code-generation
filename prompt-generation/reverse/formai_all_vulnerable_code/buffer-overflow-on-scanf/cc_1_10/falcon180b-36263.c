//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[10];
    char time[10];
} Appointment;

int compare_appointments(const void *a, const void *b) {
    const Appointment *appointment1 = a;
    const Appointment *appointment2 = b;

    if (appointment1->date[8] == '1' && appointment2->date[8] == '0') {
        return 1;
    } else if (appointment1->date[8] == '0' && appointment2->date[8] == '1') {
        return -1;
    } else {
        return strcmp(appointment1->date, appointment2->date);
    }
}

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    printf("Welcome to the C Appointment Scheduler!\n");
    printf("How many appointments would you like to schedule? ");
    scanf("%d", &num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter the name for appointment %d: ", i + 1);
        scanf("%s", appointments[i].name);

        printf("Enter the date (YYYY-MM-DD) for appointment %d: ", i + 1);
        scanf("%s", appointments[i].date);

        printf("Enter the time (HH:MM) for appointment %d: ", i + 1);
        scanf("%s", appointments[i].time);
    }

    qsort(appointments, num_appointments, sizeof(Appointment), compare_appointments);

    printf("\nAppointments sorted by date and time:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s on %s at %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }

    return 0;
}