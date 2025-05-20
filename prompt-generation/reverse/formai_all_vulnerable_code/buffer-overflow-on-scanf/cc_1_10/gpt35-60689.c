//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

//Defining a struct for the appointment
struct Appointment {
    char name[30];
    int day;
    int time;
    char location[50];
};

//Function prototypes
void addAppointment(struct Appointment appointments[], int *appointmentCount);
void printAppointments(struct Appointment appointments[], int appointmentCount);

//Main function
int main() {
    printf("Welcome to the appointment scheduler!\n");

    struct Appointment appointments[100]; //Array of appointments with max capacity of 100
    int appointmentCount = 0; //Variable to keep track of the number of appointments

    //Loop Menu
    while(1) {
        char option;
        printf("\nEnter 'a' to add an appointment or 'p' to print all appointments: ");
        scanf(" %c", &option);

        if(option == 'a') { //Adding an appointment
            addAppointment(appointments, &appointmentCount);
        } else if(option == 'p') { //Printing all appointments
            if(appointmentCount == 0) {
                printf("There are no appointments scheduled!\n");
            } else {
                printAppointments(appointments, appointmentCount);
            }
        } else { //Invalid input
            printf("Invalid option!\n");
        }
    }

    return 0;
}

//Function to add an appointment
void addAppointment(struct Appointment appointments[], int *appointmentCount) {
    printf("\nEnter the name of the appointment owner: ");
    scanf("%s", appointments[*appointmentCount].name);

    printf("Enter the day of the appointment (1-31): ");
    scanf("%d", &appointments[*appointmentCount].day);

    if(appointments[*appointmentCount].day < 1 || appointments[*appointmentCount].day > 31) {
        printf("Invalid day entered!\n");
        return;
    }

    printf("Enter the time of the appointment (in 24-hour format): ");
    scanf("%d", &appointments[*appointmentCount].time);

    if(appointments[*appointmentCount].time < 0 || appointments[*appointmentCount].time > 23) {
        printf("Invalid time entered!\n");
        return;
    }

    printf("Enter the location of the appointment: ");
    scanf("%s", appointments[*appointmentCount].location);

    printf("Appointment added successfully!\n");

    (*appointmentCount)++; //Incrementing the appointment count
}

//Function to print all appointments
void printAppointments(struct Appointment appointments[], int appointmentCount) {
    printf("\nAll appointments:\n");

    for(int i=0; i<appointmentCount; i++) {
        printf("Appointment owner: %s\n", appointments[i].name);
        printf("Day: %d\n", appointments[i].day);
        printf("Time: %d:00\n", appointments[i].time);
        printf("Location: %s\n", appointments[i].location);
        printf("\n");
    }
}