//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 50             // Maximum number of patients that can be scheduled
#define MAX_NAME_LENGTH 30          // Maximum length of a patient's name
#define MAX_APPOINTMENTS 5          // Maximum number of appointments a patient can have in a week

typedef struct {
    char name[MAX_NAME_LENGTH];
    int appointments[MAX_APPOINTMENTS];
} patient;                          // Structure to store patient's name and appointments

int main() {
    patient schedule[MAX_PATIENTS]; // Array of patients scheduled for appointments
    int num_patients = 0;           // Keeps track of the number of patients currently scheduled
    int option = 0;                 // Stores the user's menu choice
    int patient_index = 0;          // Index of a patient in the schedule array
    int appointment_index = 0;      // Index of an appointment within a patient's appointment array
    
    printf("Welcome to the Appointment Scheduler!\n\n");

    while (option != 4) {
        printf("Please select an option from the menu:\n");
        printf("1. Schedule an appointment\n");
        printf("2. Cancel an appointment\n");
        printf("3. View scheduled appointments\n");
        printf("4. Exit program\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                if (num_patients == MAX_PATIENTS) {
                    printf("Sorry, the maximum number of patients has been reached.\n\n");
                    break;
                }
                printf("Please enter the patient's name: ");
                scanf("%s", schedule[num_patients].name);
                
                for (int i = 0; i < MAX_APPOINTMENTS; i++) {
                    printf("Please enter the appointment time for day %d: ", i + 1);
                    scanf("%d", &schedule[num_patients].appointments[i]);
                }
                printf("Appointment scheduled successfully!\n\n");
                num_patients++;
                break;
            
            case 2:
                printf("Please enter the patient's name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                
                for (int i = 0; i < num_patients; i++) {
                    if (strcmp(schedule[i].name, name) == 0) {
                        printf("Please enter the index of the appointment you wish to cancel (1 - %d): ", MAX_APPOINTMENTS);
                        scanf("%d", &appointment_index);
                        if (appointment_index < 1 || appointment_index > MAX_APPOINTMENTS) {
                            printf("Error: Invalid appointment index.\n\n");
                            break;
                        }
                        schedule[i].appointments[appointment_index - 1] = 0;
                        printf("Appointment cancelled successfully!\n\n");
                        break;
                    }
                    if (i == num_patients - 1) {
                        printf("Error: Patient not found.\n\n");
                    }
                }
                break;
            
            case 3:
                printf("Current Schedule:\n");
                if (num_patients == 0) {
                    printf("No appointments scheduled.\n\n");
                    break;
                }
                for (int i = 0; i < num_patients; i++) {
                    printf("%d. %s - ", i + 1, schedule[i].name);
                    for (int j = 0; j < MAX_APPOINTMENTS; j++) {
                        printf("%d ", schedule[i].appointments[j]);
                    }
                    printf("\n");
                }
                printf("\n");
                break;
            
            case 4:
                printf("Exiting program...\n");
                break;
            
            default:
                printf("Error: Invalid option selected.\n\n");
                break;
        }
    }

    return 0;
}