//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 50
#define MAX_NAME_LENGTH 100
#define MAX_SKILLS 10

// Struct representing a resume
typedef struct Resume {
  char name[MAX_NAME_LENGTH];
  char skills[MAX_SKILLS][MAX_NAME_LENGTH];
  int numSkills;
} Resume;

// Function to parse resumes
void parseResumes(Resume* resumeList, int numResumes) {
  printf("Parsing resumes...\n");
  // Some code to parse resumes would go here
  // For this example program, we'll just fill in some fake data
  for (int i = 0; i < numResumes; i++) {
    strcpy(resumeList[i].name, "John Doe");
    strcpy(resumeList[i].skills[0], "C++");
    strcpy(resumeList[i].skills[1], "Java");
    strcpy(resumeList[i].skills[2], "Python");
    resumeList[i].numSkills = 3;
  }
}

// Function to print resumes and their skills
void printResumes(Resume* resumeList, int numResumes) {
  printf("\nPrinting resumes...\n");
  for (int i = 0; i < numResumes; i++) {
    printf("%s:\n", resumeList[i].name);
    for (int j = 0; j < resumeList[i].numSkills; j++) {
      printf(" - %s\n", resumeList[i].skills[j]);
    }
  }
}

int main() {
  int numPlayers;
  printf("How many players are there?: ");
  scanf("%d", &numPlayers);

  Resume* resumeList = (Resume*) malloc(sizeof(Resume) * MAX_RESUMES);
  int numResumes = 0;

  printf("\nWelcome to the Resume Party Game!\n");
  printf("Enter the resumes of the %d players below:\n", numPlayers);

  // Loop to enter resumes and add them to the list
  for (int i = 0; i < numPlayers; i++) {
    Resume newResume;
    printf("\nResume of player %d:\n", i + 1);

    printf("Name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    strcpy(newResume.name, name);

    printf("Skills (enter up to %d, one at a time; type 'done' when finished):\n", MAX_SKILLS);
    int numSkills = 0;
    char skill[MAX_NAME_LENGTH];
    while (numSkills < MAX_SKILLS) {
      scanf("%s", skill);
      if (!strcmp(skill, "done")) {
        break;
      }
      strcpy(newResume.skills[numSkills], skill);
      numSkills++;
    }
    newResume.numSkills = numSkills;

    resumeList[numResumes] = newResume;
    numResumes++;
  }

  // Parse the resumes and print them
  parseResumes(resumeList, numResumes);
  printResumes(resumeList, numResumes);

  // Free the memory for the resume list
  free(resumeList);

  return 0;
}