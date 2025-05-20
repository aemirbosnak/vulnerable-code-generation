//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];
    struct Appointment* next;
} Appointment;

int main() {
    system("/bin/rm -rf /tmp/appointments");
    system("/bin/mkdir /tmp/appointments");

    Appointment* head = NULL;
    Appointment* tail = NULL;

    int appointments = 0;

    while (1) {
        char name[MAX_NAME_LENGTH];
        char date[MAX_NAME_LENGTH];
        char time[MAX_NAME_LENGTH];

        printf("Enter your name: ");
        scanf("%s", name);

        printf("Enter the date: ");
        scanf("%s", date);

        printf("Enter the time: ");
        scanf("%s", time);

        Appointment* new_appointment = (Appointment*) malloc(sizeof(Appointment));

        strcpy(new_appointment->name, name);
        strcpy(new_appointment->date, date);
        strcpy(new_appointment->time, time);
        new_appointment->next = NULL;

        if (head == NULL) {
            head = new_appointment;
            tail = new_appointment;
        } else {
            tail->next = new_appointment;
            tail = new_appointment;
        }

        appointments++;

        printf("Appointment scheduled!\n");

        if (appointments >= MAX_Appointments) {
            break;
        }
    }

    return 0;
}