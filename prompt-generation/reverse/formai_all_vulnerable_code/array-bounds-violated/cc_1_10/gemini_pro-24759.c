//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

typedef struct {
  char *name;
  char *email;
  char *phone;
  char *skills[10];
  int num_skills;
} resume;

resume *parse_resume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  resume *r = (resume *)malloc(sizeof(resume));
  if (r == NULL) {
    return NULL;
  }

  char line[MAX_LINE_LENGTH];
  int line_num = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    line_num++;

    // Remove newline character
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }

    // Parse line
    if (line_num == 1) {
      r->name = strdup(line);
    } else if (line_num == 2) {
      r->email = strdup(line);
    } else if (line_num == 3) {
      r->phone = strdup(line);
    } else if (line_num >= 4 && line_num <= 13) {
      r->skills[line_num - 4] = strdup(line);
      r->num_skills++;
    }
  }

  fclose(fp);

  return r;
}

void print_resume(resume *r) {
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n", r->phone);
  printf("Skills:\n");
  for (int i = 0; i < r->num_skills; i++) {
    printf("  - %s\n", r->skills[i]);
  }
}

int main() {
  resume *r = parse_resume("resume.txt");
  if (r == NULL) {
    printf("Error parsing resume\n");
    return 1;
  }

  print_resume(r);

  // Free memory
  free(r->name);
  free(r->email);
  free(r->phone);
  for (int i = 0; i < r->num_skills; i++) {
    free(r->skills[i]);
  }
  free(r);

  return 0;
}