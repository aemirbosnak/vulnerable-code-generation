//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: scalable
// Online Examination System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store exam details
typedef struct {
  char name[50];
  int age;
  char gender[10];
  char course[50];
  int marks;
} Exam;

// Function to display exam details
void displayExam(Exam e) {
  printf("Name: %s\n", e.name);
  printf("Age: %d\n", e.age);
  printf("Gender: %s\n", e.gender);
  printf("Course: %s\n", e.course);
  printf("Marks: %d\n", e.marks);
}

// Function to calculate total marks
int calculateTotalMarks(Exam e) {
  return e.marks;
}

// Function to calculate average marks
float calculateAverageMarks(Exam e) {
  return (float)e.marks / 100;
}

// Function to calculate grade
char calculateGrade(Exam e) {
  if (e.marks >= 80) {
    return 'A';
  } else if (e.marks >= 70) {
    return 'B';
  } else if (e.marks >= 60) {
    return 'C';
  } else if (e.marks >= 50) {
    return 'D';
  } else {
    return 'F';
  }
}

// Function to display exam report
void displayExamReport(Exam e) {
  printf("Exam Report\n");
  printf("============================\n");
  displayExam(e);
  printf("Total Marks: %d\n", calculateTotalMarks(e));
  printf("Average Marks: %.2f\n", calculateAverageMarks(e));
  printf("Grade: %c\n", calculateGrade(e));
}

// Main function
int main() {
  Exam e;
  printf("Enter Exam Details:\n");
  printf("Name: ");
  scanf("%s", e.name);
  printf("Age: ");
  scanf("%d", &e.age);
  printf("Gender: ");
  scanf("%s", e.gender);
  printf("Course: ");
  scanf("%s", e.course);
  printf("Marks: ");
  scanf("%d", &e.marks);
  displayExamReport(e);
  return 0;
}