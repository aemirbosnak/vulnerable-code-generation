//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store questions and answers
typedef struct _question {
    char *question;
    char *answers[4];
    int correct_answer;
} question;

// Array of questions and answers
question questions[] = {
    {"What is the capital of France?", {"Paris", "London", "Rome", "Madrid"}, 0},
    {"Who painted the Mona Lisa?", {"Leonardo da Vinci", "Michelangelo", "Vincent van Gogh", "Pablo Picasso"}, 0},
    {"What is the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, 0},
    {"What is the largest ocean in the world?", {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 0},
    {"What is the name of the tallest mountain in the world?", {"Mount Everest", "Mount Kilimanjaro", "Mount Fuji", "Mount Denali"}, 0}
};

// Function to print the question and answers
void print_question(question *q) {
    printf("%s\n", q->question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q->answers[i]);
    }
}

// Function to get the user's answer
int get_answer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer - 1;
}

// Function to check if the user's answer is correct
int is_correct(question *q, int answer) {
    return answer == q->correct_answer;
}

// Main function
int main() {
    // Initialize the score
    int score = 0;

    // Loop through the questions
    for (int i = 0; i < 5; i++) {
        // Print the question
        print_question(&questions[i]);

        // Get the user's answer
        int answer = get_answer();

        // Check if the answer is correct
        if (is_correct(&questions[i], answer)) {
            score++;
        }
    }

    // Print the score
    printf("Your score is %d/5\n", score);

    return 0;
}