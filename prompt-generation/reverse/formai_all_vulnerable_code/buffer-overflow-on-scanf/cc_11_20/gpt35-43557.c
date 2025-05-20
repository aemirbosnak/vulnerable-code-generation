//FormAI DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int questions[10][5] = {
        {1, 2, 3, 4, 5},
        {2, 3, 4, 5, 1},
        {3, 4, 5, 1, 2},
        {4, 5, 1, 2, 3},
        {5, 1, 2, 3, 4},
        {1, 3, 5, 2, 4},
        {2, 4, 1, 5, 3},
        {3, 5, 2, 4, 1},
        {4, 1, 3, 5, 2},
        {5, 2, 4, 1, 3}
    };

    char *questions_text[10] = {
        "What is the capital of Portugal?",
        "What is the smallest country in the world?",
        "Who discovered gravity?",
        "What is the largest planet in our solar system?",
        "What is the smallest planet in our solar system?",
        "What is the output of 2+3*4/2?",
        "What is the output of (3*4+5)/2?",
        "What is the output of 5-2+4/2?",
        "What is the output of (6/3)*2+7*2?",
        "What is the output of 2*5/2+7?"
    };

    char *options[10][5] = {
        {"Madrid", "Paris", "Lisbon", "London", "Berlin"},
        {"Vatican City", "Monaco", "Maldives", "San Marino", "Nauru"},
        {"Issac Newton", "Albert Einstein", "Thomas Edison", "Alexander Graham Bell", "Benjamin Franklin"},
        {"Saturn", "Jupiter", "Uranus", "Neptune", "Mars"},
        {"Mars", "Mercury", "Venus", "Jupiter", "Earth"},
        {"7", "8", "9", "10", "11"},
        {"6", "7", "8", "9", "10"},
        {"2", "3", "4", "5", "6"},
        {"20", "24", "26", "30", "32"},
        {"6", "7", "8", "9", "10"}
    };

    int correct_answers[10] = {3, 1, 1, 2, 1, 8, 2, 2, 4, 4};
    int chosen_answers[10];

    int i, j, answer, score;

    printf("Welcome to the Retro Online Examination System\n");
    printf("---------------------------------------------\n");
    printf("You will be presented with 10 multiple choice questions.\n");
    printf("Please choose the correct answer (1-5) for each question.\n");
    printf("You will receive your score at the end.\n");
    printf("---------------------------------------------\n\n");

    srand(time(0));

    for (i = 0; i < 10; i++)
    {
        printf("Question %d: %s\n\n", i+1, questions_text[i]);
        for (j = 0; j < 5; j++)
        {
            printf("%d. %s\n", j+1, options[questions[i][j]-1][i]);
        }

        printf("\nEnter your answer (1-5): ");
        scanf("%d", &answer);

        if (answer < 1 || answer > 5)
        {
            printf("Invalid answer. Please enter a number between 1 and 5.\n");
            i--;
            continue;
        }

        chosen_answers[i] = answer;
        printf("\n");
    }

    score = 0;

    for (i = 0; i < 10; i++)
    {
        if (chosen_answers[i] == correct_answers[i])
        {
            score++;
        }
    }

    printf("\n\nYour score is %d/10.\n\n", score);

    if (score == 10)
    {
        printf("Wow! You got a perfect score. Congratulations!\n");
    }
    else if (score >= 8 && score <= 9)
    {
        printf("Great job! You got an excellent score.\n");
    }
    else if (score >= 6 && score <= 7)
    {
        printf("Not bad! You got a decent score.\n");
    }
    else
    {
        printf("Better luck next time! You scored below average.\n");
    }

    return 0;
}