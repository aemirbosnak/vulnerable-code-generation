//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining struct for storing appointment details

struct Appointment {
    int month;
    int day;
    int hour;
    int minute;
};

// Defining struct for storing appointment node details

struct AppointmentNode {
    struct Appointment appointment;
    struct AppointmentNode* next;
};

int main() {
    // Creating head node
    struct AppointmentNode* head = NULL;

    // Variable for taking user input
    int choice;

    // Menu for user to perform actions
    while (true) {
        printf("\n\n*****Appointment Scheduler*****\n");
        printf("1. Schedule an appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Schedule appointment
                printf("\nEnter appointment details\n");
                struct Appointment appointment;
                printf("Month (1-12): ");
                scanf("%d", &appointment.month);
                printf("Day (1-31): ");
                scanf("%d", &appointment.day);
                printf("Hour (0-23): ");
                scanf("%d", &appointment.hour);
                printf("Minute (0-59): ");
                scanf("%d", &appointment.minute);

                // Creating node for appointment
                struct AppointmentNode* newNode = (struct AppointmentNode*)malloc(sizeof(struct AppointmentNode));
                newNode->appointment = appointment;
                newNode->next = NULL;

                // If there is no appointment scheduled yet, set head to newly created node
                if (head == NULL) {
                    head = newNode;
                } else {
                    // Traverse through the linked list to add new node at the proper position
                    struct AppointmentNode* temp = head;
                    while (temp->next != NULL && temp->next->appointment.month < appointment.month) {
                        temp = temp->next;
                    }
                    while (temp->next != NULL && temp->next->appointment.month == appointment.month && temp->next->appointment.day < appointment.day) {
                        temp = temp->next;
                    }
                    while (temp->next != NULL && temp->next->appointment.month == appointment.month && temp->next->appointment.day == appointment.day && temp->next->appointment.hour < appointment.hour) {
                        temp = temp->next;
                    }
                    while (temp->next != NULL && temp->next->appointment.month == appointment.month && temp->next->appointment.day == appointment.day && temp->next->appointment.hour == appointment.hour && temp->next->appointment.minute < appointment.minute) {
                        temp = temp->next;
                    }
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
                printf("\nAppointment scheduled successfully!");
                break;

            case 2:
                // View appointments
                if (head == NULL) {
                    printf("\nNo appointments scheduled.");
                } else {
                    printf("\nAppointments scheduled:\n");
                    struct AppointmentNode* temp = head;
                    int count = 1;
                    while (temp != NULL) {
                        printf("\nAppointment %d: %d/%d %02d:%02d", count, temp->appointment.month, temp->appointment.day, temp->appointment.hour, temp->appointment.minute);
                        temp = temp->next;
                        count++;
                    }
                }
                break;

            case 3:
                // Exit
                printf("\nThank you for using this Appointment Scheduler!");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.");
        }
    }
    return 0;
}