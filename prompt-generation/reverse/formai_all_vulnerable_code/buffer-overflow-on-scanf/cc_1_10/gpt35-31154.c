//FormAI DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Function to generate random questions from an array
char* generate_question(char quiz[][100], int size) {
    srand(time(NULL));
    int random = rand() % size;
    return quiz[random];
}

int main() {
    //Array of quiz questions
    char quiz[][100] = {
        "What is the capital of Canada?", 
        "Who was the first president of the United States?", 
        "What is the currency of Japan?", 
        "What is the smallest country in the world by area?"
    };

    //Array of corresponding answers
    char answers[][20] = {
        "Ottawa",
        "George Washington",
        "Yen",
        "Vatican City"
    };

    //Variables to keep track of number of correct and incorrect answers
    int num_correct = 0;
    int num_incorrect = 0;

    //Welcome message
    printf("Welcome to the online quiz!\n");
    printf("You will be given 5 questions to answer. Good luck!\n\n");

    //Loop through 5 questions
    for(int i = 0; i < 5; i++) {
        //Generate a random question
        char* question = generate_question(quiz, 4);
        printf("Question %d: %s\n", i+1, question);

        //Get user's answer
        char answer[20];
        printf("Answer: ");
        scanf("%s", answer);

        //Check if user's answer is correct
        int correct = strcmp(answer, answers[i]) == 0;

        //Print message and update variables accordingly
        if(correct) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is: %s\n", answers[i]);
            num_incorrect++;
        }
        printf("----------------------------------------------------------------\n");
    }

    //Print final results
    printf("Thank you for taking the quiz!\n");
    printf("You answered %d questions correctly and %d questions incorrectly.\n", num_correct, num_incorrect);

    return 0;
}