//FormAI DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the test question
struct Question {
    char question[100];
    char options[4][100];
    int answer;
};

int main() {
    // Declare and initialise the question struct variables
    struct Question question1 = {"What is the output of the following code?\n\nint main() {\n\tint x = 10;\n\tint *y = &x;\n\tprintf(\"%d\", *y);\n\treturn 0;\n}", {"A. 0", "B. 10", "C. x", "D. None of the above"}, 1};
    struct Question question2 = {"Which of the following is a correct way of declaring a 2D array?", {"A. int arr[];", "B. int **arr;", "C. int arr[][];", "D. int arr[3][3];"}, 4};
    struct Question question3 = {"What is the output of the following code?\n\nint main() {\n\tchar name[] = \"Juliet\";\n\tprintf(\"%c\", *name);\n\treturn 0;\n}", {"A. J", "B. u", "C. l", "D. None of the above"}, 1};
    struct Question question4 = {"What does the keyword 'static' mean in a function?", {"A. The function can only be called within its own file", "B. The function cannot be redefined within the same file", "C. The value of the variable within the function is retained between function calls", "D. None of the above"}, 3};

    struct Question questions[4] = {question1, question2, question3, question4};
    int score = 0;

    printf("Welcome to the C Online Examination System!\n\n");
    printf("For each question, choose the correct option (A, B, C or D) and press Enter.\n");
    printf("------------------------------------------------------------------------------\n");

    // Loop through the questions and prompt the user for an answer
    for (int i = 0; i < 4; i++) {
        printf("\nQuestion %d:\n%s\nA. %s\nB. %s\nC. %s\nD. %s\n", i+1, questions[i].question, questions[i].options[0], questions[i].options[1], questions[i].options[2], questions[i].options[3]);

        char userAnswer;
        do {
            printf("Enter your answer (A, B, C or D): ");
            scanf(" %c", &userAnswer);
        } while (userAnswer != 'A' && userAnswer != 'B' && userAnswer != 'C' && userAnswer != 'D');

        // Check if the user's answer matches the correct answer and update the score
        if (userAnswer - 'A' + 1 == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, that's incorrect. The correct answer is %c.\n", 'A' + questions[i].answer - 1);
        }
    }

    // Print the final score and a message depending on the score
    printf("\nYour final score is %d out of 4.\n", score);
    if (score == 4) {
        printf("Congratulations, you're a C master!\n");
    } else if (score == 3 || score == 2) {
        printf("Not bad, but you could do better.\n");
    } else {
        printf("Don't worry, keep practicing and you'll get better!\n");
    }

    return 0;
}