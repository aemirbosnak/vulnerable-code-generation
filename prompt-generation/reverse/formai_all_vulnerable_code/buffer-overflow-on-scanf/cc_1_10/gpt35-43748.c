//FormAI DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include<stdio.h>
#include<string.h>

struct student{
  char name[30];
  int id;
  int marks;
};

int main(){

  struct student s[20]; //creating array of struct

  int n, i, j;
  printf("Enter the number of students:");
  scanf("%d", &n);

  //getting data from users
  for(i=0; i<n; i++){
    printf("\nEnter the name of student %d: ", i+1);
    scanf("%s", s[i].name);
    printf("Enter the ID of student %d: ", i+1);
    scanf("%d", &s[i].id);
    printf("Enter the marks of student %d: ", i+1);
    scanf("%d", &s[i].marks);
  }

  printf("\nStudent data has been recorded successfully!\n");

  //sorting data based on id
  for(i=0; i<n; i++){
    for(j=i+1; j<n; j++){
      if(s[i].id > s[j].id){
        struct student temp;
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
      }
    }
  }

  //displaying sorted data
  printf("\nStudent data sorted by ID:\n");
  printf("Name\t\tID\tMarks\n");
  printf("------------------------------\n");
  for(i=0; i<n; i++){
    printf("%s\t\t%d\t%d\n", s[i].name, s[i].id, s[i].marks);
  }

  return 0;
}