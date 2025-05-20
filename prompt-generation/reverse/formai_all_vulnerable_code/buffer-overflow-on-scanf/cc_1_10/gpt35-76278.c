//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct appointment {
    char name[MAX];
    char date[MAX];
    char time[MAX];
};

void find_appointment(struct appointment *appointments, int size) {
    char temp[MAX];
    printf("Please enter a name to look up: ");
    fgets(temp, MAX, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    for (int i = 0; i < size; i++) {
        if (strcmp(appointments[i].name, temp) == 0) {
            printf("The appointment for %s is on %s at %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
            return;
        }
    }
    printf("No appointment found for %s\n", temp);
}

void add_appointment(struct appointment *appointments, int *size) {
    printf("Please enter the name: ");
    fgets(appointments[*size].name, MAX, stdin);
    appointments[*size].name[strcspn(appointments[*size].name, "\n")] = '\0';
    printf("Please enter the date: ");
    fgets(appointments[*size].date, MAX, stdin);
    appointments[*size].date[strcspn(appointments[*size].date, "\n")] = '\0';
    printf("Please enter the time: ");
    fgets(appointments[*size].time, MAX, stdin);
    appointments[*size].time[strcspn(appointments[*size].time, "\n")] = '\0';
    (*size)++;
    printf("Appointment added successfully\n");
}

int main() {
    struct appointment appointments[MAX];
    int size = 0;
    char option;
    printf("Welcome to the Sherlock Holmes Appointment Scheduler program.\n");
    printf("Please choose an option from the menu below:\n");
    do {
        printf("\n");
        printf("A) Add an appointment\n");
        printf("F) Find an appointment\n");
        printf("X) Exit the program\n");
        printf("Your choice: ");
        scanf("%c", &option);
        while (getchar() != '\n'); // clear input buffer
        switch (option) {
            case 'A':
            case 'a':
                add_appointment(appointments, &size);
                break;
            case 'F':
            case 'f':
                find_appointment(appointments, size);
                break;
            case 'X':
            case 'x':
                printf("Thank you for using our program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again\n");
                break;
        }
    } while (option != 'X' && option != 'x');
    return 0;
}