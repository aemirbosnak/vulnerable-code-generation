//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of a question
struct Question {
    char *question;
    char *options[4];
    int correct_option;
};

// Array of questions
struct Question questions[] = {
    {"Which of the following is not a programming language?", {"C", "Java", "Python", "Excel"}, 4},
    {"What is the capital of India?", {"Delhi", "Mumbai", "Kolkata", "Chennai"}, 1},
    {"Who is the father of Indian independence?", {"Mahatma Gandhi", "Jawaharlal Nehru", "Subhas Chandra Bose", "Bhagat Singh"}, 1},
    {"Which of the following is a natural disaster?", {"Earthquake", "Tsunami", "Flood", "All of the above"}, 4},
    {"What is the name of the largest ocean in the world?", {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 1}
};

// Function to print the question and options
void print_question(struct Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get the user's answer
int get_answer() {
    int answer;
    scanf("%d", &answer);
    return answer;
}

// Function to check if the answer is correct
int is_correct(struct Question question, int answer) {
    return question.correct_option == answer;
}

// Function to print the result
void print_result(int score) {
    printf("Your score is %d out of %d\n", score, sizeof(questions) / sizeof(struct Question));
}

// Main function
int main() {
    int score = 0;
    for (int i = 0; i < sizeof(questions) / sizeof(struct Question); i++) {
        print_question(questions[i]);
        int answer = get_answer();
        if (is_correct(questions[i], answer)) {
            score++;
        }
    }
    print_result(score);
    return 0;
}