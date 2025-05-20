//FormAI DATASET v1.0 Category: Educational ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct{
   char name[30];
   int age;
   double gpa;
} student;

int main() {

   // Input students' data
   student s1, s2;
   printf("Enter student 1 name: ");
   scanf("%s", s1.name);
   printf("Enter student 1 age: ");
   scanf("%d", &s1.age);
   printf("Enter student 1 GPA: ");
   scanf("%f", &s1.gpa);

   printf("Enter student 2 name: ");
   scanf("%s", s2.name);
   printf("Enter student 2 age: ");
   scanf("%d", &s2.age);
   printf("Enter student 2 GPA: ");
   scanf("%f", &s2.gpa);

   // Sort and display students' data
   if((int)s1.gpa/'1'==3){
        if(s1.age<18)s1.gpa=s1.gpa+0.5;
        else s1.gpa+=1;
    }else if((int)s1.gpa/'1'==4){
        if(s1.age<18)s1.gpa+=1;
        else s1.gpa+=2;
    }else if((int)s1.gpa/'1'==5){
        s1.gpa=s1.gpa+2;
    }
   if((int)s2.gpa/'1'==3){
        if(s2.age<18)s2.gpa=s2.gpa+0.5;
        else s2.gpa+=1;
    }else if((int)s2.gpa/'1'==4){
        if(s2.age<18)s2.gpa+=1;
        else s2.gpa+=2;
    }else if((int)s2.gpa/'1'==5){
        s2.gpa=s2.gpa+2;
    }
   
   if(s1.gpa > s2.gpa){
      printf("%s has a higher GPA with %lf \n", s1.name, s1.gpa);
   }else{
      printf("%s has a higher GPA with %lf \n", s2.name, s2.gpa);
   }

   return 0;
}