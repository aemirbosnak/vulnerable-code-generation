//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function declarations */
void display_menu();
void add_appointment();
void view_appointments();
void export_appointments();

/* Struct for storing appointment information */
struct appointment {
    char title[50];
    char description[200];
    char date[20];
    char time[20];
};

/* Global variables */
struct appointment appointments[50];
int num_appointments = 0;

int main() {
    int choice;

    /* Loop until user chooses to exit */
    do {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                export_appointments();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

/* Display program menu */
void display_menu() {
    printf("\nAppointment Scheduler\n");
    printf("-----------------------\n");
    printf("1. Add appointment\n");
    printf("2. View appointments\n");
    printf("3. Export appointments\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

/* Add a new appointment */
void add_appointment() {
    struct appointment new_appointment;

    /* Prompt user for appointment details */
    printf("\nEnter appointment title: ");
    fgets(new_appointment.title, 50, stdin);
    printf("Enter appointment description: ");
    fgets(new_appointment.description, 200, stdin);
    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(new_appointment.date, 20, stdin);
    printf("Enter appointment time (HH:MM): ");
    fgets(new_appointment.time, 20, stdin);

    /* Add new appointment to global array */
    appointments[num_appointments] = new_appointment;
    num_appointments++;
}

/* View all appointments */
void view_appointments() {
    int i;

    /* Loop through all appointments and print details */
    printf("\nAll Appointments\n");
    for(i = 0; i < num_appointments; i++) {
        printf("-----------------------\n");
        printf("Title: %s", appointments[i].title);
        printf("Description: %s", appointments[i].description);
        printf("Date: %s", appointments[i].date);
        printf("Time: %s", appointments[i].time);
    }
}

/* Export all appointments to a text file */
void export_appointments() {
    int i;
    FILE *fp;
    char filename[50];

    /* Get filename from user */
    printf("\nEnter filename to save appointments: ");
    fgets(filename, 50, stdin);

    /* Open file for writing */
    fp = fopen(filename, "w");

    /* Loop through all appointments and write details to file */
    for(i = 0; i < num_appointments; i++) {
        fprintf(fp, "Title: %s", appointments[i].title);
        fprintf(fp, "Description: %s", appointments[i].description);
        fprintf(fp, "Date: %s", appointments[i].date);
        fprintf(fp, "Time: %s", appointments[i].time);
    }

    /* Close file */
    fclose(fp);

    printf("Appointments successfully exported to %s\n", filename);
}