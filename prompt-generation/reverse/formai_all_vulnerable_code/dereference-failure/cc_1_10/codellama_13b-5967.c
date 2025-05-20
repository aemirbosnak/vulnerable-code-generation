//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
// Post-apocalyptic C Resume Parsing System
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structures for storing resume data
typedef struct {
  char* name;
  char* email;
  char* phone;
  char* skills;
} Resume;

typedef struct {
  Resume* resumes;
  int num_resumes;
} ResumeList;

// Function to parse a resume
void parse_resume(char* resume_text, Resume* resume) {
  // Split the resume text into lines
  char** lines = strtok(resume_text, "\n");
  while (lines != NULL) {
    // Parse the name
    if (strstr(lines, "Name:") != NULL) {
      resume->name = strtok(lines, " ");
      resume->name = resume->name + 5;
    }
    // Parse the email
    if (strstr(lines, "Email:") != NULL) {
      resume->email = strtok(lines, " ");
      resume->email = resume->email + 6;
    }
    // Parse the phone number
    if (strstr(lines, "Phone:") != NULL) {
      resume->phone = strtok(lines, " ");
      resume->phone = resume->phone + 6;
    }
    // Parse the skills
    if (strstr(lines, "Skills:") != NULL) {
      resume->skills = strtok(lines, " ");
      resume->skills = resume->skills + 7;
    }
    // Move to the next line
    lines = strtok(NULL, "\n");
  }
}

// Function to sort resumes by name
void sort_resumes(ResumeList* resume_list) {
  int i, j;
  Resume temp;
  for (i = 0; i < resume_list->num_resumes - 1; i++) {
    for (j = 0; j < resume_list->num_resumes - i - 1; j++) {
      if (strcmp(resume_list->resumes[j].name, resume_list->resumes[j+1].name) > 0) {
        temp = resume_list->resumes[j];
        resume_list->resumes[j] = resume_list->resumes[j+1];
        resume_list->resumes[j+1] = temp;
      }
    }
  }
}

// Function to print resumes
void print_resumes(ResumeList* resume_list) {
  int i;
  for (i = 0; i < resume_list->num_resumes; i++) {
    printf("Name: %s\n", resume_list->resumes[i].name);
    printf("Email: %s\n", resume_list->resumes[i].email);
    printf("Phone: %s\n", resume_list->resumes[i].phone);
    printf("Skills: %s\n", resume_list->resumes[i].skills);
  }
}

// Main function
int main() {
  // Initialize the resume list
  ResumeList resume_list;
  resume_list.num_resumes = 0;

  // Read the resume text from a file
  FILE* fp = fopen("resumes.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }
  char resume_text[10000];
  fgets(resume_text, 10000, fp);
  fclose(fp);

  // Parse the resume text
  Resume resume;
  parse_resume(resume_text, &resume);

  // Add the resume to the list
  resume_list.resumes = (Resume*)malloc(sizeof(Resume));
  resume_list.resumes[resume_list.num_resumes] = resume;
  resume_list.num_resumes++;

  // Sort the resumes by name
  sort_resumes(&resume_list);

  // Print the resumes
  print_resumes(&resume_list);

  return 0;
}