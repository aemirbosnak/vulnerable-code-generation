//FormAI DATASET v1.0 Category: Online Examination System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

int main()
{
    printf("\n\n-- Welcome to the Online Examination System --\n\n");

    int i, j, max_score = MAX_QUESTIONS, score = 0, option_selected, correct_option;
    char question[MAX_QUESTIONS][200], options[MAX_QUESTIONS][MAX_OPTIONS][50];
    
    // Read the questions and associated options from the input file
    FILE *input_file = fopen("input.txt", "r");
    if(input_file == NULL)
    {
        printf("Error: Failed to open input file. Please check if the file exists.\n");
        exit(0);
    }
    for(i = 0; i < MAX_QUESTIONS; i++)
    {
        fgets(question[i], 200, input_file);
        for(j = 0; j < MAX_OPTIONS; j++)
        {
            fgets(options[i][j], 50, input_file);
        }
        fscanf(input_file, "%d\n", &correct_option);
    }
    fclose(input_file);

    // Display the questions and get answers from the user
    printf("You will be presented with %d questions, each with multiple choice options.\n", MAX_QUESTIONS);
    printf("Please select the correct option (1-4) for each question and press ENTER to submit.\n");
    for(i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("\n%d. %s\n", i+1, question[i]);
        for(j = 0; j < MAX_OPTIONS; j++)
        {
            printf("%d. %s", j+1, options[i][j]);
        }
        printf("Enter your choice (1-4): ");
        scanf("%d", &option_selected);

        if(option_selected == correct_option)
        {
            score += 1;
        }
    }

    // Display the results
    printf("\n\n-- Results --\n\n");
    printf("You scored %d out of %d.\n", score, max_score);
    if(score >= max_score/2)
    {
        printf("Congratulations! You have passed the examination.\n");
    }
    else
    {
        printf("Sorry, you have failed the examination. Please try again.\n");
    }

    return 0;
}