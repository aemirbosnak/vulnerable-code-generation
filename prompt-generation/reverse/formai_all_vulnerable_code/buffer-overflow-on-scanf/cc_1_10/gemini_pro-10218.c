//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store question and answer
struct Question {
    char question[100];
    char options[4][50];
    int correct_answer;
};

// Structure to store student's details
struct Student {
    char name[50];
    int score;
};

// Function to generate random number
int generate_random_number(int n) {
    srand(time(NULL));
    return rand() % n;
}

// Function to display question and options
void display_question(struct Question question) {
    printf("Q: %s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get student's answer
int get_student_answer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer;
}

// Function to check if student's answer is correct
int check_answer(struct Question question, int student_answer) {
    return question.correct_answer == student_answer;
}

// Function to calculate student's score
int calculate_score(struct Question* questions, int num_questions, int* student_answers) {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        if (check_answer(questions[i], student_answers[i])) {
            score++;
        }
    }
    return score;
}

// Function to display student's result
void display_result(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("Score: %d\n", student.score);
}

int main() {
    // Create questions
    struct Question questions[] = {
        {"What is the capital of India?", {"Delhi", "Mumbai", "Kolkata", "Chennai"}, 1},
        {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
        {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Peacock"}, 1},
        {"What is the national bird of India?", {"Peacock", "Parrot", "Owl", "Sparrow"}, 1},
        {"What is the national currency of India?", {"Rupee", "Dollar", "Euro", "Pound"}, 1}
    };

    // Get student's name
    char student_name[50];
    printf("Enter your name: ");
    scanf("%s", student_name);

    // Generate random questions
    int num_questions = 5;
    int random_questions[num_questions];
    for (int i = 0; i < num_questions; i++) {
        random_questions[i] = generate_random_number(5);
    }

    // Display questions and get student's answers
    int student_answers[num_questions];
    for (int i = 0; i < num_questions; i++) {
        display_question(questions[random_questions[i]]);
        student_answers[i] = get_student_answer();
    }

    // Calculate student's score
    struct Student student = {student_name, calculate_score(questions, num_questions, student_answers)};

    // Display student's result
    display_result(student);

    return 0;
}