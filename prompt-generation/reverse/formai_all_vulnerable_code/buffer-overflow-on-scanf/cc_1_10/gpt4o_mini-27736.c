//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_STUDENTS 5
#define NUM_QUESTIONS 3

typedef struct {
    int student_id;
    int score;
} Student;

Student students[MAX_STUDENTS];
sem_t exam_sem;
pthread_mutex_t lock;

void* conduct_exam(void* arg) {
    Student* student = (Student*)arg;
    int score = 0;
    int answer;

    printf("Student %d: Starting the exam...\n", student->student_id);
    
    // Conduct each question
    for (int i = 1; i <= NUM_QUESTIONS; i++) {
        printf("Student %d: Question %d: What is %d + %d?\n", student->student_id, i, i, i);
        printf("Your answer: ");
        scanf("%d", &answer);

        if (answer == (i + i)) {
            printf("Student %d: Correct!\n", student->student_id);
            score++;
        } else {
            printf("Student %d: Wrong answer!\n", student->student_id);
        }
    }

    // Update the student's score
    pthread_mutex_lock(&lock);
    student->score = score;
    pthread_mutex_unlock(&lock);

    printf("Student %d: Finished the exam with score: %d\n", student->student_id, score);
    return NULL;
}

int main() {
    pthread_t threads[MAX_STUDENTS];

    // Initialize the semaphore
    sem_init(&exam_sem, 0, MAX_STUDENTS);
    pthread_mutex_init(&lock, NULL);

    // Create student threads
    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i].student_id = i + 1;
        sem_wait(&exam_sem); // Wait for available slot
        pthread_create(&threads[i], NULL, conduct_exam, (void*)&students[i]);
    }

    // Join student threads
    for (int i = 0; i < MAX_STUDENTS; i++) {
        pthread_join(threads[i], NULL);
        sem_post(&exam_sem); // Release slot
    }

    // Print final scores
    printf("\nFinal Scores:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Student %d: Score = %d\n", students[i].student_id, students[i].score);
    }

    // Cleanup
    sem_destroy(&exam_sem);
    pthread_mutex_destroy(&lock);

    return 0;
}