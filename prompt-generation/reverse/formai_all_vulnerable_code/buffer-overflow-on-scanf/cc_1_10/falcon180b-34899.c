//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

void add_appointment(appointment* a, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", a->name);
    printf("Enter day (1-31): ");
    scanf("%d", &a->day);
    printf("Enter month (1-12): ");
    scanf("%d", &a->month);
    printf("Enter year (YYYY): ");
    scanf("%d", &a->year);
    printf("Enter hour (0-23): ");
    scanf("%d", &a->hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &a->minute);
    num_appointments++;
}

void display_appointments(appointment* a, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %d/%d/%d %d:%d\n", a[i].name, a[i].day, a[i].month, a[i].year, a[i].hour, a[i].minute);
    }
}

int main() {
    appointment a[MAX_APPOINTMENTS];
    int num_appointments = 0;

    add_appointment(a, num_appointments);

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\nDo you want to add another appointment? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'y' || choice == 'Y') {
            add_appointment(a, num_appointments);
        } else {
            break;
        }
    }

    display_appointments(a, num_appointments);

    return 0;
}