//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char name[50];
  char email[50];
  char phone[15];
  char skills[200];
} Candidate;

void parseResume(char* filename, Candidate* candidate) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  char line[100];
  while (fgets(line, 100, file)) {
    line[strlen(line)-1] = '\0'; // remove newline character
    if (strstr(line, "Name") != NULL) {
      char* name = strchr(line, ':') + 1;
      strcpy(candidate->name, name);
    }
    else if (strstr(line, "Email") != NULL) {
      char* email = strchr(line, ':') + 1;
      strcpy(candidate->email, email);
    }
    else if (strstr(line, "Phone") != NULL) {
      char* phone = strchr(line, ':') + 1;
      strcpy(candidate->phone, phone);
    }
    else if (strstr(line, "Skills") != NULL) {
      char* skills = strchr(line, ':') + 1;
      strcpy(candidate->skills, skills);
    }
  }

  fclose(file);
}

void sanitizeStr(char* str) {
  char* p = str;
  while (*p != '\0') {
    if (isspace(*p)) {
      *p = ' '; // replace whitespace with space character
    }
    else if (!isalpha(*p) && !isspace(*p)) {
      *p = '\0'; // remove non-alphabetic and non-whitespace characters
    }
    p++;
  }
}

int getWordCount(char* str) {
  int count = 0;
  char* token = strtok(str, " ");
  while (token != NULL) {
    count++;
    token = strtok(NULL, " ");
  }
  return count;
}

int computeScore(char* skills, char* keywords) {
  int score = 0;

  char* token = strtok(keywords, ",");
  while (token != NULL) {
    char* p = strstr(skills, token);
    if (p != NULL) {
      score++;
    }
    token = strtok(NULL, ",");
  }

  return score;
}

int main() {
  Candidate candidate;
  parseResume("resume.txt", &candidate);

  sanitizeStr(candidate.name);
  sanitizeStr(candidate.skills);

  char keywords[200] = "c++,python,java,html,css,javascript";

  int wordCount = getWordCount(candidate.skills);
  int score = computeScore(candidate.skills, keywords);
  float matchPercentage = (float) score / wordCount * 100;

  printf("Candidate Name: %s\n", candidate.name);
  printf("Email Address: %s\n", candidate.email);
  printf("Phone Number: %s\n", candidate.phone);
  printf("Skills: %s\n", candidate.skills);
  printf("Match Percentage: %.2f%%\n", matchPercentage);

  return 0;
}