//Falcon-180B DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a message with a delay
void delay_print(char* message, int delay) {
    for (int i = 0; message[i]!= '\0'; i++) {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(delay * 1000);
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the variables
    int num_questions = rand_num(5, 10);
    int score = 0;

    // Ask the user if they are ready to begin the quiz
    printf("Are you ready to begin the quiz? (y/n)\n");
    char response;
    scanf("%c", &response);

    if (response == 'y' || response == 'Y') {
        // Start the quiz
        for (int i = 1; i <= num_questions; i++) {
            // Generate a random question and answer
            int question_type = rand_num(1, 3);
            char* question;
            char* answer;

            if (question_type == 1) {
                question = "What is the capital of France? ";
                answer = "Paris";
            } else if (question_type == 2) {
                question = "Who wrote Romeo and Juliet? ";
                answer = "William Shakespeare";
            } else {
                question = "What is the square root of 64? ";
                answer = "8";
            }

            // Ask the user the question and wait for their answer
            printf("%s\n", question);
            char user_answer[100];
            scanf("%s", user_answer);

            // Check if the user's answer is correct
            if (strcmp(user_answer, answer) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", answer);
            }

            // Pause for a moment before moving on to the next question
            delay_print("Press enter to continue...\n", 100);
            getchar();
        }

        // Print the user's final score
        printf("You scored %d out of %d questions correct.\n", score, num_questions);
    } else {
        printf("Exiting program.\n");
    }

    return 0;
}