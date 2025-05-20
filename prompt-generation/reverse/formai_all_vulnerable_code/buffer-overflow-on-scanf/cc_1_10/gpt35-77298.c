//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure to hold appointment information
typedef struct {
    char date[20];
    char time[10];
    char client_name[50];
    char notes[100];
} Appointment;

// Function prototype
void display_menu();
void add_appointment(Appointment **appointments_list, int *num_appointments);
void view_appointments(Appointment *appointments_list, int num_appointments);
void save_appointments(Appointment *appointments_list, int num_appointments);
void load_appointments(Appointment **appointments_list, int *num_appointments);
int search_appointment(Appointment *appointments_list, int num_appointments, char *client_name);

int main() {
    int choice;
    int num_appointments = 0;
    Appointment *appointments_list = NULL;
    
    // Load appointments from file
    load_appointments(&appointments_list, &num_appointments);
    
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment(&appointments_list, &num_appointments);
                break;
            case 2:
                view_appointments(appointments_list, num_appointments);
                break;
            case 3:
                save_appointments(appointments_list, num_appointments);
                break;
            case 4:
                printf("Thank you for using the appointment scheduler.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    // Free dynamically allocated memory
    free(appointments_list);
    
    return 0;
}

void display_menu() {
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add appointment\n");
    printf("2. View appointments\n");
    printf("3. Save appointments\n");
    printf("4. Quit\n");
    printf("\nEnter your choice: ");
}

void add_appointment(Appointment **appointments_list, int *num_appointments) {
    char date[20];
    char time[10];
    char client_name[50];
    char notes[100];
    
    // Get appointment details from user
    printf("\nEnter date (MM/DD/YYYY): ");
    scanf("%s", date);
    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", time);
    printf("Enter client name: ");
    getchar(); // Clear newline character
    fgets(client_name, 50, stdin);
    client_name[strcspn(client_name, "\n")] = '\0'; // Remove trailing newline character
    printf("Enter notes: ");
    fgets(notes, 100, stdin);
    notes[strcspn(notes, "\n")] = '\0'; // Remove trailing newline character
    
    // Allocate memory for new appointment and copy details
    Appointment *new_appointment = (Appointment*) malloc(sizeof(Appointment));
    strcpy(new_appointment->date, date);
    strcpy(new_appointment->time, time);
    strcpy(new_appointment->client_name, client_name);
    strcpy(new_appointment->notes, notes);
    
    // Add new appointment to list
    (*num_appointments)++;
    *appointments_list = (Appointment*) realloc(*appointments_list, *num_appointments * sizeof(Appointment));
    (*appointments_list)[(*num_appointments)-1] = *new_appointment;
    
    printf("Appointment added successfully!\n\n");
}

void view_appointments(Appointment *appointments_list, int num_appointments) {
    if (num_appointments == 0) {
        printf("There are no appointments scheduled.\n\n");
        return;
    }
    
    // Print header
    printf("\n%-12s %-10s %-20s %-30s\n", "Date", "Time", "Client Name", "Notes");
    printf("-------------------------------------------------------------\n");
    
    // Loop through appointments and print details
    for (int i = 0; i < num_appointments; i++) {
        printf("%-12s %-10s %-20s %-30s\n", appointments_list[i].date, appointments_list[i].time, appointments_list[i].client_name, appointments_list[i].notes);
    }
    printf("\n");
}

void save_appointments(Appointment *appointments_list, int num_appointments) {
    FILE *appointments_file = fopen("appointments.txt", "w");
    if (appointments_file == NULL) {
        printf("Error opening file.\n\n");
        return;
    }
    
    // Loop through appointments and write details to file
    for (int i = 0; i < num_appointments; i++) {
        fprintf(appointments_file, "%s,%s,%s,%s\n", appointments_list[i].date, appointments_list[i].time, appointments_list[i].client_name, appointments_list[i].notes);
    }
    
    fclose(appointments_file);
    printf("Appointments saved to file.\n\n");
}

void load_appointments(Appointment **appointments_list, int *num_appointments) {
    FILE *appointments_file = fopen("appointments.txt", "r");
    if (appointments_file == NULL) {
        printf("Error opening file. Creating new file.\n\n");
        return;
    }
    
    // Determine number of appointments in file
    int count = 0;
    char c;
    while ((c = fgetc(appointments_file)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    rewind(appointments_file);
    
    // Allocate memory for appointments and read details from file
    *num_appointments = count;
    *appointments_list = (Appointment*) malloc(*num_appointments * sizeof(Appointment));
    char line[200];
    int i = 0;
    while (fgets(line, 200, appointments_file) != NULL) {
        char *token = strtok(line, ",");
        strcpy((*appointments_list)[i].date, token);
        token = strtok(NULL, ",");
        strcpy((*appointments_list)[i].time, token);
        token = strtok(NULL, ",");
        strcpy((*appointments_list)[i].client_name, token);
        token = strtok(NULL, ",");
        strcpy((*appointments_list)[i].notes, token);
        i++;
    }
    
    fclose(appointments_file);
}

int search_appointment(Appointment *appointments_list, int num_appointments, char *client_name) {
    // Loop through appointments and check for client name
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments_list[i].client_name, client_name) == 0) {
            return i;
        }
    }
    return -1; // Appointment not found
}