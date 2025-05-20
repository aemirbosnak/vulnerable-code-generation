//FormAI DATASET v1.0 Category: Online Examination System ; Style: Romeo and Juliet
// Scene 1: In a virtual classroom
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function prototypes
void introduction();
void exam();
void grading(int score);

int main() {
    char name[20];
    int choice;

    introduction();

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome, %s! Are you ready to take the C online exam?\n", name);
    printf("1) Yes\n2) No\n");
    scanf("%d", &choice);

    if (choice == 1) {
        exam();
    } else {
        printf("Come back when you're ready!\n");
    }

    return 0;
}

void introduction() {
    printf("Welcome to the C Online Examination System!\n");
    printf("This exam will test your knowledge of C programming.\n");
    printf("You will have 30 minutes to complete the exam.\n");
    printf("Good luck!\n");
}

void exam() {
    int score = 0;
    char answer[5];
    time_t start, end;
    double time_taken;

    printf("Let's begin the exam!\n");
    time(&start); // start timer

    // question 1
    printf("Question 1: What is the output of the following code?\n");
    printf("#include <stdio.h>\n");
    printf("int main() {\n");
    printf("\tint x = 3;\n");
    printf("\tprintf(\"%%d\\n\", x++ + ++x);\n");
    printf("\treturn 0;\n}\n");
    printf("a) 6\nb) 7\nc) 8\nd) 9\n");
    scanf("%s", answer);
    if (strcmp(answer, "d") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is d) 9.\n");
    }

    // question 2
    printf("Question 2: How do you declare a pointer variable in C?\n");
    printf("a) int x;\nb) double *x;\nc) float x;\nd) char x[];\n");
    scanf("%s", answer);
    if (strcmp(answer, "b") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is b) double *x;\n");
    }

    // question 3
    printf("Question 3: What does the following code do?\n");
    printf("#include <stdlib.h>\n");
    printf("int main() {\n");
    printf("\tint *p = (int*) malloc(sizeof(int));\n");
    printf("\t*p = 5;\n");
    printf("\tfree(p);\n");
    printf("\treturn 0;\n}\n");
    printf("a) Allocates memory for an int pointer and sets its value to 5\n");
    printf("b) Declares an int variable named p and sets its value to 5\n");
    printf("c) Releases the memory allocated for an int pointer\n");
    printf("d) Changes the value of an int pointer to 5\n");
    scanf("%s", answer);
    if (strcmp(answer, "c") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is c) Releases the memory allocated for an int pointer.\n");
    }

    // question 4
    printf("Question 4: What is the output of the following code?\n");
    printf("#include <stdio.h>\n");
    printf("int main() {\n");
    printf("\tint x[] = {1, 2, 3};\n");
    printf("\tint *p = x;\n");
    printf("\tprintf(\"%%d\\n\", *p++);\n");
    printf("\treturn 0;\n}\n");
    printf("a) 1\nb) 2\nc) 3\nd) Error\n");
    scanf("%s", answer);
    if (strcmp(answer, "a") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is a) 1.\n");
    }

    // question 5
    printf("Question 5: How do you declare a function in C?\n");
    printf("a) void function_name(int x, char y);\n");
    printf("b) function_name(int x, char y) {}\n");
    printf("c) int function_name(int, char);\n");
    printf("d) All of the above\n");
    scanf("%s", answer);
    if (strcmp(answer, "a") == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The answer is a) void function_name(int x, char y);\n");
    }

    time(&end); // end timer
    time_taken = difftime(end, start); // calculate time taken
    printf("Time taken: %0.2f seconds\n", time_taken);
    grading(score);
}

void grading(int score) {
    printf("Your score is: %d out of 5\n", score);
    if (score == 5) {
        printf("Congratulations! You passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam. Better luck next time!\n");
    }
}