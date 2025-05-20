//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EXPERIENCE_LENGTH 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
} Resume;

void parseResume(const char* filePath, Resume* resume) {
    FILE* file = fopen(filePath, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^\n]", resume->name);
        } else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %[^\n]", resume->email);
        } else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %[^\n]", resume->phone);
        } else if (strstr(line, "Experience:")) {
            sscanf(line, "Experience: %[^\n]", resume->experience);
        }
    }

    fclose(file);
}

void displayResume(const Resume* resume) {
    printf("Resume Details:\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Experience: %s\n", resume->experience);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume_file.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Resume resume;
    memset(&resume, 0, sizeof(resume));

    parseResume(argv[1], &resume);
    displayResume(&resume);

    return EXIT_SUCCESS;
}