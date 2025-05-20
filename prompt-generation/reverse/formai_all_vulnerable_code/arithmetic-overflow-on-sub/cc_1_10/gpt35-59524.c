//FormAI DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#define MAX_SIZE 100

// Creating a structure to hold information about a student's grade
struct student_grade {
  char student_name[20];
  int quiz1;
  int quiz2;
  int quiz3;
};

// Function to sort array of student_grade structures based on quiz averages
void sort_grades(struct student_grade arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int avg_i = (arr[i].quiz1 + arr[i].quiz2 + arr[i].quiz3) / 3;
      int avg_j = (arr[j].quiz1 + arr[j].quiz2 + arr[j].quiz3) / 3;
      if (avg_i < avg_j) {
        // Swap the structures
        struct student_grade temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  int n;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  // Creating an array of student_grade structures
  struct student_grade grades[MAX_SIZE];

  printf("Enter the name and quiz scores for each student:\n");
  for (int i = 0; i < n; i++) {
    printf("Student %d:\n", i+1);
    scanf("%s %d %d %d", grades[i].student_name, &grades[i].quiz1, &grades[i].quiz2, &grades[i].quiz3);
  }

  // Sort the grades using the sort_grades function
  sort_grades(grades, n);

  // Print out the sorted grades
  printf("\nSorted grades:\n");
  for (int i = 0; i < n; i++) {
    int avg = (grades[i].quiz1 + grades[i].quiz2 + grades[i].quiz3) / 3;
    printf("%s: %d\n", grades[i].student_name, avg);
  }

  return 0;
}