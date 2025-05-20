//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char* question;
    char** answers;
    int answer_index;
} Question;

Question questions[] =
{
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who owns a business", "b. A person who is good at sales", "c. A person who is creative", "d. A person who is ambitious"}, 2},
    {"Which programming language was invented by Ken Thompson?", {"a. Java", "b. C", "c. Python", "d. Go"}, 1},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 0}
};

int main()
{
    time_t start_time, end_time;
    int i, score = 0, num_questions = 3;

    start_time = time(NULL);

    for (i = 0; i < num_questions; i++)
    {
        printf("%s\n", questions[i].question);

        char answer[MAX_ANSWERS];
        printf("Enter your answer: ");
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answers[questions[i].answer_index]) == 0)
        {
            score++;
        }
    }

    end_time = time(NULL);

    printf("Your score: %d/%d\n", score, num_questions);
    printf("Time taken: %ld seconds\n", end_time - start_time);

    return 0;
}