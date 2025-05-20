//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define NUM_CHOICES 4

// Struct to hold question data
typedef struct {
    char question[100];
    char choices[NUM_CHOICES][100];
    int answer;
} Question;

// Function to display a question and its choices
void displayQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < NUM_CHOICES; i++) {
        printf("%c) %s\n", 'A' + i, q.choices[i]);
    }
}

// Function to get user's choice
int getChoice() {
    char input[2];
    scanf("%s", input);
    return input[0] - 'A';
}

// Function to check if user's answer is correct
int checkAnswer(Question q, int choice) {
    return choice == q.answer;
}

// Function to generate a random question
Question generateQuestion() {
    Question q;
    q.answer = rand() % NUM_CHOICES;
    sprintf(q.question, "What is the capital of %s?", rand() % 2? "France" : "Japan");
    for (int i = 0; i < NUM_CHOICES; i++) {
        if (i == q.answer) {
            sprintf(q.choices[i], "%s (Correct)", "Paris");
        } else {
            sprintf(q.choices[i], "%s", rand() % 2? "Tokyo" : "Berlin");
        }
    }
    return q;
}

// Main function
int main() {
    srand(time(NULL));

    int score = 0;
    int numQuestions = rand() % (NUM_QUESTIONS - 1) + 1;

    for (int i = 0; i < numQuestions; i++) {
        Question q = generateQuestion();
        displayQuestion(q);
        int userChoice = getChoice();
        if (checkAnswer(q, userChoice)) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("Your final score is: %d out of %d\n", score, numQuestions);

    return 0;
}