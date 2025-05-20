//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    int year, month, day, hour, minute;
};

int main() {
    int num_appointments = 0;
    struct appointment appointments[MAX_APPOINTMENTS];

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter name for appointment (%d/%d remaining): ", MAX_APPOINTMENTS - num_appointments, MAX_APPOINTMENTS);
        scanf("%s", appointments[num_appointments].name);

        printf("Enter year (YYYY): ");
        scanf("%d", &appointments[num_appointments].year);

        printf("Enter month (1-12): ");
        scanf("%d", &appointments[num_appointments].month);

        printf("Enter day (1-31): ");
        scanf("%d", &appointments[num_appointments].day);

        printf("Enter hour (0-23): ");
        scanf("%d", &appointments[num_appointments].hour);

        printf("Enter minute (0-59): ");
        scanf("%d", &appointments[num_appointments].minute);

        num_appointments++;
    }

    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    printf("\nCurrent time: %s\n", asctime(local_time));

    while (1) {
        sleep(60); // Refresh every minute

        time_t current_time = time(NULL);
        struct tm *current_local_time = localtime(&current_time);

        int current_hour = current_local_time->tm_hour;
        int current_minute = current_local_time->tm_min;

        for (int i = 0; i < num_appointments; i++) {
            if (current_hour == appointments[i].hour && current_minute == appointments[i].minute) {
                printf("\aAppointment with %s at %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].month, appointments[i].day, appointments[i].year, appointments[i].hour, appointments[i].minute);
            }
        }
    }

    return 0;
}