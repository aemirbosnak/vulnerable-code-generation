//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

typedef struct {
  char name[50];
  char email[50];
  char phone[20];
  char skills[100];
  char experience[100];
  char education[100];
} resume_t;

int main() {
  // Declare variables
  char filename[50];
  FILE *fp;
  char line[MAX_LINE_LENGTH];
  char *token;
  int i = 0;
  resume_t resumes[MAX_LINES];

  // Get the filename from the user
  printf("Enter the name of the resume file: ");
  scanf("%s", filename);

  // Open the file
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }

  // Read the file line by line
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    // Tokenize the line
    token = strtok(line, ",");
    while (token != NULL) {
      // Parse the token
      if (i == 0) {
        strcpy(resumes[i].name, token);
      } else if (i == 1) {
        strcpy(resumes[i].email, token);
      } else if (i == 2) {
        strcpy(resumes[i].phone, token);
      } else if (i == 3) {
        strcpy(resumes[i].skills, token);
      } else if (i == 4) {
        strcpy(resumes[i].experience, token);
      } else if (i == 5) {
        strcpy(resumes[i].education, token);
      }
      i++;
      token = strtok(NULL, ",");
    }
    i = 0;
  }

  // Print the resumes
  for (i = 0; i < MAX_LINES; i++) {
    printf("Name: %s\n", resumes[i].name);
    printf("Email: %s\n", resumes[i].email);
    printf("Phone: %s\n", resumes[i].phone);
    printf("Skills: %s\n", resumes[i].skills);
    printf("Experience: %s\n", resumes[i].experience);
    printf("Education: %s\n\n", resumes[i].education);
  }

  // Close the file
  fclose(fp);

  return 0;
}