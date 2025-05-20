//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

struct Resume {
  char name[50];
  char email[50];
  char phone[15];
  char skills[500];
  char experience[500];
};

void parseResume(char* filename, struct Resume* resume);
void printResume(struct Resume* resume);

int main() {

  char filename[MAX_LENGTH];
  printf("Enter the filename of the resume you want to parse: ");
  scanf("%s", filename);

  struct Resume resume;
  parseResume(filename, &resume);
  
  printf("\nHere is the parsed resume:\n");
  printResume(&resume);

  return 0;
}

// Parses a resume file with the given filename and stores the data in the provided Resume struct
void parseResume(char* filename, struct Resume* resume) {
  FILE* file = fopen(filename, "r");
  if(file == NULL) {
    printf("Error: Could not open file.\n");
    return;
  }

  char line[MAX_LENGTH];

  // Loop through each line in the file
  while(fgets(line, sizeof(line), file)) {

    // Find and store the name
    if(strstr(line, "Name:")) {
      sscanf(line, "Name: %[^\n]s", resume->name);
    }

    // Find and store the email
    if(strstr(line, "Email:")) {
      sscanf(line, "Email: %[^\n]s", resume->email);
    }

    // Find and store the phone number
    if(strstr(line, "Phone:")) {
      sscanf(line, "Phone: %[^\n]s", resume->phone);
    }

    // Find and store the skills
    if(strstr(line, "Skills:")) {
      fgets(line, sizeof(line), file);
      sscanf(line, "%[^\n]s", resume->skills);
    }

    // Find and store the experience
    if(strstr(line, "Experience:")) {
      fgets(line, sizeof(line), file);
      sscanf(line, "%[^\n]s", resume->experience);
    }
  }

  fclose(file);
}

// Prints out the parsed Resume object
void printResume(struct Resume* resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
}