//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the user's answer
char get_answer()
{
    char answer;
    printf("Enter your answer: ");
    scanf(" %c", &answer);
    return answer;
}

int main()
{
    // Define the periodic table questions and answers
    char periodic_table[7][2][50] = {
        {"What is the symbol for hydrogen?", "H"},
        {"What is the symbol for oxygen?", "O"},
        {"What is the symbol for chlorine?", "Cl"},
        {"What is the symbol for gold?", "Au"},
        {"What is the symbol for iron?", "Fe"},
        {"What is the symbol for nitrogen?", "N"},
        {"What is the symbol for helium?", "He"}};
    
    // Define the user's score variable
    int score = 0;

    // Welcome message
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Answer the following questions with the correct element symbol.\n");
    
    // Loop through each periodic table question
    for (int i = 0; i < 7; i++)
    {
        printf("\nQuestion %d: %s", i+1, periodic_table[i][0]);
        char user_answer = get_answer();
        if (strcmp(&user_answer, &periodic_table[i][1][0]) == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %s.\n", periodic_table[i][1]);
        }
    }
    
    // End of quiz message
    printf("\nQuiz Complete!\n");
    printf("You answered %d out of 7 questions correctly.\n", score);
    
    return 0;
}