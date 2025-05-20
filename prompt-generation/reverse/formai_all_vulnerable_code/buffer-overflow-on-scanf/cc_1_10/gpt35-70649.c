//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define struct for appointment
struct appointment {
    char date[20];
    char time[20];
    char name[20];
};

// Define global variables
struct appointment appt_list[20];
int num_appts = 0;

// Function prototype declaration
void add_appt();
void view_appts();
void delete_appt();
void print_welcome();
void print_menu();
void print_goodbye();
void clear_screen();
void randomize_colors();

int main() {
    srand(time(NULL)); // Seed the random number generator

    clear_screen();
    randomize_colors();
    print_welcome();

    // Loop until user quits program
    char choice;
    do {
        print_menu();
        scanf(" %c", &choice); // Include whitespace before %c to clear input buffer

        switch (tolower(choice)) {
            case 'a':
                add_appt();
                break;
            case 'v':
                view_appts();
                break;
            case 'd':
                delete_appt();
                break;
            case 'q':
                break;
            default:
                printf("\nInvalid choice. Please select a valid option from the menu.\n");
                break;
        }

    } while (tolower(choice) != 'q');

    print_goodbye();
    clear_screen();

    return 0;
}

void add_appt() {
    if (num_appts >= 20) {
        printf("\nSorry, you have reached the maximum number of appointments.\n");
        return;
    }

    struct appointment new_appt;

    printf("\nEnter appointment date (MM/DD/YYYY): ");
    scanf(" %s", new_appt.date);

    printf("\nEnter appointment time (HH:MM): ");
    scanf(" %s", new_appt.time);

    printf("\nEnter your name: ");
    scanf(" %s", new_appt.name);

    appt_list[num_appts] = new_appt;
    num_appts++;

    printf("\nAppointment added successfully.\n");
}

void view_appts() {
    if (num_appts == 0) {
        printf("\nYou currently have no appointments scheduled.\n");
        return;
    }

    printf("\nHere are your appointments:\n\n");

    for (int i = 0; i < num_appts; i++) {
        printf("%d. Date: %s\tTime: %s\tName: %s\n", i+1, appt_list[i].date, appt_list[i].time, appt_list[i].name);
    }
}

void delete_appt() {
    if (num_appts == 0) {
        printf("\nYou currently have no appointments scheduled.\n");
        return;
    }

    view_appts();

    printf("\nEnter the number of the appointment you would like to delete: ");
    int choice;
    scanf(" %d", &choice);

    if (choice < 1 || choice > num_appts) {
        printf("\nInvalid choice. Please select a valid appointment number.\n");
        return;
    }

    for (int i = choice-1; i < num_appts-1; i++) {
        appt_list[i] = appt_list[i+1];
    }

    num_appts--;

    printf("\nAppointment deleted successfully.\n");
}

void print_welcome() {
    printf("Welcome to the Surrealist Appointment Scheduler!\n\n");
}

void print_menu() {
    printf("\nWhat would you like to do?\n");
    printf("A. Add an appointment\n");
    printf("V. View your appointments\n");
    printf("D. Delete an appointment\n");
    printf("Q. Quit the program\n\n");
    printf("Enter your choice: ");
}

void print_goodbye() {
    printf("Thank you for using the Surrealist Appointment Scheduler!\n");
}

void clear_screen() {
    system("clear"); // Only works on Unix-based systems, change to "cls" for Windows
}

void randomize_colors() {
    printf("\033[%dm", (rand() % 7) + 31); // Random foreground color
    printf("\033[%dm", (rand() % 7) + 41); // Random background color
}