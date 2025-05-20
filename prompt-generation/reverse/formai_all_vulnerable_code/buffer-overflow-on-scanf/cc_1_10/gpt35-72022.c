//FormAI DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char name[20];
  double gpa;
} Student;

int main(){
  int num;
  printf("How many students do you want to input? ");
  scanf("%d", &num);

  Student *ptr;
  ptr = (Student*) malloc(num * sizeof(Student));
  
  if(ptr == NULL){
    printf("Error: Memory allocation failed.\n");
    return 1;
  }

  //Adding students
  printf("\nEnter Student Information\n");
  for(int i = 0; i < num; i++){
    printf("\nStudent %d\n", i+1);
    printf("ID: ");
    scanf("%d", &ptr[i].id);
    printf("Name: ");
    scanf("%s", ptr[i].name);
    printf("GPA: ");
    scanf("%lf", &ptr[i].gpa);
  }

  //Displaying all students
  printf("\nAll Students\n");
  for(int i = 0; i < num; i++){
    printf("ID: %d\t Name: %s\t GPA: %.2lf\n", ptr[i].id, ptr[i].name, ptr[i].gpa);
  }

  //Searching by student id
  int search_id;
  printf("\nEnter Student ID to search: ");
  scanf("%d", &search_id);
  for(int i = 0; i < num; i++){
    if(ptr[i].id == search_id){
      printf("Student found!\n");
      printf("ID: %d\t Name: %s\t GPA: %.2lf\n", ptr[i].id, ptr[i].name, ptr[i].gpa);
      break;
    }
    if(i == num-1){
      printf("Student not found.\n");
    }
  }

  //Freeing memory
  free(ptr);
  ptr = NULL;

  return 0;
}