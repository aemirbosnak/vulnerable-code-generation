//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_WAIT_TIME 5

typedef struct {
    int id;
    time_t appointment_time;
    char name[50];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void *appointment_scheduler(void *arg) {
    int i;
    time_t current_time;

    for (;;) {
        time(&current_time);

        for (i = 0; i < num_clients; i++) {
            if (difftime(current_time, clients[i].appointment_time) <= 0) {
                printf("Client %d (%s) has an appointment at %s\n", clients[i].id, clients[i].name, ctime(&clients[i].appointment_time));
            }
        }

        sleep(1);
    }

    return NULL;
}

void add_client(int id, time_t appointment_time, char *name) {
    if (num_clients >= MAX_CLIENTS) {
        printf("Sorry, we are fully booked.\n");
        return;
    }

    clients[num_clients].id = id;
    clients[num_clients].appointment_time = appointment_time;
    strcpy(clients[num_clients].name, name);

    num_clients++;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, appointment_scheduler, NULL);
}

int main() {
    srand(time(NULL));

    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        add_client(i + 1, time(NULL) + rand() % MAX_WAIT_TIME, "Client");
    }

    printf("Appointment scheduler started.\n");

    return 0;
}