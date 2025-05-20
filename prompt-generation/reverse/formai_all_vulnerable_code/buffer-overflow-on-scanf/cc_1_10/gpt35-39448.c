//FormAI DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  int age;
};

void addStudent(struct Student *students, int index) {
  printf("Enter student name:\n");
  scanf("%s", students[index].name);
  printf("Enter student ID:\n");
  scanf("%d", &students[index].id);
  printf("Enter student age:\n");
  scanf("%d", &students[index].age);
  printf("Student added successfully!\n\n");
}

void searchStudent(struct Student *students, int index) {
  int searchID;
  printf("Enter the student ID you want to search for:\n");
  scanf("%d", &searchID);

  for (int i=0; i<index; i++) {
    if (students[i].id == searchID) {
      printf("Student found:\n");
      printf("Name: %s\nID: %d\nAge: %d\n\n", students[i].name, students[i].id, students[i].age);
      return;
    }
  }

  printf("Student not found!\n\n");
}

void printDatabase(struct Student *students, int index) {
  if (index == 0) {
    printf("Database is empty!\n\n");
    return;
  }

  printf("Database has %d student(s):\n", index);
  for (int i=0; i<index; i++) {
      printf("Name: %s\nID: %d\nAge: %d\n\n", students[i].name, students[i].id, students[i].age);
  }
}

int main() {
  struct Student students[100];
  int index = 0;
  char choice[10];

  printf("*** Welcome to Student Database Simulation ***\n");

  while (1) {
    printf("Type 'add' to add new student, 'search' to search for a student, 'print' to print the database, or 'exit' to exit the program:\n");
    scanf("%s", choice);

    if (strcmp(choice, "add") == 0) {
      addStudent(students, index);
      index++;
    }
    else if (strcmp(choice, "search") == 0) {
      searchStudent(students, index);
    }
    else if (strcmp(choice, "print") == 0) {
      printDatabase(students, index);
    }
    else if (strcmp(choice, "exit") == 0) {
      printf("Exiting the program...\n");
      exit(0);
    }
    else {
      printf("Invalid input, please try again!\n\n");
    }
  }

  return 0;
}