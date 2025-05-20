//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Appointment structure */
struct Appointment {
    char date[12];
    char time[6];
    char description[50];
    struct Appointment* next;
};

/* Function to add a new appointment */
void addAppointment(struct Appointment** head_ref) {
    struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));
    printf("\nEnter date (dd-mm-yyyy): ");
    scanf("%s", newAppointment->date);
    printf("Enter time (hh:mm): ");
    scanf("%s", newAppointment->time);
    printf("Enter description: ");
    getchar();
    fgets(newAppointment->description, 50, stdin);
    newAppointment->next = *head_ref;
    *head_ref = newAppointment;
    printf("\nAppointment added successfully!\n");
}

/* Function to display all appointments */
void displayAppointments(struct Appointment* appointment) {
    if(appointment == NULL) {
        printf("\nNo appointments scheduled!\n");
    }
    else {
        printf("\nAppointments:\n");
        while(appointment != NULL) {
            printf("Date: %s\n", appointment->date);
            printf("Time: %s\n", appointment->time);
            printf("Description: %s\n", appointment->description);
            appointment = appointment->next;
        }
    }
}

/* Function to search for an appointment */
void searchAppointment(struct Appointment* appointment) {
    char date[12];
    printf("\nEnter date to search (dd-mm-yyyy): ");
    scanf("%s", date);
    while(appointment != NULL) {
        if(strcmp(appointment->date, date) == 0) {
            printf("\nAppointment found!\n");
            printf("Date: %s\n", appointment->date);
            printf("Time: %s\n", appointment->time);
            printf("Description: %s\n", appointment->description);
            return;
        }
        appointment = appointment->next;
    }
    printf("\nNo appointments found for %s!\n", date);
}

/* Main function */
int main() {
    struct Appointment* head = NULL;
    int choice;
    printf("Welcome to Appointment Scheduler!\n");
    do {
        printf("\nMenu:\n1. Add Appointment\n2. Display Appointments\n3. Search Appointment\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addAppointment(&head);
                break;
            case 2:
                displayAppointments(head);
                break;
            case 3:
                searchAppointment(head);
                break;
            case 4:
                printf("\nThank you for using Appointment Scheduler!\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Try again.\n");
        }
    } while(choice != 4);
    return 0;
}