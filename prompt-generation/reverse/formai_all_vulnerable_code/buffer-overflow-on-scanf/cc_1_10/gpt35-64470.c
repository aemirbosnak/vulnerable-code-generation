//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

//Structure to hold all the necessary details of an Appointment
struct Appointment{
    char name[30];
    char date[12];
    char time[6];
    char description[100];
    int isBooked;
};

//Function to add new Appointment
void addAppointment(struct Appointment* appointments, int* numOfAppointments){
    if(*numOfAppointments >= MAX){
        printf("\nError: Maximum number of appointments reached!\n");
        return;
    }

    printf("Enter name of the appointment: ");
    scanf(" %[^\n]",appointments[*numOfAppointments].name);

    printf("Enter the date of the appointment (in format dd/mm/yyyy): ");
    scanf(" %[^\n]",appointments[*numOfAppointments].date);

    printf("Enter the time of the appointment (in format hh:mm): ");
    scanf(" %[^\n]",appointments[*numOfAppointments].time);

    printf("Enter the description for this appointment: ");
    scanf(" %[^\n]",appointments[*numOfAppointments].description);

    appointments[*numOfAppointments].isBooked = 0;
    printf("\nAppointment added successfully!\n");
    (*numOfAppointments)++;
}

//Function to display all the appointments
void displayAppointments(struct Appointment* appointments, int numOfAppointments){
    if(numOfAppointments == 0){
        printf("\nNo Appointments yet!\n");
        return;
    }

    printf("\nAppointments:\n");
    printf("---------------------------------------------------------------------\n");
    for(int i=0;i<numOfAppointments;i++){
        printf("Name: %s\n",appointments[i].name);
        printf("Date: %s\n",appointments[i].date);
        printf("Time: %s\n",appointments[i].time);
        printf("Description: %s\n",appointments[i].description);
        if(appointments[i].isBooked == 0){
            printf("Status: Available\n");
        }
        else{
            printf("Status: Booked\n");
        }
        printf("---------------------------------------------------------------------\n");
    }
}

//Function to display all the available appointments
void displayAvailableAppointments(struct Appointment* appointments, int numOfAppointments){
    if(numOfAppointments == 0){
        printf("\nNo Appointments yet!\n");
        return;
    }

    printf("\nAvailable Appointments:\n");
    printf("---------------------------------------------------------------------\n");
    for(int i=0;i<numOfAppointments;i++){
        if(appointments[i].isBooked == 0){
            printf("Name: %s\n",appointments[i].name);
            printf("Date: %s\n",appointments[i].date);
            printf("Time: %s\n",appointments[i].time);
            printf("Description: %s\n",appointments[i].description);
            printf("---------------------------------------------------------------------\n");
        }
    }
}

//Function to book an available appointment
void bookAppointment(struct Appointment* appointments, int numOfAppointments){
    if(numOfAppointments == 0){
        printf("\nNo Appointments yet!\n");
        return;
    }

    char name[30], date[12], time[6];
    int found = 0;

    printf("Enter the name of the Appointment you want to book: ");
    scanf(" %[^\n]",name);

    for(int i=0;i<numOfAppointments;i++){
        if(strcmp(appointments[i].name,name) == 0 && appointments[i].isBooked == 0){
            found = 1;
            printf("Enter the date (in format dd/mm/yyyy): ");
            scanf(" %[^\n]",date);
            if(strcmp(appointments[i].date,date) == 0){
                printf("Enter the time (in format hh:mm): ");
                scanf(" %[^\n]",time);
                if(strcmp(appointments[i].time,time) == 0){
                    appointments[i].isBooked = 1;
                    printf("\nAppointment booked successfully!\n");
                    return;
                }
                else{
                    printf("\nError: Invalid time for this appointment!\n");
                    return;
                }
            }
            else{
                printf("\nError: Invalid date for this appointment!\n");
                return;
            }
        }
    }

    if(!found){
        printf("\nError: Appointment not found or already booked!\n");
    }
}

int main(){

    struct Appointment appointments[MAX];
    int numOfAppointments = 0;

    char choice;
    do{
        //Display menu
        printf("\nMenu\n");
        printf("1. Add new Appointment\n");
        printf("2. Display all Appointments\n");
        printf("3. Display available Appointments\n");
        printf("4. Book an Appointment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c",&choice);

        //Perform corresponding action based on user's choice
        switch(choice){
            case '1': addAppointment(appointments,&numOfAppointments);
                      break;
            case '2': displayAppointments(appointments,numOfAppointments);
                      break;
            case '3': displayAvailableAppointments(appointments,numOfAppointments);
                      break;
            case '4': bookAppointment(appointments,numOfAppointments);
                      break;
            case '5': printf("\nExiting..\n");
                      exit(0);
            default:  printf("\nInvalid choice!\n");
        }
    }while(1);

    return 0;
}