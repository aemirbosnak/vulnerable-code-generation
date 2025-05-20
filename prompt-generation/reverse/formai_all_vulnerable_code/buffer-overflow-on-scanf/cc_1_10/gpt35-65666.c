//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the structure for an appointment
struct Appointment {
    char name[50];
    char date[20];
    char time[15];
};

// Function to display the menu with options
void displayMenu() {
    printf("\nWelcome to Appointment Scheduler\n");
    printf("1. View All Appointments\n");
    printf("2. Add New Appointment\n");
    printf("3. Edit Existing Appointment\n");
    printf("4. Delete Appointment\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

int main() {
    int choice = 0, numAppointments = 0;
    struct Appointment appointments[50];
    
    // Display the menu and get the choice from user
    while(choice != 5) {
        displayMenu();
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                // View All Appointments
                if(numAppointments == 0) {
                    printf("No appointments scheduled.\n");
                } else {
                    printf("All Appointments:\n");
                    for(int i = 0; i < numAppointments; i++) {
                        printf("%d. Name: %s | Date: %s | Time: %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
                    }
                }
                break;
            case 2:
                // Add New Appointment
                printf("Enter name: ");
                scanf("%s",appointments[numAppointments].name);
                printf("Enter date (DD/MM/YYYY): ");
                scanf("%s",appointments[numAppointments].date);
                printf("Enter time (HH:MM AM/PM): ");
                scanf("%s",appointments[numAppointments].time);
                numAppointments++;
                break;
            case 3:
                // Edit Existing Appointment
                if(numAppointments == 0) {
                    printf("No appointments scheduled.\n");
                } else {
                    printf("Enter appointment number: ");
                    int appointmentNum;
                    scanf("%d",&appointmentNum);
                    appointmentNum--;
                    if(appointmentNum < 0 || appointmentNum >= numAppointments) {
                        printf("Invalid appointment number.\n");
                    } else {
                        printf("Enter new name or press Enter to skip: ");
                        scanf("%s",appointments[appointmentNum].name);
                        printf("Enter new date or press Enter to skip (DD/MM/YYYY): ");
                        scanf("%s",appointments[appointmentNum].date);
                        printf("Enter new time or press Enter to skip (HH:MM AM/PM): ");
                        scanf("%s",appointments[appointmentNum].time);
                        printf("Appointment updated.\n");
                    }
                }
                break;
            case 4:
                // Delete Appointment
                if(numAppointments == 0) {
                    printf("No appointments scheduled.\n");
                } else {
                    printf("Enter appointment number to delete: ");
                    int appointmentNum;
                    scanf("%d",&appointmentNum);
                    appointmentNum--;
                    if(appointmentNum < 0 || appointmentNum >= numAppointments) {
                        printf("Invalid appointment number.\n");
                    } else {
                        for(int i = appointmentNum; i < numAppointments-1; i++) {
                            strcpy(appointments[i].name,appointments[i+1].name);
                            strcpy(appointments[i].date,appointments[i+1].date);
                            strcpy(appointments[i].time,appointments[i+1].time);
                        }
                        numAppointments--;
                        printf("Appointment deleted.\n");
                    }
                }
                break;
            case 5:
                // Exit
                printf("Thank you for using the Appointment Scheduler.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}