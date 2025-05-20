//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>

// Define a structure for each resume entry
typedef struct {
  char name[50];
  char email[50];
  char phone[20];
  char education[100];
  char skills[200];
  char experience[500];
} ResumeEntry;

int main() {
  // Prompt for and read in the number of resumes to parse
  int numResumes;
  printf("Enter the number of resumes to parse: ");
  scanf("%d", &numResumes);

  // Create an array of ResumeEntry structures to hold the parsed resumes
  ResumeEntry resumes[numResumes];

  // Loop through each resume and prompt the user to enter the necessary information
  for (int i = 0; i < numResumes; i++) {
    printf("Enter the name of the candidate: ");
    scanf("%s", resumes[i].name);

    printf("Enter the candidate's email address: ");
    scanf("%s", resumes[i].email);

    printf("Enter the candidate's phone number: ");
    scanf("%s", resumes[i].phone);

    printf("Enter the candidate's education background: ");
    scanf(" %[^\n]s", resumes[i].education);

    printf("Enter the candidate's skills: ");
    scanf(" %[^\n]s", resumes[i].skills);

    printf("Enter the candidate's work experience: ");
    scanf(" %[^\n]s", resumes[i].experience);
  }

  // Output the parsed resumes in a readable format
  printf("\nRESUME PARSING RESULTS:\n\n");
  for (int i = 0; i < numResumes; i++) {
    printf("Candidate %d:\n", i+1);
    printf("Name: %s\n", resumes[i].name);
    printf("Email: %s\n", resumes[i].email);
    printf("Phone Number: %s\n", resumes[i].phone);
    printf("Education Background: %s\n", resumes[i].education);
    printf("Skills: %s\n", resumes[i].skills);
    printf("Experience: %s\n", resumes[i].experience);
    printf("\n");
  }

  return 0;
}