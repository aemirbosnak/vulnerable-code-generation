//FormAI DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

// Function prototype
void displayQuiz();
void displayResult();
void generateQuizQuestions();
int evaluateQuiz();

// Global variables
int score = 0, numOfQuestions = 5;

int main() 
{ 
    int choice;
    srand(time(0)); // seeding the random number generator

    printf("Welcome to the Online Examination System\n");
    printf("Please select an option from the menu:\n");
    printf("1. Take a quiz\n");
    printf("2. View previous results\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            displayQuiz();
            break;
        case 2:
            displayResult();
            break;
        case 3:
            printf("Thank you for taking the quiz!\n");
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            main(); // redirecting to the main menu if invalid option is selected
    }

    return 0; 
} 

void displayQuiz() {
    int result;
    printf("\nYou have selected to take the quiz. The quiz will have %d questions. Good luck!\n\n", numOfQuestions);
    generateQuizQuestions(); // fetching the questions randomly
    result = evaluateQuiz();
    printf("\nCongratulations! Your score is %d out of %d\n\n", score, numOfQuestions);
    displayResult(); // displaying the result immediately after the quiz
}

int evaluateQuiz() {
    int answer, result;
    for(int i = 0; i < numOfQuestions; i++) {
        printf("Question %d: %d + %d = ", i+1, rand()%100, rand()%100); // displaying addition questions
        scanf("%d", &answer);
        if(answer == score) {
            printf("Correct answer! "); score++; // incrementing the score if the answer is correct
        } else {
            printf("Incorrect answer. "); // displaying the message if the answer is incorrect
        }
    }
    result = (score/numOfQuestions)*100;
    return result;
}

void displayResult() {
    printf("Your previous result is %d%%\n", rand()%100);
    main(); // redirecting to the main menu
}

void generateQuizQuestions() {
    srand(time(0));
    for(int i = 0; i < numOfQuestions; i++) {
        printf("Question %d: %d + %d = \n", i+1, rand()%100, rand()%100); // generating random addition questions
    }
}