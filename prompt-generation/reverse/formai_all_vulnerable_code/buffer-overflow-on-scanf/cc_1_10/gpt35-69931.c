//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct{
    int day;
    int month;
    int year;
} Date;

typedef struct{
    char name[MAX_SIZE];
    char email[MAX_SIZE];
    char phone[MAX_SIZE];
    Date date;
} Appointment;

void addAppointment(Appointment* appointments, int* numAppointments);
void printAppointments(Appointment* appointments, int numAppointments);
void removeAppointment(Appointment* appointments, int* numAppointments);
void searchAppointment(Appointment* appointments, int numAppointments);

int main(){
    Appointment appointments[MAX_SIZE];
    int numAppointments = 0;
    int option;

    printf("*** Welcome to Cyberpunk Appointment Scheduler ***\n");
    do{
        printf("\nPlease select an option:\n");
        printf("1. Add an appointment\n");
        printf("2. Remove an appointment\n");
        printf("3. View all appointments\n");
        printf("4. Search for an appointment\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        switch(option){
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                removeAppointment(appointments, &numAppointments);
                break;
            case 3:
                printAppointments(appointments, numAppointments);
                break;
            case 4:
                searchAppointment(appointments, numAppointments);
                break;
            case 5:
                printf("Thank you for using Cyberpunk Appointment Scheduler.\n");
                break;
            default:
                printf("Invalid option. Please select a valid option.\n");
        }
    }while(option != 5);

    return 0;
}

void addAppointment(Appointment* appointments, int* numAppointments){
    // Get appointment information from user
    printf("\nEnter appointment date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appointments[*numAppointments].date.day, &appointments[*numAppointments].date.month, &appointments[*numAppointments].date.year);
    printf("Enter client name: ");
    scanf("%s", appointments[*numAppointments].name);
    printf("Enter client email: ");
    scanf("%s", appointments[*numAppointments].email);
    printf("Enter client phone: ");
    scanf("%s", appointments[*numAppointments].phone);

    (*numAppointments)++;

    printf("\nAppointment added successfully!\n");
}

void printAppointments(Appointment* appointments, int numAppointments){
    // Print all appointments
    if(numAppointments == 0){
        printf("\nThere are no appointments.\n");
        return;
    }

    printf("\nAppointment list:\n");
    for(int i=0; i<numAppointments; i++){
        printf("%d/%d/%d\tName: %s\tEmail: %s\tPhone: %s\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year, appointments[i].name, appointments[i].email, appointments[i].phone);
    }
}

void removeAppointment(Appointment* appointments, int* numAppointments){
    int day, month, year;
    int index = -1;

    // Get appointment date from user
    printf("\nEnter appointment date to remove (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Search for appointment with date
    for(int i=0; i<*numAppointments; i++){
        if(appointments[i].date.day == day && appointments[i].date.month == month && appointments[i].date.year == year){
            index = i;
            break;
        }
    }

    if(index != -1){
        // Remove appointment
        for(int j=index; j<*numAppointments-1; j++){
            appointments[j] = appointments[j+1];
        }
        (*numAppointments)--;
        printf("\nAppointment removed successfully!\n");
    }
    else{
        printf("\nAppointment not found.\n");
    }
}

void searchAppointment(Appointment* appointments, int numAppointments){
    int day, month, year;
    int index = -1;

    // Get appointment date from user
    printf("\nEnter appointment date to search (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    // Search for appointment with date
    for(int i=0; i<numAppointments; i++){
        if(appointments[i].date.day == day && appointments[i].date.month == month && appointments[i].date.year == year){
            index = i;
            break;
        }
    }

    if(index != -1){
        printf("\nAppointment found:\n");
        printf("%d/%d/%d\tName: %s\tEmail: %s\tPhone: %s\n", appointments[index].date.day, appointments[index].date.month, appointments[index].date.year, appointments[index].name, appointments[index].email, appointments[index].phone);
    }
    else{
        printf("\nAppointment not found.\n");
    }
}