//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_Appointments 10
#define MAX_LENGTH 20

typedef struct Appointment {
    char name[MAX_LENGTH];
    char date[MAX_LENGTH];
    char time[MAX_LENGTH];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newApp->name, name);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
    newApp->next = NULL;
    return newApp;
}

int main() {
    // Create a linked list of appointments
    Appointment* head = NULL;

    // Get the current user's name
    char userName[MAX_LENGTH];
    printf("Enter your name: ");
    scanf("%s", userName);

    // Prompt the user to enter their appointment details
    char date[MAX_LENGTH];
    char time[MAX_LENGTH];
    printf("Enter the date of your appointment: ");
    scanf("%s", date);

    printf("Enter the time of your appointment: ");
    scanf("%s", time);

    // Create a new appointment
    Appointment* newApp = createAppointment(userName, date, time);

    // Add the new appointment to the linked list
    if (head == NULL) {
        head = newApp;
    } else {
        newApp->next = head;
        head = newApp;
    }

    // Print the user's appointments
    printf("Your appointments:");
    for (Appointment* currentApp = head; currentApp != NULL; currentApp = currentApp->next) {
        printf("\nName: %s", currentApp->name);
        printf("\nDate: %s", currentApp->date);
        printf("\nTime: %s", currentApp->time);
    }

    return 0;
}