//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the questions
typedef struct Question {
  char question[100];
  char options[4][50];
  int correct_option;
} Question;

// Structure to store the student's responses
typedef struct Response {
  char question[100];
  int selected_option;
} Response;

// Array of questions
Question questions[] = {
  {"What is the capital of India?", {"New Delhi", "Mumbai", "Kolkata", "Chennai"}, 1},
  {"Who is the current Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
  {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Peacock"}, 1},
  {"What is the national flower of India?", {"Lotus", "Rose", "Jasmine", "Marigold"}, 1},
  {"What is the national fruit of India?", {"Mango", "Apple", "Banana", "Orange"}, 1},
};

// Function to display the questions
void display_questions(Question questions[], int num_questions) {
  for (int i = 0; i < num_questions; i++) {
    printf("%d. %s\n", i + 1, questions[i].question);
    for (int j = 0; j < 4; j++) {
      printf("(%d) %s\n", j + 1, questions[i].options[j]);
    }
  }
}

// Function to get the student's responses
void get_responses(Response responses[], int num_questions) {
  for (int i = 0; i < num_questions; i++) {
    printf("Enter your response for question %d: ", i + 1);
    scanf("%s", responses[i].question);
    printf("Enter the option you selected (1-4): ");
    scanf("%d", &responses[i].selected_option);
  }
}

// Function to evaluate the student's responses
int evaluate_responses(Response responses[], Question questions[], int num_questions) {
  int score = 0;
  for (int i = 0; i < num_questions; i++) {
    if (responses[i].selected_option == questions[i].correct_option) {
      score++;
    }
  }
  return score;
}

// Function to print the student's score
void print_score(int score, int num_questions) {
  printf("Your score is %d out of %d\n", score, num_questions);
}

// Main function
int main() {
  int num_questions = sizeof(questions) / sizeof(questions[0]);

  // Display the questions
  display_questions(questions, num_questions);

  // Get the student's responses
  Response responses[num_questions];
  get_responses(responses, num_questions);

  // Evaluate the student's responses
  int score = evaluate_responses(responses, questions, num_questions);

  // Print the student's score
  print_score(score, num_questions);

  return 0;
}