//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Question structure
typedef struct Question {
    char question[100];
    char options[4][50];
    int correct_answer;
} Question;

// Student structure
typedef struct Student {
    char name[50];
    int score;
} Student;

// Array of questions
Question questions[] = {
    {"What is the capital of India?", {"New Delhi", "Mumbai", "Chennai", "Kolkata"}, 0},
    {"Who is the current Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 0},
    {"What is the currency of India?", {"Rupee", "Dollar", "Euro", "Pound"}, 0},
    {"What is the national language of India?", {"Hindi", "English", "Sanskrit", "Tamil"}, 0},
    {"What is the largest state in India?", {"Rajasthan", "Uttar Pradesh", "Madhya Pradesh", "Maharashtra"}, 0}
};

// Function to display the questions
void display_questions(Question *questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("  (%c) %s\n", 'A' + j, questions[i].options[j]);
        }
    }
}

// Function to get the student's answers
void get_answers(int *answers, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("Enter your answer for question %d (A/B/C/D): ", i + 1);
        char answer;
        scanf(" %c", &answer);
        answers[i] = answer - 'A';
    }
}

// Function to check the student's answers
int check_answers(int *answers, Question *questions, int num_questions) {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        if (answers[i] == questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Initialize the students
    Student students[] = {
        {"John", 0},
        {"Mary", 0},
        {"Bob", 0}
    };

    // Display the questions
    display_questions(questions, 5);

    // Get the students' answers
    for (int i = 0; i < 3; i++) {
        int answers[5];
        get_answers(answers, 5);

        // Check the students' answers
        students[i].score = check_answers(answers, questions, 5);
    }

    // Display the results
    printf("\nResults:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}