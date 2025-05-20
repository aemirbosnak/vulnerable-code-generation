//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_APPOINTMENTS 100
#define MAX_THREADS 10

struct appointment {
    int id;
    char name[50];
    time_t start_time;
    time_t end_time;
};

struct thread_data {
    int thread_id;
    int num_appointments;
    struct appointment *appointments;
};

void *thread_function(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;

    for (int i = 0; i < data->num_appointments; i++) {
        struct appointment *appointment = &data->appointments[i];

        time_t now = time(NULL);
        if (now >= appointment->start_time && now <= appointment->end_time) {
            printf("Thread %d is handling appointment %d for %s\n", data->thread_id, appointment->id, appointment->name);
        }
    }

    return NULL;
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Error opening appointments file\n");
        exit(1);
    }

    while (fscanf(file, "%d %s %ld %ld", &appointments[num_appointments].id, appointments[num_appointments].name, &appointments[num_appointments].start_time, &appointments[num_appointments].end_time) == 4) {
        num_appointments++;
    }

    fclose(file);

    pthread_t threads[MAX_THREADS];
    struct thread_data thread_data[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].num_appointments = num_appointments / MAX_THREADS;
        if (i == MAX_THREADS - 1) {
            thread_data[i].num_appointments = num_appointments - (MAX_THREADS - 1) * (num_appointments / MAX_THREADS);
        }

        thread_data[i].appointments = appointments;
        pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}