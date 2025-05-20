//FormAI DATASET v1.0 Category: Data mining ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

struct data{
  char name[50];
  int age;
  float salary;
};

int main(){
   FILE *fp;
   struct data e;
   int n, i;
   char ch;
   
   fp = fopen("employee.txt", "w");
   
   if(fp == NULL){
      printf("File cannot be created\n");
      exit(1);
   }

   printf("Enter the number of employees: ");
   scanf("%d", &n);

   for(i = 0; i < n; i++){
      printf("\nEnter name, age and salary of employee %d: \n", i+1);
      fgets(&ch, sizeof(ch), stdin);
      fgets(e.name, sizeof(e.name), stdin);
      scanf("%d %f", &e.age, &e.salary);
      fprintf(fp, "%s %d %.2f\n", e.name, e.age, e.salary);
   }

   fclose(fp);
   fp = fopen("employee.txt", "r");

   if(fp == NULL){
      printf("File cannot be opened\n");
      exit(1);
   }

   printf("\n\nData from the file:\n\n");
   
   while(fscanf(fp, "%s %d %f", e.name, &e.age, &e.salary) != EOF){
      printf("%s %d %.2f\n", e.name, e.age, e.salary);
   }

   fclose(fp);
   return 0;
}