//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPTS 10 // maximum number of appointments that can be scheduled
#define MAX_NAME_LEN 20 // maximum length of customer name
#define MAX_TIME_LEN 7 // maximum length of appointment time (hh:mm)

typedef struct {
    char name[MAX_NAME_LEN];
    char time[MAX_TIME_LEN];
} Appointment;

void displayMenu();
void addAppointment(Appointment appts[], int* numAppts);
void displayAppointments(Appointment appts[], int numAppts);
void searchAppointment(Appointment appts[], int numAppts);

int main() {
    Appointment appts[MAX_APPTS];
    int numAppts = 0;
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addAppointment(appts, &numAppts);
                break;
            case 2:
                displayAppointments(appts, numAppts);
                break;
            case 3:
                searchAppointment(appts, numAppts);
                break;
            case 4:
                printf("Exiting Program...");
                break;
            default:
                printf("Invalid Choice. Please Try Again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void displayMenu() {
    printf("\nWelcome to the Appointment Scheduler!\n");
    printf("Please select an option from the menu below:\n");
    printf("1. Add an Appointment\n");
    printf("2. Display Appointments\n");
    printf("3. Search Appointments\n");
    printf("4. Exit\n");
}

void addAppointment(Appointment appts[], int* numAppts) {
    if (*numAppts == MAX_APPTS) {
        printf("Sorry, Maximum Appointments Reached!\n");
        return;
    }
    
    Appointment newAppt;
    printf("Enter Customer Name: ");
    scanf("%s", newAppt.name);
    printf("Enter Appointment Time (hh:mm): ");
    scanf("%s", newAppt.time);
    appts[*numAppts] = newAppt;
    (*numAppts)++;
    printf("Appointment Added Successfully!\n");
}

void displayAppointments(Appointment appts[], int numAppts) {
    if (numAppts == 0) {
        printf("No Appointments Found.\n");
        return;
    }
    
    printf("\nList of Appointments:\n");
    for (int i = 0; i < numAppts; i++) {
        printf("Appointment %d\n", i+1);
        printf("Customer Name: %s\n", appts[i].name);
        printf("Appointment Time: %s\n\n", appts[i].time);
    }
}

void searchAppointment(Appointment appts[], int numAppts) {
    if (numAppts == 0) {
        printf("No Appointments Found.\n");
        return;
    }
    
    char name[MAX_NAME_LEN];
    printf("Enter Customer Name: ");
    scanf("%s", name);
    
    for (int i = 0; i < numAppts; i++) {
        if (strcmp(name, appts[i].name) == 0) {
            printf("Appointment Found!\n");
            printf("Customer Name: %s\n", appts[i].name);
            printf("Appointment Time: %s\n", appts[i].time);
            return;
        }
    }
    
    printf("No Appointments Found for Customer: %s\n", name);
}