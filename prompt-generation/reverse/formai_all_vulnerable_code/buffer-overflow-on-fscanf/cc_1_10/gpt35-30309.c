//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure to store appointment details
struct appointment{
    char name[100];
    char doctor[100];
    char time[10];
};

//Function to add a new appointment
void addAppointment(){
    struct appointment newAppointment;
    printf("\nEnter patient name: ");
    scanf("%s", newAppointment.name);
    printf("\nEnter doctor name: ");
    scanf("%s", newAppointment.doctor);
    printf("\nEnter time of appointment (HH:MM): ");
    scanf("%s", newAppointment.time);

    //Storing appointment details in a file
    FILE *fp = fopen("appointments.txt", "a");
    fprintf(fp, "%s %s %s\n", newAppointment.name, newAppointment.doctor, newAppointment.time);
    fclose(fp);

    printf("\nAppointment added successfully!\n");
}

//Function to view all appointments
void viewAppointments(){
    FILE *fp = fopen("appointments.txt", "r");
    char name[100], doctor[100], time[10];

    if(fp == NULL){
        printf("\nNo appointments added yet!\n");
        return;
    }

    printf("\nAll Appointments:\n");
    printf("Patient Name\tDoctor Name\tAppointment Time\n");
    printf("------------------------------------------------\n");

    //Reading and printing appointment details from file
    while(fscanf(fp, "%s %s %s", name, doctor, time) != EOF){
        printf("%s\t\t%s\t\t%s\n", name, doctor, time);
    }

    fclose(fp);
}

int main(){
    int choice;

    printf("\nWelcome to the Appointment Scheduler!\n");

    while(1){
        printf("\nChoose an option:\n");
        printf("\n1. Add Appointment");
        printf("\n2. View Appointments");
        printf("\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("\nThank you for using Appointment Scheduler!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}