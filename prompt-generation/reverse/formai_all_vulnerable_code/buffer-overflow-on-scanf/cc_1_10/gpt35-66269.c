//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 50
#define MAX_TIME_LENGTH 20

typedef struct appointment {
    char name[MAX_NAME_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

void scheduleAppointment(Appointment appointments[], int *numAppointments);
void showAppointments(Appointment appointments[], int numAppointments);
void cancelAppointment(Appointment appointments[], int *numAppointments);

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    char choice;
    
    printf("Welcome to the appointment scheduler!\n");
    
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Schedule an appointment\n");
        printf("2. View appointments\n");
        printf("3. Cancel an appointment\n");
        printf("4. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                scheduleAppointment(appointments, &numAppointments);
                break;
            case '2':
                showAppointments(appointments, numAppointments);
                break;
            case '3':
                cancelAppointment(appointments, &numAppointments);
                break;
            case '4':
                printf("\nThank you for using the appointment scheduler. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != '4');
    
    return 0;
}

void scheduleAppointment(Appointment appointments[], int *numAppointments) {
    if (*numAppointments >= MAX_APPOINTMENTS) {
        printf("\nSorry, the schedule is full. No more appointments can be scheduled at this time.\n");
        return;
    }
    
    printf("\nEnter the name of the person requesting the appointment: ");
    scanf(" %[^\n]", appointments[*numAppointments].name);
    
    printf("Enter the desired time of the appointment (e.g. 3:30 PM): ");
    scanf(" %[^\n]", appointments[*numAppointments].time);
    
    printf("\nAppointment scheduled successfully for %s at %s.\n", appointments[*numAppointments].name, appointments[*numAppointments].time);
    
    *numAppointments += 1;
}

void showAppointments(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("\nThere are no appointments scheduled at this time.\n");
        return;
    }
    
    printf("\n%s\t%s\n", "Name", "Time");
    printf("--------------------------\n");
    
    for (int i = 0; i < numAppointments; i++) {
        printf("%s\t%s\n", appointments[i].name, appointments[i].time);
    }
}

void cancelAppointment(Appointment appointments[], int *numAppointments) {
    if (*numAppointments == 0) {
        printf("\nThere are no appointments scheduled at this time.\n");
        return;
    }
    
    char name[MAX_NAME_LENGTH];
    int foundIndex = -1;
    
    printf("\nEnter the name of the person whose appointment you wish to cancel: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < *numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex == -1) {
        printf("\nNo appointment found for %s.\n", name);
        return;
    }
    
    printf("\nAppointment cancelled for %s at %s.\n", appointments[foundIndex].name, appointments[foundIndex].time);
    
    for (int i = foundIndex; i < *numAppointments - 1; i++) {
        appointments[i] = appointments[i+1];
    }
    
    *numAppointments -= 1;
}