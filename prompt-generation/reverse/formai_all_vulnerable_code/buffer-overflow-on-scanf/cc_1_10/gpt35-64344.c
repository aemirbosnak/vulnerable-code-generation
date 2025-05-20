//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 256
#define MAX_THREAD 4

typedef struct {
  char name[MAX_SIZE];
  int age;
  char gender[MAX_SIZE];
  float salary;
} Employee;

Employee employees[MAX_SIZE];
int employee_count = 0;

void* read_csv(void *file_name) {
  FILE *fp = fopen((char *)file_name, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    pthread_exit(NULL);
  }

  char line[MAX_SIZE], * token;
  fgets(line, MAX_SIZE, fp); // ignore header

  while (fgets(line, MAX_SIZE, fp)) {
    token = strtok(line, ",");
    strcpy(employees[employee_count].name, token);
    token = strtok(NULL, ",");
    employees[employee_count].age = atoi(token);
    token = strtok(NULL, ",");
    strcpy(employees[employee_count].gender, token);
    token = strtok(NULL, ",");
    employees[employee_count].salary = atof(token);
    employee_count++;
  }

  fclose(fp);
  pthread_exit(NULL);
}

int main() {
  char file_name[MAX_SIZE];
  printf("Please enter CSV file name: ");
  scanf("%s", file_name);

  pthread_t ThreadID[MAX_THREAD];
  for (int i = 0; i < MAX_THREAD; i++) {
    pthread_create(&ThreadID[i], NULL, read_csv, (void *)file_name);
  }

  for (int i = 0; i < MAX_THREAD; i++) {
    pthread_join(ThreadID[i], NULL);
  }

  printf("\nTotal employees read from CSV: %d\n", employee_count);
  printf("Employee details:\n\n");

  for (int i = 0; i < employee_count; i++) {
    printf("Name: %s\n", employees[i].name);
    printf("Age: %d\n", employees[i].age);
    printf("Gender: %s\n", employees[i].gender);
    printf("Salary: %.2f\n\n", employees[i].salary);
  }

  return 0;
}