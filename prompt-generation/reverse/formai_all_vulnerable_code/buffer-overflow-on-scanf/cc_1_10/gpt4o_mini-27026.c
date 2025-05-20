//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_QUESTIONS 5
#define MAX_OPTION_LENGTH 50
#define MAX_USERNAME_LENGTH 30

typedef struct {
    char question[100];
    char options[4][MAX_OPTION_LENGTH];
    char answer;
} Question;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    int score;
    int answered[MAX_QUESTIONS];
} User;

Question questions[MAX_QUESTIONS] = {
    {"What is 2 + 2?", {"1", "2", "3", "4"}, 'd'},
    {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 'c'},
    {"What is the boiling point of water?", {"90C", "100C", "80C", "120C"}, 'b'},
    {"What gas do plants absorb?", {"Oxygen", "Nitrogen", "Carbon Dioxide", "Helium"}, 'c'},
    {"What is 5 x 6?", {"30", "31", "32", "29"}, 'a'}
};

User user;

void *take_exam(void *arg) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (!user.answered[i]) {
            printf("Question %d: %s\n", i + 1, questions[i].question);
            printf("a) %s\nb) %s\nc) %s\nd) %s\n", 
                questions[i].options[0], 
                questions[i].options[1], 
                questions[i].options[2], 
                questions[i].options[3]);
            printf("Enter your answer (a/b/c/d): ");
            char answer;
            scanf(" %c", &answer);
            if (answer == questions[i].answer) {
                user.score++;
            }
            user.answered[i] = 1; // Mark question as answered
            printf("\n");
        }
    }
    return NULL;
}

void display_results() {
    printf("Exam Results for %s:\n", user.username);
    printf("Total Score: %d/%d\n", user.score, MAX_QUESTIONS);
}

void initialize_user() {
    printf("Enter your username: ");
    scanf("%s", user.username);
    user.score = 0;
    memset(user.answered, 0, sizeof(user.answered));
}

int main() {
    pthread_t exam_thread;

    initialize_user();
    
    if (pthread_create(&exam_thread, NULL, take_exam, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the exam thread to finish
    pthread_join(exam_thread, NULL);
    display_results();

    printf("Thank you for participating in the online examination!\n");
    return 0;
}