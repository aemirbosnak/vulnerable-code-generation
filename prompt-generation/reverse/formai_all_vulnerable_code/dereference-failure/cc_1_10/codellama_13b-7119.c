//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
// C Resume Parsing System

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store the information of a resume
typedef struct {
  char name[50];
  char email[50];
  char phone[50];
  char address[50];
  char education[50];
  char skills[50];
  char experience[50];
} Resume;

// Function to parse the resume and store the information in a struct
void parse_resume(Resume *resume, char *input) {
  char *token;
  char *saveptr;

  // Get the name
  token = strtok_r(input, ",", &saveptr);
  strcpy(resume->name, token);

  // Get the email
  token = strtok_r(NULL, ",", &saveptr);
  strcpy(resume->email, token);

  // Get the phone number
  token = strtok_r(NULL, ",", &saveptr);
  strcpy(resume->phone, token);

  // Get the address
  token = strtok_r(NULL, ",", &saveptr);
  strcpy(resume->address, token);

  // Get the education
  token = strtok_r(NULL, ",", &saveptr);
  strcpy(resume->education, token);

  // Get the skills
  token = strtok_r(NULL, ",", &saveptr);
  strcpy(resume->skills, token);

  // Get the experience
  token = strtok_r(NULL, ",", &saveptr);
  strcpy(resume->experience, token);
}

// Function to print the resume information
void print_resume(Resume *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Address: %s\n", resume->address);
  printf("Education: %s\n", resume->education);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
}

int main() {
  // Create a new resume
  Resume resume;

  // Get the input from the user
  char input[100];
  printf("Enter the resume information (name, email, phone, address, education, skills, experience): ");
  fgets(input, 100, stdin);

  // Parse the resume information
  parse_resume(&resume, input);

  // Print the resume information
  print_resume(&resume);

  return 0;
}