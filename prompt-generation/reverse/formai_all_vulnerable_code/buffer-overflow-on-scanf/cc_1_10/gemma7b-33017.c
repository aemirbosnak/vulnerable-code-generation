//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate {
  char name[MAX_NAME_LENGTH];
  int age;
  float salary;
} Candidate;

int main() {
  Candidate candidates[10];
  int numCandidates = 0;

  // Read candidate information from the input
  while (1) {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;

    printf("Enter candidate's name: ");
    scanf("%s", name);

    printf("Enter candidate's age: ");
    scanf("%d", &age);

    printf("Enter candidate's salary: ");
    scanf("%f", &salary);

    // Create a new candidate
    candidates[numCandidates++] = (Candidate){.name = name, .age = age, .salary = salary};

    // Check if the user wants to continue
    char continueStr;
    printf("Do you want to continue? (Y/N): ");
    scanf(" %c", &continueStr);

    if (continueStr == 'N') {
      break;
    }
  }

  // Print candidate information
  for (int i = 0; i < numCandidates; i++) {
    printf("Name: %s\n", candidates[i].name);
    printf("Age: %d\n", candidates[i].age);
    printf("Salary: %.2f\n", candidates[i].salary);
  }

  return 0;
}