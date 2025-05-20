//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char* name;
    time_t start_time;
    time_t end_time;
    int duration;
};

int main() {
    int num_appointments = 0;
    struct appointment* appointments = malloc(MAX_APPOINTMENTS * sizeof(struct appointment));

    if (appointments == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter appointment details (name, start time, end time, duration):\n");
        char* name = NULL;
        time_t start_time, end_time;
        int duration;

        scanf("%s %ld %ld %d", name, &start_time, &end_time, &duration);

        struct tm* start_tm = localtime(&start_time);
        struct tm* end_tm = localtime(&end_time);

        printf("Appointment %d:\n", num_appointments + 1);
        printf("Name: %s\n", name);
        printf("Start time: %s\n", asctime(start_tm));
        printf("End time: %s\n", asctime(end_tm));
        printf("Duration: %d minutes\n\n", duration);

        appointments[num_appointments].name = name;
        appointments[num_appointments].start_time = start_time;
        appointments[num_appointments].end_time = end_time;
        appointments[num_appointments].duration = duration;

        num_appointments++;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Start time: %s\n", ctime(&appointments[i].start_time));
        printf("End time: %s\n", ctime(&appointments[i].end_time));
        printf("Duration: %d minutes\n\n", appointments[i].duration);
    }

    free(appointments);

    return 0;
}