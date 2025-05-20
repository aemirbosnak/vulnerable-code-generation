//FormAI DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define NUM_STUDENTS 5
#define NUM_SUBJECTS 3
#define MAX_SCORE 100
#define MIN_SCORE 0

typedef struct {
    char name[50];
    int scores[NUM_SUBJECTS];
    double average;
} Student;

void calculateAverage(Student *student) {
    int total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        total += student->scores[i];
    }
    student->average = total / (double) NUM_SUBJECTS;
}

void printStudent(Student *student) {
    printf("%s's scores:\n", student->name);
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Subject %d: %d\n", i + 1, student->scores[i]);
    }
    printf("Average: %.2f\n", student->average);
}

int main() {
    Student students[NUM_STUDENTS];
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        for (int j = 0; j < NUM_SUBJECTS; j++) {
            int score;
            do {
                printf("Enter score for subject %d (0-100): ", j + 1);
                scanf("%d", &score);
            } while (score < MIN_SCORE || score > MAX_SCORE);
            students[i].scores[j] = score;
        }

        calculateAverage(&students[i]);
        printStudent(&students[i]);
        printf("\n");
    }

    return EXIT_SUCCESS;
}