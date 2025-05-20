//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  int id;
  char name[20];
  float marks;
};

void addStudent(FILE*);
void displayData(FILE*);
void searchStudent(FILE*);
void updateMarks(FILE*);

int main() {

  int choice;
  FILE *file = fopen("students.dat", "w+");

  if(file == NULL) {
    printf("Error opening file!");
    exit(1);
  }

  while(1){

    printf("\nWelcome to the Student Management System\n");
    printf("1. Add a new student\n");
    printf("2. Display all students data\n");
    printf("3. Search a student\n");
    printf("4. Update student records\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

      case 1:
        addStudent(file);
        break;

      case 2:
        displayData(file);
        break;

      case 3:
        searchStudent(file);
        break;

      case 4:
        updateMarks(file);
        break;

      case 5:
        printf("\nThank you for using our system!\n");
        fclose(file);
        exit(0);

      default:
        printf("\nInvalid choice, please choose from 1-5\n");
        break;

    }
  }

  return 0;
}

void addStudent(FILE *file) {

  struct Student student;
  printf("\nEnter student id: ");
  scanf("%d", &student.id);

  printf("Enter student name: ");
  scanf("%s", student.name);

  printf("Enter student marks: ");
  scanf("%f", &student.marks);

  fwrite(&student, sizeof(struct Student), 1, file);

  printf("\nStudent details added successfully!\n");

}

void displayData(FILE *file) {

  struct Student student;
  rewind(file);

  printf("\nStudent data:\n");
  printf("\nID\t\tName\t\tMarks\n");

  while(fread(&student, sizeof(struct Student), 1, file) == 1) {
    printf("%d\t\t%s\t\t%.2f\n", student.id, student.name, student.marks);
  }
}

void searchStudent(FILE *file) {

  int id;
  struct Student student;
  int found = 0;

  printf("\nEnter student id to search: ");
  scanf("%d", &id);

  rewind(file);

  while(fread(&student, sizeof(struct Student), 1, file) == 1) {

    if(student.id == id) {
      printf("\nStudent found!\n");
      printf("\nID\t\tName\t\tMarks\n");
      printf("%d\t\t%s\t\t%.2f\n", student.id, student.name, student.marks);
      found = 1;
      break;
    }
  }
  if(found == 0) {
    printf("\nStudent not found!\n");
  }
}

void updateMarks(FILE *file) {

  int id;
  struct Student student;
  int found = 0;

  printf("\nEnter student id to update: ");
  scanf("%d", &id);

  rewind(file);

  while(fread(&student, sizeof(struct Student), 1, file) == 1) {

    if(student.id == id) {
      printf("\nEnter new marks: ");
      scanf("%f", &student.marks);
      fseek(file, -sizeof(struct Student), SEEK_CUR);
      fwrite(&student, sizeof(struct Student), 1, file);
      found = 1;
      printf("\nMarks updated successfully!\n");
      break;
    }
  }
  if(found == 0) {
    printf("\nStudent not found!\n");
  }
}