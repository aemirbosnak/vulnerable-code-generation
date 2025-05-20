//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char education[MAX_LENGTH];
    char skills[MAX_LENGTH];
    char experience[MAX_LENGTH];
} Resume;

void parseResume(const char* filename, Resume* resume);
void displayResume(const Resume* resume);
void displayAllResumes(Resume resumes[], int count);
void saveParsedResumes(const char* outputFile, Resume resumes[], int count);

int main() {
    Resume resumes[MAX_RESUMES];
    int resumeCount = 0;
    char inputFile[MAX_LENGTH];
    char outputFile[MAX_LENGTH];

    printf("Enter the filename of the resumes to parse: ");
    scanf("%s", inputFile);
    
    FILE *input = fopen(inputFile, "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening file: %s\n", inputFile);
        return EXIT_FAILURE;
    }

    while (!feof(input) && resumeCount < MAX_RESUMES) {
        parseResume(input, &resumes[resumeCount]);
        resumeCount++;
    }
    
    fclose(input);

    printf("Parsed %d resumes.\n", resumeCount);
    displayAllResumes(resumes, resumeCount);

    printf("Enter filename to save parsed resumes: ");
    scanf("%s", outputFile);
    saveParsedResumes(outputFile, resumes, resumeCount);

    return EXIT_SUCCESS;
}

void parseResume(const char* filename, Resume* resume) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for parsing.\n");
        return;
    }

    // Basic parsing assuming a very specific format
    fscanf(file, "Name: %[^\n]\n", resume->name);
    fscanf(file, "Email: %[^\n]\n", resume->email);
    fscanf(file, "Phone: %[^\n]\n", resume->phone);
    fscanf(file, "Education: %[^\n]\n", resume->education);
    fscanf(file, "Skills: %[^\n]\n", resume->skills);
    fscanf(file, "Experience: %[^\n]\n", resume->experience);

    fclose(file);
}

void displayResume(const Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("---------------------------------\n");
}

void displayAllResumes(Resume resumes[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Resume %d:\n", i + 1);
        displayResume(&resumes[i]);
    }
}

void saveParsedResumes(const char* outputFile, Resume resumes[], int count) {
    FILE *output = fopen(outputFile, "w");
    if (output == NULL) {
        fprintf(stderr, "Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(output, "Name: %s\n", resumes[i].name);
        fprintf(output, "Email: %s\n", resumes[i].email);
        fprintf(output, "Phone: %s\n", resumes[i].phone);
        fprintf(output, "Education: %s\n", resumes[i].education);
        fprintf(output, "Skills: %s\n", resumes[i].skills);
        fprintf(output, "Experience: %s\n", resumes[i].experience);
        fprintf(output, "---------------------------------\n");
    }

    fclose(output);
    printf("Resumes saved to %s.\n", outputFile);
}