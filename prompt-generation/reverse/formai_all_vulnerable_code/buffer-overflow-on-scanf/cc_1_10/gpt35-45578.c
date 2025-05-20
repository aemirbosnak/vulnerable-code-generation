//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

struct Resume {
    char name[BUFFER_SIZE];
    char email[BUFFER_SIZE];
    char phone[BUFFER_SIZE];
    char skills[BUFFER_SIZE];
    char education[BUFFER_SIZE];
    char work_exp[BUFFER_SIZE];
};

void parseResume(struct Resume *resume, char *fileName);
void printResume(struct Resume *resume);

int main() {
    struct Resume myResume;
    char fileName[BUFFER_SIZE];

    printf("Enter the name of the resume file: ");
    scanf("%s", fileName);

    parseResume(&myResume, fileName);
    printResume(&myResume);

    return 0;
}

void parseResume(struct Resume *resume, char *fileName) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t len = 0;
    ssize_t read;

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while ((read = getline(&buffer, &len, file)) != -1) {
        if (strstr(buffer, "Name:")) {
            strcpy(resume->name, buffer + strlen("Name:"));
            resume->name[strcspn(resume->name, "\n")] = 0;  // remove newline character
        } else if (strstr(buffer, "Email:")) {
            strcpy(resume->email, buffer + strlen("Email:"));
            resume->email[strcspn(resume->email, "\n")] = 0;
        } else if (strstr(buffer, "Phone:")) {
            strcpy(resume->phone, buffer + strlen("Phone:"));
            resume->phone[strcspn(resume->phone, "\n")] = 0;
        } else if (strstr(buffer, "Skills:")) {
            strcpy(resume->skills, buffer + strlen("Skills:"));
            resume->skills[strcspn(resume->skills, "\n")] = 0;
        } else if (strstr(buffer, "Education:")) {
            strcpy(resume->education, buffer + strlen("Education:"));
            resume->education[strcspn(resume->education, "\n")] = 0;
        } else if (strstr(buffer, "Work Experience:")) {
            strcpy(resume->work_exp, buffer + strlen("Work Experience:"));
            resume->work_exp[strcspn(resume->work_exp, "\n")] = 0;
        }
    }

    fclose(file);
}

void printResume(struct Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Work Experience: %s\n", resume->work_exp);
}