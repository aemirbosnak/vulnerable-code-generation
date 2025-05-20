//FormAI DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//functions to check user answers and calculate results
int checkAnswer(char userAns, char correctAns){
    if(userAns == correctAns){
        return 1;
    } else {
        return 0;
    }
}

double calculateResult(int correct, int total){
    double result = ((double)correct / total) * 100;
    return result;
}

//main function
int main(){
    char questions[5][100] = {
        "What is the capital of France?",
        "Who is the inventor of the telephone?",
        "Which is the smallest planet in our solar system?",
        "What is the largest mammal in the world?",
        "Who was the first person to step on the moon?"
    };
    char options[5][4][50] = {
        {"A) London", "B) Paris", "C) Berlin", "D) Madrid"},
        {"A) Thomas Edison", "B) Alexander Graham Bell", "C) Nikola Tesla", "D) Isaac Newton"},
        {"A) Venus", "B) Mercury", "C) Mars", "D) Pluto"},
        {"A) Elephant", "B) Blue Whale", "C) Rhino", "D) Giraffe"},
        {"A) Neil Armstrong", "B) Buzz Aldrin", "C) Yuri Gagarin", "D) John F. Kennedy"}
    };
    char correctAnswers[5] = {'B', 'B', 'B', 'B', 'A'};
    int userAnswers[5];
    int correctCount = 0;
    double result;
    
    printf("Welcome to the C Online Examination System!\n\n");
    printf("Instructions: \n");
    printf("1. There are 5 questions in this quiz.\n");
    printf("2. Each question has 4 options, out of which only 1 is correct.\n");
    printf("3. Enter the option alphabet (A/B/C/D) for each question to answer.\n");
    printf("4. Press enter after each answer.\n\n");
    printf("Let's begin!\n\n");
    
    for(int i=0; i<5; i++){
        printf("%d. %s\n", i+1, questions[i]);
        for(int j=0; j<4; j++){
            printf("%s\n", options[i][j]);
        }
        printf("Answer: ");
        scanf(" %c", &userAnswers[i]);
    }
    
    for(int i=0; i<5; i++){
        if(checkAnswer(userAnswers[i], correctAnswers[i])){
            correctCount++;
        }
    }
    
    result = calculateResult(correctCount, 5);
    
    printf("\nThank you for taking the quiz.\n\n");
    printf("Your score: %d/5\n", correctCount);
    printf("Your percentage: %.2f\n", result);
    
    return 0;
}