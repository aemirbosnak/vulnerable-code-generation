//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 1000
#define MAX_LENGTH 100

struct resume {
  char name[MAX_LENGTH];
  char email[MAX_LENGTH];
  char phone[MAX_LENGTH];
  char address[MAX_LENGTH];
  int years_of_experience;
  char skills[MAX_LENGTH];
};

int read_resumes(struct resume* resumes) {
  int num_resumes = 0;
  char filename[MAX_LENGTH];
  FILE* fp;
  printf("Enter name of file containing resumes: ");
  scanf("%s", filename);
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("File not found.\n");
    return 0;
  }
  char line[MAX_LENGTH], *ptr;
  while (fgets(line, MAX_LENGTH, fp) != NULL) {
    ptr = strtok(line, ",");
    strncpy(resumes[num_resumes].name, ptr, MAX_LENGTH);
    ptr = strtok(NULL, ",");
    strncpy(resumes[num_resumes].email, ptr, MAX_LENGTH);
    ptr = strtok(NULL, ",");
    strncpy(resumes[num_resumes].phone, ptr, MAX_LENGTH);
    ptr = strtok(NULL, ",");
    strncpy(resumes[num_resumes].address, ptr, MAX_LENGTH);
    ptr = strtok(NULL, ",");
    resumes[num_resumes].years_of_experience = atoi(ptr);
    ptr = strtok(NULL, ",");
    strncpy(resumes[num_resumes].skills, ptr, MAX_LENGTH);
    num_resumes++;
  }
  fclose(fp);
  return num_resumes;
}

void print_resume(struct resume r) {
  printf("Name: %s\n", r.name);
  printf("Email: %s\n", r.email);
  printf("Phone: %s\n", r.phone);
  printf("Address: %s\n", r.address);
  printf("Years of experience: %d\n", r.years_of_experience);
  printf("Skills: %s\n", r.skills);
}

void search_resumes(struct resume* resumes, int num_resumes) {
  char skill[MAX_LENGTH];
  printf("Enter a skill to search for: ");
  scanf("%s", skill);
  printf("Matching resumes:\n");
  for (int i = 0; i < num_resumes; i++) {
    if (strstr(resumes[i].skills, skill) != NULL) {
      print_resume(resumes[i]);
    }
  }
}

int main() {
  struct resume resumes[MAX_RESUMES];
  int num_resumes = read_resumes(resumes);
  if (num_resumes == 0) {
    return 1;
  }
  search_resumes(resumes, num_resumes);
  return 0;
}