//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: complete
// Unique C Memory Management Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
typedef struct {
  char name[50];
  int age;
  float gpa;
} Student;

// Function to dynamically allocate memory for an array of student structures
Student* allocate_students(int num_students) {
  return (Student*) malloc(num_students * sizeof(Student));
}

// Function to dynamically allocate memory for a string
char* allocate_string(int size) {
  return (char*) malloc(size * sizeof(char));
}

// Function to dynamically allocate memory for an array of strings
char** allocate_strings(int num_strings, int string_size) {
  char** strings = (char**) malloc(num_strings * sizeof(char*));
  for (int i = 0; i < num_strings; i++) {
    strings[i] = allocate_string(string_size);
  }
  return strings;
}

// Function to free memory allocated for an array of strings
void free_strings(char** strings, int num_strings) {
  for (int i = 0; i < num_strings; i++) {
    free(strings[i]);
  }
  free(strings);
}

// Function to free memory allocated for an array of student structures
void free_students(Student* students, int num_students) {
  free(students);
}

int main() {
  // Allocate memory for 10 student structures
  Student* students = allocate_students(10);

  // Allocate memory for 5 strings
  char** names = allocate_strings(5, 20);

  // Populate student information
  for (int i = 0; i < 10; i++) {
    strcpy(students[i].name, names[i]);
    students[i].age = i * 2;
    students[i].gpa = i * 1.5;
  }

  // Print student information
  for (int i = 0; i < 10; i++) {
    printf("Student %d: %s, %d, %.2f\n", i, students[i].name, students[i].age, students[i].gpa);
  }

  // Free memory allocated for student information
  free_students(students, 10);

  // Free memory allocated for string array
  free_strings(names, 5);

  return 0;
}