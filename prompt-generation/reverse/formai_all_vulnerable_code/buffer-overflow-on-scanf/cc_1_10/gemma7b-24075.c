//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_Appointments 20

struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
};

void addAppointment(struct Appointment* head) {
    struct Appointment* newApp = (struct Appointment*)malloc(sizeof(struct Appointment));
    printf("Enter your name: ");
    scanf("%s", newApp->name);
    printf("Enter the date: ");
    scanf("%s", newApp->date);
    printf("Enter the time: ");
    scanf("%s", newApp->time);
    newApp->next = NULL;

    if (head == NULL) {
        head = newApp;
    } else {
        head->next = newApp;
    }
}

void printAppointments(struct Appointment* head) {
    struct Appointment* currentApp = head;
    printf("Your appointments:\n");
    while (currentApp) {
        printf("Name: %s\n", currentApp->name);
        printf("Date: %s\n", currentApp->date);
        printf("Time: %s\n", currentApp->time);
        printf("\n");
        currentApp = currentApp->next;
    }
}

int main() {
    struct Appointment* head = NULL;
    int choice;

    printf("Welcome to the Retro Appointment Scheduler!\n");
    printf("1. Add an appointment\n");
    printf("2. Print your appointments\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addAppointment(head);
            break;
        case 2:
            printAppointments(head);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}