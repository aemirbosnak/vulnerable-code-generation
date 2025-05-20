//FormAI DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_QUESTIONS 10
#define MAX_ANSWER_LEN 20
#define MAX_NAME_LEN 50

// Define structure for question
struct Question {
    char question[100];
    char answers[4][MAX_ANSWER_LEN];
    int correct_answer;
};

// Define function to display questions
void display_questions(struct Question questions[MAX_QUESTIONS], int n_questions) {
    int i, j;

    // Display each question
    for (i = 0; i < n_questions; i++) {
        printf("%d. %s\n", i+1, questions[i].question);
        for (j = 0; j < 4; j++) {
            printf("%c) %s\n", 'A'+j, questions[i].answers[j]);
        }
        printf("\n");
    }
}

// Define function to collect user input
void collect_input(struct Question questions[MAX_QUESTIONS], int n_questions, int user_input[MAX_QUESTIONS]) {
    int i, answer;

    // Collect user input for each question
    for (i = 0; i < n_questions; i++) {
        printf("Enter your answer for question %d: ", i+1);
        scanf("%d", &answer);
        
        // Validate input
        while (answer < 1 || answer > 4) {
            printf("Invalid input. Please enter a number between 1 and 4: ");
            scanf("%d", &answer);
        }
        
        // Store user input (subtract 1 to index starting from 0)
        user_input[i] = answer - 1;
    }
}

// Define function to grade the test
int grade_test(struct Question questions[MAX_QUESTIONS], int n_questions, int user_input[MAX_QUESTIONS]) {
    int i, score = 0;

    // Check each answer and tally score
    for (i = 0; i < n_questions; i++) {
        if (user_input[i] == questions[i].correct_answer) {
            score++;
        }
    }

    return score;
}

// Define function to generate a random order of questions
void generate_random_order(int order[MAX_QUESTIONS], int n_questions) {
    int i, j, temp;

    // Initialize array with numbers 0 to n_questions-1
    for (i = 0; i < n_questions; i++) {
        order[i] = i;
    }

    // Shuffle the array
    for (i = 0; i < n_questions; i++) {
        // Generate a random index between i and n_questions-1
        j = i + rand() % (n_questions-i);

        // Swap i and j elements
        temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
}

// Main function
int main() {
    // Initialize questions
    struct Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"London", "Paris", "Berlin", "Madrid"}, 1},
        {"What is the largest mammal in the world?", {"Elephant", "Whale", "Rhinoceros", "Giraffe"}, 1},
        {"What chemical element is diamond made of?", {"Carbon", "Gold", "Silver", "Platinum"}, 0},
        {"Which planet is closest to the sun?", {"Earth", "Mars", "Mercury", "Venus"}, 2},
        {"Who discovered penicillin?", {"Thomas Edison", "Marie Curie", "Alexander Fleming", "Albert Einstein"}, 2},
        {"What is the tallest mammal in the world?", {"Elephant", "Giraffe", "Hippopotamus", "Rhino"}, 1},
        {"What is the most populated country in the world?", {"India", "China", "USA", "Russia"}, 1},
        {"What is the largest desert in the world?", {"Sahara", "Antarctica", "Arctic", "Gobi"}, 0},
        {"Who wrote 'To Kill a Mockingbird'?", {"Harper Lee", "Scott Fitzgerald", "William Faulkner", "John Steinbeck"}, 0},
        {"What is the largest organ of the human body?", {"Heart", "Liver", "Kidney", "Skin"}, 3}
    };

    // Define variables
    char user_name[MAX_NAME_LEN];
    int user_input[MAX_QUESTIONS];
    int n_questions, i, order[MAX_QUESTIONS], score;

    // Seed random number generator
    srand(time(NULL));

    // Get user name
    printf("Enter your name: ");
    fgets(user_name, MAX_NAME_LEN, stdin);
    user_name[strcspn(user_name, "\n")] = 0;

    // Get number of questions
    printf("Welcome %s! Please enter the number of questions you wish to answer (maximum %d): ", user_name, MAX_QUESTIONS);
    scanf("%d", &n_questions);

    // Validate user input
    while (n_questions < 1 || n_questions > MAX_QUESTIONS) {
        printf("Invalid input. Please enter a number between 1 and %d: ", MAX_QUESTIONS);
        scanf("%d", &n_questions);
    }

    // Generate random order of questions
    generate_random_order(order, n_questions);

    // Display questions in random order
    for (i = 0; i < n_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        printf("%s\n", questions[order[i]].question);
        printf("%c) %s\n", 'A'+0, questions[order[i]].answers[0]);
        printf("%c) %s\n", 'A'+1, questions[order[i]].answers[1]);
        printf("%c) %s\n", 'A'+2, questions[order[i]].answers[2]);
        printf("%c) %s\n", 'A'+3, questions[order[i]].answers[3]);
        printf("\n");
    }

    // Collect user input
    collect_input(questions, n_questions, user_input);

    // Grade the test
    score = grade_test(questions, n_questions, user_input);

    // Display score
    printf("\nTest complete. Your score is %d out of %d.\n", score, n_questions);

    return 0;
}