//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  char* name;
  char* email;
  char* phone;
  char* address;
  char* education;
  char* skills;
  char* experience;
} Resume;

bool parse_resume(char* filename, Resume* resume) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return false;
  }

  char line[100];
  while (fgets(line, sizeof(line), file)) {
    char* token = strtok(line, ",");
    if (strcmp(token, "Name:") == 0) {
      token = strtok(NULL, ",");
      resume->name = token;
    } else if (strcmp(token, "Email:") == 0) {
      token = strtok(NULL, ",");
      resume->email = token;
    } else if (strcmp(token, "Phone:") == 0) {
      token = strtok(NULL, ",");
      resume->phone = token;
    } else if (strcmp(token, "Address:") == 0) {
      token = strtok(NULL, ",");
      resume->address = token;
    } else if (strcmp(token, "Education:") == 0) {
      token = strtok(NULL, ",");
      resume->education = token;
    } else if (strcmp(token, "Skills:") == 0) {
      token = strtok(NULL, ",");
      resume->skills = token;
    } else if (strcmp(token, "Experience:") == 0) {
      token = strtok(NULL, ",");
      resume->experience = token;
    }
  }

  fclose(file);
  return true;
}

int main() {
  Resume resume;
  if (!parse_resume("resume.txt", &resume)) {
    printf("Error parsing resume\n");
    return 1;
  }

  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Address: %s\n", resume.address);
  printf("Education: %s\n", resume.education);
  printf("Skills: %s\n", resume.skills);
  printf("Experience: %s\n", resume.experience);

  return 0;
}