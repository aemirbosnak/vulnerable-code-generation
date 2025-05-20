//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_QUES 10
#define MAX_LEN 100

int main() {
    int num_ques, num_ans, num_right, num_wrong;
    int que_num, ans_num;
    char question[MAX_LEN], answer[MAX_LEN];
    char que_ans[MAX_LEN];

    int child_pid[MAX_QUES];
    int status;

    printf("Welcome to the Online Examination System!\n");

    // Ask the user for the number of questions
    printf("Please enter the number of questions: ");
    scanf("%d", &num_ques);

    // Ask the user for the number of answers
    printf("Please enter the number of answers: ");
    scanf("%d", &num_ans);

    // Ask the user for the questions and answers
    for (que_num = 0; que_num < num_ques; que_num++) {
        printf("Question %d: ", que_num + 1);
        scanf("%s", question);

        printf("Answer %d: ", que_num + 1);
        scanf("%s", answer);

        printf("Correct Answer: ");
        scanf("%s", que_ans);

        // Start a new child process to execute the answer
        child_pid[que_num] = fork();

        if (child_pid[que_num] == 0) {
            // Child process

            printf("Executing Answer: %s\n", answer);
            printf("Expected Answer: %s\n", que_ans);

            // Check if the answer is correct
            if (strcmp(answer, que_ans) == 0) {
                printf("Correct!\n");
                num_right++;
            } else {
                printf("Incorrect!\n");
                num_wrong++;
            }

            // Exit the child process
            exit(0);
        } else if (child_pid[que_num] > 0) {
            // Parent process

            // Wait for the child process to finish
            status = wait(&status);

            // Check the status of the child process
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                printf("Correct!\n");
                num_right++;
            } else {
                printf("Incorrect!\n");
                num_wrong++;
            }
        } else {
            printf("Error: Fork failed\n");
        }
    }

    // Print the results
    printf("Number of questions: %d\n", num_ques);
    printf("Number of answers: %d\n", num_ans);
    printf("Number of correct answers: %d\n", num_right);
    printf("Number of incorrect answers: %d\n", num_wrong);

    return 0;
}