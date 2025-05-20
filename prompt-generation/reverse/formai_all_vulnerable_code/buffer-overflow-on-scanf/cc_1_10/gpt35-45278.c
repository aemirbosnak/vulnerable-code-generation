//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum buffer length for input
#define MAX_LENGTH 100

// Define the maximum number of resumes to parse
#define MAX_RESUMES 10

// Define the structure for storing resume information
typedef struct {
  char name[MAX_LENGTH];
  char email[MAX_LENGTH];
  char education[MAX_LENGTH];
  char experience[MAX_LENGTH];
} Resume;

int main() {
  // Initialize the array of resumes
  Resume resumes[MAX_RESUMES];

  // Get the number of resumes to parse
  int num_resumes;
  printf("How many resumes do you want to parse? ");
  scanf("%d", &num_resumes);

  // Parse each resume
  for (int i = 0; i < num_resumes; i++) {
    printf("Enter the name on resume %d: ", i+1);
    scanf("%s", resumes[i].name);

    printf("Enter the email on resume %d: ", i+1);
    scanf("%s", resumes[i].email);

    printf("Enter the education on resume %d: ", i+1);
    scanf("%s", resumes[i].education);

    printf("Enter the experience on resume %d: ", i+1);
    scanf("%s", resumes[i].experience);

    printf("\n");
  }

  // Print out all resumes
  printf("--- RESUME PARSER RESULTS ---\n");
  for (int i = 0; i < num_resumes; i++) {
    printf("RESUME %d\n", i+1);
    printf("Name: %s\n", resumes[i].name);
    printf("Email: %s\n", resumes[i].email);
    printf("Education: %s\n", resumes[i].education);
    printf("Experience: %s\n", resumes[i].experience);
    printf("\n");
  }

  return 0;
}