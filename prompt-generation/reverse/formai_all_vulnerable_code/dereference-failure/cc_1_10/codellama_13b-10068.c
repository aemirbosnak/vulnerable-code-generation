//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
// Resume Parsing System

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to parse a resume
void parseResume(char *resume) {
  // Split the resume into individual lines
  char *lines[100];
  int numLines = 0;
  char *line = strtok(resume, "\n");
  while (line != NULL) {
    lines[numLines] = line;
    numLines++;
    line = strtok(NULL, "\n");
  }

  // Iterate through each line and extract information
  for (int i = 0; i < numLines; i++) {
    // Check for name and email
    if (strstr(lines[i], "Name:") != NULL) {
      char *name = strtok(lines[i], ":");
      printf("Name: %s\n", name);
    }
    if (strstr(lines[i], "Email:") != NULL) {
      char *email = strtok(lines[i], ":");
      printf("Email: %s\n", email);
    }

    // Check for education
    if (strstr(lines[i], "Education:") != NULL) {
      char *education = strtok(lines[i], ":");
      printf("Education: %s\n", education);
    }

    // Check for experience
    if (strstr(lines[i], "Experience:") != NULL) {
      char *experience = strtok(lines[i], ":");
      printf("Experience: %s\n", experience);
    }

    // Check for skills
    if (strstr(lines[i], "Skills:") != NULL) {
      char *skills = strtok(lines[i], ":");
      printf("Skills: %s\n", skills);
    }
  }
}

// Main function
int main() {
  // Read the resume from a file
  FILE *file = fopen("resume.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Allocate memory for the resume
  char *resume = malloc(10000 * sizeof(char));
  if (resume == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  // Read the resume into the buffer
  fread(resume, 1, 10000, file);
  fclose(file);

  // Parse the resume
  parseResume(resume);

  // Free the memory
  free(resume);

  return 0;
}