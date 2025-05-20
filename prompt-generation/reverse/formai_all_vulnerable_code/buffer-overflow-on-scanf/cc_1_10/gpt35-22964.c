//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct appointment {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
bool done = false;

void* scheduler(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (num_appointments == 0 && !done) {
            pthread_cond_wait(&cond, &mutex);
        }

        if (done) {
            pthread_mutex_unlock(&mutex);
            return NULL;
        }

        time_t current_time;
        time(&current_time);

        for (int i = 0; i < num_appointments; i++) {
            if (current_time >= appointments[i].start_time && current_time < appointments[i].end_time) {
                printf("%s, your appointment has started!\n", appointments[i].name);
                strcpy(appointments[i].name, "");
                appointments[i].start_time = 0;
                appointments[i].end_time = 0;
            }
        }

        pthread_mutex_unlock(&mutex);
    }
}

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, maximum number of appointments has been reached.\n");
        return;
    }

    Appointment new_appointment;

    printf("Enter name: ");
    fgets(new_appointment.name, MAX_NAME_LENGTH, stdin);
    new_appointment.name[strcspn(new_appointment.name, "\n")] = 0;

    printf("Enter start time (in seconds since epoch): ");
    scanf("%ld", &new_appointment.start_time);
    getchar();

    printf("Enter end time (in seconds since epoch): ");
    scanf("%ld", &new_appointment.end_time);
    getchar();

    appointments[num_appointments++] = new_appointment;

    pthread_cond_signal(&cond);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, scheduler, NULL);

    while (1) {
        char command[10];
        printf("Enter a command (add or exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            add_appointment();
        } else if (strcmp(command, "exit") == 0) {
            done = true;
            pthread_cond_signal(&cond);
            pthread_join(thread, NULL);
            return 0;
        } else {
            printf("Invalid command.\n");
        }
    }
}