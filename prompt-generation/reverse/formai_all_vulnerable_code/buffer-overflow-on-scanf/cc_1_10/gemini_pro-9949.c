//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment_t;

void print_appointment(appointment_t *appt) {
    printf("%s\n", appt->description);
    printf("Date: %d/%d/%d\n", appt->day, appt->month, appt->year);
    printf("Time: %d:%d\n", appt->hour, appt->minute);
}

int compare_appointments(appointment_t *appt1, appointment_t *appt2) {
    if (appt1->year != appt2->year) {
        return appt1->year - appt2->year;
    }
    if (appt1->month != appt2->month) {
        return appt1->month - appt2->month;
    }
    if (appt1->day != appt2->day) {
        return appt1->day - appt2->day;
    }
    if (appt1->hour != appt2->hour) {
        return appt1->hour - appt2->hour;
    }
    return appt1->minute - appt2->minute;
}

void sort_appointments(appointment_t **appts, int num_appts) {
    int i, j;
    appointment_t *temp;
    for (i = 0; i < num_appts - 1; i++) {
        for (j = 0; j < num_appts - i - 1; j++) {
            if (compare_appointments(appts[j], appts[j + 1]) > 0) {
                temp = appts[j];
                appts[j] = appts[j + 1];
                appts[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num_appts;
    appointment_t **appts;
    int i;
    char input[100];

    printf("How many appointments do you want to schedule? ");
    scanf("%d", &num_appts);

    appts = (appointment_t **)malloc(num_appts * sizeof(appointment_t *));
    for (i = 0; i < num_appts; i++) {
        appts[i] = (appointment_t *)malloc(sizeof(appointment_t));
        printf("Enter the description of appointment %d: ", i + 1);
        scanf("%s", input);
        appts[i]->description = (char *)malloc(strlen(input) + 1);
        strcpy(appts[i]->description, input);
        printf("Enter the date of appointment %d (dd/mm/yyyy): ", i + 1);
        scanf("%d/%d/%d", &appts[i]->day, &appts[i]->month, &appts[i]->year);
        printf("Enter the time of appointment %d (hh:mm): ", i + 1);
        scanf("%d:%d", &appts[i]->hour, &appts[i]->minute);
    }

    sort_appointments(appts, num_appts);

    printf("\nYour appointments:\n");
    for (i = 0; i < num_appts; i++) {
        print_appointment(appts[i]);
        printf("\n");
    }

    return 0;
}