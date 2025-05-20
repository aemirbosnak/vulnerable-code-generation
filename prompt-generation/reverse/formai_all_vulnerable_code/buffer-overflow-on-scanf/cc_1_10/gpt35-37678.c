//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_APPTS 10

struct Appointment {
    char name[50];
    int start_time;
    int end_time;
};

struct Scheduler {
    struct Appointment appts[MAX_APPTS];
    int num_appts;
    pthread_mutex_t lock;
};

void add_appointment(struct Scheduler *sched, struct Appointment appt) {
    pthread_mutex_lock(&sched->lock);
    if (sched->num_appts < MAX_APPTS) {
        sched->appts[sched->num_appts++] = appt;
        printf("New appointment added to the schedule.\n");
    }
    else {
        printf("Sorry, the schedule is full.\n");
    }
    pthread_mutex_unlock(&sched->lock);
}

void print_schedule(struct Scheduler *sched) {
    pthread_mutex_lock(&sched->lock);
    if (sched->num_appts == 0) {
        printf("There are no appointments scheduled.\n");
    }
    else {
        printf("Schedule:\n");
        for (int i = 0; i < sched->num_appts; i++) {
            printf("%s: %d - %d\n", sched->appts[i].name, sched->appts[i].start_time, sched->appts[i].end_time);
        }
    }
    pthread_mutex_unlock(&sched->lock);
}

void *add_appointment_thread(void *arg) {
    struct Scheduler *sched = (struct Scheduler *)arg;
    struct Appointment appt;
    printf("Enter new appointment name: ");
    fgets(appt.name, 50, stdin);
    printf("Enter start time: ");
    scanf("%d", &appt.start_time);
    printf("Enter end time: ");
    scanf("%d", &appt.end_time);
    add_appointment(sched, appt);
}

void *print_schedule_thread(void *arg) {
    struct Scheduler *sched = (struct Scheduler *)arg;
    print_schedule(sched);
}

int main() {
    struct Scheduler sched = { .num_appts = 0 };
    pthread_mutex_init(&sched.lock, NULL);

    pthread_t add_thread, print_thread;

    pthread_create(&add_thread, NULL, add_appointment_thread, &sched);
    pthread_create(&print_thread, NULL, print_schedule_thread, &sched);

    pthread_join(add_thread, NULL);
    pthread_join(print_thread, NULL);

    pthread_mutex_destroy(&sched.lock);

    return 0;
}