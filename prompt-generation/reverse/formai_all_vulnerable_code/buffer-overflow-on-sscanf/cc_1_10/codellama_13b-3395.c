//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: retro
// Retro C Resume Parsing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a resume
typedef struct {
  char name[50];
  char email[50];
  char phone[15];
  char experience[50];
  char education[50];
  char skills[50];
} Resume;

// Function to parse a resume
void parseResume(char *resume, Resume *resumeData) {
  // Get the name
  sscanf(resume, "%s %s", resumeData->name, resumeData->email);

  // Get the email
  sscanf(resume, "%s %s", resumeData->email, resumeData->phone);

  // Get the phone
  sscanf(resume, "%s %s", resumeData->phone, resumeData->experience);

  // Get the experience
  sscanf(resume, "%s %s", resumeData->experience, resumeData->education);

  // Get the education
  sscanf(resume, "%s %s", resumeData->education, resumeData->skills);

  // Get the skills
  sscanf(resume, "%s %s", resumeData->skills, resumeData->skills);
}

// Function to print the parsed resume
void printResume(Resume *resumeData) {
  printf("Name: %s\n", resumeData->name);
  printf("Email: %s\n", resumeData->email);
  printf("Phone: %s\n", resumeData->phone);
  printf("Experience: %s\n", resumeData->experience);
  printf("Education: %s\n", resumeData->education);
  printf("Skills: %s\n", resumeData->skills);
}

int main() {
  // Create a resume
  Resume resume;

  // Parse the resume
  parseResume("John Doe johndoe@example.com 555-555-5555 5 years 4 years Java, Python", &resume);

  // Print the parsed resume
  printResume(&resume);

  return 0;
}