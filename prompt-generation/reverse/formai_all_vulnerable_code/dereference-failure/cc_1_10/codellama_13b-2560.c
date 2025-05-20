//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
// C Resume Parsing System
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to tokenize a string
char** tokenize(char* str) {
  char** tokens = malloc(sizeof(char*) * 100);
  char* token = strtok(str, " ");
  int i = 0;
  while (token != NULL) {
    tokens[i] = token;
    token = strtok(NULL, " ");
    i++;
  }
  return tokens;
}

// Function to parse a resume
void parse_resume(char* resume_text) {
  // Tokenize the resume text
  char** tokens = tokenize(resume_text);

  // Parse the tokens
  for (int i = 0; i < 100; i++) {
    char* token = tokens[i];
    if (strcmp(token, "Name") == 0) {
      // Get the name
      char* name = tokens[i + 1];
      printf("Name: %s\n", name);
    } else if (strcmp(token, "Email") == 0) {
      // Get the email
      char* email = tokens[i + 1];
      printf("Email: %s\n", email);
    } else if (strcmp(token, "Phone") == 0) {
      // Get the phone number
      char* phone = tokens[i + 1];
      printf("Phone: %s\n", phone);
    } else if (strcmp(token, "Summary") == 0) {
      // Get the summary
      char* summary = tokens[i + 1];
      printf("Summary: %s\n", summary);
    } else if (strcmp(token, "Skills") == 0) {
      // Get the skills
      char* skills = tokens[i + 1];
      printf("Skills: %s\n", skills);
    } else if (strcmp(token, "Education") == 0) {
      // Get the education
      char* education = tokens[i + 1];
      printf("Education: %s\n", education);
    } else if (strcmp(token, "Experience") == 0) {
      // Get the experience
      char* experience = tokens[i + 1];
      printf("Experience: %s\n", experience);
    }
  }

  // Free the tokens
  free(tokens);
}

int main() {
  // Get the resume text
  char* resume_text = "Name: John Doe\nEmail: johndoe@example.com\nPhone: 555-555-5555\nSummary: A summary of my experience and skills\nSkills: C, C++, Java\nEducation: Bachelor's degree in Computer Science\nExperience: 5 years of experience in software development";

  // Parse the resume
  parse_resume(resume_text);

  return 0;
}