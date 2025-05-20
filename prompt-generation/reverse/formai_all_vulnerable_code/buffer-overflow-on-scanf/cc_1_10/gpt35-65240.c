//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
  char name[50];
  char email[50];
  char skills[500];
  struct resume* next;
};

struct resume* head = NULL;

void createResume(char name[], char email[], char skills[]) {
  struct resume* new_resume = (struct resume*)malloc(sizeof(struct resume));
  strcpy(new_resume->name, name);
  strcpy(new_resume->email, email);
  strcpy(new_resume->skills, skills);
  new_resume->next = NULL;

  if(head == NULL) {
    head = new_resume;
  } else {
    struct resume* current = head;
    while(current->next != NULL) {
      current = current->next;
    }
    current->next = new_resume;
  }

  printf("\nResume created successfully.\n");
}

void printResume() {
  struct resume* current = head;
  printf("\n----------- List of Resumes -----------\n\n");
  while(current != NULL) {
    printf("Name: %s\n", current->name);
    printf("Email: %s\n", current->email);
    printf("Skills: %s\n\n", current->skills);
    current = current->next;
  }
}

int main() {
  printf("C Resume Parsing System\n\n");
  printf("1. Create Resume\n");
  printf("2. Print Resumes\n");
  printf("3. Exit\n");

  int choice;
  char name[50], email[50], skills[500];

  while(1) {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nName: ");
        scanf("%s", name);
        printf("Email: ");
        scanf("%s", email);
        printf("Skills: ");
        scanf(" %[^\n]s", skills);
        createResume(name, email, skills);
        break;
      case 2:
        printResume();
        break;
      case 3:
        printf("\nThank you for using C Resume Parsing System.\n");
        exit(0);
        break;
      default:
        printf("\nInvalid choice. Please enter again.\n");
    }
  }

  return 0;
}