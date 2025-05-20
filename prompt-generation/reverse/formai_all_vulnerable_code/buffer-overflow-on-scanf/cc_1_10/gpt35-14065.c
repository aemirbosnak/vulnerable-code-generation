//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdbool.h>

// function prototypes
void displayMenu();
void bookAppointment(bool schedule[], int timeSlot);
void cancelAppointment(bool schedule[], int timeSlot);
void viewSchedule(bool schedule[]);
void clearScreen();

int main() {
    bool schedule[8] = {false}; // assuming 8 time slots in day
    int choice, timeSlot;
    bool validInput;

    do {
        displayMenu(); // display menu
        printf("Enter your choice: ");
        validInput = scanf("%d", &choice); // get input from user
        clearScreen(); // clear screen

        if (validInput) {
            switch (choice) {
                case 1:
                    // book appointment
                    printf("Enter time slot (1-8): ");
                    validInput = scanf("%d", &timeSlot); // get input from user
                    clearScreen(); // clear screen

                    if (validInput && timeSlot >= 1 && timeSlot <= 8) {
                        bookAppointment(schedule, timeSlot);
                    } else {
                        printf("Invalid input!\n");
                    }
                    break;
                case 2:
                    // cancel appointment
                    printf("Enter time slot (1-8): ");
                    validInput = scanf("%d", &timeSlot); // get input from user
                    clearScreen(); // clear screen

                    if (validInput && timeSlot >= 1 && timeSlot <= 8) {
                        cancelAppointment(schedule, timeSlot);
                    } else {
                        printf("Invalid input!\n");
                    }
                    break;
                case 3:
                    // view schedule
                    viewSchedule(schedule);
                    break;
                case 4:
                    // exit program
                    printf("Goodbye!\n");
                    break;
                default:
                    // invalid choice
                    printf("Invalid choice!\n");
                    break;
            }
        } else {
            printf("Invalid input!\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("--------------------\n");
    printf("Appointment Scheduler\n");
    printf("--------------------\n");
    printf("1. Book appointment\n");
    printf("2. Cancel appointment\n");
    printf("3. View schedule\n");
    printf("4. Exit\n");
}

void bookAppointment(bool schedule[], int timeSlot) {
    if (schedule[timeSlot - 1] == false) {
        schedule[timeSlot - 1] = true; // book appointment
        printf("Appointment booked successfully!\n");
    } else {
        printf("Appointment slot already taken!\n");
    }
}

void cancelAppointment(bool schedule[], int timeSlot) {
    if (schedule[timeSlot - 1] == true) {
        schedule[timeSlot - 1] = false; // cancel appointment
        printf("Appointment cancelled successfully!\n");
    } else {
        printf("No appointment booked in this slot!\n");
    }
}

void viewSchedule(bool schedule[]) {
    printf("Schedule:\n");

    for (int i = 0; i < 8; i++) {
        if (schedule[i] == false) {
            printf("%d. Free\n", i + 1);
        } else {
            printf("%d. Booked\n", i + 1);
        }
    }
}

void clearScreen() {
    system("clear"); // works on Unix based systems
}