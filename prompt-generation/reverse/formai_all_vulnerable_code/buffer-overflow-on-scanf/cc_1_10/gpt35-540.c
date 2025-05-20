//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct to store appointment details
struct Appointment {
    char name[50];
    char purpose[100];
    int day;
    int month;
    int year;
    char time[10];
};

//Function declarations
void displayMenu();
void newAppointment();
void viewAppointments();
void saveAppointmentsToFile();
void loadAppointmentsFromFile();
void exitProgram();

//Global variables
struct Appointment *appointments[100];
int numAppointments = 0;

int main() {
    loadAppointmentsFromFile();
    displayMenu();
    return 0;
}

//Function to display the options menu
void displayMenu() {
    int choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Create new appointment\n");
        printf("2. View appointments\n");
        printf("3. Save appointments to file\n");
        printf("4. Load appointments from file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                newAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                saveAppointmentsToFile();
                break;
            case 4:
                loadAppointmentsFromFile();
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);
}

//Function to create a new appointment
void newAppointment() {
    struct Appointment *newAppt = (struct Appointment*)malloc(sizeof(struct Appointment));

    printf("Enter name of the person: ");
    scanf("%s", &newAppt->name);

    printf("Enter purpose of the appointment: ");
    scanf("%s", &newAppt->purpose);

    printf("Enter day of the appointment: ");
    scanf("%d", &newAppt->day);

    printf("Enter month of the appointment: ");
    scanf("%d", &newAppt->month);

    printf("Enter year of the appointment: ");
    scanf("%d", &newAppt->year);

    printf("Enter time of the appointment (in HH:MM format): ");
    scanf("%s", &newAppt->time);

    appointments[numAppointments++] = newAppt;

    printf("Appointment created!\n");
}

//Function to view existing appointments
void viewAppointments() {
    printf("Existing appointments:\n");
    printf("Name\tPurpose\t\tDate\t\tTime\n");
    for(int i=0; i<numAppointments; i++) {
        printf("%s\t%s\t\t%d/%d/%d\t%s\n", appointments[i]->name, appointments[i]->purpose, appointments[i]->day, appointments[i]->month, appointments[i]->year, appointments[i]->time);
    }
}

//Function to save all appointments to file
void saveAppointmentsToFile() {
    FILE *outfile = fopen("appointments.txt", "w");

    if(outfile == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(outfile, "Name,Purpose,Date,Time\n");
    for(int i=0; i<numAppointments; i++) {
        fprintf(outfile, "%s,%s,%d/%d/%d,%s\n", appointments[i]->name, appointments[i]->purpose, appointments[i]->day, appointments[i]->month, appointments[i]->year, appointments[i]->time);
    }

    fclose(outfile);

    printf("Appointments saved to file!\n");
}

//Function to load appointments from file
void loadAppointmentsFromFile() {
    FILE *infile = fopen("appointments.txt", "r");

    if(infile == NULL) {
        printf("No saved appointments found.\n");
        return;
    }

    char line[150];
    fgets(line, sizeof(line), infile); //Ignore the header line

    while(fgets(line, sizeof(line), infile)) {
        struct Appointment *newAppt = (struct Appointment*)malloc(sizeof(struct Appointment));

        char *token = strtok(line, ",");
        strcpy(newAppt->name, token);

        token = strtok(NULL, ",");
        strcpy(newAppt->purpose, token);

        token = strtok(NULL, ",");
        sscanf(token, "%d/%d/%d", &newAppt->day, &newAppt->month, &newAppt->year);

        token = strtok(NULL, ",");
        strcpy(newAppt->time, token);

        appointments[numAppointments++] = newAppt;
    }

    fclose(infile);

    printf("Appointments loaded from file!\n");
}

//Function to exit the program
void exitProgram() {
    printf("Exiting program.\n");
    exit(0);
}