//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_questions = 10;
    int num_correct = 0;
    char element_symbols[118][3] = {/* elements' symbols */};
    int element_weights[118] = {/* elements' weights */};
    int i, j;

    srand(time(NULL));  // initialize random seed

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given %d questions about element symbols and weights.\n", num_questions);

    for(i = 1; i <= num_questions; i++)
    {
        int random_element = rand() % 118;
        int random_question = rand() % 2;
        int user_answer;
        int correct_answer;

        printf("\nQuestion %d:\n", i);

        if(random_question == 0) // question about symbol
        {
            printf("What is the atomic symbol of element %d?\n", random_element+1);
            printf("Enter your answer: ");
            scanf("%s", &user_answer);
            correct_answer = element_symbols[random_element][0];

            if(user_answer == correct_answer)
            {
                printf("Congratulations! Your answer is correct!\n");
                num_correct++;
            }
            else
            {
                printf("Sorry, your answer is incorrect. The correct answer is %s.\n", element_symbols[random_element]);
            }
        }
        else // question about weight
        {
            printf("What is the atomic weight of element %d?\n", random_element+1);
            printf("Enter your answer: ");
            scanf("%d", &user_answer);
            correct_answer = element_weights[random_element];

            if(user_answer == correct_answer)
            {
                printf("Congratulations! Your answer is correct!\n");
                num_correct++;
            }
            else
            {
                printf("Sorry, your answer is incorrect. The correct answer is %d.\n", element_weights[random_element]);
            }
        }
    }

    printf("\nQuiz completed! You got %d out of %d questions right.\n", num_correct, num_questions);

    return 0;
}