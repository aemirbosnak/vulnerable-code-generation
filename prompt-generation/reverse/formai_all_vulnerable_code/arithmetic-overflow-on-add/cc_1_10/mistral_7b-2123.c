//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char education[100];
    char experience[200];
} Candidate;

void mumble(char *str, int *length) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    *length = i;
}

Candidate *jibberJabber(FILE *resumeFile) {
    Candidate *candidate = (Candidate *) malloc(sizeof(Candidate));
    char nameBuffer[50];
    int nameLength;
    char educationBuffer[100];
    int educationLength;
    char experienceBuffer[200];
    int experienceLength;

    fgets(nameBuffer, 50, resumeFile); // Get name
    mumble(nameBuffer, &nameLength);
    strcpy(candidate->name, nameBuffer);

    fgets(educationBuffer, 100, resumeFile); // Get education
    mumble(educationBuffer, &educationLength);
    strcpy(candidate->education, educationBuffer);

    char ch;
    int inExperience = 0;
    while ((ch = fgetc(resumeFile)) != EOF) {
        if (ch == '\n') {
            if (inExperience) {
                experienceBuffer[experienceLength] = '\0';
                mumble(experienceBuffer, &experienceLength);
                strcpy(candidate->experience, experienceBuffer);
                break;
            }
            continue;
        }
        experienceBuffer[experienceLength++] = ch;
        if (ch == '\n') {
            inExperience = 1;
        }
    }

    return candidate;
}

int main() {
    FILE *resumeFile = fopen("resume.txt", "r");
    if (resumeFile == NULL) {
        printf("Could not open resume file.\n");
        return 1;
    }

    Candidate *mysteryMan = jibberJabber(resumeFile);
    printf("Name: %s\n", mysteryMan->name);
    printf("Education: %s\n", mysteryMan->education);
    printf("Experience: %s\n", mysteryMan->experience);

    free(mysteryMan);
    fclose(resumeFile);

    return 0;
}