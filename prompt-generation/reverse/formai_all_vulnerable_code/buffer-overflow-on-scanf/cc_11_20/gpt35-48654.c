//FormAI DATASET v1.0 Category: Online Examination System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); // Initialize random number generator

    int questions[10]; // Array to store 10 random questions
    int correctAnswers = 0; // Variable to track correct answers

    printf("\nWelcome to the Post-Apocalyptic Online Exam!\n");
    printf("Answer the following 10 questions to test your survival skills.\n");

    // Generate 10 random questions
    for(int i=0; i<10; i++){
        questions[i] = (rand() % 3) + 1; // Randomly generate a number between 1 and 3
    }

    // Ask the questions and check answers
    for(int i=0; i<10; i++){
        printf("\nQuestion %d:\n", i+1);
        if(questions[i] == 1){
            printf("What is the most important resource in a post-apocalyptic world?\n");
            printf("1. Food\n2. Water\n3. Shelter\n");
            int answer;
            scanf("%d", &answer);
            if(answer == 2) {
                printf("Correct!\n");
                correctAnswers++;
            } else {
                printf("Incorrect. The correct answer is 2.\n");
            }
        } else if(questions[i] == 2){
            printf("What is the best way to defend yourself against zombies?\n");
            printf("1. Use melee weapons\n2. Use firearms\n3. Run away\n");
            int answer;
            scanf("%d", &answer);
            if(answer == 3) {
                printf("Correct!\n");
                correctAnswers++;
            } else {
                printf("Incorrect. The correct answer is 3.\n");
            }
        } else if(questions[i] == 3){
            printf("Which of the following is NOT a necessary skill for survival?\n");
            printf("1. Hunting\n2. Gardening\n3. Singing\n");
            int answer;
            scanf("%d", &answer);
            if(answer == 3) {
                printf("Correct!\n");
                correctAnswers++;
            } else {
                printf("Incorrect. The correct answer is 3.\n");
            }
        }
    }

    // Display score and feedback
    printf("\nExam complete!\n");
    printf("You got %d out of 10 questions correct.\n", correctAnswers);
    if(correctAnswers <= 3){
        printf("Looks like you need to brush up on your survival skills.\n");
    } else if(correctAnswers <= 7){
        printf("Not bad, but you could use a little more practice.\n");
    } else {
        printf("Impressive! You're well prepared for the post-apocalypse.\n");
    }

    return 0;
}