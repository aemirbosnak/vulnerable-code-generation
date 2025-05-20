//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

/* Function to check if user's answer is correct */
int checkAnswer(char answer[], char correct[])
{
    if (strcmp(answer, correct) == 0) {
        printf("Correct!\n");
        return 1;  /* return 1 for correct answer */
    }
    else {
        printf("Incorrect. The correct answer is %s.\n", correct);
        return 0;  /* return 0 for incorrect answer */
    }
}

/* Function to print question and get user's answer */
int askQuestion(char question[], char answer[])
{
    char userAnswer[20];
    printf("%s\n", question);  /* print question */
    scanf("%s", userAnswer);   /* get user's answer */
    int result = checkAnswer(userAnswer, answer);  /* check if answer is correct */
    return result;  /* return 1 or 0 depending on correctness */
}

int main()
{
    /* Define questions and answers in arrays */
    char questions[10][100] = {
        "What is the symbol for the element Oxygen? (Enter symbol in lowercase)",
        "What is the atomic number of the element Gold?",
        "What is the name of the element with the symbol Na?",
        "What is the symbol for the element with the atomic number 56?",
        "What is the name of the element with the atomic number 17?",
        "What is the symbol for the element with the highest atomic number?",
        "What is the symbol for the element Carbon?",
        "What is the atomic number of the element with the symbol Cl?",
        "What is the name of the element with the atomic number 47?",
        "What is the symbol for the element Helium?"
    };
    char answers[10][20] = {
        "o",
        "79",
        "sodium",
        "ba",
        "chlorine",
        "uuo",
        "c",
        "17",
        "silver",
        "he"
    };
    
    /* Introduce quiz */
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given 10 questions to test your knowledge of the elements.\n");
    printf("Enter your answer and press enter.\n\n");
    
    /* Ask questions and keep score */
    int score = 0;
    for (int i=0; i<10; i++) {
        score += askQuestion(questions[i], answers[i]);
        printf("Your score is %d out of %d.\n\n", score, i+1);
    }
    
    /* Give final score and feedback */
    printf("Congratulations! You have completed the quiz.\n");
    printf("Your final score is %d out of 10.\n", score);
    if (score >= 8) {
        printf("Great job! You really know your elements!\n");
    }
    else if (score >= 6) {
        printf("Not bad, but there's still room for improvement.\n");
    }
    else {
        printf("You might want to brush up on your elements before trying again.\n");
    }

    return 0;
}