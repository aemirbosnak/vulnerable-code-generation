//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER_LENGTH 100

// Question structure
typedef struct {
    char question[MAX_ANSWER_LENGTH];
    int answer;
} Question;

// Function to initialize a question with its text and answer
void init_question(Question* q, char* text, int answer) {
    strcpy(q->question, text);
    q->answer = answer;
}

// Function to print a question
void print_question(Question q) {
    printf("%s? ", q.question);
}

// Function to check if the user's answer is correct
int check_answer(int user_answer, int correct_answer) {
    return user_answer == correct_answer;
}

// Function to run the exam
int run_exam(Question questions[], int num_questions) {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        print_question(questions[i]);
        int user_answer;
        scanf("%d", &user_answer);
        if (check_answer(user_answer, questions[i].answer)) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Initialize questions
    Question questions[MAX_QUESTIONS];
    init_question(&questions[0], "What is 2+2?", 4);
    init_question(&questions[1], "What is the capital of France?", 1);
    init_question(&questions[2], "What is the square root of 16?", 4);

    // Run the exam
    int num_questions = 3;
    int score = run_exam(questions, num_questions);

    // Print the results
    printf("You got %d out of %d questions correct.\n", score, num_questions);

    return 0;
}