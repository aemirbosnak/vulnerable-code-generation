//FormAI DATASET v1.0 Category: Math exercise ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
void generate_question(int* a, int* b, char* op);
int get_answer(char op, int a, int b);
int check_answer(int result, int answer);
void print_result(int correct, int total);

int main() {
    srand(time(NULL));  /* Initialize random seed */
    int a, b, answer, result, correct = 0, total = 0;
    char op;
    printf("Welcome to the Math Exercise Program.\n\n");
    printf("You will be presented with a series of math problems to solve.\n");
    printf("Please enter your answer for each problem. The program will tell you if you're correct or not.\n\n");
    printf("Press enter to start the exercise.\n");
    getchar();  /* Wait for user input */
    while (1) {
        generate_question(&a, &b, &op); /* Generate a new question */
        printf("Question %d:\n", total+1);
        printf("%d %c %d = ", a, op, b);
        scanf("%d", &answer);
        result = get_answer(op, a, b);
        if (check_answer(result, answer)) {
            printf("Correct!\n\n");
            correct += 1;
        } else {
            printf("Incorrect. The correct answer is %d.\n\n", result);
        }
        total += 1;
        printf("Press enter to continue or 'q' to quit.\n");
        getchar();  /* Clear input buffer */
        char c = getchar();
        if (c == 'q') {
            break;
        }
    }
    print_result(correct, total);
    return 0;
}

/* Generates a random math question */
void generate_question(int* a, int* b, char* op) {
    *a = rand() % 101;
    *b = rand() % 101;
    switch (rand() % 4) {
        case 0:
            *op = '+';
            break;
        case 1:
            *op = '-';
            break;
        case 2:
            *op = '*';
            break;
        case 3:
            *op = '/';
            *b = rand() % (*a) + 1;  /* Ensure b is a factor of a */
            *a = (*a) * (*b);
            break;
    }
}

/* Calculates the correct answer for a given math question */
int get_answer(char op, int a, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
    return 0;
}

/* Checks if user answer is correct */
int check_answer(int result, int answer) {
    return result == answer;
}

/* Prints user's final result */
void print_result(int correct, int total) {
    printf("You answered %d questions correctly out of %d total questions.\n", correct, total);
    if (correct == total) {
        printf("Congratulations, you answered every question correctly!\n");
    } else if (correct > total/2) {
        printf("Well done, keep practicing to improve your skills.\n");
    } else {
        printf("You may want to spend some more time practicing math exercises.\n");
    }
}