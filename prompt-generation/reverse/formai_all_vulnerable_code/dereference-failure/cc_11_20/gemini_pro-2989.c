//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int readResume(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Couldn't open file %s!\n", filename);
    return -1;
  }
  int ch;
  int state = 0;
  int inName = 0;
  int inSkills = 0;
  int inExperience = 0;
  int inEducation = 0;
  int inAwards = 0;
  char *keyWords[] = {"Name:", "Skills:", "Experience:", "Education:", "Awards:"};
  char *names[100], *skills[100], *experiences[100], *educations[100], *awards[100];
  int numNames = 0, numSkills = 0, numExperiences = 0, numEducations = 0, numAwards = 0;
  while ((ch = fgetc(fp)) != EOF) {
    if (isspace(ch)) {
      if (state == 0) {
        state = 0;
      } else if (state == 1) {
        state = 1;
      } else {
        state = 0;
      }
    } else {
      if (state == 0) {
        if (ch == keyWords[0][0]) {
          state = 1;
          inName = 1;
        } else if (ch == keyWords[1][0]) {
          state = 2;
          inSkills = 1;
        } else if (ch == keyWords[2][0]) {
          state = 3;
          inExperience = 1;
        } else if (ch == keyWords[3][0]) {
          state = 4;
          inEducation = 1;
        } else if (ch == keyWords[4][0]) {
          state = 5;
          inAwards = 1;
        }
      } else if (state == 1) {
        if (inName) {
          names[numNames++] = malloc(100);
          char *name = names[numNames - 1];
          while (ch != '\n') {
            *name++ = ch;
            ch = fgetc(fp);
          }
          *name = '\0';
          inName = 0;
        }
      } else if (state == 2) {
        if (inSkills) {
          skills[numSkills++] = malloc(100);
          char *skill = skills[numSkills - 1];
          while (ch != '\n') {
            *skill++ = ch;
            ch = fgetc(fp);
          }
          *skill = '\0';
          inSkills = 0;
        }
      } else if (state == 3) {
        if (inExperience) {
          experiences[numExperiences++] = malloc(100);
          char *experience = experiences[numExperiences - 1];
          while (ch != '\n') {
            *experience++ = ch;
            ch = fgetc(fp);
          }
          *experience = '\0';
          inExperience = 0;
        }
      } else if (state == 4) {
        if (inEducation) {
          educations[numEducations++] = malloc(100);
          char *education = educations[numEducations - 1];
          while (ch != '\n') {
            *education++ = ch;
            ch = fgetc(fp);
          }
          *education = '\0';
          inEducation = 0;
        }
      } else if (state == 5) {
        if (inAwards) {
          awards[numAwards++] = malloc(100);
          char *award = awards[numAwards - 1];
          while (ch != '\n') {
            *award++ = ch;
            ch = fgetc(fp);
          }
          *award = '\0';
          inAwards = 0;
        }
      }
    }
  }
  fclose(fp);
  printf("Name: %s\n", names[0]);
  printf("Skills: ");
  for (int i = 0; i < numSkills; i++) {
    printf("%s, ", skills[i]);
  }
  printf("\nExperience: ");
  for (int i = 0; i < numExperiences; i++) {
    printf("%s, ", experiences[i]);
  }
  printf("\nEducation: ");
  for (int i = 0; i < numEducations; i++) {
    printf("%s, ", educations[i]);
  }
  printf("\nAwards: ");
  for (int i = 0; i < numAwards; i++) {
    printf("%s, ", awards[i]);
  }
  printf("\n");
  return 0;
}

int main() {
  char filename[] = "resume.txt";
  printf("Yay! Let's parse this resume!\n");
  int result = readResume(filename);
  if (result == 0) {
    printf("Parsing successful! Here's what we found:\n");
  } else {
    printf("Oops! Something went wrong while parsing the resume. :( Try checking the file name or the file itself.\n");
  }
  return 0;
}