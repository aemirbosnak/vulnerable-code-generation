//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions;
    int score = 0;
    int correct_answers = 0;
    int i;
    int rand_num;
    int user_answer;
    char answer[4];
    char correct_answer[4];
    struct tm *tm_struct;
    time_t current_time;
    srand(time(0));

    // Get user input for number of questions to answer
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);

    // Loop through num_questions
    for (i = 0; i < num_questions; i++) {
        // Get a random element from the periodic table
        rand_num = rand() % 118;
        printf("Question %d: What is the symbol for element %d? ", i+1, rand_num+1);

        // Get user input for answer
        scanf("%s", answer);

        // Check if answer is correct
        strcpy(correct_answer, "");
        switch (rand_num) {
            case 0:
                strcpy(correct_answer, "H");
                break;
            case 1:
                strcpy(correct_answer, "He");
                break;
            case 2:
                strcpy(correct_answer, "Li");
                break;
            // Add more cases for each element in the periodic table
        }

        // Compare user answer to correct answer
        if (strcmp(answer, correct_answer) == 0) {
            correct_answers++;
        }
        score++;
    }

    // Print final score and percentage correct
    printf("You got %d out of %d questions correct (%d%%).\n", correct_answers, num_questions, (int)(((float)correct_answers/num_questions)*100));

    return 0;
}