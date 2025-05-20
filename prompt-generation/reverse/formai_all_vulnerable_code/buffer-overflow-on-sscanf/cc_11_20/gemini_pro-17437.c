//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_RESUMES 100
#define MAX_SKILLS 10
#define MAX_SKILLS_LENGTH 100
#define MAX_EXPERIENCE 10
#define MAX_EXPERIENCE_LENGTH 100

typedef struct {
  char name[100];
  char email[100];
  char phone[20];
  char skills[MAX_SKILLS][MAX_SKILLS_LENGTH];
  char experience[MAX_EXPERIENCE][MAX_EXPERIENCE_LENGTH];
} Resume;

Resume resumes[MAX_RESUMES];
int num_resumes = 0;

int main() {
  // Read resumes from file
  FILE *fp = fopen("resumes.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    if (num_resumes >= MAX_RESUMES) {
      fprintf(stderr, "Error: Too many resumes\n");
      return EXIT_FAILURE;
    }
    Resume *resume = &resumes[num_resumes++];
    // Parse name
    if (sscanf(line, "Name: %s", resume->name) != 1) {
      fprintf(stderr, "Error: Invalid name\n");
      return EXIT_FAILURE;
    }
    // Parse email
    if (sscanf(line, "Email: %s", resume->email) != 1) {
      fprintf(stderr, "Error: Invalid email\n");
      return EXIT_FAILURE;
    }
    // Parse phone
    if (sscanf(line, "Phone: %s", resume->phone) != 1) {
      fprintf(stderr, "Error: Invalid phone\n");
      return EXIT_FAILURE;
    }
    // Parse skills
    int num_skills = 0;
    char *skill;
    while ((skill = strtok(NULL, ";")) != NULL) {
      if (num_skills >= MAX_SKILLS) {
        fprintf(stderr, "Error: Too many skills\n");
        return EXIT_FAILURE;
      }
      strncpy(resume->skills[num_skills++], skill, MAX_SKILLS_LENGTH);
    }
    // Parse experience
    int num_experience = 0;
    char *experience;
    while ((experience = strtok(NULL, ";")) != NULL) {
      if (num_experience >= MAX_EXPERIENCE) {
        fprintf(stderr, "Error: Too much experience\n");
        return EXIT_FAILURE;
      }
      strncpy(resume->experience[num_experience++], experience, MAX_EXPERIENCE_LENGTH);
    }
  }
  fclose(fp);

  // Search resumes for skills
  char skill[100];
  printf("Enter a skill to search for: ");
  scanf("%s", skill);
  for (int i = 0; i < num_resumes; i++) {
    Resume *resume = &resumes[i];
    for (int j = 0; j < MAX_SKILLS; j++) {
      if (strcmp(resume->skills[j], skill) == 0) {
        printf("Found resume for %s with skill %s\n", resume->name, skill);
      }
    }
  }

  return EXIT_SUCCESS;
}