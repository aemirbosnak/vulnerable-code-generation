//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter day (1-31): ");
    scanf("%d", &appointments[num_appointments].day);

    printf("Enter month (1-12): ");
    scanf("%d", &appointments[num_appointments].month);

    printf("Enter year (YYYY): ");
    scanf("%d", &appointments[num_appointments].year);

    printf("Enter hour (0-23): ");
    scanf("%d", &appointments[num_appointments].hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &appointments[num_appointments].minute);

    num_appointments++;
}

void view_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        struct tm appointment_time;
        appointment_time.tm_year = appointments[i].year - 1900;
        appointment_time.tm_mon = appointments[i].month - 1;
        appointment_time.tm_mday = appointments[i].day;
        appointment_time.tm_hour = appointments[i].hour;
        appointment_time.tm_min = appointments[i].minute;

        time_t appointment_timestamp = mktime(&appointment_time);
        char appointment_date[20];
        strftime(appointment_date, 20, "%Y-%m-%d %H:%M", &appointment_time);

        printf("%s - %s\n", appointments[i].name, appointment_date);
    }
}

int main() {
    printf("Welcome to the appointment scheduler!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}