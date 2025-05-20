//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A resume structure to hold the candidate's information
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[100];
    char experience[100];
    char education[100];
} Resume;

// A function to read a resume from a file
Resume read_resume(char *filename) {
    Resume resume;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fscanf(file, "%s %s %s %s %s %s", resume.name, resume.email, resume.phone, resume.skills, resume.experience, resume.education);
    fclose(file);
    return resume;
}

// A function to print a resume
void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
}

// A function to match a resume to a job description
int match_resume(Resume resume, char *job_description) {
    int score = 0;
    char *skills_required = strtok(job_description, ",");
    while (skills_required != NULL) {
        if (strstr(resume.skills, skills_required) != NULL) {
            score++;
        }
        skills_required = strtok(NULL, ",");
    }
    return score;
}

int main() {
    // Read the resume from a file
    Resume resume = read_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Match the resume to a job description
    int score = match_resume(resume, "C programming, Java programming, Python programming");

    // Print the score
    printf("Score: %d\n", score);

    return 0;
}