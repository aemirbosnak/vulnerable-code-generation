//FormAI DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to display the menu
void displayMenu() {
    printf("\n \t Welcome to Online Examination System\n");
    printf("------------------------------------------------------\n");
    printf("Choose an option from below:\n");
    printf("1. Start Exam\n");
    printf("2. View Results\n");
    printf("3. Exit\n");
    printf("------------------------------------------------------\n");
}

// Function to start exam
void startExam() {
    system("cls");  // Clearing the screen
    printf("\n \t Exam Started\n");
    printf("------------------------------------------------------\n");
    // Your code to display questions and take answers from user
    printf("------------------------------------------------------\n");
    printf("Thank you for taking the exam.\n");
    // Your code to calculate the score and store it
}

// Function to display results
void viewResults() {
    system("cls");  // Clearing the screen
    printf("\n \t Exam Results\n");
    printf("------------------------------------------------------\n");
    // Your code to retrieve the score and display it
    printf("------------------------------------------------------\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                startExam();
                break;
            case 2:
                viewResults();
                break;
            case 3:
                printf("Thank you for using Online Examination System!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 3);
    
    return 0;
}