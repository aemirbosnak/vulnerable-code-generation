//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

void print_appointments(Appointment appointments[], int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s on %d/%d/%d at %d:%d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
    }
}

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];
    char input[MAX_NAME_LENGTH];

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name for appointment (or 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        printf("Enter day (1-31): ");
        scanf("%d", &appointments[num_appointments].day);

        printf("Enter month (1-12): ");
        scanf("%d", &appointments[num_appointments].month);

        printf("Enter year (e.g. 2022): ");
        scanf("%d", &appointments[num_appointments].year);

        printf("Enter hour (0-23): ");
        scanf("%d", &appointments[num_appointments].hour);

        printf("Enter minute (0-59): ");
        scanf("%d", &appointments[num_appointments].minute);

        num_appointments++;
    }

    printf("Appointments:\n");
    print_appointments(appointments, num_appointments);

    return 0;
}