//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1024

struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
};

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <resume.txt>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  int line_num = 0;
  struct resume resume;
  memset(&resume, 0, sizeof(resume));

  while ((nread = getline(&line, &len, fp)) != -1) {
    line_num++;
    if (nread > MAX_LINE_LENGTH) {
      fprintf(stderr, "Line %d is too long (max %d characters)\n", line_num, MAX_LINE_LENGTH);
      exit(EXIT_FAILURE);
    }

    // Parse the line
    if (line[0] == '#') {
      // Comment line
      continue;
    } else if (strncmp(line, "Name:", 5) == 0) {
      // Name line
      resume.name = strdup(line + 5);
    } else if (strncmp(line, "Email:", 6) == 0) {
      // Email line
      resume.email = strdup(line + 6);
    } else if (strncmp(line, "Phone:", 6) == 0) {
      // Phone line
      resume.phone = strdup(line + 6);
    } else if (strncmp(line, "Skills:", 7) == 0) {
      // Skills line
      resume.skills = strdup(line + 7);
    } else if (strncmp(line, "Experience:", 11) == 0) {
      // Experience line
      resume.experience = strdup(line + 11);
    } else if (strncmp(line, "Education:", 10) == 0) {
      // Education line
      resume.education = strdup(line + 10);
    } else {
      // Unknown line
      fprintf(stderr, "Unknown line %d: %s", line_num, line);
      exit(EXIT_FAILURE);
    }
  }

  fclose(fp);

  // Print the resume
  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Skills: %s\n", resume.skills);
  printf("Experience: %s\n", resume.experience);
  printf("Education: %s\n", resume.education);

  // Free the allocated memory
  free(resume.name);
  free(resume.email);
  free(resume.phone);
  free(resume.skills);
  free(resume.experience);
  free(resume.education);

  exit(EXIT_SUCCESS);
}