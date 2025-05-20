//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[30];
    int age;
    char gender;
    int phone;
    char email[50];
    time_t appointment;
} appointment;

int main() {
    int choice, i, n, count = 0;
    char ch;
    appointment patient[100];

    printf("Welcome to the Cheerful Appointment Scheduler!\n");
    printf("Please choose an option:\n");
    printf("1. Add a new patient\n");
    printf("2. View patient list\n");
    printf("3. Schedule an appointment\n");
    printf("4. Cancel an appointment\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter patient name: ");
            scanf("%s", patient[count].name);
            printf("Enter patient age: ");
            scanf("%d", &patient[count].age);
            printf("Enter patient gender (M/F): ");
            scanf(" %c", &patient[count].gender);
            printf("Enter patient phone number: ");
            scanf("%d", &patient[count].phone);
            printf("Enter patient email: ");
            scanf("%s", patient[count].email);
            printf("Appointment scheduled for (YYYY-MM-DD HH:MM:SS): ");
            scanf("%s", patient[count].appointment);
            count++;
            break;
        case 2:
            printf("Patient List:\n");
            for(i=0; i<count; i++) {
                printf("%s %d years old %c %d %s\n", patient[i].name, patient[i].age, patient[i].gender, patient[i].phone, patient[i].email);
            }
            break;
        case 3:
            printf("Enter patient name: ");
            scanf("%s", ch);
            for(i=0; i<count; i++) {
                if(strcmp(patient[i].name, ch) == 0) {
                    printf("Appointment scheduled for %s at %s\n", patient[i].name, ctime(&patient[i].appointment));
                }
            }
            break;
        case 4:
            printf("Enter patient name: ");
            scanf("%s", ch);
            for(i=0; i<count; i++) {
                if(strcmp(patient[i].name, ch) == 0) {
                    patient[i].appointment = 0;
                    printf("Appointment cancelled for %s\n", patient[i].name);
                }
            }
            break;
        case 5:
            printf("Thank you for using the Cheerful Appointment Scheduler!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}