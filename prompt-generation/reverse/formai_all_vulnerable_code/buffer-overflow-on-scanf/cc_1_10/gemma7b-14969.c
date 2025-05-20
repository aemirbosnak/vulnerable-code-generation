//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

struct Question {
  char question[255];
  char answer[255];
  int marks;
};

struct Student {
  char name[255];
  int roll_no;
  int marks;
  struct Student *next;
};

void create_question(struct Question **questions) {
  for (int i = 0; i < MAX_QUESTIONS; i++) {
    questions[i] = (struct Question *)malloc(sizeof(struct Question));
    printf("Enter question: ");
    scanf("%s", questions[i]->question);
    printf("Enter answer: ");
    scanf("%s", questions[i]->answer);
    printf("Enter marks: ");
    scanf("%d", &questions[i]->marks);
  }
}

void create_student(struct Student **students) {
  struct Student *new_student = (struct Student *)malloc(sizeof(struct Student));
  printf("Enter name: ");
  scanf("%s", new_student->name);
  printf("Enter roll no: ");
  scanf("%d", &new_student->roll_no);
  new_student->marks = 0;
  new_student->next = NULL;

  *students = new_student;
}

void calculate_marks(struct Student *students, struct Question **questions) {
  for (struct Student *current_student = students; current_student; current_student = current_student->next) {
    int total_marks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
      struct Question *current_question = questions[i];
      if (strcmp(current_student->name, current_question->answer) == 0) {
        total_marks += current_question->marks;
      }
    }
    current_student->marks = total_marks;
  }
}

void display_results(struct Student *students) {
  for (struct Student *current_student = students; current_student; current_student = current_student->next) {
    printf("Name: %s, Roll No: %d, Marks: %d\n", current_student->name, current_student->roll_no, current_student->marks);
  }
}

int main() {
  struct Question *questions = (struct Question *)malloc(MAX_QUESTIONS * sizeof(struct Question));
  create_question(questions);

  struct Student *students = (struct Student *)malloc(sizeof(struct Student));
  create_student(students);

  calculate_marks(students, questions);

  display_results(students);

  return 0;
}