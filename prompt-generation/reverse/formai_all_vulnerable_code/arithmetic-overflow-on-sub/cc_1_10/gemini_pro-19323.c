//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
typedef struct Question {
    char question[256];
    char options[4][64];
    int correct_answer;
} Question;

// Array of questions
Question questions[] = {
    {
        "What is the capital of India?",
        {
            "New Delhi",
            "Mumbai",
            "Kolkata",
            "Chennai"
        },
        0
    },
    {
        "Who is the current Prime Minister of India?",
        {
            "Narendra Modi",
            "Rahul Gandhi",
            "Arvind Kejriwal",
            "Manmohan Singh"
        },
        0
    },
    {
        "What is the currency of India?",
        {
            "Rupee",
            "Dollar",
            "Euro",
            "Pound"
        },
        0
    },
    {
        "What is the national animal of India?",
        {
            "Tiger",
            "Lion",
            "Elephant",
            "Peacock"
        },
        0
    },
    {
        "What is the national bird of India?",
        {
            "Peacock",
            "Parrot",
            "Sparrow",
            "Eagle"
        },
        0
    }
};

// Function to print the question and options
void print_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get the user's answer
int get_answer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer - 1;
}

// Function to check if the answer is correct
int is_correct_answer(Question question, int answer) {
    return question.correct_answer == answer;
}

// Function to print the result
void print_result(int score) {
    printf("Your score is %d out of %d.\n", score, sizeof(questions) / sizeof(Question));
}

int main() {
    int score = 0;
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        print_question(questions[i]);
        int answer = get_answer();
        if (is_correct_answer(questions[i], answer)) {
            score++;
        }
    }
    print_result(score);
    return 0;
}