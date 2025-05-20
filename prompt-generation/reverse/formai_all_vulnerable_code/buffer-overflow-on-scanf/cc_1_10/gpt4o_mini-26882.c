//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define TIME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int count;
    pthread_mutex_t lock;
} Scheduler;

Scheduler scheduler;

void init_scheduler() {
    scheduler.count = 0;
    pthread_mutex_init(&scheduler.lock, NULL);
}

void add_appointment(const char* name, const char* time) {
    pthread_mutex_lock(&scheduler.lock);
    if (scheduler.count < MAX_APPOINTMENTS) {
        strcpy(scheduler.appointments[scheduler.count].name, name);
        strcpy(scheduler.appointments[scheduler.count].time, time);
        scheduler.count++;
        printf("Appointment added for %s at %s\n", name, time);
    } else {
        printf("Error: Maximum appointments reached. Cannot add more.\n");
    }
    pthread_mutex_unlock(&scheduler.lock);
}

void view_appointments() {
    pthread_mutex_lock(&scheduler.lock);
    printf("\nAppointments List:\n");
    for (int i = 0; i < scheduler.count; i++) {
        printf("%d: %s at %s\n", i + 1, scheduler.appointments[i].name, scheduler.appointments[i].time);
    }
    pthread_mutex_unlock(&scheduler.lock);
}

void delete_appointment(int index) {
    pthread_mutex_lock(&scheduler.lock);
    if (index >= 0 && index < scheduler.count) {
        for (int i = index; i < scheduler.count - 1; i++) {
            scheduler.appointments[i] = scheduler.appointments[i + 1];
        }
        scheduler.count--;
        printf("Appointment deleted.\n");
    } else {
        printf("Error: Appointment index out of range.\n");
    }
    pthread_mutex_unlock(&scheduler.lock);
}

void* user_input(void* arg) {
    while (1) {
        char command[10];
        printf("\nEnter command (add/view/delete/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[NAME_LENGTH];
            char time[TIME_LENGTH];
            printf("Enter name: ");
            scanf(" %[^\n]", name);
            printf("Enter time (HH:MM): ");
            scanf(" %[^\n]", time);
            add_appointment(name, time);
        } else if (strcmp(command, "view") == 0) {
            view_appointments();
        } else if (strcmp(command, "delete") == 0) {
            int index;
            printf("Enter appointment number to delete: ");
            scanf("%d", &index);
            delete_appointment(index - 1);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting application.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return NULL;
}

int main() {
    pthread_t input_thread;

    init_scheduler();

    // Start user input thread
    pthread_create(&input_thread, NULL, user_input, NULL);

    // Wait for user input thread to finish
    pthread_join(input_thread, NULL);

    pthread_mutex_destroy(&scheduler.lock);
    return 0;
}