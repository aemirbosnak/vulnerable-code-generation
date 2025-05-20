//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_RECORDS 100

typedef struct {
  int id;
  char name[50];
  int age;
  float grade_point_avg;
} student_t;

student_t students[MAX_RECORDS];
int num_records = 0;

void display_menu() {
  printf("========= STUDENT DATABASE SIMULATOR =========\n");
  printf("1 - Add new record\n");
  printf("2 - Search record by ID\n");
  printf("3 - Delete record by ID\n");
  printf("4 - Print all records\n");
  printf("5 - Exit\n");
  printf("Enter your choice: ");
}

void add_record() {
  student_t new_student;
  printf("Enter ID: ");
  scanf("%d", &new_student.id);
  printf("Enter name: ");
  scanf("%s", new_student.name);
  printf("Enter age: ");
  scanf("%d", &new_student.age);
  printf("Enter grade point average: ");
  scanf("%f", &new_student.grade_point_avg);
  students[num_records++] = new_student;
  printf("Record added successfully.\n");
}

void print_record(student_t student) {
  printf("ID: %d\n", student.id);
  printf("Name: %s\n", student.name);
  printf("Age: %d\n", student.age);
  printf("Grade Point Average: %.2f\n", student.grade_point_avg);
}

void search_record() {
  int id;
  printf("Enter ID to search: ");
  scanf("%d", &id);
  for (int i = 0; i < num_records; i++) {
    if (students[i].id == id) {
      printf("Record found:\n");
      print_record(students[i]);
      return;
    }
  }
  printf("Record not found.\n");
}

void delete_record() {
  int id;
  printf("Enter ID to delete: ");
  scanf("%d", &id);
  for (int i = 0; i < num_records; i++) {
    if (students[i].id == id) {
      for (int j = i; j < num_records - 1; j++) {
        students[j] = students[j+1];
      }
      num_records--;
      printf("Record deleted successfully.\n");
      return;
    }
  }
  printf("Record not found.\n");
}

void print_all_records() {
  for (int i = 0; i < num_records; i++) {
    print_record(students[i]);
    printf("\n");
  }
}

int main() {
  int choice;
  do {
    display_menu();
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_record();
        break;
      case 2:
        search_record();
        break;
      case 3:
        delete_record();
        break;
      case 4:
        print_all_records();
        break;
      case 5:
        printf("Exiting program...\n");
        exit(0);
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (true);
  return 0;
}