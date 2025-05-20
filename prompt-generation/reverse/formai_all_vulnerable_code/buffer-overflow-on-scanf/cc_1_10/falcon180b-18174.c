//Falcon-180B DATASET v1.0 Category: Educational ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num_questions, score = 0, i;
    char option;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of questions from the user
    printf("How many questions do you want to answer? ");
    scanf("%d", &num_questions);

    // Loop through the questions
    for (i = 1; i <= num_questions; i++) {
        // Generate a random number between 1 and 10
        int num = rand_num(1, 10);

        // Display the question to the user
        printf("Question %d: What is %d + %d? ", i, num, num);

        // Get the user's answer
        scanf(" %c", &option);

        // Check the user's answer
        if (option == 'a' && num + num == 20) {
            score++;
        } else if (option == 'b' && num + num == 11) {
            score++;
        } else if (option == 'c' && num + num == 22) {
            score++;
        } else if (option == 'd' && num + num == 33) {
            score++;
        } else {
            printf("Wrong answer!\n");
        }
    }

    // Display the user's score
    printf("You got %d out of %d questions correct.\n", score, num_questions);

    return 0;
}