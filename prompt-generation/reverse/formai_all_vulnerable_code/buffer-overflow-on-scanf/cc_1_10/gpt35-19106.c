//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    char* date;
    char* description;
} Appointment;

Appointment schedule[MAX_APPOINTMENTS];

// Recursive function to schedule an appointment
bool scheduleAppointment(int index) {
    // Base case
    if (index == MAX_APPOINTMENTS) {
        return true;
    }
    
    // Recursive case
    printf("Enter date of appointment %d (DD/MM/YYYY):\n", index+1);
    char date[11];
    scanf("%s", date);
    
    printf("Enter appointment description:\n");
    char* description = (char*) malloc(100);
    scanf(" %[^\n]s", description);
    
    Appointment newAppointment = {date, description};
    
    // Check for conflicts with already scheduled appointments
    for (int i = 0; i < index; i++) {
        if (strcmp(schedule[i].date, newAppointment.date) == 0) {
            printf("There is already an appointment scheduled on this date. Please choose a different date.\n");
            free(description);
            return scheduleAppointment(index);
        }
    }
    
    // Schedule appointment
    schedule[index] = newAppointment;
    return scheduleAppointment(index+1);
}

int main() {
    printf("Welcome to the appointment scheduler!\n\n");
    printf("You can schedule up to %d appointments.\n\n", MAX_APPOINTMENTS);
    
    bool success = scheduleAppointment(0);
    
    if (success) {
        printf("\nAppointment schedule:\n");
        for (int i = 0; i < MAX_APPOINTMENTS; i++) {
            printf("%s: %s\n", schedule[i].date, schedule[i].description);
        }
    } else {
        printf("\nAppointment scheduling failed.\n");
    }
    
    return 0;
}