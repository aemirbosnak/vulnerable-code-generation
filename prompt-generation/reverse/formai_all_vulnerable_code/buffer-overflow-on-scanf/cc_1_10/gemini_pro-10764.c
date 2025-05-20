//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Database of questions and answers
typedef struct {
    char question[256];
    char answers[4][64];
    int correct_answer;
} Question;

Question questions[] = {
    {"What is the capital of France?", {"Paris", "London", "Rome", "Madrid"}, 0},
    {"Who is the author of Hamlet?", {"William Shakespeare", "Jane Austen", "Charles Dickens", "Oscar Wilde"}, 0},
    {"What is the largest ocean in the world?", {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 0},
    {"What is the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, 0},
    {"What is the name of the tallest mountain in the world?", {"Mount Everest", "K2", "Kangchenjunga", "Lhotse"}, 0},
};

// Function to generate a random number
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to shuffle an array
void shuffle(int *array, int size) {
    for (int i = 0; i < size; i++) {
        int j = get_random_number(0, size - 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to display the question and answer choices
void display_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.answers[i]);
    }
}

// Function to get the user's answer
int get_user_answer() {
    int answer;
    scanf("%d", &answer);
    return answer;
}

// Function to check if the user's answer is correct
int is_correct_answer(Question question, int answer) {
    return question.correct_answer == answer;
}

// Function to display the result
void display_result(int score) {
    printf("Your score is %d out of %d\n", score, sizeof(questions) / sizeof(Question));
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the array of questions
    int question_order[sizeof(questions) / sizeof(Question)];
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        question_order[i] = i;
    }
    shuffle(question_order, sizeof(questions) / sizeof(Question));

    // Keep track of the user's score
    int score = 0;

    // Iterate over the questions
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        // Display the question and answer choices
        display_question(questions[question_order[i]]);

        // Get the user's answer
        int answer = get_user_answer();

        // Check if the user's answer is correct
        if (is_correct_answer(questions[question_order[i]], answer)) {
            score++;
        }
    }

    // Display the result
    display_result(score);

    return 0;
}