//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment {
    char date[20];
    char time[20];
    char patientName[50];
    char doctorName[50];
    int appointmentID;
};

int main() {
    int choice, count = 0, i, appointmentID, valid;
    char temp[50];
    struct appointment appointments[10];
    
    do {
        printf("\n-------- Appointment Scheduler --------\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Edit Appointment\n");
        printf("4. Delete Appointment\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if(count < 10) {
                    struct appointment newAppointment;
                    printf("Enter Date (dd-mm-yyyy): ");
                    scanf("%s", newAppointment.date);
                    printf("Enter Time (hh:mm AM/PM): ");
                    scanf("%s", newAppointment.time);
                    printf("Enter Patient Name: ");
                    scanf("%s", newAppointment.patientName);
                    printf("Enter Doctor Name: ");
                    scanf("%s", newAppointment.doctorName);
                    do {
                        valid = 1;
                        printf("Enter Appointment ID (must be unique): ");
                        scanf("%d", &newAppointment.appointmentID);
                        for(i = 0; i < count; i++) {
                            if(newAppointment.appointmentID == appointments[i].appointmentID) {
                                printf("Appointment ID already exists!\n");
                                valid = 0;
                                break;
                            }
                        }
                    } while(!valid);
                    appointments[count++] = newAppointment;
                    printf("Appointment created successfully!\n");
                } else {
                    printf("Can't add more than 10 appointments!\n");
                }
                break;
            case 2:
                printf("\n-------- Appointments List --------\n");
                if(count == 0) {
                    printf("No appointments!\n");
                } else {
                    printf("%-15s%-15s%-20s%-20s%-15s\n", "Appointment ID", "Date", "Time", "Patient Name", "Doctor Name");
                    for(i = 0; i < count; i++) {
                        printf("%-15d%-15s%-20s%-20s%-15s\n", appointments[i].appointmentID, appointments[i].date, appointments[i].time, appointments[i].patientName, appointments[i].doctorName);
                    }
                }
                break;
            case 3:
                printf("Enter Appointment ID to edit: ");
                scanf("%d", &appointmentID);
                for(i = 0; i < count; i++) {
                    if(appointmentID == appointments[i].appointmentID) {
                        printf("Enter new Date (dd-mm-yyyy): ");
                        scanf("%s", appointments[i].date);
                        printf("Enter new Time (hh:mm AM/PM): ");
                        scanf("%s", appointments[i].time);
                        printf("Enter new Patient Name: ");
                        scanf("%s", appointments[i].patientName);
                        printf("Enter new Doctor Name: ");
                        scanf("%s", appointments[i].doctorName);
                        printf("Appointment updated successfully!\n");
                        break;
                    }
                }
                if(i == count) {
                    printf("Invalid Appointment ID!\n");
                }
                break;
            case 4:
                printf("Enter Appointment ID to delete: ");
                scanf("%d", &appointmentID);
                for(i = 0; i < count; i++) {
                    if(appointmentID == appointments[i].appointmentID) {
                        for(int j = i; j < count - 1; j++) {
                            appointments[j] = appointments[j+1];
                        }
                        count--;
                        printf("Appointment deleted successfully!\n");
                        break;
                    }
                }
                if(i == count) {
                    printf("Invalid Appointment ID!\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
        
    } while(choice != 5);
    
    return 0;
}