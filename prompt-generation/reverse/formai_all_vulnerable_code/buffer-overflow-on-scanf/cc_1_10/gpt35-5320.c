//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10 // maximum appointments that can be scheduled
#define MAX_NAME_LEN 50 // maximum length allowed for name of the person scheduling appointment

typedef struct {
    bool is_available; // a flag which tells whether the appointment slot is available
    char name[MAX_NAME_LEN]; // name of the person who booked the appointment
} appointment_t;

appointment_t appointments[MAX_APPOINTMENTS]; // an array to store appointment details
pthread_mutex_t mutex; // a mutex to lock appointment handling

void* book_appointments(void* arg) {
    int appointment_num = *(int*)arg;

    pthread_mutex_lock(&mutex);

    if(appointments[appointment_num].is_available == true) {
        char name[MAX_NAME_LEN];
        printf("Enter your name: ");
        scanf("%s", name);
        strcpy(appointments[appointment_num].name, name);
        appointments[appointment_num].is_available = false;
        printf("Appointment booked successfully\n");
    } else {
        printf("\nThis appointment slot is already taken, please select another one\n");
    }

    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

void display_menu() {
    printf("Enter appointment number from 1 to %d (0 to exit):\n", MAX_APPOINTMENTS);
    for(int i=0; i<MAX_APPOINTMENTS; i++) {
        printf("%d. Appointment %d - ", i+1, i+1);
        if(appointments[i].is_available == true) {
            printf("Available\n");
        } else {
            printf("Taken by %s\n", appointments[i].name);
        }
    }
    printf("\n");
}

int main() {
    // initialize appointments as available
    for(int i=0; i<MAX_APPOINTMENTS; i++){
        appointments[i].is_available = true;
    }

    int selection;
    do {
        display_menu();
        printf("Enter your selection: ");
        scanf("%d", &selection);
        if(selection >=1 && selection <= MAX_APPOINTMENTS) {
            int appointment_num = selection-1;
            pthread_t thread_id;
            pthread_attr_t attr;
            pthread_attr_init(&attr);
            int *arg = malloc(sizeof(*arg));
            *arg = appointment_num;
            pthread_create(&thread_id, &attr, book_appointments, arg);
            pthread_join(thread_id, NULL);
            pthread_attr_destroy(&attr);
            free(arg);
        } else if(selection != 0) {
            printf("\nInvalid input. Please try again.\n");
        }
    } while(selection != 0);

    printf("\nThank you for using the Appointment Scheduler.\n");

    return 0;
}