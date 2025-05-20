//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the wasteland constants
#define RESUME_LENGTH 100
#define SKILL_COUNT 5
#define EXPERIENCE_COUNT 3

// Declare the wasteland warriors
struct resume {
  char name[RESUME_LENGTH];
  char skills[SKILL_COUNT][RESUME_LENGTH];
  char experience[EXPERIENCE_COUNT][RESUME_LENGTH];
};

// Define the wasteland scavenger functions
int load_resume(struct resume *resume);
int parse_resume(struct resume *resume);
int display_resume(struct resume *resume);

// The main wasteland scavenging program
int main() {
  struct resume resume;

  // Load the resume from the wasteland
  if (!load_resume(&resume)) {
    printf("Failed to load resume from the wasteland.\n");
    return 1;
  }

  // Parse the resume for valuable skills and experience
  if (!parse_resume(&resume)) {
    printf("Failed to parse resume for valuable skills and experience.\n");
    return 1;
  }

  // Display the resume to the wasteland recruiters
  if (!display_resume(&resume)) {
    printf("Failed to display resume to the wasteland recruiters.\n");
    return 1;
  }

  return 0;
}

// Load the resume from the wasteland
int load_resume(struct resume *resume) {
  FILE *fp;

  // Open the resume file
  if ((fp = fopen("resume.txt", "r")) == NULL) {
    return 0;
  }

  // Read the resume data
  fscanf(fp, "%s", resume->name);
  for (int i = 0; i < SKILL_COUNT; i++) {
    fscanf(fp, "%s", resume->skills[i]);
  }
  for (int i = 0; i < EXPERIENCE_COUNT; i++) {
    fscanf(fp, "%s", resume->experience[i]);
  }

  // Close the resume file
  fclose(fp);

  return 1;
}

// Parse the resume for valuable skills and experience
int parse_resume(struct resume *resume) {
  // Iterate through the skills
  for (int i = 0; i < SKILL_COUNT; i++) {
    // Check if the skill is valuable
    if (strcmp(resume->skills[i], "Scavenging") == 0 ||
        strcmp(resume->skills[i], "Bartering") == 0 ||
        strcmp(resume->skills[i], "Survival") == 0) {
      // Mark the skill as valuable
      resume->skills[i][0] = '*';
    }
  }

  // Iterate through the experience
  for (int i = 0; i < EXPERIENCE_COUNT; i++) {
    // Check if the experience is valuable
    if (strcmp(resume->experience[i], "Raiding") == 0 ||
        strcmp(resume->experience[i], "Trading") == 0 ||
        strcmp(resume->experience[i], "Hunting") == 0) {
      // Mark the experience as valuable
      resume->experience[i][0] = '*';
    }
  }

  return 1;
}

// Display the resume to the wasteland recruiters
int display_resume(struct resume *resume) {
  // Print the resume header
  printf("====================================================\n");
  printf("Name: %s\n", resume->name);
  printf("====================================================\n");

  // Print the skills
  printf("Skills:\n");
  for (int i = 0; i < SKILL_COUNT; i++) {
    printf("  %s\n", resume->skills[i]);
  }

  // Print the experience
  printf("Experience:\n");
  for (int i = 0; i < EXPERIENCE_COUNT; i++) {
    printf("  %s\n", resume->experience[i]);
  }

  // Print the resume footer
  printf("====================================================\n");

  return 1;
}