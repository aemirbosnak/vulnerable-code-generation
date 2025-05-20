//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure for patient data
struct patient {
    char name[50];
    int age;
    char gender[10];
    char phone[20];
    char email[50];
};

// structure for appointment data
struct appointment {
    char date[15];
    char time[10];
    struct patient p;
};

// function to display main menu
void display_menu() {
    printf("\nAppointment Scheduler\n");
    printf("------------------------\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("0. Exit Program\n");
    printf("------------------------\n");
}

// function to get patient details
struct patient get_patient_details() {
    struct patient p;
    printf("\nEnter Patient Details:\n");
    printf("Name: ");
    scanf("%s", p.name);
    printf("Age: ");
    scanf("%d", &p.age);
    printf("Gender: ");
    scanf("%s", p.gender);
    printf("Phone: ");
    scanf("%s", p.phone);
    printf("Email: ");
    scanf("%s", p.email);
    return p;
}

// function to get appointment details
struct appointment get_appointment_details() {
    struct appointment a;
    printf("\nEnter Appointment Details:\n");
    printf("Date: ");
    scanf("%s", a.date);
    printf("Time: ");
    scanf("%s", a.time);
    a.p = get_patient_details();
    return a;
}

// function to print patient details
void print_patient_details(struct patient p) {
    printf("\nPatient Details:\n");
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %s\n", p.gender);
    printf("Phone: %s\n", p.phone);
    printf("Email: %s\n", p.email);
}

// function to print appointment details
void print_appointment_details(struct appointment a) {
    printf("\nAppointment Details:\n");
    printf("Date: %s\n", a.date);
    printf("Time: %s\n", a.time);
    print_patient_details(a.p);
}

int main() {
    int choice;
    int count = 0;
    struct appointment appointments[50]; // array to store appointments

    do {
        display_menu();
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: { // Schedule Appointment
                appointments[count++] = get_appointment_details(); // get appointment details and add to array
                printf("\nAppointment Scheduled Successfully!\n");
                break;
            }
            case 2: { // View Appointments
                if (count == 0) {
                    printf("\nNo Appointments Scheduled!\n");
                } else {
                    printf("\nAppointments:\n");
                    for (int i = 0; i < count; i++) {
                        printf("------------------------\n");
                        printf("Appointment %d:\n", i+1);
                        print_appointment_details(appointments[i]);
                    }
                }
                break;
            }
            case 0: { // Exit Program
                printf("\nExiting Program...\n");
                break;
            }
            default: { // Invalid Choice
                printf("\nInvalid Choice! Try Again.\n");
                break;
            }
        }
    } while (choice != 0);

    return 0;
}