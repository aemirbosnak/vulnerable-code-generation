//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 500
#define NAME_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char skills[MAX_LENGTH];
    char experience[MAX_LENGTH];
    char education[MAX_LENGTH];
} Resume;

void initResume(Resume* resume) {
    strcpy(resume->name, "");
    strcpy(resume->email, "");
    strcpy(resume->phone, "");
    strcpy(resume->skills, "");
    strcpy(resume->experience, "");
    strcpy(resume->education, "");
}

void parseResume(const char* filePath, Resume* resume) {
    FILE* file = fopen(filePath, "r");
    if (!file) {
        printf("Could not open file: %s\n", filePath);
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^\n]", resume->name);
        } else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %[^\n]", resume->email);
        } else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %[^\n]", resume->phone);
        } else if (strstr(line, "Skills:")) {
            sscanf(line, "Skills: %[^\n]", resume->skills);
        } else if (strstr(line, "Experience:")) {
            sscanf(line, "Experience: %[^\n]", resume->experience);
        } else if (strstr(line, "Education:")) {
            sscanf(line, "Education: %[^\n]", resume->education);
        }
    }

    fclose(file);
}

void displayResume(const Resume* resume) {
    printf("\n--- Resume ---\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
    printf("----------------\n");
}

void searchResumes(Resume resumes[], int count, const char* keyword) {
    printf("\n--- Search Results for '%s' ---\n", keyword);
    for (int i = 0; i < count; i++) {
        if (strstr(resumes[i].skills, keyword) || strstr(resumes[i].experience, keyword)) {
            displayResume(&resumes[i]);
        }
    }
}

int main() {
    Resume resumes[MAX_RESUMES];
    int count = 0;

    while (count < MAX_RESUMES) {
        char filePath[MAX_LENGTH];
        printf("Enter the path to the resume file (or 'quit' to exit): ");
        scanf("%s", filePath);

        if (strcmp(filePath, "quit") == 0) {
            break;
        }

        initResume(&resumes[count]);
        parseResume(filePath, &resumes[count]);
        displayResume(&resumes[count]);
        count++;
    }

    char keyword[MAX_LENGTH];
    printf("Enter a keyword to search for (or 'quit' to exit): ");
    while (scanf("%s", keyword) && strcmp(keyword, "quit") != 0) {
        searchResumes(resumes, count, keyword);
        printf("Enter a keyword to search for (or 'quit' to exit): ");
    }

    return 0;
}