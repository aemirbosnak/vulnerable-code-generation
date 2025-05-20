//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structures for storing resume data
typedef struct {
    char name[50];
    char email[50];
    char education[100];
    char skills[200];
} Resume;

typedef struct {
    char title[50];
    char keywords[200];
} JobPosting;

// function prototypes
void parseResume(char *filename, Resume *resume);
void parseJobPosting(char *filename, JobPosting *jobPosting);
int matchKeywords(Resume *resume, JobPosting *jobPosting);

int main() {
    Resume resume;
    JobPosting jobPosting;
    char resumeFilename[50], jobPostingFilename[50];
    int match;

    printf("Enter filename of resume: ");
    scanf("%s", resumeFilename);
    parseResume(resumeFilename, &resume);

    printf("Enter filename of job posting: ");
    scanf("%s", jobPostingFilename);
    parseJobPosting(jobPostingFilename, &jobPosting);

    match = matchKeywords(&resume, &jobPosting);

    if (match) {
        printf("Congratulations! Your skills match the job posting.\n");
    } else {
        printf("Sorry, your skills do not match the job posting.\n");
    }

    return 0;
}

void parseResume(char *filename, Resume *resume) {
    FILE *file;
    char line[1000], *token;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name: ")) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->name, token);
        } else if (strstr(line, "Email: ")) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->email, token);
        } else if (strstr(line, "Education: ")) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->education, token);
        } else if (strstr(line, "Skills: ")) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->skills, token);
        }
    }

    fclose(file);
}

void parseJobPosting(char *filename, JobPosting *jobPosting) {
    FILE *file;
    char line[1000], *token;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Title: ")) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(jobPosting->title, token);
        } else if (strstr(line, "Keywords: ")) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(jobPosting->keywords, token);
        }
    }

    fclose(file);
}

int matchKeywords(Resume *resume, JobPosting *jobPosting) {
    char *keywords[20], *token;
    int i, numKeywords = 0;

    token = strtok(jobPosting->keywords, ",");
    while (token != NULL) {
        keywords[numKeywords++] = token;
        token = strtok(NULL, ",");
    }

    for (i = 0; i < numKeywords; i++) {
        if (strstr(resume->skills, keywords[i])) {
            return 1;
        }
    }

    return 0;
}