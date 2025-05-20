//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10
#define MAX_CHOICES 5

typedef struct {
    char name[50];
    int score;
} Student;

typedef struct {
    char question[100];
    char choice1[100];
    char choice2[100];
    char choice3[100];
    char choice4[100];
    char correct_choice[100];
} Question;

Question questions[MAX_QUESTIONS];

void print_header() {
    printf("Excalibur, the Sword of Justice!\n");
    printf("-----------------------------\n");
    printf("Welcome to the Online Exam!\n");
    printf("-----------------------------\n");
}

void print_questions() {
    int i;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
    }
}

void print_answer(int index) {
    if (index >= 0 && index < MAX_QUESTIONS) {
        printf("Question %d:\n", index + 1);
        printf("%s\n", questions[index].correct_choice);
        printf("A. %s\n", questions[index].choice1);
        printf("B. %s\n", questions[index].choice2);
        printf("C. %s\n", questions[index].choice3);
        printf("D. %s\n", questions[index].choice4);
    } else {
        printf("Invalid question index!\n");
    }
}

int main() {
    Student students[10];
    Question questions[MAX_QUESTIONS];

    int i, j, index, choice, score;

    // Initialize students
    for (i = 0; i < 10; i++) {
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        printf("Enter student score: ");
        scanf("%d", &score);
    }

    // Initialize questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question: ");
        scanf("%s", questions[i].question);
        printf("Enter choice 1: ");
        scanf("%s", questions[i].choice1);
        printf("Enter choice 2: ");
        scanf("%s", questions[i].choice2);
        printf("Enter choice 3: ");
        scanf("%s", questions[i].choice3);
        printf("Enter choice 4: ");
        scanf("%s", questions[i].choice4);
        printf("Enter correct choice: ");
        scanf("%s", questions[i].correct_choice);
    }

    // Print header
    print_header();

    // Print questions
    print_questions();

    // Print answers
    printf("Enter question index: ");
    scanf("%d", &index);
    print_answer(index);

    // Calculate scores
    for (i = 0; i < 10; i++) {
        for (j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(students[i].name, questions[j].correct_choice) == 0) {
                score = j + 1;
                break;
            }
        }
        printf("Student %s's score for question %d is %d\n", students[i].name, score, score);
    }

    return 0;
}