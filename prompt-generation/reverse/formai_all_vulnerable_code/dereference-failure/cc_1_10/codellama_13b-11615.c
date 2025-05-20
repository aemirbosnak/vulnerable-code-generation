//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: lively
// C Resume Parsing System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a resume
struct Resume {
  char name[100];
  char email[100];
  char phone[100];
  char address[100];
  char experience[100];
  char education[100];
  char skills[100];
};

// Function to parse a resume
void parse_resume(struct Resume *resume, char *input) {
  char *token;
  char *saveptr;

  // Parse name
  token = strtok_r(input, " ", &saveptr);
  strcpy(resume->name, token);

  // Parse email
  token = strtok_r(NULL, " ", &saveptr);
  strcpy(resume->email, token);

  // Parse phone
  token = strtok_r(NULL, " ", &saveptr);
  strcpy(resume->phone, token);

  // Parse address
  token = strtok_r(NULL, " ", &saveptr);
  strcpy(resume->address, token);

  // Parse experience
  token = strtok_r(NULL, " ", &saveptr);
  strcpy(resume->experience, token);

  // Parse education
  token = strtok_r(NULL, " ", &saveptr);
  strcpy(resume->education, token);

  // Parse skills
  token = strtok_r(NULL, " ", &saveptr);
  strcpy(resume->skills, token);
}

int main() {
  // Create a resume structure
  struct Resume resume;

  // Parse a resume
  char input[] = "John Doe johndoe@example.com 555-555-5555 123 Main St 10 years 4 years C, C++, Java";
  parse_resume(&resume, input);

  // Print the resume
  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Address: %s\n", resume.address);
  printf("Experience: %s\n", resume.experience);
  printf("Education: %s\n", resume.education);
  printf("Skills: %s\n", resume.skills);

  return 0;
}