//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to check if the entered answer is correct
int checkAnswer(char *answer, char *correctAnswer){
    if(strcmp(answer, correctAnswer)==0){
        printf("\nYou have entered the correct answer! Proceed...\n\n");
        return 1;
    }
    printf("\nWrong answer! Try again...\n\n");
    return 0;
}

//function to display the current question and ask for answer
int displayQuestion(char *question, char *correctAnswer){
    char input[20];
    printf("%s\n", question);
    printf("Enter your answer: ");
    scanf("%s", input);
    return checkAnswer(input, correctAnswer);
}

//Entrance of the game
int main(){
    printf("\n\nWelcome to the Puzzling Adventure Game!\n\n");

    int score = 0;

    //Question 1
    printf("Question 1:\n");
    char *question1 = "What has to be broken before you can use it?";
    char *answer1 = "egg";
    score += displayQuestion(question1, answer1);

    //Question 2
    printf("Question 2:\n");
    char *question2 = "What is always in front of you but can’t be seen?";
    char *answer2 = "future";
    score += displayQuestion(question2, answer2);

    //Question 3
    printf("Question 3:\n");
    char *question3 = "What is so fragile that saying its name breaks it?";
    char *answer3 = "silence";
    score += displayQuestion(question3, answer3);

    //Question 4
    printf("Question 4:\n");
    char *question4 = "What is full of holes but still holds water?";
    char *answer4 = "sponge";
    score += displayQuestion(question4, answer4);

    //Question 5
    printf("Question 5:\n");
    char *question5 = "What goes up but never comes down?";
    char *answer5 = "age";
    score += displayQuestion(question5, answer5);

    //Final Score
    printf("\n\nYour final score is: %d/5\n", score);
    if(score == 5){
        printf("\n\nCongratulation! You have successfully completed the game!\n\n");
    }else{
        printf("\n\nBetter luck next time!\n\n");
    }

    return 0;
}