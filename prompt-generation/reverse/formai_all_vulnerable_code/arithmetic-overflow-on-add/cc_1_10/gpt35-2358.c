//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define structure for resume data
typedef struct resume {
    char name[50];
    char email[50];
    char phone[15];
    char education[250];
    char skills[500];
    char experience[500];
} Resume;

// function to parse resume based on keywords
void parseResume(Resume* r1, char* resumeText) {
    // keyword arrays for each section
    char eduKeywords[5][20] = {"education", "degree", "qualification", "certification", "coursework"};
    char skillKeywords[4][20] = {"skills", "programming", "tools", "languages"};
    char expKeywords[4][20] = {"experience", "work", "employment", "projects"};

    // tokenizing the resume text
    char* token = strtok(resumeText, "\n");
    while (token != NULL) {
        // check for education section
        for (int i = 0; i < 5; i++) {
            if (strstr(token, eduKeywords[i])) {
                strcpy(r1->education, token);
                break;
            }
        }

        // check for skills section
        for (int i = 0; i < 4; i++) {
            if (strstr(token, skillKeywords[i])) {
                strcpy(r1->skills, token);
                break;
            }
        }

        // check for experience section
        for (int i = 0; i < 4; i++) {
            if (strstr(token, expKeywords[i])) {
                strcpy(r1->experience, token);
                break;
            }
        }

        // check for name, email, or phone
        if (strstr(token, "@")) {
            strcpy(r1->email, token);
        }
        else if (strstr(token, "phone")) {
            strcpy(r1->phone, token);
        }
        else if (strlen(token) < 25) {
            strcpy(r1->name, token);
        }

        // get next token
        token = strtok(NULL, "\n");
    }
}

int main() {
    // read file with resume text
    FILE* fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error reading file!\n");
        exit(1);
    }

    // get size of file
    fseek(fp, 0L, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // allocate memory for resume text
    char* resumeText = (char*) malloc((fileSize+1) * sizeof(char));

    // read file into resume text
    fread(resumeText, sizeof(char), fileSize, fp);
    resumeText[fileSize] = '\0';

    // close file
    fclose(fp);

    // create resume object
    Resume r1;
    strcpy(r1.name, "");
    strcpy(r1.email, "");
    strcpy(r1.phone, "");
    strcpy(r1.education, "");
    strcpy(r1.skills, "");
    strcpy(r1.experience, "");

    // parse resume text into resume object
    parseResume(&r1, resumeText);

    // print resume data
    printf("Name: %s\n", r1.name);
    printf("Email: %s\n", r1.email);
    printf("Phone: %s\n", r1.phone);
    printf("Education: %s\n", r1.education);
    printf("Skills: %s\n", r1.skills);
    printf("Experience: %s\n", r1.experience);

    // free allocated memory
    free(resumeText);

    return 0;
}