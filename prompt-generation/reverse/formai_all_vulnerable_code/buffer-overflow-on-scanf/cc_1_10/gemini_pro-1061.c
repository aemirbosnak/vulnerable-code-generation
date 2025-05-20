//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a question
typedef struct Question {
    char question[256];
    char options[4][64];
    char correct_answer;
} Question;

// Structure to represent a student
typedef struct Student {
    char name[64];
    int score;
} Student;

// Array of questions
Question questions[] = {
    {"What is the capital of India?", {"Delhi", "Mumbai", "Kolkata", "Chennai"}, 'A'},
    {"Who is the current Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 'A'},
    {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Peacock"}, 'A'},
    {"What is the national bird of India?", {"Peacock", "Parrot", "Owl", "Sparrow"}, 'A'},
    {"What is the national flower of India?", {"Lotus", "Rose", "Jasmine", "Marigold"}, 'A'}
};

// Array of students
Student students[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0},
    {"Dave", 0},
    {"Eve", 0}
};

// Function to print a question
void print_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get the student's answer
char get_answer() {
    char answer;
    printf("Enter your answer (A, B, C, or D): ");
    scanf(" %c", &answer);
    return answer;
}

// Function to check the student's answer
int check_answer(Question question, char answer) {
    return question.correct_answer == answer;
}

// Function to administer the exam
void administer_exam() {
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        print_question(questions[i]);
        char answer = get_answer();
        int correct = check_answer(questions[i], answer);
        if (correct) {
            printf("Correct!\n");
            students[i].score++;
        } else {
            printf("Incorrect!\n");
        }
    }
}

// Function to print the results
void print_results() {
    printf("Results:\n");
    for (int i = 0; i < sizeof(students) / sizeof(Student); i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }
}

// Main function
int main() {
    administer_exam();
    print_results();
    return 0;
}