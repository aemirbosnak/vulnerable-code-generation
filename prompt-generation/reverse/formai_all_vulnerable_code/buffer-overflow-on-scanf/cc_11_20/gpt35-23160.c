//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    int day;
    int month;
    int year;
    char name[30];
    char reason[100];
};

int main() {
    int choice, count = 0;
    struct Appointment appointments[30];
    
    printf("Welcome to Appointment Scheduler!\n\n");
    do {
        printf("Please choose an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. Cancel an appointment\n");
        printf("3. View all appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(count >= 30) {
                    printf("Sorry, we have reached the maximum number of appointments.\n");
                    break;
                }
                
                printf("Please enter the appointment details:\n");
                printf("Enter the date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &appointments[count].day, &appointments[count].month, &appointments[count].year);
                printf("Enter the name of the patient: ");
                scanf(" %[^\n]", appointments[count].name);
                printf("Enter the reason for the appointment: ");
                scanf(" %[^\n]", appointments[count].reason);
                
                printf("\nAppointment scheduled successfully!\n");
                count++;
                break;
                
            case 2:
                if(count == 0) {
                    printf("There are no appointments to cancel.\n");
                    break;
                }
                
                int cancel;
                printf("Please enter the number of the appointment you wish to cancel: ");
                scanf("%d", &cancel);
                
                if(cancel < 1 || cancel > count) {
                    printf("Invalid appointment number.\n");
                    break;
                }
                
                for(int i=cancel-1; i<count-1; i++) {
                    appointments[i] = appointments[i+1];
                }
                count--;
                
                printf("\nAppointment cancelled successfully!\n");
                break;
                
            case 3:
                if(count == 0) {
                    printf("There are no appointments to view.\n");
                    break;
                }
                
                printf("\nAppointment List:\n");
                printf("--------------------\n");
                for(int i=0; i<count; i++) {
                    printf("Appointment #%d\n", i+1);
                    printf("Date: %d/%d/%d\n", appointments[i].day, appointments[i].month, appointments[i].year);
                    printf("Patient name: %s\n", appointments[i].name);
                    printf("Reason: %s\n", appointments[i].reason);
                    printf("--------------------\n");
                }
                break;
                
            case 4:
                printf("\nThank you for using Appointment Scheduler!\n");
                break;
                
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        
        printf("\n");
        
    } while(choice != 4);
    
    return 0;
}