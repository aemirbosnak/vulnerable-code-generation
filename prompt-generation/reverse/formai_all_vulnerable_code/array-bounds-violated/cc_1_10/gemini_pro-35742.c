//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

// Declare the global variables
char *lines[MAX_LINES];
int num_lines;

// Function to read the resume text file
void read_resume(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Read the lines of the file
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    // Remove the newline character from the line
    line[strlen(line) - 1] = '\0';

    // Add the line to the array of lines
    lines[num_lines] = strdup(line);
    num_lines++;
  }

  // Close the file
  fclose(fp);
}

// Function to parse the resume text
void parse_resume() {
  // Iterate over the lines of the resume
  for (int i = 0; i < num_lines; i++) {
    // Get the current line
    char *line = lines[i];

    // Check if the line is a header
    if (line[0] == '#') {
      // Print the header
      printf("%s\n", line);

      // Get the next line
      i++;
      line = lines[i];
    }

    // Check if the line is a skill
    if (strstr(line, "Skills:") != NULL) {
      // Print the skills
      printf("%s\n", line);

      // Get the next line
      i++;
      line = lines[i];

      // Iterate over the skills
      while (line[0] != '\0') {
        // Print the skill
        printf("  - %s\n", line);

        // Get the next line
        i++;
        line = lines[i];
      }
    }

    // Check if the line is a job title
    if (strstr(line, "Job Title:") != NULL) {
      // Print the job title
      printf("%s\n", line);

      // Get the next line
      i++;
      line = lines[i];
    }

    // Check if the line is an employer
    if (strstr(line, "Employer:") != NULL) {
      // Print the employer
      printf("%s\n", line);

      // Get the next line
      i++;
      line = lines[i];
    }

    // Check if the line is a start date
    if (strstr(line, "Start Date:") != NULL) {
      // Print the start date
      printf("%s\n", line);

      // Get the next line
      i++;
      line = lines[i];
    }

    // Check if the line is an end date
    if (strstr(line, "End Date:") != NULL) {
      // Print the end date
      printf("%s\n", line);

      // Get the next line
      i++;
      line = lines[i];
    }

    // Check if the line is a description
    if (strstr(line, "Description:") != NULL) {
      // Print the description
      printf("%s\n", line);

      // Get the next line
      i++;
      line = lines[i];

      // Iterate over the description
      while (line[0] != '\0') {
        // Print the description line
        printf("  - %s\n", line);

        // Get the next line
        i++;
        line = lines[i];
      }
    }
  }
}

// Function to free the memory allocated for the lines
void free_lines() {
  for (int i = 0; i < num_lines; i++) {
    free(lines[i]);
  }
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a filename
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  // Read the resume text file
  read_resume(argv[1]);

  // Parse the resume text
  parse_resume();

  // Free the memory allocated for the lines
  free_lines();

  return 0;
}