//FormAI DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to display the main menu
void displayMenu() {
    printf("Welcome to the Online Examination System!\n\n");
    printf("1. Start Exam\n");
    printf("2. View Results\n");
    printf("3. Exit\n\n");
    printf("Please enter your choice: ");
}

// Function to start the exam
void startExam() {
    // Declare variables
    int score = 0;
    char answer;
    
    printf("\n\n**** Welcome to the Exam! ****\n\n");
    printf("1. What is 2 + 2?\n");
    printf("a. 1\n");
    printf("b. 3\n");
    printf("c. 4\n\n");
    printf("Enter your answer: ");
    
    scanf(" %c", &answer);
    
    if (answer == 'c') {
        score++;
    }
    
    printf("\n2. What is the capital city of France?\n");
    printf("a. Paris\n");
    printf("b. London\n");
    printf("c. Beijing\n\n");
    printf("Enter your answer: ");
    
    scanf(" %c", &answer);
    
    if (answer == 'a') {
        score++;
    }
    
    printf("\n3. Which planet is known as the Red Planet?\n");
    printf("a. Venus\n");
    printf("b. Mars\n");
    printf("c. Jupiter\n\n");
    printf("Enter your answer: ");
    
    scanf(" %c", &answer);
    
    if (answer == 'b') {
        score++;
    }
    
    printf("\n\n**** Exam Completed! ****\n");
    printf("Your final score is %d out of 3.", score);
}

// Function to view the results
void viewResults() {
    printf("\n\n**** Results ****\n\n");
    printf("No results found.\n");
}

int main() {
    // Declare variables
    int choice;
    bool quit = false;
    
    // Loop until the user chooses to exit
    while (!quit) {
        // Display the main menu
        displayMenu();
        
        // Get the user's choice
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                startExam();
                break;
            case 2:
                viewResults();
                break;
            case 3:
                printf("\nThank you for using the Online Examination System!");
                quit = true;
                break;
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
        
        printf("\n\n");
    }
    
    return 0;
}