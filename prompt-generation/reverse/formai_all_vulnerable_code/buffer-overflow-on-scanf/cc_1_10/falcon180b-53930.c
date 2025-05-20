//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_APPOINTMENT_LENGTH 100

typedef struct {
    int id;
    time_t start_time;
    time_t end_time;
    char description[MAX_APPOINTMENT_LENGTH];
} Appointment;

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter appointment ID (0 to quit): ");
        int id = 0;
        scanf("%d", &id);

        if (id == 0) {
            break;
        }

        printf("Enter appointment start time (YYYY-MM-DD HH:MM:SS): ");
        struct tm start_time;
        if (scanf("%d-%d-%d %d:%d:%d", &start_time.tm_year, &start_time.tm_mon, &start_time.tm_mday, &start_time.tm_hour, &start_time.tm_min, &start_time.tm_sec)!= 6) {
            printf("Invalid start time format.\n");
            continue;
        }

        printf("Enter appointment end time (YYYY-MM-DD HH:MM:SS): ");
        struct tm end_time;
        if (scanf("%d-%d-%d %d:%d:%d", &end_time.tm_year, &end_time.tm_mon, &end_time.tm_mday, &end_time.tm_hour, &end_time.tm_min, &end_time.tm_sec)!= 6) {
            printf("Invalid end time format.\n");
            continue;
        }

        printf("Enter appointment description (max %d characters): ", MAX_APPOINTMENT_LENGTH - 1);
        fgets(appointments[num_appointments].description, MAX_APPOINTMENT_LENGTH, stdin);
        appointments[num_appointments].id = id;
        appointments[num_appointments].start_time = mktime(&start_time);
        appointments[num_appointments].end_time = mktime(&end_time);
        num_appointments++;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d: %s\n", appointments[i].id, appointments[i].description);
    }

    return 0;
}