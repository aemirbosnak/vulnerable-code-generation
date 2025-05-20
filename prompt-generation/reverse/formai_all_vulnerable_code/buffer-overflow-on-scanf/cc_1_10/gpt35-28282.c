//FormAI DATASET v1.0 Category: Math exercise ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions = 10, max_range = 20;
    int score = 0;
    char answer[10];

    // Seed for random number generator
    srand(time(0));
    
    // Loop for number of questions
    for(int i=1; i<=num_questions; i++) {
        // Generate random numbers
        int num1 = rand() % max_range + 1;
        int num2 = rand() % max_range + 1;

        // Choose random operation
        int op_type = rand() % 4;
        char op;
        int result = 0;
        if(op_type == 0) { // Addition
            result = num1 + num2;
            op = '+';
        } else if(op_type == 1) { // Subtraction
            result = num1 - num2;
            op = '-';
        } else if(op_type == 2) { // Multiplication
            result = num1 * num2;
            op = '*';
        } else { // Division
            // Ensure non-zero denominator
            while(num2 == 0) {
                num2 = rand() % max_range + 1;
            }
            result = num1 / num2;
            op = '/';
        }

        // Print question and get answer
        printf("\nQuestion %d:\n", i);
        printf("%d %c %d = ", num1, op, num2);
        scanf("%s", answer);

        // Check answer and add to score
        if(atoi(answer) == result) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %d\n", result);
        }
    }

    // Print final score
    printf("\nYour final score is %d/%d\n", score, num_questions);

    return 0;
}