//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] =
{
    {"What is the capital of France?", {"Paris", "Rome", "London", "Berlin"}, 0},
    {"Which planet is the largest?", {"Mars", "Jupiter", "Earth", "Saturn"}, 1},
    {"Who wrote the Harry Potter series?", {"J.R.R. Tolkien", "Stephen King", "J.K. Rowling", "George R.R. Martin"}, 2},
    {"What is the meaning of the word 'entrepreneur'?", {"Someone who sells things", "Someone who starts businesses", "Someone who is good at math", "Someone who is rich"}, 3},
    {"Which scientist invented the theory of relativity?", {"Albert Einstein", "Isaac Newton", "Charles Darwin", "Galileo Galilei"}, 0}
};

int main()
{
    time_t start, end;
    int score = 0, currentQuestion = 0, guessAnswer;

    start = time(NULL);

    while (score < MAX_QUESTIONS && currentQuestion < MAX_QUESTIONS)
    {
        printf("Question %d: %s\n", currentQuestion + 1, questions[currentQuestion].question);

        for (int i = 0; i < MAX_ANSWERS; i++)
        {
            printf("  Answer %d: %s\n", i + 1, questions[currentQuestion].answers[i]);
        }

        printf("Enter your answer: ");
        scanf("%d", &guessAnswer);

        if (guessAnswer == questions[currentQuestion].correctAnswer)
        {
            score++;
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The answer is %s.\n", questions[currentQuestion].answers[questions[currentQuestion].correctAnswer - 1]);
        }

        currentQuestion++;
    }

    end = time(NULL);

    printf("Your score: %d\n", score);
    printf("Time taken: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}