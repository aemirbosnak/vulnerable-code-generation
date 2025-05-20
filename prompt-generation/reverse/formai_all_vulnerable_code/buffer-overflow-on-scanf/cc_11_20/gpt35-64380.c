//FormAI DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>

struct student {
  char name[50];
  int age;
  int grade;
};

int main() {
  printf("Welcome to the C Database Simulation!\n\n");
  
  struct student students[5];
  int num_students = 0;
  
  while (1) {
    printf("What would you like to do? (Add [a], Remove [r], Print All [p], Quit [q])\n");
    char option;
    scanf(" %c", &option);
    
    if (option == 'a') {
      printf("\nEnter student name: ");
      scanf("%s", students[num_students].name);
      printf("Enter student age: ");
      scanf("%d", &students[num_students].age);
      printf("Enter student grade: ");
      scanf("%d", &students[num_students].grade);
      printf("\nNew student added!\n\n");
      num_students++;
      
    } else if (option == 'r') {
      printf("\nEnter the number of the student you would like to remove (starting from 0): ");
      int remove_index;
      scanf("%d", &remove_index);
      
      if (remove_index < 0 || remove_index >= num_students) {
        printf("Invalid student number!\n\n");
      } else {
        for (int i = remove_index; i < num_students - 1; i++) {
          students[i] = students[i + 1];
        }
        num_students--;
        printf("\nStudent removed!\n\n");
      }
      
    } else if (option == 'p') {
      if (num_students == 0) {
        printf("\nNo students in database!\n\n");
      } else {
        printf("\n%-20s %-10s %-10s\n", "Name", "Age", "Grade");
        for (int i = 0; i < num_students; i++) {
          printf("%-20s %-10d %-10d\n", students[i].name, students[i].age, students[i].grade);
        }
        printf("\n");
      }
      
    } else if (option == 'q') {
      printf("\nGoodbye!\n");
      break;
      
    } else {
      printf("\nInvalid option, please try again.\n\n");
    }
  }
  
  return 0;
}