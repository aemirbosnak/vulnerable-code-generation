//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct appointment {
    char *title;
    char *description;
    time_t start_time;
    time_t end_time;
    struct appointment *next;
} appointment_t;

appointment_t *head = NULL;

void insert_appointment(char *title, char *description, time_t start_time, time_t end_time) {
    appointment_t *new_appointment = malloc(sizeof(appointment_t));
    new_appointment->title = strdup(title);
    new_appointment->description = strdup(description);
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    new_appointment->next = NULL;

    if (head == NULL) {
        head = new_appointment;
    } else {
        appointment_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_appointment;
    }
}

void print_appointments() {
    appointment_t *current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Description: %s\n", current->description);
        printf("Start time: %s", ctime(&current->start_time));
        printf("End time: %s", ctime(&current->end_time));
        printf("\n");
        current = current->next;
    }
}

void free_appointments() {
    appointment_t *current = head;
    while (current != NULL) {
        appointment_t *next = current->next;
        free(current->title);
        free(current->description);
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    // Insert some sample appointments
    insert_appointment("Doctor's appointment", "Annual checkup", time(NULL), time(NULL) + 3600);
    insert_appointment("Meeting with boss", "Discuss project progress", time(NULL) + 86400, time(NULL) + 90000);
    insert_appointment("Lunch with friends", "Catch up and have some fun", time(NULL) + 172800, time(NULL) + 180000);

    // Print the appointments
    print_appointments();

    // Free the appointments
    free_appointments();

    return 0;
}