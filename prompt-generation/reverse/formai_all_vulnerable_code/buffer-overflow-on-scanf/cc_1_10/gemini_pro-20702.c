//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a question
typedef struct Question {
  char question[100];
  char options[4][50];
  int correct_option;
} Question;

// Array of questions
Question questions[] = {
  {"What is the capital of India?", {"New Delhi", "Mumbai", "Chennai", "Kolkata"}, 1},
  {"What is the currency of Japan?", {"Yen", "Yuan", "Euro", "Dollar"}, 1},
  {"Who is the father of the Indian constitution?", {"Mahatma Gandhi", "Jawaharlal Nehru", "B.R. Ambedkar", "Sardar Patel"}, 3},
  {"What is the largest ocean in the world?", {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 1},
  {"Who is the author of the famous novel 'To Kill a Mockingbird'?", {"Harper Lee", "J.K. Rowling", "Jane Austen", "Ernest Hemingway"}, 1}
};

// Function to display the welcome message
void welcome() {
  printf("\n\nWelcome to our online examination system!\n\n");
}

// Function to display the instructions
void instructions() {
  printf("Instructions:\n");
  printf("1. Read the question carefully.\n");
  printf("2. Choose the correct option from the given choices.\n");
  printf("3. If you are not sure about the answer, you can skip the question.\n");
  printf("4. There is no time limit for the exam.\n");
  printf("5. Your score will be displayed at the end of the exam.\n\n");
}

// Function to display the question
void display_question(Question question) {
  printf("\n%s\n\n", question.question);
  for (int i = 0; i < 4; i++) {
    printf("%d. %s\n", i + 1, question.options[i]);
  }
}

// Function to get the user's input
int get_input() {
  int input;
  scanf("%d", &input);
  return input;
}

// Function to check if the user's input is correct
int check_answer(Question question, int input) {
  return input == question.correct_option;
}

// Function to calculate the score
int calculate_score(int *answers, int num_questions) {
  int score = 0;
  for (int i = 0; i < num_questions; i++) {
    if (answers[i] == 1) {
      score++;
    }
  }
  return score;
}

// Main function
int main() {
  // Display the welcome message
  welcome();

  // Display the instructions
  instructions();

  // Get the number of questions
  int num_questions = sizeof(questions) / sizeof(questions[0]);

  // Allocate memory for the answers array
  int *answers = (int *)malloc(num_questions * sizeof(int));

  // Loop through the questions
  for (int i = 0; i < num_questions; i++) {
    // Display the question
    display_question(questions[i]);

    // Get the user's input
    int input = get_input();

    // Check if the user's input is correct
    int is_correct = check_answer(questions[i], input);

    // Store the user's answer in the answers array
    answers[i] = is_correct;
  }

  // Calculate the score
  int score = calculate_score(answers, num_questions);

  // Display the score
  printf("\nYour score is %d out of %d\n", score, num_questions);

  // Free the memory allocated for the answers array
  free(answers);

  return 0;
}