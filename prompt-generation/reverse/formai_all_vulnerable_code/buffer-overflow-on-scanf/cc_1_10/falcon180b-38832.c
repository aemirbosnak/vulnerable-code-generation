//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 80

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    char date[MAX_APPOINTMENT_LENGTH];
    char time[MAX_APPOINTMENT_LENGTH];
} appointment;

void add_appointment(appointment *appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);
    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);
}

void print_appointments(appointment *appointments, int num_appointments) {
    printf("Name\tDate\tTime\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int compare_dates(const char *date1, const char *date2) {
    struct tm tm1, tm2;
    strptime(date1, "%Y-%m-%d", &tm1);
    strptime(date2, "%Y-%m-%d", &tm2);
    return mktime(&tm1) - mktime(&tm2);
}

void sort_appointments(appointment *appointments, int num_appointments) {
    qsort(appointments, num_appointments, sizeof(appointment), (int (*)(const void *, const void *)) compare_dates);
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    printf("Enter number of appointments: ");
    scanf("%d", &num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        add_appointment(appointments, i);
    }

    sort_appointments(appointments, num_appointments);
    print_appointments(appointments, num_appointments);

    return 0;
}