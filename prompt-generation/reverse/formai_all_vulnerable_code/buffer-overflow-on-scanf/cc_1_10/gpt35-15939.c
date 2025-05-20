//FormAI DATASET v1.0 Category: Online Examination System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numQuestions = 10; // number of questions
    float score = 0; // initialize score to zero
    
    // questions and corresponding answers
    char * questions[] = {"What is the capital of India?", 
                          "Who is known as the 'Father of the Nation' in India?",
                          "What is the full form of CPU?",
                          "What is the name of the largest organ of human body?",
                          "What is the largest mammal in the world?",
                          "What is the most abundant gas in the Earth's atmosphere?",
                          "What is the largest country by area?",
                          "What is the main component of natural gas?",
                          "What is the chemical symbol for gold?",
                          "What is the boiling point of water in Celsius?"};
                          
    char * answers[] = {"New Delhi", "Mahatma Gandhi", "Central Processing Unit", "Skin", "Blue Whale",
                        "Nitrogen", "Russia", "Methane", "Au", "100"};
    
    // shuffle questions
    srand(time(NULL));
    for (int i = numQuestions - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char *temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
        
        temp = answers[i];
        answers[i] = answers[j];
        answers[j] = temp;
    }
    
    // print instructions
    printf("Welcome to the Online Examination System!\n");
    printf("You will be given %d multiple choice questions to answer.\n", numQuestions);
    printf("Enter the number corresponding to your answer and press Enter.\n");
    
    // ask questions
    for (int i = 0; i < numQuestions; i++)
    {
        printf("\nQuestion %d: %s\n", i+1, questions[i]);
        printf("a. %s\n", answers[i]);
        printf("b. %s\n", answers[(i + 1) % numQuestions]);
        printf("c. %s\n", answers[(i + 2) % numQuestions]);
        printf("d. %s\n", answers[(i + 3) % numQuestions]);
        
        // get answer from user
        char choice;
        printf("Enter your answer: ");
        scanf(" %c", &choice);
        
        // check answer
        if (choice == 'a')
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %s\n", answers[i]);
        }
    }
    
    // calculate and print final score
    printf("\nYour final score is %.2f out of %d\n", score, numQuestions);
    
    return 0;
}