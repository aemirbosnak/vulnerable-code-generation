//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a question
typedef struct Question {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a question
void print_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get the user's answer
int get_user_answer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer;
}

// Function to check the user's answer
int check_answer(Question question, int answer) {
    return question.correct_option == answer;
}

// Function to print the result
void print_result(int score, int total_questions) {
    printf("Your score is %d/%d\n", score, total_questions);
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Create an array of questions
    Question questions[] = {
        {"What is the capital of India?", {"New Delhi", "Mumbai", "Chennai", "Kolkata"}, 1},
        {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
        {"What is the currency of India?", {"Rupee", "Dollar", "Euro", "Pound"}, 1},
        {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Rhinoceros"}, 1},
        {"What is the national bird of India?", {"Peacock", "Eagle", "Sparrow", "Crow"}, 1}
    };

    // Get the total number of questions
    int total_questions = sizeof(questions) / sizeof(Question);

    // Generate a random question paper
    int question_paper[total_questions];
    for (int i = 0; i < total_questions; i++) {
        question_paper[i] = generate_random_number(0, total_questions - 1);
    }

    // Administer the exam
    int score = 0;
    for (int i = 0; i < total_questions; i++) {
        // Print the question
        print_question(questions[question_paper[i]]);

        // Get the user's answer
        int answer = get_user_answer();

        // Check the user's answer
        if (check_answer(questions[question_paper[i]], answer)) {
            score++;
        }
    }

    // Print the result
    print_result(score, total_questions);

    return 0;
}