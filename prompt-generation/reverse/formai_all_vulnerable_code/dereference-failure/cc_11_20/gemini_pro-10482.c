//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills;
  char *experience;
  char *education;
} resume;

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s resume.txt\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  int parsing_state = 0;  // 0 = name, 1 = email, 2 = phone, 3 = skills, 4 = experience, 5 = education

  resume *r = malloc(sizeof(resume));
  r->name = NULL;
  r->email = NULL;
  r->phone = NULL;
  r->skills = NULL;
  r->experience = NULL;
  r->education = NULL;

  while ((read = getline(&line, &len, fp)) != -1) {
    // Remove whitespace from the beginning and end of the line
    char *trimmed = strtok(line, " \n\r");

    // Parse the line
    switch (parsing_state) {
      case 0:  // Name
        r->name = strdup(trimmed);
        parsing_state = 1;
        break;
      case 1:  // Email
        if (strstr(trimmed, "@")) {
          r->email = strdup(trimmed);
          parsing_state = 2;
        }
        break;
      case 2:  // Phone
        if (strlen(trimmed) == 10 && strspn(trimmed, "0123456789") == 10) {
          r->phone = strdup(trimmed);
          parsing_state = 3;
        }
        break;
      case 3:  // Skills
        if (strstr(trimmed, "Skills")) {
          r->skills = strdup(trimmed);
          parsing_state = 4;
        }
        break;
      case 4:  // Experience
        if (strstr(trimmed, "Experience")) {
          r->experience = strdup(trimmed);
          parsing_state = 5;
        }
        break;
      case 5:  // Education
        if (strstr(trimmed, "Education")) {
          r->education = strdup(trimmed);
          parsing_state = 0;
        }
        break;
    }
  }

  // Print the resume
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n", r->phone);
  printf("Skills: %s\n", r->skills);
  printf("Experience: %s\n", r->experience);
  printf("Education: %s\n", r->education);

  // Free the allocated memory
  free(r->name);
  free(r->email);
  free(r->phone);
  free(r->skills);
  free(r->experience);
  free(r->education);
  free(r);
  free(line);
  fclose(fp);

  return 0;
}