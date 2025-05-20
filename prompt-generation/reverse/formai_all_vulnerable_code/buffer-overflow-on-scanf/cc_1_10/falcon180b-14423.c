//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} appointment;

int compare_appointments(const void* a, const void* b) {
    const appointment* apt_a = (const appointment*) a;
    const appointment* apt_b = (const appointment*) b;

    time_t diff = difftime(apt_a->start_time, apt_b->start_time);

    if (diff < 0) {
        return -1;
    } else if (diff > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_appointments;
    appointment* appointments;
    char input[MAX_NAME_LENGTH + MAX_DESCRIPTION_LENGTH + 10];

    printf("Enter number of appointments: ");
    scanf("%d", &num_appointments);

    appointments = (appointment*) malloc(sizeof(appointment) * num_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter name and description for appointment %d: ", i + 1);
        scanf("%s", input);

        strcpy(appointments[i].name, input);

        printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);

        appointments[i].start_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);

        printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);

        appointments[i].end_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);
    }

    qsort(appointments, num_appointments, sizeof(appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s\n%s - %s\n", ctime(&appointments[i].start_time), ctime(&appointments[i].end_time));
    }

    return 0;
}