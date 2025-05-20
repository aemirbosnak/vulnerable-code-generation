//FormAI DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for the exam and system
#define TOTAL_QUESTIONS 10
#define QUESTION_LENGTH 100
#define ANSWER_LENGTH 20
#define MAX_ATTEMPTS 3

// Function prototypes
void displayMenu();
void startExam();
void generateQuestions(char questions[TOTAL_QUESTIONS][QUESTION_LENGTH], char answers[TOTAL_QUESTIONS][ANSWER_LENGTH]);
void shuffleQuestions(char questions[TOTAL_QUESTIONS][QUESTION_LENGTH], char answers[TOTAL_QUESTIONS][ANSWER_LENGTH]);
int askQuestion(char question[QUESTION_LENGTH], char correctAnswer[ANSWER_LENGTH]);
void displayScore(int score);

int main() {

    // Cyberpunk theme
    printf("------WELCOME TO THE CYBERPUNK ONLINE EXAMINATION SYSTEM------\n");
    printf("Connecting to cyberspace...\n");

    // Call displayMenu() function to start the program
    displayMenu();

    return 0;
}

void displayMenu() {

    // Display menu to user
    printf("\n---MAIN MENU---\n");
    printf("1. Start Exam\n");
    printf("2. Exit\n");

    // Get input from user
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Call appropriate function based on user's input
    switch(choice) {
        case 1: startExam();
                break;
        case 2: printf("Goodbye!\n");
                break;
        default: printf("Invalid input! Please try again.\n");
                 displayMenu();
                 break;
    }
}

void startExam() {

    // Declare variables
    char questions[TOTAL_QUESTIONS][QUESTION_LENGTH];
    char answers[TOTAL_QUESTIONS][ANSWER_LENGTH];
    int score = 0;
    srand(time(NULL)); // Seed random number generator

    // Generate and shuffle questions/answers
    generateQuestions(questions, answers);
    shuffleQuestions(questions, answers);

    // Ask each question and tally score
    for(int i = 0; i < TOTAL_QUESTIONS; i++) {
        char question[QUESTION_LENGTH];
        char correctAnswer[ANSWER_LENGTH];
        strcpy(question, questions[i]);
        strcpy(correctAnswer, answers[i]);

        int attempts = 0;
        while(attempts < MAX_ATTEMPTS) {
            int result = askQuestion(question, correctAnswer);
            if(result == 1) {
                score++;
                printf("Correct!\n");
                break;
            } else if(result == 0) {
                printf("Incorrect! Please try again.\n");
                attempts++;
            } else {
                printf("Invalid input! Please try again.\n");
            }
        }
    }

    // Display final score
    displayScore(score);

    // Return to main menu
    displayMenu();

}

void generateQuestions(char questions[TOTAL_QUESTIONS][QUESTION_LENGTH], char answers[TOTAL_QUESTIONS][ANSWER_LENGTH]) {

    // Define array of potential questions and answers
    char potentialQuestions[][QUESTION_LENGTH] = {
        "What is the largest organ in the human body?",
        "What is the name of the closest planet to the sun?",
        "How many points are scored for a touchdown in American football?",
        "What is the capital of Australia?",
        "What is the smallest country in the world?",
        "What is the highest mountain in the world?",
        "Who painted the Mona Lisa?",
        "What is the chemical formula for water?",
        "What is the technical term for the human collarbone?",
        "What is the first element on the periodic table?"
    };
    char potentialAnswers[][ANSWER_LENGTH] = {
        "skin",
        "mercury",
        "6",
        "canberra",
        "vatican",
        "everest",
        "da vinci",
        "h2o",
        "clavicle",
        "hydrogen"
    };

    // Select 10 random questions/answers from array
    for(int i = 0; i < TOTAL_QUESTIONS; i++) {
        int index = rand() % 10;
        strcpy(questions[i], potentialQuestions[index]);
        strcpy(answers[i], potentialAnswers[index]);
    }
}

void shuffleQuestions(char questions[TOTAL_QUESTIONS][QUESTION_LENGTH], char answers[TOTAL_QUESTIONS][ANSWER_LENGTH]) {

    // Shuffle questions/answers using Fisher-Yates algorithm
    for(int i = TOTAL_QUESTIONS - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        char tempQuestion[QUESTION_LENGTH];
        char tempAnswer[ANSWER_LENGTH];

        strcpy(tempQuestion, questions[i]);
        strcpy(tempAnswer, answers[i]);
        strcpy(questions[i], questions[j]);
        strcpy(answers[i], answers[j]);
        strcpy(questions[j], tempQuestion);
        strcpy(answers[j], tempAnswer);
    }

}

int askQuestion(char question[QUESTION_LENGTH], char correctAnswer[ANSWER_LENGTH]) {

    // Ask question and get user's answer
    printf("%s\n", question);
    char answer[ANSWER_LENGTH];
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Check if user's answer is correct
    int result = strcmp(answer, correctAnswer);
    if(result == 0) {
        return 1; // Correct answer
    } else {
        return 0; // Incorrect answer
    }

}

void displayScore(int score) {

    // Display final score to user
    printf("\nYour score is: %d/%d\n", score, TOTAL_QUESTIONS);
    if(score == TOTAL_QUESTIONS) {
        printf("Congratulations! You achieved a perfect score. You truly are a cyberpunk!\n");
    } else if(score > (TOTAL_QUESTIONS / 2)) {
        printf("Well done, you passed the exam! Keep improving your cyberpunk skills.\n");
    } else {
        printf("Sorry, you did not pass the exam. Better luck next time!\n");
    }

}