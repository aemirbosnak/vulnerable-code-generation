//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// structure definition for appointments
struct Appointment {
    int day;
    int month;
    int year;
    char name[50];
    char time[6];
};

// function to add a new appointment
void addAppointment(struct Appointment* appointments, int* numAppointments) {
    printf("\nEnter appointment details:\n");
    printf("Name: ");
    scanf("%s", appointments[*numAppointments].name);
    printf("Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appointments[*numAppointments].day, &appointments[*numAppointments].month, &appointments[*numAppointments].year);
    printf("Time (hh:mm): ");
    scanf("%s", appointments[*numAppointments].time);
    
    (*numAppointments)++;
    printf("\nAppointment added!\n");
}

// function to view all appointments
void viewAppointments(const struct Appointment* appointments, int numAppointments) {
    if(numAppointments == 0) {
        printf("\nYou have no appointments!\n");
        return;
    }
    
    printf("\nYour appointments:\n");
    for(int i = 0; i < numAppointments; i++) {
        printf("%d/%d/%d at %s with %s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].time, appointments[i].name);
    }
}

// main function
int main() {
    struct Appointment appointments[100];
    int numAppointments = 0;
    int choice;
    
    printf("Welcome to the Appointment Scheduler!\n");
    
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new appointment\n");
        printf("2. View all appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                printf("\nThank you for using the Appointment Scheduler!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again!\n");
        }
    }
    
    return 0;
}