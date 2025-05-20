//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_APPOINTMENTS 100
#define MAX_THREADS 10

typedef struct {
    int id;
    time_t start_time;
    time_t end_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void* schedule_appointment(void* arg) {
    int i;
    for (i = 0; i < num_appointments; i++) {
        if (appointments[i].start_time == *(time_t*) arg) {
            printf("Appointment %d scheduled at %s\n", appointments[i].id, ctime(&appointments[i].start_time));
        }
    }
    pthread_exit(0);
}

int main() {
    int i, choice, thread_id;
    time_t current_time;

    srand(time(NULL));

    printf("Welcome to the Appointment Scheduler!\n");
    printf("Please choose an option:\n");
    printf("1. Schedule an appointment\n");
    printf("2. View appointments\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter appointment ID: ");
            scanf("%d", &appointments[num_appointments].id);
            printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", ctime(&appointments[num_appointments].start_time));
            printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", ctime(&appointments[num_appointments].end_time));
            num_appointments++;
            break;
        case 2:
            current_time = time(NULL);
            printf("Current time: %s\n", ctime(&current_time));
            printf("Appointments:\n");
            for (i = 0; i < num_appointments; i++) {
                printf("ID: %d\n", appointments[i].id);
                printf("Start time: %s\n", ctime(&appointments[i].start_time));
                printf("End time: %s\n", ctime(&appointments[i].end_time));
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}