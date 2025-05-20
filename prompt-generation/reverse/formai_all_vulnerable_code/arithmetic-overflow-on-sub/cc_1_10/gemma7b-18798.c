//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int num_questions = 10;
    int current_question = 0;
    int user_answer;
    char answer_key[] = {'a', 'b', 'c', 'd'};
    char user_input[20];
    int score = 0;
    time_t start_time;
    time_t end_time;

    // Initialize the timer
    start_time = time(NULL);

    // Display the first question
    printf("Question %d: What is the meaning of the word 'entrepreneur'?\n", current_question + 1);
    printf("a. A person who owns a business\n");
    printf("b. A person who is good at math\n");
    printf("c. A person who is creative\n");
    printf("d. A person who is intelligent\n");

    // Get the user's answer
    printf("Enter your answer: ");
    scanf("%s", user_input);

    // Check if the user's answer is correct
    if (user_input[0] == answer_key[current_question])
    {
        // Award points
        score++;
    }

    // Move on to the next question
    current_question++;

    // Display the next question
    if (current_question < num_questions)
    {
        printf("Question %d: Who invented the telephone?\n", current_question + 1);
        printf("a. Alexander Graham Bell\n");
        printf("b. Thomas Edison\n");
        printf("c. Charles Babbage\n");
        printf("d. Nikola Tesla\n");

        // Get the user's answer
        printf("Enter your answer: ");
        scanf("%s", user_input);

        // Check if the user's answer is correct
        if (user_input[0] == answer_key[current_question])
        {
            // Award points
            score++;
        }
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    int time_taken = (end_time - start_time) / 60;

    // Display the results
    printf("Your score: %d\n", score);
    printf("Time taken: %d minutes\n", time_taken);

    // Thank you message
    printf("Thank you for taking the exam!\n");

    return 0;
}