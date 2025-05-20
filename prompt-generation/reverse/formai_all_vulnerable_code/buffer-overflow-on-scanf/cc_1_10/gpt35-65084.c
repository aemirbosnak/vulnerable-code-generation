//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char question[100]; //question text
    char optionA[50]; //option A
    char optionB[50]; //option B
    char optionC[50]; //option C
    char optionD[50]; //option D
    char correctAns; //correct answer
} Question;

int main() {
    srand(time(NULL)); //seeding the rand() function with current time

    //creating an array of questions
    Question questions[10] = {
        {"What is the capital of France?", "Paris", "Rome", "Berlin", "Madrid", 'A'},
        {"What is the largest planet in our solar system?", "Jupiter", "Mars", "Venus", "Pluto", 'A'},
        {"What is the square root of 144?", "11", "12", "13", "14", 'B'},
        {"Who wrote the novel '1984'?", "Stephen King", "J.K. Rowling", "George Orwell", "Ernest Hemingway", 'C'},
        {"What is the chemical symbol for gold?", "Ag", "Au", "Cu", "Fe", 'B'},
        {"Which city is known as the 'Big Apple'?", "New York", "Los Angeles", "Chicago", "Houston", 'A'},
        {"What is the smallest country in the world?", "Vatican City", "Monaco", "San Marino", "Nauru", 'A'},
        {"Who discovered electricity?", "Rudolf Diesel", "Thomas Edison", "Benjamin Franklin", "Nikola Tesla", 'C'},
        {"Which of the following is not a primary color?", "Green", "Red", "Yellow", "Blue", 'A'},
        {"What is the longest river in the world?", "Mississippi", "Amazon", "Nile", "Yangtze", 'C'},
    };

    int score = 0; //initializing score to 0

    printf("\n~ Welcome to the C Online Examination System! ~\n\n");
    printf("Answer the following 10 multiple choice questions to test your knowledge.\n");
    printf("Enter the letter of the option you think is correct (A, B, C, or D).\n\n");

    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % 10; //generating a random index of question
        printf("%d. %s\n", i + 1, questions[randomIndex].question);
        printf("   A. %s\n", questions[randomIndex].optionA);
        printf("   B. %s\n", questions[randomIndex].optionB);
        printf("   C. %s\n", questions[randomIndex].optionC);
        printf("   D. %s\n", questions[randomIndex].optionD);

        char answer;
        printf("\nYour answer: ");
        scanf(" %c", &answer);

        if (answer == questions[randomIndex].correctAns) {
            printf("Correct! +1 mark.\n\n");
            score++;
        } else {
            printf("Sorry, wrong answer. The correct answer is %c.\n\n", questions[randomIndex].correctAns);
        }
    }

    printf("Your score: %d/10.\n", score);
    if (score >= 7) {
        printf("Congratulations, you passed the test!\n");
    } else {
        printf("Sorry, you failed the test. Better luck next time.\n");
    }

    printf("\n~ End of Examination System ~\n");

    return 0;
}