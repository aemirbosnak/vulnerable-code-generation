//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure for the Appointment object
struct Appointment { 
    char name[50];
    char email[50]; 
    char phone[15];
    char date[10];
    char time[10];
    char reason[100];
};

// Define a function to add an appointment
void makeAppointment(struct Appointment appointmentArray[], int size) {
    printf("Please enter your name: ");
    scanf("%s", appointmentArray[size].name);

    printf("Please enter your email address: ");
    scanf("%s", appointmentArray[size].email);

    printf("Please enter your phone number: ");
    scanf("%s", appointmentArray[size].phone);

    printf("Please enter the date you would like the appointment (MM/DD/YYYY): ");
    scanf("%s", appointmentArray[size].date);

    printf("Please enter the time you would like the appointment (HH:MM AM/PM): ");
    scanf("%s", appointmentArray[size].time);

    printf("Please enter the reason for the appointment: ");
    scanf("%s", appointmentArray[size].reason);
}

// Define a function to print all appointments
void printAppointments(struct Appointment appointmentArray[], int size) {
    if (size == 0) {
        printf("No appointments scheduled!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("\nAppointment #%d:\n", i+1);
        printf("Name: %s\n", appointmentArray[i].name);
        printf("Email: %s\n", appointmentArray[i].email);
        printf("Phone: %s\n", appointmentArray[i].phone);
        printf("Date: %s\n", appointmentArray[i].date);
        printf("Time: %s\n", appointmentArray[i].time);
        printf("Reason: %s\n", appointmentArray[i].reason);
    }
}

// Define a function to delete all appointments
void deleteAppointments(struct Appointment appointmentArray[], int size) {
    if (size == 0) {
        printf("No appointments scheduled!\n");
        return;
    }
    printf("Are you sure you want to delete all appointments? (Y/N)\n");
    char ans;
    scanf("%c", &ans);
    if (ans == 'Y' || ans == 'y') {
        memset(appointmentArray, 0, sizeof(appointmentArray));   
        printf("All appointments deleted!\n");
    } else {
        printf("No appointments were deleted.\n");
    }  
}

// Define the main function to run the program
int main() {
    struct Appointment appointments[100];
    int numAppointments = 0;

    while(1) {
        printf("\nWelcome to the appointment scheduler!\n");
        printf("1. Make a new appointment.\n");
        printf("2. View all appointments.\n");
        printf("3. Delete all appointments.\n");
        printf("4. Exit.\n");

        char ans;
        scanf("%c", &ans);
        switch(ans) {
            case '1':
                makeAppointment(appointments, numAppointments);
                numAppointments++;
                break;
            case '2':
                printAppointments(appointments, numAppointments);
                break;
            case '3':
                deleteAppointments(appointments, numAppointments);
                numAppointments = 0;
                break;
            case '4':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}