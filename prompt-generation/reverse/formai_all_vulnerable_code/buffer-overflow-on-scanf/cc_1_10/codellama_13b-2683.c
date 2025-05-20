//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
// Online Examination System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures
typedef struct {
  char name[100];
  char email[100];
  char password[100];
  int roll_no;
} User;

typedef struct {
  char question[1000];
  char answer[1000];
  int marks;
} Question;

// Functions
void create_user(User *user) {
  printf("Enter your name: ");
  scanf("%s", user->name);
  printf("Enter your email: ");
  scanf("%s", user->email);
  printf("Enter your password: ");
  scanf("%s", user->password);
  printf("Enter your roll number: ");
  scanf("%d", &user->roll_no);
}

void create_question(Question *question) {
  printf("Enter the question: ");
  scanf("%s", question->question);
  printf("Enter the answer: ");
  scanf("%s", question->answer);
  printf("Enter the marks: ");
  scanf("%d", &question->marks);
}

void display_question(Question *question) {
  printf("Question: %s\n", question->question);
  printf("Answer: %s\n", question->answer);
  printf("Marks: %d\n", question->marks);
}

void display_result(User *user, int total_marks) {
  printf("Name: %s\n", user->name);
  printf("Email: %s\n", user->email);
  printf("Roll number: %d\n", user->roll_no);
  printf("Total marks: %d\n", total_marks);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Declare variables
  User user;
  Question questions[10];
  int total_marks = 0;

  // Create a user
  create_user(&user);

  // Create questions
  for (int i = 0; i < 10; i++) {
    create_question(&questions[i]);
  }

  // Display questions
  for (int i = 0; i < 10; i++) {
    display_question(&questions[i]);
  }

  // Take the exam
  for (int i = 0; i < 10; i++) {
    char answer[100];
    printf("Enter the answer for question %d: ", i + 1);
    scanf("%s", answer);
    if (strcmp(answer, questions[i].answer) == 0) {
      total_marks += questions[i].marks;
    }
  }

  // Display result
  display_result(&user, total_marks);

  return 0;
}