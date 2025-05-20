//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    char name[50];
    char time[10];
    char date[10];
} Appointment;

void print_appointments(Appointment appointments[], int num_appointments) {
    printf("---------------------------------------------------\n");
    printf("Appointment Schedule\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s, %s, %s\n", appointments[i].name, appointments[i].time, appointments[i].date);
    }
    printf("---------------------------------------------------\n");
}

void add_appointment(Appointment appointments[], int* num_appointments) {
    if (*num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the appointment book is full.\n");
        return;
    }

    Appointment appointment;
    printf("Enter appointment name: ");
    scanf("%s", appointment.name);
    printf("Enter appointment time: ");
    scanf("%s", appointment.time);
    printf("Enter appointment date: ");
    scanf("%s", appointment.date);

    appointments[*num_appointments] = appointment;
    (*num_appointments)++;
}

void remove_appointment(Appointment appointments[], int* num_appointments) {
    if (*num_appointments <= 0) {
        printf("Sorry, there are no appointments to remove.\n");
        return;
    }

    printf("Enter appointment name to remove: ");
    char name[50];
    scanf("%s", name);

    for (int i = 0; i < *num_appointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            for (int j = i; j < *num_appointments; j++) {
                appointments[j] = appointments[j + 1];
            }
            (*num_appointments)--;
            return;
        }
    }

    printf("Appointment not found.\n");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    print_appointments(appointments, num_appointments);

    char choice;
    do {
        printf("---------------------------------------------------\n");
        printf("Enter your choice:\n");
        printf("a) Add appointment\n");
        printf("r) Remove appointment\n");
        printf("q) Quit\n");
        printf("---------------------------------------------------\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                add_appointment(appointments, &num_appointments);
                break;
            case 'r':
                remove_appointment(appointments, &num_appointments);
                break;
            case 'q':
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 'q');

    return 0;
}