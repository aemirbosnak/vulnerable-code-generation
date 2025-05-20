//FormAI DATASET v1.0 Category: Online Examination System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_QUESTIONS 10
#define MAX_ANSWER_LEN 20

int main()
{
    char correct_answers[TOTAL_QUESTIONS][MAX_ANSWER_LEN] = {"A", "C", "B", "D", "B", "C", "A", "D", "C", "B"};
    char student_answers[TOTAL_QUESTIONS][MAX_ANSWER_LEN];
    int options_count = 4;
    int total_marks = 0;
    int i, j;

    printf("Welcome to the online C examination!\n\n");

    for (i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("Question %d:\n", i+1);
        printf("What is the output of the following code snippet?\n");
        printf("=======================================\n");

        // Generate a random code snippet
        switch (rand() % 3) {
            case 0:
                printf("#include <stdio.h>\n\n");
                printf("int main()\n");
                printf("{\n");
                printf("    int x = 10;\n");
                printf("    int *p = &x;\n");
                printf("    *p = 20;\n");
                printf("    printf(\"%%d\\n\", x);\n");
                printf("    return 0;\n");
                printf("}\n");
                strcpy(correct_answers[i], "B");
                break;

            case 1:
                printf("#include <stdio.h>\n\n");
                printf("int main()\n");
                printf("{\n");
                printf("    int arr[5] = {1, 2, 3, 4, 5};\n");
                printf("    printf(\"%%d\\n\", arr[4]);\n");
                printf("    return 0;\n");
                printf("}\n");
                strcpy(correct_answers[i], "E");
                break;

            case 2:
                printf("#include <stdio.h>\n\n");
                printf("int sum(int a, int b)\n");
                printf("{\n");
                printf("    return a + b;\n");
                printf("}\n\n");
                printf("int main()\n");
                printf("{\n");
                printf("    int x = 10;\n");
                printf("    int y = 20;\n");
                printf("    printf(\"The sum is %%d\\n\", sum(x, y));\n");
                printf("    return 0;\n");
                printf("}\n");
                strcpy(correct_answers[i], "D");
                break;
        }
        printf("=======================================\n");

        printf("Options:\n");
        printf("A) 10\n");
        printf("B) 20\n");
        printf("C) garbage value\n");
        printf("D) segmentation fault\n");

        printf("Enter your answer: ");
        scanf("%s", student_answers[i]);

        while (strlen(student_answers[i]) > 1 || *student_answers[i] < 'A' || *student_answers[i] > ('A' + options_count - 1)) {
            printf("Invalid answer! Please enter a valid answer (A-%c): ", ('A' + options_count - 1));
            scanf("%s", student_answers[i]);
        }
        printf("\n");
    }

    // Grade the exam
    for (i = 0; i < TOTAL_QUESTIONS; i++) {
        if (strcmp(correct_answers[i], student_answers[i]) == 0) {
            total_marks++;
        }
    }

    printf("Your total marks: %d/%d\n", total_marks, TOTAL_QUESTIONS);

    if (total_marks >= 7) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("Sorry, you have failed the exam. Better luck next time!\n");
    }

    return 0;
}