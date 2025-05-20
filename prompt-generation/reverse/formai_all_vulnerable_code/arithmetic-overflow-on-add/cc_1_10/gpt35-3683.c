//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: protected
/* Program to simulate time travel */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Function declarations */
void display_menu();
void travel_to_past();
void travel_to_future();
void ask_confirmation(char time_travel[]);
void print_current_year(int year);
void print_new_year(int year);

/* Global variables */
int current_year = 2021;

/* Main function */
int main() {
    printf("Welcome to the Time Travel Simulator\n");
    display_menu();
    return 0;
}

/* Function to display the menu */
void display_menu() {
    printf("\n");
    printf("Select an option:\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("3. Exit program\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            travel_to_past();
            break;
        case 2:
            travel_to_future();
            break;
        case 3:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            display_menu();
    }
}

/* Function to travel to the past */
void travel_to_past() {
    int years_to_travel;
    printf("How many years back would you like to travel? ");
    scanf("%d", &years_to_travel);
    
    /* Calculate new year */
    int new_year = current_year - years_to_travel;
    
    /* Ask for confirmation */
    char time_travel[50];
    sprintf(time_travel, "to the year %d", new_year);
    ask_confirmation(time_travel);
    
    /* Update current year and display */
    current_year = new_year;
    print_current_year(current_year);
    
    /* Display success message */
    printf("Congratulations, you have successfully traveled to the past!\n");
    
    /* Display menu again */
    display_menu();
}

/* Function to travel to the future */
void travel_to_future() {
    int years_to_travel;
    printf("How many years ahead would you like to travel? ");
    scanf("%d", &years_to_travel);
    
    /* Calculate new year */
    int new_year = current_year + years_to_travel;
    
    /* Ask for confirmation */
    char time_travel[50];
    sprintf(time_travel, "to the year %d", new_year);
    ask_confirmation(time_travel);
    
    /* Update current year and display */
    current_year = new_year;
    print_current_year(current_year);
    
    /* Display success message */
    printf("Congratulations, you have successfully traveled to the future!\n");
    
    /* Display menu again */
    display_menu();
}

/* Function to ask for confirmation */
void ask_confirmation(char time_travel[]) {
    char confirmation[50];
    printf("\nAre you sure you want to travel %s? (yes/no) ", time_travel);
    scanf("%s", confirmation);
    if (strcmp(confirmation, "yes") != 0) {
        printf("Time travel cancelled.\n\n");
        display_menu();
    }
}

/* Function to print current year */
void print_current_year(int year) {
    printf("Current year is: %d\n", year);
}

/* Function to print new year after time travel */
void print_new_year(int year) {
    printf("New year after time travel is: %d\n", year);
}