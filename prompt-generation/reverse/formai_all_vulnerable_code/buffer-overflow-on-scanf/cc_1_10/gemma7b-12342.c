//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

void addAppointment(Appointment** head) {
    Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
    printf("Enter your name: ");
    scanf("%s", newApp->name);
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", newApp->date);
    printf("Enter the time (hh:mm): ");
    scanf("%s", newApp->time);
    newApp->next = NULL;

    if (*head == NULL) {
        *head = newApp;
    } else {
        (*head)->next = newApp;
    }
}

void listAppointments(Appointment* head) {
    while (head) {
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    printf("Welcome to the Appointment Scheduler!\n");
    printf("Would you like to add an appointment? (Y/N): ");
    char answer;
    scanf("%c", &answer);

    if (answer == 'Y') {
        addAppointment(&head);
    }

    printf("Here is your list of appointments:\n");
    listAppointments(head);

    return 0;
}