//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
// C Resume Parsing System Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define structs for Resume and Skill
struct Resume {
  char name[50];
  char email[50];
  char phone[50];
  char summary[100];
  char skills[10][50];
};

struct Skill {
  char name[50];
  int level;
};

// Function to parse a resume and extract skills
void parseResume(char *resumeText, struct Resume *resume) {
  // Initialize variables
  char line[100];
  char *token;
  int i = 0;

  // Loop through each line of the resume
  while (fgets(line, 100, resumeText)) {
    // Tokenize each line
    token = strtok(line, " ");

    // Extract name
    if (strcmp(token, "Name:") == 0) {
      strcpy(resume->name, token);
    }

    // Extract email
    else if (strcmp(token, "Email:") == 0) {
      strcpy(resume->email, token);
    }

    // Extract phone
    else if (strcmp(token, "Phone:") == 0) {
      strcpy(resume->phone, token);
    }

    // Extract summary
    else if (strcmp(token, "Summary:") == 0) {
      strcpy(resume->summary, token);
    }

    // Extract skills
    else if (strcmp(token, "Skills:") == 0) {
      while (token != NULL) {
        strcpy(resume->skills[i], token);
        i++;
        token = strtok(NULL, ",");
      }
    }
  }
}

// Function to calculate the average skill level of a resume
float calculateSkillLevel(struct Resume *resume) {
  // Initialize variables
  int totalLevels = 0;
  int numSkills = 0;
  float averageLevel;

  // Loop through each skill of the resume
  for (int i = 0; i < 10; i++) {
    // Check if skill is not empty
    if (resume->skills[i] != NULL) {
      // Get the level of the skill
      int level = getLevel(resume->skills[i]);

      // Add the level to the total
      totalLevels += level;

      // Increment the number of skills
      numSkills++;
    }
  }

  // Calculate the average level
  averageLevel = (float)totalLevels / numSkills;

  return averageLevel;
}

// Function to get the level of a skill
int getLevel(char *skill) {
  // Initialize variables
  int level = 0;

  // Check if skill is not empty
  if (skill != NULL) {
    // Get the last character of the skill
    char lastChar = skill[strlen(skill) - 1];

    // Check if last character is a number
    if (lastChar >= '0' && lastChar <= '9') {
      // Convert the last character to an integer
      level = lastChar - '0';
    }
  }

  return level;
}

// Function to print the resume
void printResume(struct Resume *resume) {
  // Print the name
  printf("Name: %s\n", resume->name);

  // Print the email
  printf("Email: %s\n", resume->email);

  // Print the phone
  printf("Phone: %s\n", resume->phone);

  // Print the summary
  printf("Summary: %s\n", resume->summary);

  // Print the skills
  for (int i = 0; i < 10; i++) {
    if (resume->skills[i] != NULL) {
      printf("Skill %d: %s (Level %d)\n", i + 1, resume->skills[i], getLevel(resume->skills[i]));
    }
  }
}

int main() {
  // Create a resume object
  struct Resume resume;

  // Parse a resume
  parseResume("resume.txt", &resume);

  // Calculate the average skill level of the resume
  float averageLevel = calculateSkillLevel(&resume);

  // Print the resume
  printResume(&resume);

  // Print the average skill level of the resume
  printf("Average Skill Level: %.2f\n", averageLevel);

  return 0;
}