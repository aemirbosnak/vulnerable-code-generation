//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    int duration;
};

void print_appointment(struct appointment *app) {
    printf("%s - %s to %s (Duration: %d minutes)\n",
           app->name,
           ctime(&app->start_time),
           ctime(&app->start_time + app->duration * 60));
}

int compare_appointments(const void *a, const void *b) {
    struct appointment *app1 = (struct appointment *)a;
    struct appointment *app2 = (struct appointment *)b;

    return difftime(app1->start_time, app2->start_time);
}

int main() {
    int num_appointments, i;
    struct appointment appointments[MAX_APPOINTMENTS];

    printf("Welcome to the Futuristic Appointment Scheduler!\n");
    printf("How many appointments would you like to schedule? ");
    scanf("%d", &num_appointments);

    for (i = 0; i < num_appointments; i++) {
        printf("Enter the name for appointment %d: ", i + 1);
        scanf("%s", appointments[i].name);

        printf("Enter the start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].name);

        appointments[i].start_time = strptime(appointments[i].name, "%Y-%m-%d %H:%M:%S", NULL);

        printf("Enter the duration in minutes: ");
        scanf("%d", &appointments[i].duration);
    }

    qsort(appointments, num_appointments, sizeof(struct appointment), compare_appointments);

    printf("\nAppointments:\n");
    for (i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}