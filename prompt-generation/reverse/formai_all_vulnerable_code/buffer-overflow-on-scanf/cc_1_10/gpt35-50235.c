//FormAI DATASET v1.0 Category: Online Examination System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
  char name[50];
  int id;
  float marks[5]; // total of 5 subjects
  float total;
  char grade;
};

char calc_grade(float marks) {
  if(marks >= 90)
    return 'A';
  else if(marks >= 80 && marks < 90)
    return 'B';
  else if(marks >= 70 && marks < 80)
    return 'C';
  else if(marks >= 60 && marks < 70)
    return 'D';
  else
    return 'F';
}

int main() {
  int n, i, choice, id, flag=0;
  float total;
  char grade;
  struct student stu[50];
  printf("Enter number of students: ");
  scanf("%d", &n);
  for(i=0; i<n; i++) {
    printf("Enter Student %d Details:\n", i+1);
    printf("Enter Name: ");
    scanf(" %[^\n]%*c", stu[i].name);
    printf("Enter Student ID: ");
    scanf("%d", &stu[i].id);
    printf("Enter English Marks: ");
    scanf("%f", &stu[i].marks[0]);
    printf("Enter Math Marks: ");
    scanf("%f", &stu[i].marks[1]);
    printf("Enter Chemistry Marks: ");
    scanf("%f", &stu[i].marks[2]);
    printf("Enter Physics Marks: ");
    scanf("%f", &stu[i].marks[3]);
    printf("Enter Computer Science Marks: ");
    scanf("%f", &stu[i].marks[4]);
  }
  do {
    printf("Enter ID number to view result: ");
    scanf("%d", &id);
    flag = 0;
    for(i=0; i<n; i++) {
      if(id == stu[i].id) {
        total = 0;
        for(int j=0; j<5; j++)
          total += stu[i].marks[j];
        stu[i].total = total;
        stu[i].grade = calc_grade(total/5);
        printf("Name: %s\n", stu[i].name);
        printf("English: %.2f\n", stu[i].marks[0]);
        printf("Math: %.2f\n", stu[i].marks[1]);
        printf("Chemistry: %.2f\n", stu[i].marks[2]);
        printf("Physics: %.2f\n", stu[i].marks[3]);
        printf("Computer Science: %.2f\n", stu[i].marks[4]);
        printf("Total: %.2f\n", stu[i].total);
        printf("Grade: %c\n", stu[i].grade);
        flag = 1;
        break;
      }
    }
    if(flag == 0)
      printf("Invalid ID number, please try again!\n");
    printf("Do you want to view another result? (1 for yes, 0 for no): ");
    scanf("%d", &choice);
  } while(choice == 1);
  return 0;
}