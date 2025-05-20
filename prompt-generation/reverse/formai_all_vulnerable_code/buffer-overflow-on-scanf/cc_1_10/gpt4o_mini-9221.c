//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_APPOINTMENTS 100
#define APPOINTMENT_TIME_STR_LEN 30

typedef struct {
    char description[100];
    char time[APPOINTMENT_TIME_STR_LEN];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

pthread_mutex_t appointment_mutex;

void* add_appointment(void* arg) {
    char* description = (char*)arg;
    char time[APPOINTMENT_TIME_STR_LEN];

    printf("Enter the appointment time (YYYY-MM-DD HH:MM): ");
    scanf("%s", time);
    
    pthread_mutex_lock(&appointment_mutex);
    
    if (appointment_count < MAX_APPOINTMENTS) {
        strcpy(appointments[appointment_count].description, description);
        strcpy(appointments[appointment_count].time, time);
        appointment_count++;
        printf("Appointment added: %s at %s\n", description, time);
    } else {
        printf("Cannot add appointment: appointment list is full.\n");
    }
    
    pthread_mutex_unlock(&appointment_mutex);
    return NULL;
}

void* view_schedule(void* arg) {
    pthread_mutex_lock(&appointment_mutex);
    
    printf("\nScheduled Appointments:\n");
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
    } else {
        for (int i = 0; i < appointment_count; i++) {
            printf("%d: %s at %s\n", i + 1, appointments[i].description, appointments[i].time);
        }
    }
    
    pthread_mutex_unlock(&appointment_mutex);
    return NULL;
}

void* cancel_appointment(void* arg) {
    int index = *((int*)arg);

    pthread_mutex_lock(&appointment_mutex);
    
    if (index >= 0 && index < appointment_count) {
        printf("Cancelling appointment: %s at %s\n", appointments[index].description, appointments[index].time);
        for (int i = index; i < appointment_count - 1; i++) {
            appointments[i] = appointments[i + 1];
        }
        appointment_count--;
    } else {
        printf("Invalid index: No appointment found to cancel.\n");
    }
    
    pthread_mutex_unlock(&appointment_mutex);
    return NULL;
}

int main() {
    pthread_mutex_init(&appointment_mutex, NULL);
    
    printf("Welcome to the Appointment Scheduler!\n");
    int choice, index;
    char description[100];
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Appointment\n");
        printf("2. View Schedule\n");
        printf("3. Cancel Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter appointment description: ");
                scanf(" %[^\n]", description);
                {
                    pthread_t add_thread;
                    pthread_create(&add_thread, NULL, add_appointment, (void*)strdup(description));
                    pthread_detach(add_thread);
                }
                break;
            case 2:
                {
                    pthread_t view_thread;
                    pthread_create(&view_thread, NULL, view_schedule, NULL);
                    pthread_detach(view_thread);
                }
                break;
            case 3:
                printf("Enter the index of the appointment to cancel: ");
                scanf("%d", &index);
                {
                    pthread_t cancel_thread;
                    pthread_create(&cancel_thread, NULL, cancel_appointment, (void*)&index);
                    pthread_detach(cancel_thread);
                }
                break;
            case 4:
                printf("Exiting the scheduler. Goodbye!\n");
                pthread_mutex_destroy(&appointment_mutex);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        sleep(1); // To simulate a small pause for better user experience
    }
    return 0;
}