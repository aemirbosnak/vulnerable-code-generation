//FormAI DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
  char name[50];
  int age;
  char course[30];
  float grade;
};

int main(){
  FILE *fp = fopen("student_info.dat", "rb");
  if(fp == NULL){
    printf("Error in opening file");
    exit(1);
  }
  
  int count = 0;
  struct student temp;
  while(fread(&temp, sizeof(struct student), 1, fp)){
    count++;
    if(count == 1){
      printf("Student Information:\nName\tAge\tCourse\tGrade\n");
    }
    printf("%s\t%d\t%s\t%.2f\n", temp.name, temp.age, temp.course, temp.grade);
  }
  fclose(fp);

  char name_to_search[50];
  printf("Enter name of student to search: ");
  scanf("%s", name_to_search);

  FILE *fp2 = fopen("student_info.dat", "rb");
  if(fp2 == NULL){
    printf("Error in opening file");
    exit(1);
  }

  count = 0;
  while(fread(&temp, sizeof(struct student), 1, fp2)){
    count++;
    if(strcmp(temp.name, name_to_search) == 0){
      printf("Student Information:\nName\tAge\tCourse\tGrade\n");
      printf("%s\t%d\t%s\t%.2f\n", temp.name, temp.age, temp.course, temp.grade);
      break;
    }
  }
  if(count != 0 && count == 1){
    printf("Search results: %d record found\n", count);
  }
  else{
    printf("Search results: %d records found\n", count);
  }
  fclose(fp2);

  int choice;
  printf("\nSelect an operation:\n1. Modify student information\n2. Add new student\n3. Delete existing student\n4. Exit program\nChoice: ");
  scanf("%d", &choice);

  FILE *fp3 = fopen("student_info.dat", "rb+");
  if(fp3 == NULL){
    printf("Error in opening file");
    exit(1);
  }

  count = 0;
  int record_num = 0;
  while(fread(&temp, sizeof(struct student), 1, fp3)){
    count++;
    if(strcmp(temp.name, name_to_search) == 0){
      record_num = count;
      break;
    }
  }

  fseek(fp3, (record_num-1)*sizeof(struct student), SEEK_SET);

  struct student new_student;
  switch(choice){
    case 1:
      printf("Enter new age: ");
      scanf("%d", &new_student.age);
      printf("Enter new course: ");
      scanf("%s", new_student.course);
      printf("Enter new grade: ");
      scanf("%f", &new_student.grade);
      fwrite(&new_student, sizeof(struct student), 1, fp3);
      break;
    case 2:
      printf("Enter name: ");
      scanf("%s", new_student.name);
      printf("Enter age: ");
      scanf("%d", &new_student.age);
      printf("Enter course: ");
      scanf("%s", new_student.course);
      printf("Enter grade: ");
      scanf("%f", &new_student.grade);
      fseek(fp3, 0, SEEK_END);
      fwrite(&new_student, sizeof(struct student), 1, fp3);
      break;
    case 3:
      fseek(fp3, (record_num-1)*sizeof(struct student), SEEK_SET);
      struct student null_student = {"",0,"",0.0};
      fwrite(&null_student, sizeof(struct student), 1, fp3);
      printf("Record deleted successfully.");
      break;
    case 4:
      exit(0);
    default:
      printf("Invalid choice.");
  }
  fclose(fp3);
  return 0;
}