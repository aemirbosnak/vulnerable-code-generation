//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdbool.h>

struct Appointment {
    int day;
    int month;
    int year;
    char clientName[50];
};

int main() {
    struct Appointment appointments[10];
    int appointmentCount = 0;
    char choice;
    
    printf("*** APPOINTMENT SCHEDULER ***\n");
    
    do {
        printf("\nWhat would you like to do? (A)dd appointment, (D)elete appointment, (V)iew appointments, (E)xit: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case 'A':
            case 'a': {
                if(appointmentCount < 10) {
                    printf("\nEnter the appointment details: \n");
                    printf("Client name: ");
                    scanf("%s", appointments[appointmentCount].clientName);
                    printf("Appointment date (dd/mm/yyyy): ");
                    scanf("%d/%d/%d", &appointments[appointmentCount].day, &appointments[appointmentCount].month, &appointments[appointmentCount].year);
                    printf("\nAppointment added successfully!");
                    appointmentCount++;
                }
                else {
                    printf("\nAppointment scheduler is full! Please delete some appointments before adding.");
                }
                break;
            }
            case 'D':
            case 'd': {
                if(appointmentCount > 0) {
                    int index;
                    bool found = false;
                    char clientToDelete[50];
                    printf("\nEnter the name of the client whose appointment you want to delete: ");
                    scanf("%s", clientToDelete);
                    
                    for(int i = 0; i < appointmentCount; i++) {
                        if(strcmp(appointments[i].clientName, clientToDelete) == 0) {
                            index = i;
                            found = true;
                            break;
                        }
                    }
                    
                    if(found) {
                        for(int i = index; i < appointmentCount-1; i++) {
                            appointments[i] = appointments[i+1];
                        }
                        appointmentCount--;
                        printf("\nAppointment for %s on %d/%d/%d deleted successfully!", clientToDelete, appointments[index].day, appointments[index].month, appointments[index].year);
                    }
                    else {
                        printf("\nAppointment not found for client %s!", clientToDelete);
                    }
                }
                else {
                    printf("\nNo appointments found to delete!");
                }
                break;
            }
            case 'V':
            case 'v': {
                if(appointmentCount > 0) {
                    printf("\nCurrent appointments:\n");
                    for(int i = 0; i < appointmentCount; i++) {
                        printf("%d. %s on %d/%d/%d\n", i+1, appointments[i].clientName, appointments[i].day, appointments[i].month, appointments[i].year);
                    }
                }
                else {
                    printf("\nNo appointments found!");
                }
                break;
            }
            case 'E':
            case 'e': {
                printf("\nThank you for using appointment scheduler! Goodbye.");
                break;
            }
            default: {
                printf("\nInvalid choice! Please try again.");
                break;
            }
        }
    }
    while(choice != 'E' && choice != 'e');
    
    return 0;
}