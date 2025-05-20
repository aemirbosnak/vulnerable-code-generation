//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define QUESTION_LENGTH 256

typedef struct {
    char name[50];
    int score;
} User;

typedef struct {
    char question[QUESTION_LENGTH];
    char options[4][30];
    int correctOption;
} Question;

User users[MAX_USERS];
int userCount = 0;
Question questions[MAX_QUESTIONS];
int questionCount = 0;

pthread_mutex_t lock;

void *registerUser(void *arg) {
    char username[50];
    printf("Enter your name: ");
    scanf("%s", username);

    pthread_mutex_lock(&lock);
    if (userCount < MAX_USERS) {
        strcpy(users[userCount].name, username);
        users[userCount].score = 0;
        printf("User %s registered successfully!\n", username);
        userCount++;
    } else {
        printf("User limit reached, cannot register!\n");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *addQuestion(void *arg) {
    pthread_mutex_lock(&lock);
    if (questionCount < MAX_QUESTIONS) {
        printf("Enter question: ");
        scanf(" %[^\n]%*c", questions[questionCount].question);
        for (int i = 0; i < 4; i++) {
            printf("Enter option %d: ", i + 1);
            scanf(" %[^\n]%*c", questions[questionCount].options[i]);
        }
        printf("Enter correct option (1-4): ");
        scanf("%d", &questions[questionCount].correctOption);
        questionCount++;
        printf("Question added successfully!\n");
    } else {
        printf("Question limit reached, cannot add more questions!\n");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *conductExam(void *arg) {
    int userIndex = *(int *)arg;
    printf("Starting exam for %s...\n", users[userIndex].name);

    for (int i = 0; i < questionCount; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("   %d. %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        printf("Your answer (1-4): ");
        scanf("%d", &answer);

        if (answer == questions[i].correctOption) {
            printf("Correct answer!\n");
            users[userIndex].score++;
        } else {
            printf("Wrong answer!\n");
        }
    }
    printf("Exam completed! %s's score: %d/%d\n", users[userIndex].name, users[userIndex].score, questionCount);
    return NULL;
}

void *displayResults(void *arg) {
    printf("\nExam Results:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s: %d/%d\n", users[i].name, users[i].score, questionCount);
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    int userIndex;

    pthread_mutex_init(&lock, NULL);

    while (1) {
        int choice;
        printf("\nOnline Examination System\n");
        printf("1. Register User\n");
        printf("2. Add Question\n");
        printf("3. Conduct Exam\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&threads[0], NULL, registerUser, NULL);
                pthread_join(threads[0], NULL);
                break;
            case 2:
                pthread_create(&threads[1], NULL, addQuestion, NULL);
                pthread_join(threads[1], NULL);
                break;
            case 3:
                printf("Enter user index to conduct exam (0-%d): ", userCount - 1);
                scanf("%d", &userIndex);
                pthread_create(&threads[2], NULL, conductExam, &userIndex);
                pthread_join(threads[2], NULL);
                break;
            case 4:
                pthread_create(&threads[3], NULL, displayResults, NULL);
                pthread_join(threads[3], NULL);
                break;
            case 5:
                pthread_mutex_destroy(&lock);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}