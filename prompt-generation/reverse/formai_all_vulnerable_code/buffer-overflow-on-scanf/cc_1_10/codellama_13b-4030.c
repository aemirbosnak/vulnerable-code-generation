//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define structure for student
struct student {
  char name[50];
  int roll_no;
  int marks[5];
};

// Define structure for exam
struct exam {
  char name[50];
  int marks[5];
};

// Function to calculate total marks
int calculate_total_marks(struct student *s, struct exam *e) {
  int total_marks = 0;
  for (int i = 0; i < 5; i++) {
    total_marks += s->marks[i];
  }
  return total_marks;
}

// Function to calculate average marks
float calculate_average_marks(struct student *s, struct exam *e) {
  return (float)calculate_total_marks(s, e) / 5;
}

// Function to calculate percentage
float calculate_percentage(struct student *s, struct exam *e) {
  return calculate_average_marks(s, e) / 100;
}

// Function to display result
void display_result(struct student *s, struct exam *e) {
  printf("Name: %s\n", s->name);
  printf("Roll No: %d\n", s->roll_no);
  printf("Total Marks: %d\n", calculate_total_marks(s, e));
  printf("Average Marks: %f\n", calculate_average_marks(s, e));
  printf("Percentage: %f%%\n", calculate_percentage(s, e));
}

// Main function
int main() {
  // Declare variables
  struct student s1, s2;
  struct exam e1;
  int marks[5];

  // Get student details
  printf("Enter name: ");
  scanf("%s", s1.name);
  printf("Enter roll no: ");
  scanf("%d", &s1.roll_no);
  for (int i = 0; i < 5; i++) {
    printf("Enter mark %d: ", i + 1);
    scanf("%d", &s1.marks[i]);
  }

  // Get exam details
  printf("Enter exam name: ");
  scanf("%s", e1.name);
  for (int i = 0; i < 5; i++) {
    printf("Enter mark %d: ", i + 1);
    scanf("%d", &e1.marks[i]);
  }

  // Display result
  display_result(&s1, &e1);

  return 0;
}