//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Appointment structure
typedef struct {
    int id;
    time_t start_time;
    time_t end_time;
    char *description;
} Appointment;

// Appointment list
Appointment *appointments = NULL;
int num_appointments = 0;

// Mutex to protect the appointment list
pthread_mutex_t appointments_lock;

// Thread function to add an appointment
void *add_appointment(void *arg) {
    Appointment *appointment = (Appointment *)arg;

    // Lock the appointment list
    pthread_mutex_lock(&appointments_lock);

    // Add the appointment to the list
    appointments = realloc(appointments, (num_appointments + 1) * sizeof(Appointment));
    appointments[num_appointments] = *appointment;
    num_appointments++;

    // Unlock the appointment list
    pthread_mutex_unlock(&appointments_lock);

    return NULL;
}

// Thread function to remove an appointment
void *remove_appointment(void *arg) {
    int id = *(int *)arg;

    // Lock the appointment list
    pthread_mutex_lock(&appointments_lock);

    // Find the appointment to remove
    int i;
    for (i = 0; i < num_appointments; i++) {
        if (appointments[i].id == id) {
            break;
        }
    }

    // If the appointment was not found, unlock the appointment list and return
    if (i == num_appointments) {
        pthread_mutex_unlock(&appointments_lock);
        return NULL;
    }

    // Remove the appointment from the list
    for (; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    num_appointments--;

    // Unlock the appointment list
    pthread_mutex_unlock(&appointments_lock);

    return NULL;
}

// Thread function to print the appointment list
void *print_appointments(void *arg) {
    // Lock the appointment list
    pthread_mutex_lock(&appointments_lock);

    // Print the appointment list
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("ID: %d, Start time: %s, End time: %s, Description: %s\n", appointments[i].id, ctime(&appointments[i].start_time), ctime(&appointments[i].end_time), appointments[i].description);
    }

    // Unlock the appointment list
    pthread_mutex_unlock(&appointments_lock);

    return NULL;
}

int main() {
    // Initialize the mutex
    pthread_mutex_init(&appointments_lock, NULL);

    // Create a thread to add an appointment
    pthread_t add_appointment_thread;
    Appointment appointment = {1, time(NULL) + 3600, time(NULL) + 7200, "Meeting with John"};
    pthread_create(&add_appointment_thread, NULL, add_appointment, &appointment);

    // Create a thread to remove an appointment
    pthread_t remove_appointment_thread;
    int id = 1;
    pthread_create(&remove_appointment_thread, NULL, remove_appointment, &id);

    // Create a thread to print the appointment list
    pthread_t print_appointments_thread;
    pthread_create(&print_appointments_thread, NULL, print_appointments, NULL);

    // Join the threads
    pthread_join(add_appointment_thread, NULL);
    pthread_join(remove_appointment_thread, NULL);
    pthread_join(print_appointments_thread, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&appointments_lock);

    return 0;
}