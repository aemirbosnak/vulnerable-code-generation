//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

void addAppointment(Appointment **appointments, int *size) {
    printf("\nEnter appointment details:\n");
    Appointment *newAppointment = (Appointment *) malloc(sizeof(Appointment));
    printf("Name: ");
    scanf("%s", newAppointment->name);
    printf("Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &newAppointment->day, &newAppointment->month, &newAppointment->year);
    printf("Time (hh:mm): ");
    scanf("%d:%d", &newAppointment->hour, &newAppointment->minute);
    appointments[*size] = newAppointment;
    (*size)++;
}

void printAppointment(Appointment *appointment) {
    printf("%s - %02d/%02d/%04d - %02d:%02d\n", appointment->name, appointment->day, appointment->month, appointment->year, appointment->hour, appointment->minute);
}

void printAppointments(Appointment **appointments, int size) {
    printf("\nAppointments:\n");
    printf("----------------\n");
    for (int i = 0; i < size; i++) {
        printAppointment(appointments[i]);
    }
    printf("\n");
}

void removeAppointment(Appointment **appointments, int *size, char *name) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(appointments[i]->name, name) == 0) {
            free(appointments[i]);
            appointments[i] = appointments[*size - 1];
            (*size)--;
            printf("\nAppointment for %s removed.\n", name);
            return;
        }
    }
    printf("\nAppointment for %s not found.\n", name);
}

void bubbleSort(Appointment **appointments, int size) {
    Appointment *temp;
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (appointments[j]->year > appointments[j+1]->year 
                    || (appointments[j]->year == appointments[j+1]->year 
                        && appointments[j]->month > appointments[j+1]->month) 
                    || (appointments[j]->year == appointments[j+1]->year 
                        && appointments[j]->month == appointments[j+1]->month 
                        && appointments[j]->day > appointments[j+1]->day) 
                    || (appointments[j]->year == appointments[j+1]->year 
                        && appointments[j]->month == appointments[j+1]->month 
                        && appointments[j]->day == appointments[j+1]->day 
                        && appointments[j]->hour > appointments[j+1]->hour) 
                    || (appointments[j]->year == appointments[j+1]->year 
                        && appointments[j]->month == appointments[j+1]->month 
                        && appointments[j]->day == appointments[j+1]->day 
                        && appointments[j]->hour == appointments[j+1]->hour 
                        && appointments[j]->minute > appointments[j+1]->minute)) {
                temp = appointments[j];
                appointments[j] = appointments[j+1];
                appointments[j+1] = temp;
            }
        }
    }
}

int main() {
    int capacity = 10;
    int size = 0;
    Appointment **appointments = (Appointment **) malloc(capacity * sizeof(Appointment *));
    char command;
    char name[50];
    do {
        printf("\n");
        printf("A - Add an appointment\n");
        printf("P - Print all appointments\n");
        printf("R - Remove an appointment\n");
        printf("Q - Quit\n");
        printf("Enter a command: ");
        scanf(" %c", &command);
        switch (command) {
            case 'A':
            case 'a':
                if (size == capacity) {
                    capacity *= 2;
                    appointments = (Appointment **) realloc(appointments, capacity * sizeof(Appointment *));
                }
                addAppointment(appointments, &size);
                bubbleSort(appointments, size);
                break;
            case 'P':
            case 'p':
                printAppointments(appointments, size);
                break;
            case 'R':
            case 'r':
                printf("\nEnter the name of the appointment to remove: ");
                scanf("%s", name);
                removeAppointment(appointments, &size, name);
                bubbleSort(appointments, size);
                break;
            case 'Q':
            case 'q':
                printf("\nExiting.\n");
                break;
            default:
                printf("\nInvalid command.\n");
        }
    } while (command != 'Q' && command != 'q');
    for (int i = 0; i < size; i++) {
        free(appointments[i]);
    }
    free(appointments);
    return 0;
}