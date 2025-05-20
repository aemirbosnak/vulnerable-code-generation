//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// function to match regular expressions
int match(char *string, char *pattern) {
  regex_t regex;
  int result;

  if (regcomp(&regex, pattern, REG_EXTENDED | REG_ICASE) != 0) {
    printf("Error compiling regex pattern: %s\n", pattern);
    return 0;
  }

  result = regexec(&regex, string, 0, NULL, 0);
  regfree(&regex);

  if (result == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char resume[10000], name[100], email[100], phone[20], education[200], skills[500], experience[500];
  int i, len;

  printf("Paste your resume here:\n");
  fgets(resume, 10000, stdin);
  len = strlen(resume);

  // extract name using regex
  if (match(resume, "^[A-Z][a-z]+\\s[A-Z][a-z]+$")) {
    sscanf(resume, "%s", name);
    printf("Name: %s\n", name);
  }

  // extract email using regex
  if (match(resume, "\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b")) {
    for (i = 0; i < len; i++) {
      if (resume[i] == '@') {
        sscanf(resume+i, "%s", email);
        printf("Email: %s\n", email);
        break;
      }
    }
  }

  // extract phone number using regex
  if (match(resume, "\\b\\d{3}[ -.]?\\d{3}[ -.]?\\d{4}\\b")) {
    for (i = 0; i < len; i++) {
      if (isdigit(resume[i])) {
        sscanf(resume+i, "%s", phone);
        printf("Phone: %s\n", phone);
        break;
      }
    }
  }

  // extract education using regex
  if (match(resume, "(BS|BA|MS|MA|MBA|PhD) ([A-Za-z]+[,\\s])+[A-Za-z]+")) {
    for (i = 0; i < len; i++) {
      if (match(resume+i, "(BS|BA|MS|MA|MBA|PhD) ([A-Za-z]+[,\\s])+[A-Za-z]+")) {
        sscanf(resume+i, "%[^\n]", education);
        printf("Education: %s\n", education);
        break;
      }
    }
  }

  // extract skills using regex
  if (match(resume, "\\b[\\w ]+ skills?\\b")) {
    for (i = 0; i < len; i++) {
      if (match(resume+i, "\\b[\\w ]+ skills?\\b")) {
        sscanf(resume+i, "%[^\n]", skills);
        printf("Skills: %s\n", skills);
        break;
      }
    }
  }

  // extract work experience using regex
  if (match(resume, "\\bExperience\\b")) {
    for (i = 0; i < len; i++) {
      if (match(resume+i, "\\b((Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec)\\s)?\\d{4}\\s-\\s((Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec)\\s)?\\d{4}\\b")) {
        sscanf(resume+i, "%[^\n]", experience);
        printf("Experience: %s\n", experience);
        break;
      }
    }
  }

  return 0;
}