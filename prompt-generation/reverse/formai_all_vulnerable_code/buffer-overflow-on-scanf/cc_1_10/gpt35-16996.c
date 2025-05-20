//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

// Struct representing a single appointment
typedef struct Appointment {
    char patientFirstName[50];
    char patientLastName[50];
    char doctorName[50];
    char date[20];
    char time[20];
} Appointment;

// Array of appointments
Appointment appointments[MAX_APPOINTMENTS];

// Number of appointments scheduled
int numAppointments = 0;

// Function to add a new appointment
void addAppointment()
{
    // Check if there is space for a new appointment
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Max appointment limit reached.\n");
        return;
    }

    // Get appointment details from user
    printf("Enter patient's first name: ");
    scanf("%s", appointments[numAppointments].patientFirstName);

    printf("Enter patient's last name: ");
    scanf("%s", appointments[numAppointments].patientLastName);

    printf("Enter doctor's name: ");
    scanf("%s", appointments[numAppointments].doctorName);

    printf("Enter date (dd.mm.yyyy): ");
    scanf("%s", appointments[numAppointments].date);

    printf("Enter time (hh:mm): ");
    scanf("%s", appointments[numAppointments].time);

    // Increment number of appointments
    numAppointments++;

    // Print confirmation to user
    printf("Appointment scheduled successfully.\n");
}

// Function to print a single appointment
void printAppointment(int appointmentIndex)
{
    printf("========================================\n");
    printf("Appointment %d\n", appointmentIndex);
    printf("Patient: %s %s\n", appointments[appointmentIndex].patientFirstName, appointments[appointmentIndex].patientLastName);
    printf("Doctor: %s\n", appointments[appointmentIndex].doctorName);
    printf("Date: %s\n", appointments[appointmentIndex].date);
    printf("Time: %s\n", appointments[appointmentIndex].time);
}

// Function to print all appointments
void printAppointments()
{
    // Check if there are any appointments
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    // Print all appointments
    for (int i = 0; i < numAppointments; i++) {
        printAppointment(i);
    }
}

// Function to search for appointments by patient name
void searchAppointments()
{
    // Get patient name to search for
    char searchName[100];
    printf("Enter patient name to search for: ");
    scanf("%s", searchName);

    // Search for appointments matching the name
    int foundAppointments = 0;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].patientFirstName, searchName) == 0 ||
            strcmp(appointments[i].patientLastName, searchName) == 0) {
            printAppointment(i);
            foundAppointments++;
        }
    }

    // Print message if no matching appointments were found
    if (foundAppointments == 0) {
        printf("No appointments found for patient %s.\n", searchName);
    }
}

// Function to randomly generate appointments for testing purposes
void generateAppointments()
{
    // Array of possible patient first names
    char* patientFirstNames[] = {
        "John", "Jane", "Bob", "Samantha", "David",
        "Amy", "Emily", "Maggie", "Max", "Sophia"
    };
    int numPatientFirstNames = 10;

    // Array of possible patient last names
    char* patientLastNames[] = {
        "Smith", "Johnson", "Wilson", "Garcia", "Taylor",
        "Lee", "Nguyen", "Brown", "Jones", "Davis"
    };
    int numPatientLastNames = 10;

    // Array of possible doctor names
    char* doctorNames[] = {
        "Dr. Smith", "Dr. Rodriguez", "Dr. Lee", "Dr. Patel", "Dr. Nguyen"
    };
    int numDoctorNames = 5;

    // Array of possible dates
    char* dates[] = {
        "01.01.2022", "02.01.2022", "03.01.2022", "04.01.2022", "05.01.2022",
        "06.01.2022", "07.01.2022", "08.01.2022", "09.01.2022", "10.01.2022"
    };
    int numDates = 10;

    // Array of possible times
    char* times[] = {
        "09:00", "10:00", "11:00", "12:00", "13:00",
        "14:00", "15:00", "16:00", "17:00", "18:00"
    };
    int numTimes = 10;

    // Generate random appointments
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        strcpy(appointments[i].patientFirstName, patientFirstNames[rand() % numPatientFirstNames]);
        strcpy(appointments[i].patientLastName, patientLastNames[rand() % numPatientLastNames]);
        strcpy(appointments[i].doctorName, doctorNames[rand() % numDoctorNames]);
        strcpy(appointments[i].date, dates[rand() % numDates]);
        strcpy(appointments[i].time, times[rand() % numTimes]);
        numAppointments++;
    }

    // Print confirmation to user
    printf("Appointments generated successfully.\n");
}

int main()
{
    // Set random seed
    srand(time(NULL));

    // Main loop
    while (1) {
        // Print menu options
        printf("\n");
        printf("1. Schedule appointment\n");
        printf("2. View all appointments\n");
        printf("3. Search appointments by patient name\n");
        printf("4. Generate test appointments\n");
        printf("5. Exit\n");

        // Get user choice
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        // Perform action based on user choice
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                printAppointments();
                break;
            case 3:
                searchAppointments();
                break;
            case 4:
                generateAppointments();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}