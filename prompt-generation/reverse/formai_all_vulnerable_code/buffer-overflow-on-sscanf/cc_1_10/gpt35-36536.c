//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char skills[500];
    char experience[1000];
};

// Function to parse the input resume
void parseResume(char* inputResume, struct resume* parsedResume) {
    char* tempResume = inputResume;
    
    // Extract the name
    char* tempName = strstr(tempResume, "Name:");
    sscanf(tempName, "Name:%s", parsedResume->name);
    tempResume = tempName + strlen(parsedResume->name) + 6;
    
    // Extract the email
    char* tempEmail = strstr(tempResume, "Email:");
    sscanf(tempEmail, "Email:%s", parsedResume->email);
    tempResume = tempEmail + strlen(parsedResume->email) + 7;
    
    // Extract the skills
    char* tempSkills = strstr(tempResume, "Skills:");
    int skillsLength = strlen(tempSkills);
    char* skillsEnd = strstr(tempSkills, "Experience:");
    int skillsEndIndex = skillsEnd - tempSkills;
    skillsEndIndex -= 2;
    strncpy(parsedResume->skills, tempSkills, skillsEndIndex);
    
    // Extract the experience
    char* tempExperience = strstr(tempResume, "Experience:");
    sscanf(tempExperience, "Experience:%[^\n]", parsedResume->experience);
}

int main() {
    char inputResume[1500] = "Name:John Doe\nEmail:john_doe@email.com\nSkills:C, C++, Python\n"
                              "Experience:3 years of experience in software development.\n"
                              "Developed multiple projects in C and C++ including a chat application.";

    struct resume parsedResume;
    parseResume(inputResume, &parsedResume);

    // Print the parsed data
    printf("Name: %s\nEmail: %s\nSkills: %s\nExperience: %s\n", parsedResume.name, parsedResume.email,
           parsedResume.skills, parsedResume.experience);

    return 0;
}