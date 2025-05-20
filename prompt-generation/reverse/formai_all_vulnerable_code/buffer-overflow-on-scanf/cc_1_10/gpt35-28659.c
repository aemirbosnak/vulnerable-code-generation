//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* A time machine struct */
struct TimeMachine {
    char model[50];
    int year;
};

/* A function to add a new time machine */
void addTimeMachine(struct TimeMachine *time_machine) {
    printf("Enter Time Machine model: ");
    scanf("%s", time_machine->model);
    printf("Enter Time Machine year: ");
    scanf("%d", &time_machine->year);
    printf("Time Machine %s from %d has been added!\n", time_machine->model, time_machine->year);
}

/* A function to travel to a specific year */
void travelToYear(int year, struct TimeMachine *time_machine) {
    if (year < time_machine->year) {
        printf("%d? Are you crazy? I can't travel back in time!\n", year);
    } else if (year == time_machine->year) {
        printf("I am already in year %d!\n", year);
    } else {
        printf("Traveling to year %d...\n", year);
        printf("Arrived in year %d! This place looks different...\n", year);
        time_machine->year = year;
    }
}

/* A function to display the details of the time machine */
void displayTimeMachine(struct TimeMachine time_machine) {
    printf("Time Machine %s from year %d.\n", time_machine.model, time_machine.year);
}

/* Main function */
int main() {
    int choice, year;
    bool exit_program = false;
    struct TimeMachine my_time_machine;

    /* Initialize the time machine */
    strcpy(my_time_machine.model, "Delorean");
    my_time_machine.year = 1985;

    /* Loop until the user chooses to exit */
    while (!exit_program) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new Time Machine\n");
        printf("2. Travel to a specific year\n");
        printf("3. Display Time Machine details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTimeMachine(&my_time_machine);
                break;
            case 2:
                printf("Enter the year you want to travel to: ");
                scanf("%d", &year);
                travelToYear(year, &my_time_machine);
                break;
            case 3:
                displayTimeMachine(my_time_machine);
                break;
            case 4:
                printf("Goodbye!\n");
                exit_program = true;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}