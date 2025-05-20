//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256
#define MAX_EDUCATION 5
#define MAX_EXPERIENCE 5

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char education[MAX_EDUCATION][MAX_LENGTH];
    int edu_count;
    char experience[MAX_EXPERIENCE][MAX_LENGTH];
    int exp_count;
} Resume;

int parse_resume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return -1;
    }

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 5, "%[^\n]", resume->name);
        } else if (strncmp(line, "Email:", 6) == 0) {
            sscanf(line + 6, "%[^\n]", resume->email);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            sscanf(line + 6, "%[^\n]", resume->phone);
        } else if (strncmp(line, "Education:", 11) == 0) {
            if (resume->edu_count < MAX_EDUCATION) {
                sscanf(line + 11, "%[^\n]", resume->education[resume->edu_count]);
                resume->edu_count++;
            }
        } else if (strncmp(line, "Experience:", 11) == 0) {
            if (resume->exp_count < MAX_EXPERIENCE) {
                sscanf(line + 11, "%[^\n]", resume->experience[resume->exp_count]);
                resume->exp_count++;
            }
        }
    }

    fclose(file);
    return 0;
}

void display_resume(const Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education:\n");
    for (int i = 0; i < resume->edu_count; i++) {
        printf(" - %s\n", resume->education[i]);
    }
    printf("Experience:\n");
    for (int i = 0; i < resume->exp_count; i++) {
        printf(" - %s\n", resume->experience[i]);
    }
}

int main() {
    Resume resume;
    memset(&resume, 0, sizeof(Resume)); // Initialize all fields to zero

    const char *filename = "resume.txt";
    if (parse_resume(filename, &resume) == -1) {
        return EXIT_FAILURE;
    }

    display_resume(&resume);
    return EXIT_SUCCESS;
}