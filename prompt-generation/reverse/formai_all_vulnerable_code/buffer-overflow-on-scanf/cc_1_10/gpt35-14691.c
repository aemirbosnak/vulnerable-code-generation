//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Appointment {
    char date[11];
    char time[6];
    char location[30];
    char description[100];
};

struct Node {
    struct Appointment appointment;
    struct Node* next;
};

struct Node* head = NULL;
int count = 0;

void insertAppointment() {
    // Ask for details from the user
    char date[11], time[6], location[30], description[100];
    printf("Enter date of appointment (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter time of appointment (hh:mm): ");
    scanf("%s", time);
    printf("Enter location of appointment: ");
    scanf("%s", location);
    printf("Enter description of appointment: ");
    scanf("%s", description);

    // Create a new node for the appointment
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->appointment.date, date);
    strcpy(newNode->appointment.time, time);
    strcpy(newNode->appointment.location, location);
    strcpy(newNode->appointment.description, description);
    newNode->next = NULL;

    // If the list is empty, add the first node
    if (head == NULL) {
        head = newNode;
    }
    else { // Add node at the end of the list
        struct Node* currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    count++;
    printf("Appointment has been scheduled successfully!\n");
}

void removeAppointment() {
    // Ask for date and time from the user to remove the appointment
    char date[11], time[6];
    printf("Enter date of appointment to remove (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter time of appointment to remove (hh:mm): ");
    scanf("%s", time);

    // Traverse the list to find the appointment to remove
    struct Node* currentNode = head;
    struct Node* prevNode = NULL;
    while (currentNode != NULL) {
        if (strcmp(currentNode->appointment.date, date) == 0 &&
            strcmp(currentNode->appointment.time, time) == 0) {
            // Remove the node since it matches the given date and time
            if (prevNode == NULL) {
                head = currentNode->next;
            }
            else {
                prevNode->next = currentNode->next;
            }
            free(currentNode);
            count--;
            printf("Appointment has been removed successfully!\n");
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("Appointment not found\n");
}

void displayAppointments() {
    if (head == NULL) {
        printf("No appointments scheduled at the moment.\n");
    }
    else {
        printf("Appointments:\n");
        struct Node* currentNode = head;
        while (currentNode != NULL) {
            printf("Date: %s\n", currentNode->appointment.date);
            printf("Time: %s\n", currentNode->appointment.time);
            printf("Location: %s\n", currentNode->appointment.location);
            printf("Description: %s\n", currentNode->appointment.description);
            printf("\n");
            currentNode = currentNode->next;
        }
    }
}

int main() {
    int choice;
    bool isRunning = true;

    while (isRunning) {
        printf("\nAppointment Scheduler\n");
        printf("1. Schedule new appointment\n");
        printf("2. Remove existing appointment\n");
        printf("3. Display all appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insertAppointment(); // Schedule new appointment
                break;
            case 2:
                removeAppointment(); // Remove existing appointment
                break;
            case 3:
                displayAppointments(); // Display all appointments
                break;
            case 4:
                isRunning = false; // Exit
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}