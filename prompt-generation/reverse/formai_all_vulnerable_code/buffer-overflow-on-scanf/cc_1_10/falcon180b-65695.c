//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    time_t start_time;
};

void* schedule_appointments(void* arg) {
    struct appointment* appointments = (struct appointment*) arg;
    int i, j;

    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].name[0] == '\0') {
            break;
        }

        for (j = i + 1; j < MAX_APPOINTMENTS; j++) {
            if (appointments[j].name[0] == '\0') {
                continue;
            }

            if (difftime(appointments[i].start_time, appointments[j].start_time) > 0) {
                struct appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char input[100];
    pthread_t thread_id;

    printf("Enter number of appointments: ");
    scanf("%d", &num_appointments);

    printf("Enter appointment details:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name for appointment %d: ", i + 1);
        scanf("%s", appointments[i].name);

        printf("Start time for appointment %d (YYYY-MM-DD HH:MM:SS): ", i + 1);
        scanf("%s", input);
        strptime(input, "%Y-%m-%d %H:%M:%S", &appointments[i].start_time);
    }

    printf("Scheduling appointments...\n");
    pthread_create(&thread_id, NULL, schedule_appointments, (void*) appointments);
    pthread_join(thread_id, NULL);

    printf("Appointments scheduled successfully!\n");

    return 0;
}