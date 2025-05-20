//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
  char name[MAX_NAME_LENGTH];
  int age;
  float salary;
  struct Candidate* next;
} Candidate;

void parse_resume(Candidate** head) {
  FILE* file = fopen("resume.txt", "r");
  if (file == NULL) {
    return;
  }

  char name[MAX_NAME_LENGTH];
  int age;
  float salary;

  while (fscanf(file, "Name: %s", name) != EOF) {
    fscanf(file, "Age: %d", &age);
    fscanf(file, "Salary: %f", &salary);

    Candidate* new_candidate = malloc(sizeof(Candidate));
    new_candidate->name[0] = '\0';
    strcpy(new_candidate->name, name);
    new_candidate->age = age;
    new_candidate->salary = salary;
    new_candidate->next = NULL;

    if (*head == NULL) {
      *head = new_candidate;
    } else {
      (*head)->next = new_candidate;
    }

    head = &((*head)->next);
  }

  fclose(file);
}

int main() {
  Candidate* head = NULL;
  parse_resume(&head);

  Candidate* current = head;
  while (current) {
    printf("Name: %s\n", current->name);
    printf("Age: %d\n", current->age);
    printf("Salary: %.2f\n", current->salary);
    printf("\n");

    current = current->next;
  }

  return 0;
}