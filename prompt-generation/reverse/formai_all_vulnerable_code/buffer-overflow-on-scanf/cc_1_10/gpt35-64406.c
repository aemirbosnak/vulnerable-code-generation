//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int age;
    char gender[10];
    char phone_no[15];
    char date[11];
    char time[6];
} Appointment;

Appointment schedule[MAX_SIZE];
int num_of_appointments = 0;

void make_appointment(char* name, int age, char* gender, char* phone_no, char* date, char* time) {
    if (num_of_appointments >= MAX_SIZE) {
        printf("Appointment scheduler is full!\n");
        return;
    }

    strcpy(schedule[num_of_appointments].name, name);
    schedule[num_of_appointments].age = age;
    strcpy(schedule[num_of_appointments].gender, gender);
    strcpy(schedule[num_of_appointments].phone_no, phone_no);
    strcpy(schedule[num_of_appointments].date, date);
    strcpy(schedule[num_of_appointments].time, time);

    num_of_appointments++;

    printf("Appointment made successfully!\n");
}

void print_schedule() {
    printf("List of Appointments\n---------------------\n");

    for (int i = 0; i < num_of_appointments; i++) {
        printf("Name: %s\n", schedule[i].name);
        printf("Age: %d\n", schedule[i].age);
        printf("Gender: %s\n", schedule[i].gender);
        printf("Phone Number: %s\n", schedule[i].phone_no);
        printf("Date: %s\n", schedule[i].date);
        printf("Time: %s\n", schedule[i].time);
        printf("---------------------\n");
    }
}

int main() {
    printf("Welcome to the Multiplayer Appointment Scheduler!\n");
    printf("You can use this program to make appointments for multiple users.\n");
    printf("Simply follow the instructions.\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Make an appointment\n");
        printf("2. View schedule\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[50], gender[10], phone_no[15], date[11], time[6];
                int age;

                printf("\nEnter name: ");
                scanf("%s", name);

                printf("Enter age: ");
                scanf("%d", &age);

                printf("Enter gender: ");
                scanf("%s", gender);

                printf("Enter phone number: ");
                scanf("%s", phone_no);

                printf("Appointment date (DD/MM/YYYY): ");
                scanf("%s", date);

                printf("Appointment time (HH:MM): ");
                scanf("%s", time);

                make_appointment(name, age, gender, phone_no, date, time);

                break;
            }
            case 2: {
                print_schedule();
                break;
            }
            case 3: {
                printf("Thank you for using the Multiplayer Appointment Scheduler!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice! Try again.\n");
                break;
            }
        }
    }

    return 0;
}