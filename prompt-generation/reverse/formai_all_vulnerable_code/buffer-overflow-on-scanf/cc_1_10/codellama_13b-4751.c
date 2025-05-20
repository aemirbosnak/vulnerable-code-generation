//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

struct question {
    char element[3];
    char correct_answer[MAX_ANSWERS][2];
    int num_answers;
};

struct question questions[MAX_QUESTIONS] = {
    {
        "H",
        {
            "Hydrogen",
            "Helium",
            "Lithium",
            "Beryllium"
        },
        4
    },
    {
        "He",
        {
            "Helium",
            "Hydrogen",
            "Lithium",
            "Beryllium"
        },
        4
    },
    {
        "Li",
        {
            "Lithium",
            "Beryllium",
            "Boron",
            "Carbon"
        },
        4
    },
    {
        "Be",
        {
            "Beryllium",
            "Boron",
            "Carbon",
            "Nitrogen"
        },
        4
    },
    {
        "B",
        {
            "Boron",
            "Carbon",
            "Nitrogen",
            "Oxygen"
        },
        4
    },
    {
        "C",
        {
            "Carbon",
            "Nitrogen",
            "Oxygen",
            "Fluorine"
        },
        4
    },
    {
        "N",
        {
            "Nitrogen",
            "Oxygen",
            "Fluorine",
            "Neon"
        },
        4
    },
    {
        "O",
        {
            "Oxygen",
            "Fluorine",
            "Neon",
            "Sodium"
        },
        4
    },
    {
        "F",
        {
            "Fluorine",
            "Neon",
            "Sodium",
            "Magnesium"
        },
        4
    },
    {
        "Na",
        {
            "Sodium",
            "Magnesium",
            "Aluminum",
            "Silicon"
        },
        4
    }
};

int main() {
    int correct_answers = 0;
    int incorrect_answers = 0;
    int total_questions = 0;
    int question_index = 0;

    srand(time(NULL));

    while (total_questions < MAX_QUESTIONS) {
        struct question question = questions[question_index];
        int correct_answer_index = rand() % question.num_answers;
        char correct_answer[2];
        strcpy(correct_answer, question.correct_answer[correct_answer_index]);

        char user_answer[2];
        printf("What is the name of the %s element? ", question.element);
        scanf("%s", user_answer);

        if (strcmp(user_answer, correct_answer) == 0) {
            correct_answers++;
        } else {
            incorrect_answers++;
        }

        total_questions++;
        question_index++;
    }

    printf("You answered %d questions correctly and %d questions incorrectly.\n", correct_answers, incorrect_answers);

    return 0;
}