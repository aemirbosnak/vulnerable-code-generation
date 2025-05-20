//FormAI DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    int id;
    char *question;
    char *answer;
} Question;

Question questions[5] = {
    {1, "What is the capital of France?", "Paris"},
    {2, "What is the largest country in the world?", "Russia"},
    {3, "Who created Facebook?", "Mark Zuckerberg"},
    {4, "What is the smallest planet in our solar system?", "Mercury"},
    {5, "Who wrote the Harry Potter book series?", "J.K. Rowling"},
};

typedef struct {
    int id;
    char *answer;
} UserAnswer;

UserAnswer userAnswers[5];

void *takeExam(void *threadId) {
    int id = *(int*)threadId;
    printf("Thread #%d started\n", id);

    int questionIndex = 0;
    int answeredQuestions = 0;
    while (questionIndex < 5) {
        Question currentQuestion = questions[questionIndex];

        printf("Thread #%d Question %d: %s\n", id, currentQuestion.id, currentQuestion.question);
        char answer[256];
        scanf("%s", answer);

        userAnswers[questionIndex] = (UserAnswer) {currentQuestion.id, answer};
        answeredQuestions++;
        questionIndex++;
    }

    printf("Thread #%d finished. Answered %d questions\n", id, answeredQuestions);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIds[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, takeExam, (void*)&threadIds[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nExam finished. Here are the correct answers:\n");

    for (int i = 0; i < 5; i++) {
        printf("Question %d: %s\n", questions[i].id, questions[i].answer);
    }

    printf("\nHere are your answers:\n");

    for (int i = 0; i < 5; i++) {
        printf("Question %d: %s\n", userAnswers[i].id, userAnswers[i].answer);
    }

    return 0;
}