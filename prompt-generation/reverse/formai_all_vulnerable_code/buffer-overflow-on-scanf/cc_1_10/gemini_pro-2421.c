//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *question;
    char *options[4];
    int answer;
} Question;

Question questions[] = {
    {
        "What is the capital of France?",
        {
            "Paris",
            "London",
            "Rome",
            "Madrid",
        },
        0,
    },
    {
        "What is the largest ocean in the world?",
        {
            "Pacific Ocean",
            "Atlantic Ocean",
            "Indian Ocean",
            "Arctic Ocean",
        },
        0,
    },
    {
        "Who is the author of the Harry Potter series?",
        {
            "J.K. Rowling",
            "Stephen King",
            "George R.R. Martin",
            "Suzanne Collins",
        },
        0,
    },
    {
        "What is the chemical symbol for gold?",
        {
            "Au",
            "Ag",
            "Cu",
            "Fe",
        },
        0,
    },
    {
        "What is the name of the largest moon in the solar system?",
        {
            "Ganymede",
            "Titan",
            "Callisto",
            "Io",
        },
        0,
    },
};

int main() {
    int score = 0;

    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        printf("%s\n", questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        int answer;
        scanf("%d", &answer);

        if (answer == questions[i].answer) {
            score++;
        }
    }

    printf("Your score is %d out of %d\n", score, sizeof(questions) / sizeof(Question));

    return 0;
}