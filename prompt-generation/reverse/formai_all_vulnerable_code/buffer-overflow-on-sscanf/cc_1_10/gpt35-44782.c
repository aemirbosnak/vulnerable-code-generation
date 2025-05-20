//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  int age;
  char gender;
  int years_of_experience;
  char skills[500];
} Resume;

int parse_resume(char* file_path, Resume* res) {
  FILE* fp;
  char line[100];
  int current_line = 0;

  fp = fopen(file_path, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 0;
  }

  while (fgets(line, sizeof(line), fp)) {
    switch (current_line) {
      case 0:
        sscanf(line, "Name: %s", res->name);
        break;
      case 1:
        sscanf(line, "Age: %d", &res->age);
        break;
      case 2:
        sscanf(line, "Gender: %c", &res->gender);
        break;
      case 3:
        sscanf(line, "Years of Experience: %d", &res->years_of_experience);
        break;
      case 4:
        sscanf(line, "Skills: %[^\n]", res->skills);
        break;
      default:
        printf("Invalid resume format.\n");
        fclose(fp);
        return 0;
    }
    current_line++;
  }

  fclose(fp);
  return 1;
}

int main() {
  Resume res1;
  int success = parse_resume("resume1.txt", &res1);

  if (success) {
    printf("Name: %s\n", res1.name);
    printf("Age: %d\n", res1.age);
    printf("Gender: %c\n", res1.gender);
    printf("Years of Experience: %d\n", res1.years_of_experience);
    printf("Skills: %s\n", res1.skills);
  }

  return 0;
}