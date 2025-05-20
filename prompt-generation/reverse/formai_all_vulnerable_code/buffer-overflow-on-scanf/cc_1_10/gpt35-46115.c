//FormAI DATASET v1.0 Category: Online Examination System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the questions
typedef struct {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int answer;
} Question;

int main() {
    int numQuestions; // Number of questions
    int score = 0; // Player's score
    char name[50]; // Player's name

    // Welcome message and instructions
    printf("\nWelcome to the Online Examination System\n");
    printf("You will be presented with a series of multiple-choice questions.\n");
    printf("Enter the number of the option that you think is correct (1-4).\n");
    printf("Let's begin!\n\n");

    // Ask for player's name
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\n");

    // Ask for number of questions
    printf("How many questions would you like to answer (1-10)? ");
    scanf("%d", &numQuestions);
    
    // Create the array of questions
    Question questions[numQuestions];

    // Fill the questions array with questions, options, and answers
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].option1, "Paris");
    strcpy(questions[0].option2, "Rome");
    strcpy(questions[0].option3, "Berlin");
    strcpy(questions[0].option4, "Madrid");
    questions[0].answer = 1;

    strcpy(questions[1].question, "What is the largest country by area?");
    strcpy(questions[1].option1, "Russia");
    strcpy(questions[1].option2, "Canada");
    strcpy(questions[1].option3, "China");
    strcpy(questions[1].option4, "USA");
    questions[1].answer = 1;

    strcpy(questions[2].question, "What language do they speak in Brazil?");
    strcpy(questions[2].option1, "Portuguese");
    strcpy(questions[2].option2, "Spanish");
    strcpy(questions[2].option3, "English");
    strcpy(questions[2].option4, "French");
    questions[2].answer = 1;

    strcpy(questions[3].question, "What is the largest organ in the human body?");
    strcpy(questions[3].option1, "Liver");
    strcpy(questions[3].option2, "Heart");
    strcpy(questions[3].option3, "Brain");
    strcpy(questions[3].option4, "Skin");
    questions[3].answer = 4;

    // Add more questions here...

    // Loop through the questions and ask the player
    for (int i = 0; i < numQuestions; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        printf("1. %s\n", questions[i].option1);
        printf("2. %s\n", questions[i].option2);
        printf("3. %s\n", questions[i].option3);
        printf("4. %s\n", questions[i].option4);
        
        int answer;
        printf("Enter the number of your answer: ");
        scanf("%d", &answer);
        printf("\n");
        
        // Check if the answer is correct and update the score
        if (answer == questions[i].answer) {
            score++;
        }
    }
    
    // Print the final score
    printf("Congratulations %s! You have completed the exam.\n", name);
    printf("Your final score is %d out of %d.\n", score, numQuestions);
    
    return 0;
}