//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_APPOINTMENTS 100
#define DESCRIPTION_LENGTH 256

typedef struct {
    char description[DESCRIPTION_LENGTH];
    int hour;
    int minute;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* add_appointment(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        if (appointment_count < MAX_APPOINTMENTS) {
            Appointment new_appointment;
            printf("Enter appointment description: ");
            fgets(new_appointment.description, DESCRIPTION_LENGTH, stdin);
            new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline
            printf("Enter appointment hour (0-23): ");
            scanf("%d", &new_appointment.hour);
            printf("Enter appointment minute (0-59): ");
            scanf("%d", &new_appointment.minute);
            getchar();  // Consume leftover newline

            appointments[appointment_count++] = new_appointment;
            printf("Appointment added: %s at %02d:%02d\n",
                   new_appointment.description, new_appointment.hour, new_appointment.minute);
        } else {
            printf("Maximum number of appointments reached. Cannot add more!\n");
        }

        pthread_mutex_unlock(&mutex);
        sleep(2); // Simulate a brief pause before accepting new appointments
    }
    return NULL;
}

void* view_appointments(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        if (appointment_count > 0) {
            printf("\nCurrent Appointments:\n");
            for (int i = 0; i < appointment_count; i++) {
                printf("%d. %s at %02d:%02d\n",
                       i + 1, appointments[i].description,
                       appointments[i].hour, appointments[i].minute);
            }
        } else {
            printf("\nNo appointments scheduled.\n");
        }

        pthread_mutex_unlock(&mutex);
        sleep(5); // Refresh the appointment list every 5 seconds
    }
    return NULL;
}

int main() {
    pthread_t add_thread, view_thread;

    if (pthread_create(&add_thread, NULL, add_appointment, NULL) != 0) {
        perror("Failed to create add_appointment thread");
        return 1;
    }

    if (pthread_create(&view_thread, NULL, view_appointments, NULL) != 0) {
        perror("Failed to create view_appointments thread");
        return 1;
    }

    pthread_join(add_thread, NULL);
    pthread_join(view_thread, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}