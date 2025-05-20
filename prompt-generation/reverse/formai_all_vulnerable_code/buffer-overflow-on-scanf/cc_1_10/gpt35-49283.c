//FormAI DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

// Exam questions and answers
char* questions[] = {"What is the capital of France?", "What is the largest continent?", "What is the smallest planet of the solar system?", "What is the highest mountain in the world?", "What does the acronym CPU stand for?"};
char* answers[] = {"Paris", "Asia", "Mercury", "Mount Everest", "Central Processing Unit"};

int score = 0; // initialize score to 0
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // create a mutex

// Function to simulate answering a question
void answer_question(int question_num, char* answer) {
    printf("Q%d: %s\n", question_num, questions[question_num]);
    printf("Your answer: %s\n", answer);
    if (strcmp(answer, answers[question_num]) == 0) {
        printf("Correct!\n");
        pthread_mutex_lock(&mutex);
        score++; // increment score if answer is correct
        pthread_mutex_unlock(&mutex);
    } else {
        printf("Incorrect.\n");
    }
}

// Thread function for answering questions
void* answer_questions(void* arg) {
    int num_questions = *(int*)arg;
    free(arg); // free memory allocated for arg
    for (int i = 0; i < num_questions; i++) {
        char answer[50];
        printf("Question %d:\n", i+1);
        fgets(answer, 50, stdin);
        answer[strcspn(answer, "\n")] = '\0'; // remove newline from answer
        answer_question(i, answer);
    }
    pthread_exit(NULL);
}

// Thread function for displaying time
void* display_time(void* arg) {
    time_t start_time = time(NULL);
    while (1) {
        time_t curr_time = time(NULL);
        int elapsed_time = (int)(curr_time - start_time);
        printf("Time elapsed: %d seconds\n", elapsed_time);
        sleep(1);
    }
}

int main() {
    int num_questions;
    printf("Enter the number of questions for the exam: ");
    scanf("%d", &num_questions);
    getchar(); // remove newline from input buffer
    pthread_t answers_thread, time_thread;
    int* num_questions_ptr = malloc(sizeof(int));
    *num_questions_ptr = num_questions;
    pthread_create(&answers_thread, NULL, answer_questions, num_questions_ptr);
    pthread_create(&time_thread, NULL, display_time, NULL);
    pthread_join(answers_thread, NULL);
    pthread_join(time_thread, NULL);
    printf("Exam complete. Final score: %d/%d\n", score, num_questions);
    pthread_mutex_destroy(&mutex);
    return 0;
}