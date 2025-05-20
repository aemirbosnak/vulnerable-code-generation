//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num_problems, num_tries, correct_answers, i;
    char answer[10];
    int problem_num, correct_answer, user_answer;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of problems the user wants to solve
    printf("Enter the number of problems you want to solve: ");
    scanf("%d", &num_problems);

    // Loop through the specified number of problems
    for (i = 1; i <= num_problems; i++) {
        // Generate a random problem number between 1 and 10
        problem_num = rand_int(1, 10);

        // Generate a random answer for the problem
        correct_answer = rand_int(1, 10);

        // Prompt the user to solve the problem
        printf("Problem %d: %d + %d = ", problem_num, rand_int(1, 10), rand_int(1, 10));

        // Get the user's answer and check if it's correct
        num_tries = 0;
        while (num_tries < 3) {
            scanf("%s", answer);
            user_answer = atoi(answer);

            if (user_answer == correct_answer) {
                printf("Correct!\n");
                correct_answers++;
            } else {
                printf("Incorrect. The correct answer is %d.\n", correct_answer);
            }

            num_tries++;
        }
    }

    // Print the user's score
    printf("You got %d out of %d problems correct.\n", correct_answers, num_problems);

    return 0;
}