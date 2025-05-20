//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_QUESTIONS 10
#define NUM_THREADS 5

int question_index;
pthread_mutex_t mutex;

void *thread_func(void *arg)
{
    int question_num = *(int *)arg;
    char answer[50];
    int correct_answer;

    pthread_mutex_lock(&mutex);
    correct_answer = question_index % 2;
    question_index++;
    pthread_mutex_unlock(&mutex);

    printf("Thread %d: Question %d: %s\n", question_num, question_index, (correct_answer == 0)? "True" : "False");
    scanf("%s", answer);

    if (strcmp(answer, (correct_answer == 0)? "True" : "False") == 0)
    {
        printf("Thread %d: Correct answer!\n", question_num);
    }
    else
    {
        printf("Thread %d: Incorrect answer.\n", question_num);
    }

    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int question_nums[NUM_THREADS];
    int i;

    question_index = 0;
    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < NUM_THREADS; i++)
    {
        question_nums[i] = i + 1;
        pthread_create(threads + i, NULL, thread_func, (void *)&question_nums[i]);
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}