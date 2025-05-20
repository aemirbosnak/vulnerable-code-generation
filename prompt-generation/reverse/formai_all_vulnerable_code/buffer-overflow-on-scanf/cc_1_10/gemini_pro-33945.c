//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    char *text;
    char *answers[4];
    int correct;
};

struct exam {
    char *name;
    int num_questions;
    struct question *questions;
};

struct student {
    char *name;
    int score;
};

int main() {
    struct exam exam = {
        "C Programming Exam",
        5,
        (struct question[]) {
            {
                "What is the output of the following code?\n"
                "int main() {\n"
                "    int a = 5;\n"
                "    printf(\"%d\", a++);\n"
                "    return 0;\n"
                "}\n",
                {
                    "4",
                    "5",
                    "6",
                    "Error"
                },
                1
            },
            {
                "Which of the following is a valid C data type?\n",
                {
                    "int",
                    "float",
                    "double",
                    "All of the above"
                },
                3
            },
            {
                "What is the purpose of the & operator in C?",
                {
                    "To get the address of a variable",
                    "To dereference a pointer",
                    "To perform bitwise AND operation",
                    "To perform logical AND operation"
                },
                0
            },
            {
                "Which of the following is a valid C function declaration?\n",
                {
                    "int main() {\n    return 0;\n}",
                    "void main() {\n    return;\n}",
                    "int main(void) {\n    return 0;\n}",
                    "int main(int argc, char** argv) {\n    return 0;\n}"
                },
                3
            },
            {
                "What is the output of the following code?\n"
                "int main() {\n"
                "    int a = 5;\n"
                "    printf(\"%d %d\", a, a++);\n"
                "    return 0;\n"
                "}\n",
                {
                    "5 5",
                    "5 6",
                    "6 5",
                    "6 6"
                },
                1
            }
        }
    };

    struct student student = {
        "John Doe",
        0
    };

    printf("Welcome to the %s!\n\n", exam.name);

    for (int i = 0; i < exam.num_questions; i++) {
        printf("%s\n", exam.questions[i].text);
        for (int j = 0; j < 4; j++) {
            printf("    %d. %s\n", j + 1, exam.questions[i].answers[j]);
        }

        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);

        if (answer == exam.questions[i].correct + 1) {
            student.score++;
        }
    }

    printf("\nYour score is %d out of %d.\n", student.score, exam.num_questions);

    return 0;
}