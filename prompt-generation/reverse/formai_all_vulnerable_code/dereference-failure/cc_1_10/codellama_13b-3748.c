//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: expert-level
// Online Examination System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures for Questions and Answers
typedef struct {
  int id;
  char *question;
  char *option1;
  char *option2;
  char *option3;
  char *option4;
  char *correct_answer;
} question;

typedef struct {
  int id;
  char *student_name;
  char *student_id;
  char *roll_number;
  int total_marks;
  int marks_obtained;
  question *questions[100];
} student_info;

// Function to get user input
char* get_input(char* prompt) {
  char* input = malloc(100);
  printf("%s", prompt);
  fgets(input, 100, stdin);
  return input;
}

// Function to display questions
void display_questions(question* questions, int num_questions) {
  for (int i = 0; i < num_questions; i++) {
    printf("Question %d: %s\n", i + 1, questions[i].question);
    printf("A) %s\nB) %s\nC) %s\nD) %s\n", questions[i].option1, questions[i].option2, questions[i].option3, questions[i].option4);
  }
}

// Function to display results
void display_results(student_info* student, int num_questions) {
  printf("Student Name: %s\n", student->student_name);
  printf("Student ID: %s\n", student->student_id);
  printf("Roll Number: %s\n", student->roll_number);
  printf("Total Marks: %d\n", student->total_marks);
  printf("Marks Obtained: %d\n", student->marks_obtained);
  printf("Percentage: %.2f%%\n", (float)student->marks_obtained / student->total_marks * 100);
}

// Main function
int main() {
  // Initialize variables
  int num_questions = 10;
  question* questions = malloc(num_questions * sizeof(question));
  student_info* student = malloc(sizeof(student_info));

  // Get student information
  student->student_name = get_input("Enter student name: ");
  student->student_id = get_input("Enter student ID: ");
  student->roll_number = get_input("Enter roll number: ");
  student->total_marks = num_questions * 10;
  student->marks_obtained = 0;

  // Get questions
  for (int i = 0; i < num_questions; i++) {
    questions[i].id = i + 1;
    questions[i].question = get_input("Enter question: ");
    questions[i].option1 = get_input("Enter option 1: ");
    questions[i].option2 = get_input("Enter option 2: ");
    questions[i].option3 = get_input("Enter option 3: ");
    questions[i].option4 = get_input("Enter option 4: ");
    questions[i].correct_answer = get_input("Enter correct answer: ");
  }

  // Display questions
  display_questions(questions, num_questions);

  // Take test
  for (int i = 0; i < num_questions; i++) {
    char* user_answer = get_input("Enter your answer: ");
    if (strcmp(user_answer, questions[i].correct_answer) == 0) {
      student->marks_obtained += 10;
    }
  }

  // Display results
  display_results(student, num_questions);

  // Free memory
  free(questions);
  free(student);

  return 0;
}