//FormAI DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// A function to display the menu
void displayMenu() {
    printf("=============Welcome to the Online Examination System!==============\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Exit\n");
    printf("===================================================================\n");
}

// A function to login to the system
void login() {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Code to check if the username and password are correct
    // If correct, display the exam questions
    printf("Welcome, %s!\n", username);
    printf("==============Exam Questions==============\n");
    printf("Question 1. What is the capital of France?\n");
    printf("a) Paris\nb) London\nc) Berlin\nd) Madrid\n");
    // More questions
}

// A function to register for the system
void registerUser() {
    char username[20];
    char password[20];
    char email[50];

    printf("Enter your desired username: ");
    scanf("%s", username);

    printf("Enter your desired password: ");
    scanf("%s", password);

    printf("Enter your email address: ");
    scanf("%s", email);

    // Code to register the user in the system
    printf("Thank you for registering, %s!", username);
}

int main() {
    int choice = 0;

    while (choice != 3) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                printf("Thank you for using the Online Examination System! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}