//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DAYS_IN_WEEK 7
#define HOURS_IN_DAY 24

typedef struct {
    char name[50];
    int day;
    int hour;
} Appointment;

void display_appointments(Appointment appointments[], int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s | %d | %d\n", appointments[i].name, appointments[i].day, appointments[i].hour);
    }
}

void sort_appointments(Appointment appointments[], int num_appointments) {
    for (int i = 0; i < num_appointments - 1; i++) {
        for (int j = i + 1; j < num_appointments; j++) {
            if (appointments[i].day > appointments[j].day) {
                Appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            } else if (appointments[i].day == appointments[j].day && appointments[i].hour > appointments[j].hour) {
                Appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }
}

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name of person (or type 'done' to finish): ");
        scanf("%s", appointments[num_appointments].name);

        if (strcmp(appointments[num_appointments].name, "done") == 0) {
            break;
        }

        printf("Enter day of appointment (1-7): ");
        scanf("%d", &appointments[num_appointments].day);

        printf("Enter hour of appointment (0-23): ");
        scanf("%d", &appointments[num_appointments].hour);

        num_appointments++;
    }

    printf("Appointments:\n");
    display_appointments(appointments, num_appointments);

    sort_appointments(appointments, num_appointments);

    printf("\nSorted Appointments:\n");
    display_appointments(appointments, num_appointments);

    return 0;
}