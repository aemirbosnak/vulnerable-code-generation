//FormAI DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generate two random integers and return their sum
int generateQuestion() {
    // Generate two random numbers between 1 and 100
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;
    
    // Calculate the answer
    int answer = num1 + num2;
    
    // Print the question
    printf("What is %d + %d?\n", num1, num2);
    
    // Return the answer
    return answer;
}

// Check if the user's answer is correct
int checkAnswer(int answer) {
    int userAnswer;
    
    // Get the user's answer
    scanf("%d", &userAnswer);
    
    // Check if the answer is correct
    if (userAnswer == answer) {
        printf("Correct! Good job!\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %d.\n", answer);
        return 0;
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    int numQuestions = 10;
    int correctAnswers = 0;
    
    // Ask 10 math questions
    for (int i = 0; i < numQuestions; i++) {
        int answer = generateQuestion();
        correctAnswers += checkAnswer(answer);
    }

    // Print the user's score
    printf("You got %d out of %d questions correct!\n", correctAnswers, numQuestions);
    
    return 0;
}