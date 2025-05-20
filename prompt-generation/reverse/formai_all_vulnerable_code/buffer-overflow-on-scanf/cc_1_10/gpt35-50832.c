//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 50

typedef struct appointment {
    char name[50];
    char date[20];
    char time[20];
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void display_menu() {
    printf("==========================\n");
    printf("  Appointment Scheduler\n");
    printf("==========================\n");
    printf("1. Add Appointment\n");
    printf("2. Cancel Appointment\n");
    printf("3. View Appointments\n");
    printf("4. Exit\n");
}

void add_appointment() {
    if(num_appointments == MAX_APPOINTMENTS) {
        printf("Sorry, the appointment scheduler is full.");
        return;
    }
    
    printf("Please enter name: ");
    scanf("%s", appointments[num_appointments].name);
    
    printf("Please enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Please enter time (HH:MM AM/PM): ");
    scanf("%s", appointments[num_appointments].time);
    
    printf("Appointment has been added.\n\n");
    
    num_appointments++;
}

void cancel_appointment() {
    if(num_appointments == 0) {
        printf("Sorry, there are no appointments to cancel.\n");
        return;
    }
    
    char name[50];
    printf("Please enter the name associated with the appointment you would like to cancel: ");
    scanf("%s", name);
    
    int found = 0;
    for(int i=0; i<num_appointments; i++) {
        if(strcmp(name, appointments[i].name) == 0) {
            appointments[i] = appointments[num_appointments-1];
            num_appointments--;
            found = 1;
            break;
        }
    }
    
    if(found == 0) {
        printf("Sorry, no appointment was found with that name.\n");
        return;
    }
    
    printf("Appointment has been cancelled.\n\n");
}

void view_appointments() {
    if(num_appointments == 0) {
        printf("Sorry, there are no appointments to display.\n");
        return;
    }
    
    printf("Appointments:\n");
    for(int i=0; i<num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("--------------------\n");
    }
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Please enter choice (1-4): ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                cancel_appointment();
                break;
            case 3:
                view_appointments();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Sorry, that is an invalid choice.\n");
        }
    } while(choice != 4);
    
    return 0;
}