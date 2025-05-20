//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Structure to store the questions and answers
typedef struct {
    char question[256];
    char answers[4][256];
    int correctAnswer;
} Question;

// Function to compare two strings
int strcmp(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}

// Function to print the question and answers
void printQuestion(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.answers[i]);
    }
}

// Function to get the user's answer
int getAnswer() {
    int answer;
    scanf("%d", &answer);
    return answer;
}

// Function to check the user's answer
int checkAnswer(Question question, int answer) {
    return answer == question.correctAnswer;
}

// Function to print the results
void printResults(int score, int totalQuestions) {
    printf("Your score is %d out of %d\n", score, totalQuestions);
}

// Main function
int main() {
    // Array of questions
    Question questions[] = {
        {
            "What is the capital of France?",
            {"Paris", "London", "Rome", "Madrid"},
            1
        },
        {
            "What is the largest ocean in the world?",
            {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"},
            1
        },
        {
            "What is the highest mountain in the world?",
            {"Mount Everest", "K2", "Kangchenjunga", "Lhotse"},
            1
        },
        {
            "What is the longest river in the world?",
            {"Nile", "Amazon", "Yangtze", "Mississippi"},
            1
        },
        {
            "What is the most populous country in the world?",
            {"China", "India", "United States", "Indonesia"},
            1
        }
    };

    // Total number of questions
    int totalQuestions = sizeof(questions) / sizeof(questions[0]);

    // Score
    int score = 0;

    // Iterate over the questions
    for (int i = 0; i < totalQuestions; i++) {
        // Print the question
        printQuestion(questions[i]);

        // Get the user's answer
        int answer = getAnswer();

        // Check the user's answer
        if (checkAnswer(questions[i], answer)) {
            score++;
        }
    }

    // Print the results
    printResults(score, totalQuestions);

    return 0;
}