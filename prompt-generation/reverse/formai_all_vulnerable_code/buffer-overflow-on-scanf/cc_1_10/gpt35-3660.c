//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char patientName[50];
    char doctorName[50];
    char time[50];
    struct Appointment* next;
};

struct Appointment* head = NULL;

void addAppointment(char name[], char doctor[], char time[]) {
    struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));
    strcpy(newAppointment->patientName, name);
    strcpy(newAppointment->doctorName, doctor);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
        return;
    }

    struct Appointment* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newAppointment;
}

void removeAppointment() {
    if (head == NULL) {
        printf("No appointments to remove.\n");
        return;
    }

    struct Appointment* temp = head;
    head = head->next;
    free(temp);
}

void displayAppointments() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }

    struct Appointment* current = head;
    printf("Current Appointments:\n");
    while (current != NULL) {
        printf("Patient Name: %s\n", current->patientName);
        printf("Doctor Name: %s\n", current->doctorName);
        printf("Time: %s\n", current->time);
        printf("--------------------\n");
        current = current->next;
    }
}

int main() {
    int choice;
    char name[50], doctor[50], time[50];

    while (1) {
        printf("1. Schedule Appointment\n");
        printf("2. Remove Appointment\n");
        printf("3. Display Appointments\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient Name: ");
                scanf("%s", name);
                printf("Enter Doctor Name: ");
                scanf("%s", doctor);
                printf("Enter Time: ");
                scanf("%s", time);
                addAppointment(name, doctor, time);
                break;
            case 2:
                removeAppointment();
                break;
            case 3:
                displayAppointments();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}