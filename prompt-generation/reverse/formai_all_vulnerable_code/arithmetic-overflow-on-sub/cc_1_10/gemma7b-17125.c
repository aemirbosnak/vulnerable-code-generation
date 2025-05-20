//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question
{
    char *question;
    char *options[4];
    int answer;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the meaning of the word 'entrepreneur'?",
     {"a. A person who owns and operates a business",
      "b. A person who is good at math",
      "c. A person who is a teacher",
      "d. A person who is a lawyer"},
    1},

    {"Which of the following is not a planet?",
     {"a. Mars",
      "b. Earth",
      "c. Jupiter",
      "d. Venus"},
    2},

    {"What is the capital of France?",
     {"a. Paris",
      "b. Rome",
      "c. Berlin",
      "d. Lyon"},
    3},

    {"Which scientist invented the theory of relativity?",
     {"a. Albert Einstein",
      "b. Isaac Newton",
      "c. Charles Darwin",
      "d. Galileo Galilei"},
    4},

    {"What is the sound of one hand clapping?",
     {"a. Silence",
      "b. A whistle",
      "c. A click",
      "d. A thud"},
    5},

    {"What is the meaning of the word 'entrepreneur'?",
     {"a. A person who owns and operates a business",
      "b. A person who is good at math",
      "c. A person who is a teacher",
      "d. A person who is a lawyer"},
    6},

    {"Which of the following is not a fruit?",
     {"a. Apple",
      "b. Orange",
      "c. Banana",
      "d. Peach"},
    7},

    {"What is the color of the sky?",
     {"a. Red",
      "b. Blue",
      "c. Green",
      "d. Yellow"},
    8},

    {"Which of the following is the largest animal on Earth?",
     {"a. Whale",
      "b. Elephant",
      "c. Giraffe",
      "d. Lion"},
    9},

    {"What is the sound of a clock ticking?",
     {"a. A hum",
      "b. A beep",
      "c. A click",
      "d. A groan"},
    10}
};

int main()
{
    int i, score = 0;

    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i].question);

        printf("a. %s\n", questions[i].options[0]);
        printf("b. %s\n", questions[i].options[1]);
        printf("c. %s\n", questions[i].options[2]);
        printf("d. %s\n", questions[i].options[3]);

        printf("Enter your answer: ");
        int answer = getchar() - 'a';

        if (answer == questions[i].answer)
        {
            score++;
        }
    }

    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);

    return 0;
}