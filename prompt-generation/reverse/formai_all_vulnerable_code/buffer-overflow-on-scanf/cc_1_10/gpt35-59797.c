//FormAI DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define NUM_QUESTIONS 10
#define NUM_THREADS 5

int correct_answers = 0;
pthread_mutex_t mutex;

/* Structure to hold the question and answer */
struct question {
    char *question_text;
    char *answer;
};

/* Create an array of questions */
struct question questions[NUM_QUESTIONS] = {
    {"What is the capital of India?", "New Delhi"},
    {"Which is the largest desert in the world?", "Sahara"},
    {"Which is the hottest planet in the solar system?", "Venus"},
    {"Which river is known as 'The Lifeline of India'?", "Ganges"},
    {"What is the tallest mountain in the world?", "Mount Everest"},
    {"Who is the founder of Apple Inc?", "Steve Jobs"},
    {"Which is the smallest continent in the world?", "Australia"},
    {"Which is the nearest star to our solar system?", "Proxima Centauri"},
    {"Who invented the telephone?", "Alexander Graham Bell"},
    {"What is the largest mammal in the world?", "Blue Whale"}
};

/* This function will be executed by each thread */
void *exam_thread(void *arg) {
    int thread_id = *(int *)arg;
    int start_question = thread_id * (NUM_QUESTIONS / NUM_THREADS);
    int end_question = (thread_id + 1) * (NUM_QUESTIONS / NUM_THREADS);
    
    for (int i = start_question; i < end_question; i++) {
        /* Print the question and get answer from user */
        printf("Question %d: %s\n", i + 1, questions[i].question_text);
        char user_answer[100];
        scanf("%s", user_answer);
        
        /* Check if the answer is correct and update the correct_answers variable */
        if (strcmp(user_answer, questions[i].answer) == 0) {
            pthread_mutex_lock(&mutex);
            correct_answers++;
            pthread_mutex_unlock(&mutex);
        }
    }
    pthread_exit(NULL);
}

int main() {
    /* Initialize mutex */
    pthread_mutex_init(&mutex, NULL);
    
    /* Create an array for thread IDs */
    pthread_t thread_ids[NUM_THREADS];
    int ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        /* Create threads */
        pthread_create(&thread_ids[i], NULL, exam_thread, &ids[i]);
    }
    
    /* Wait for all threads to finish */
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_ids[i], NULL);
    }
    
    printf("Exam completed!\n");
    printf("Number of correct answers: %d\n", correct_answers);
    
    /* Destroy mutex */
    pthread_mutex_destroy(&mutex);
    
    return 0;
}