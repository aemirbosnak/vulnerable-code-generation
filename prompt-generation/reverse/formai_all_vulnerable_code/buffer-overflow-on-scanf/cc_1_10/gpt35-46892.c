//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

// Functions for parsing the resume
void parseName(char *resume);
void parseContact(char *resume);
void parseEducation(char *resume);
void parseExperience(char *resume);
void parseSkills(char *resume);

// Other functions
int findEndLine(char *resume, int start);
int findNextWord(char *resume, int start);
char *findSubstring(char *resume, int start, int end);

// Global variables to store the parsed data
char *name = NULL;
char *phone = NULL;
char *email = NULL;
char *education = NULL;
char *experience = NULL;
char *skills = NULL;

int main() {
  char resume[MAX_LEN];
  printf("Enter your resume:\n");
  fgets(resume, MAX_LEN, stdin);

  parseName(resume);
  parseContact(resume);
  parseEducation(resume);
  parseExperience(resume);
  parseSkills(resume);

  printf("Name: %s\n", name);
  printf("Phone: %s\n", phone);
  printf("Email: %s\n", email);
  printf("Education: %s\n", education);
  printf("Experience: %s\n", experience);
  printf("Skills: %s\n", skills);

  free(name);
  free(phone);
  free(email);
  free(education);
  free(experience);
  free(skills);

  return 0;
}

void parseName(char *resume) {
  int start = 0, end;
  while (resume[start] == ' ') start++;
  end = findNextWord(resume, start);
  name = findSubstring(resume, start, end);
}

void parseContact(char *resume) {
  int start = 0, end;
  char *tmp = NULL;
  while ((start = strstr(resume, "Contact Info")) == NULL &&
         (start = strstr(resume, "Contact")) == NULL &&
         (start = strstr(resume, "Contact Information")) == NULL) {
    printf("Cannot find contact information, please enter your phone number: ");
    scanf("%s", tmp);
    if (phone) free(phone);
    phone = (char *) malloc(strlen(tmp) + 1);
    strcpy(phone, tmp);
    printf("Please enter your email address: ");
    scanf("%s", tmp);
    if (email) free(email);
    email = (char *) malloc(strlen(tmp) + 1);
    strcpy(email, tmp);
    return;
  }
  start += strlen("Contact Info");

  end = findEndLine(resume, start);
  tmp = findSubstring(resume, start, end);
  phone = strtok(tmp, "/");
  email = strtok(NULL, "/");
}

void parseEducation(char *resume) {
  education = "To be implemented.";
}

void parseExperience(char *resume) {
  experience = "To be implemented.";
}

void parseSkills(char *resume) {
  skills = "To be implemented.";
}

int findEndLine(char *resume, int start) {
  int i = start;
  while (resume[i] && resume[i] != '\n') i++;
  return i;
}

int findNextWord(char *resume, int start) {
  int i = start;
  while (resume[i] && resume[i] != ' ') i++;
  return i;
}

char *findSubstring(char *resume, int start, int end) {
  char *result = (char *) malloc(end - start + 1);
  strncpy(result, resume + start, end - start);
  result[end - start] = '\0';
  return result;
}