//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_APPOINTMENTS 100

int num_appointments = 0;
pthread_mutex_t mutex;

struct Appointment {
    char name[50];
    char phone[15];
    char date[20];
    char time[10];
};

struct Appointment appointments[MAX_APPOINTMENTS];

void print_menu() {
    printf("\n\n===== APPOINTMENT SCHEDULER =====\n\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Update Appointment\n");
    printf("4. Cancel Appointment\n");
    printf("5. Exit\n\n");
}

void add_appointment() {
    struct Appointment new_appointment;
    printf("\nEnter name: ");
    scanf("%s", new_appointment.name);
    printf("Enter phone number: ");
    scanf("%s", new_appointment.phone);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", new_appointment.date);
    printf("Enter time (hh:mm): ");
    scanf("%s", new_appointment.time);
    pthread_mutex_lock(&mutex);
    if (num_appointments < MAX_APPOINTMENTS) {
        appointments[num_appointments] = new_appointment;
        num_appointments++;
        printf("\nAppointment created successfully!\n");
    } else {
        printf("\nMaximum appointments reached!\n");
    }
    pthread_mutex_unlock(&mutex);
}

void view_appointments() {
    printf("\n\n===== APPOINTMENTS =====\n\n");
    pthread_mutex_lock(&mutex);
    if (num_appointments == 0) {
        printf("No appointments found!\n");
    } else {
        for (int i = 0; i < num_appointments; i++) {
            printf("Appointment #%d\n", i+1);
            printf("Name: %s\n", appointments[i].name);
            printf("Phone: %s\n", appointments[i].phone);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n\n", appointments[i].time);
        }
    }
    pthread_mutex_unlock(&mutex);
}

void update_appointment() {
    int appointment_number;
    printf("\nEnter appointment number to update: ");
    scanf("%d", &appointment_number);
    appointment_number--;
    if (appointment_number >= 0 && appointment_number < num_appointments) {
        struct Appointment new_appointment;
        printf("\nEnter new name: ");
        scanf("%s", new_appointment.name);
        printf("Enter new phone number: ");
        scanf("%s", new_appointment.phone);
        printf("Enter new date (dd/mm/yyyy): ");
        scanf("%s", new_appointment.date);
        printf("Enter new time (hh:mm): ");
        scanf("%s", new_appointment.time);
        pthread_mutex_lock(&mutex);
        appointments[appointment_number] = new_appointment;
        printf("\nAppointment updated successfully!\n");
        pthread_mutex_unlock(&mutex);
    } else {
        printf("\nInvalid appointment number!\n");
    }
}

void cancel_appointment() {
    int appointment_number;
    printf("\nEnter appointment number to cancel: ");
    scanf("%d", &appointment_number);
    appointment_number--;
    if (appointment_number >= 0 && appointment_number < num_appointments) {
        pthread_mutex_lock(&mutex);
        for (int i = appointment_number; i < num_appointments-1; i++) {
            appointments[i] = appointments[i+1];
        }
        num_appointments--;
        printf("\nAppointment cancelled successfully!\n");
        pthread_mutex_unlock(&mutex);
    } else {
        printf("\nInvalid appointment number!\n");
    }
}

void* menu_handler(void* arg) {
    int* exit_flag = (int*) arg;
    int choice;
    while (!*exit_flag) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_appointment(); break;
            case 2: view_appointments(); break;
            case 3: update_appointment(); break;
            case 4: cancel_appointment(); break;
            case 5: *exit_flag = 1; break;
            default: printf("\nInvalid choice!\n"); break;
        }
    }
    return NULL;
}

int main() {
    int exit_flag = 0;
    pthread_t menu_thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&menu_thread, NULL, &menu_handler, (void*) &exit_flag);
    pthread_join(menu_thread, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}