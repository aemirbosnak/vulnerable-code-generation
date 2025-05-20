//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 80

struct appointment {
    char description[MAX_APPOINTMENT_LENGTH];
    time_t start_time;
    time_t end_time;
};

void print_appointment(struct appointment* a) {
    printf("%s: %s - %s\n", a->description, ctime(&a->start_time), ctime(&a->end_time));
}

int compare_appointments(const void* a, const void* b) {
    struct appointment* appointment_a = (struct appointment*) a;
    struct appointment* appointment_b = (struct appointment*) b;

    time_t start_time_a = appointment_a->start_time;
    time_t start_time_b = appointment_b->start_time;

    if (start_time_a < start_time_b) {
        return -1;
    } else if (start_time_a > start_time_b) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_appointments;
    printf("Enter the number of appointments (up to %d): ", MAX_APPOINTMENTS);
    scanf("%d", &num_appointments);

    struct appointment appointments[MAX_APPOINTMENTS];

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter appointment %d:\n", i+1);
        printf("Description: ");
        scanf("%s", appointments[i].description);

        printf("Start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].description);
        appointments[i].start_time = strptime(appointments[i].description, "%Y-%m-%d %H:%M:%S", NULL);

        printf("End time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].description);
        appointments[i].end_time = strptime(appointments[i].description, "%Y-%m-%d %H:%M:%S", NULL);
    }

    qsort(appointments, num_appointments, sizeof(struct appointment), compare_appointments);

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}