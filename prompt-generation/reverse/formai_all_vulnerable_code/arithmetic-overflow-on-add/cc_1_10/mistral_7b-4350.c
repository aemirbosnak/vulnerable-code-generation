//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Appointment {
    int id;
    char description[50];
    time_t start_time;
    time_t end_time;
    struct Appointment *next;
} Appointment;

Appointment *head = NULL;

void add_appointment(char *description, time_t start_time, time_t end_time) {
    Appointment *new_appointment = (Appointment *) malloc(sizeof(Appointment));

    new_appointment->id = rand() % 1000;
    strcpy(new_appointment->description, description);
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    new_appointment->next = head;

    head = new_appointment;
}

void delete_appointment(int id) {
    Appointment *current = head;
    Appointment *previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void view_appointments() {
    Appointment *current = head;

    printf("\nAppointment List:\n");
    printf("--------------------\n");

    while (current != NULL) {
        printf("\nAppointment ID: %d", current->id);
        printf("\nDescription: %s", current->description);
        printf("\nStart Time: %s", ctime(&current->start_time));
        printf("\nEnd Time: %s", ctime(&current->end_time));

        current = current->next;
    }
}

int main() {
    srand(time(NULL));

    add_appointment("Doctor's appointment", mktime(NULL), mktime(NULL) + 3600);
    add_appointment("Meeting with team", mktime(NULL), mktime(NULL) + 7200);
    add_appointment("Dinner with family", mktime(NULL), mktime(NULL) + 10800);

    view_appointments();

    delete_appointment(123);

    view_appointments();

    return 0;
}