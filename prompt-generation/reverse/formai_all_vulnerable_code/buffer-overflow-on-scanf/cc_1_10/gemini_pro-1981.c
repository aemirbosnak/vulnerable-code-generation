//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse the resume
int parse_resume(char *resume, char *name, char *email, char *phone) {
  // Initialize the variables
  name[0] = '\0';
  email[0] = '\0';
  phone[0] = '\0';

  // Parse the resume
  char *line = strtok(resume, "\n");
  while (line != NULL) {
    // Check if the line contains the name
    if (strstr(line, "Name:") != NULL) {
      strcpy(name, line + 6);  // Copy the name to the name variable
    }

    // Check if the line contains the email
    if (strstr(line, "Email:") != NULL) {
      strcpy(email, line + 7);  // Copy the email to the email variable
    }

    // Check if the line contains the phone number
    if (strstr(line, "Phone:") != NULL) {
      strcpy(phone, line + 7);  // Copy the phone number to the phone variable
    }

    // Get the next line
    line = strtok(NULL, "\n");
  }

  // Return 0 if the resume was parsed successfully
  return 0;
}

// Function to print the resume data
void print_resume_data(char *name, char *email, char *phone) {
  // Print the name
  printf("Name: %s\n", name);

  // Print the email
  printf("Email: %s\n", email);

  // Print the phone number
  printf("Phone: %s\n", phone);
}

// Main function
int main() {
  // Get the resume from the user
  char resume[1000];
  printf("Enter your resume: ");
  scanf("%s", resume);

  // Parse the resume
  char name[100];
  char email[100];
  char phone[100];
  parse_resume(resume, name, email, phone);

  // Print the resume data
  print_resume_data(name, email, phone);

  return 0;
}