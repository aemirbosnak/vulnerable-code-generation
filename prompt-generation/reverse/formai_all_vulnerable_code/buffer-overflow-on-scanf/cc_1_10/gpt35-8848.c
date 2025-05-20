//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLen 200
#define MAX_NUM_RESUMES 20

typedef struct {
    char name[MaxLen];
    char email[MaxLen];
    char phone[MaxLen];
    char education[MaxLen];
    char experience[MaxLen];
} Resume;

Resume resumes[MAX_NUM_RESUMES];
int num_resumes = 0;

void parse_resume(char* filename);
void print_resume(int index);

int main() {
    char filename[MaxLen];
    printf("Enter resume filename: ");
    scanf("%s", filename);
    parse_resume(filename);
    printf("\n");
    int i;
    for (i = 0; i < num_resumes; i++) {
        printf("Resume #%d:\n", i + 1);
        print_resume(i);
        printf("\n");
    }
    return 0;
}

void parse_resume(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(0);
    }
    char line[MaxLen];
    char* key;
    char* val;
    int state = 0;
    Resume resume;
    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '\n') {
            if (state > 0) {
                resumes[num_resumes++] = resume;
                resume = (Resume) {0};
            }
            state = 0;
            continue;
        }
        switch (state) {
            case 0:
                key = strtok(line, ":");
                val = strtok(NULL, "\n");
                strcpy(resume.name, key);
                strcpy(resume.email, val);
                break;
            case 1:
                strcpy(resume.phone, line);
                break;
            case 2:
                strcpy(resume.education, line);
                break;
            case 3:
                strcpy(resume.experience, line);
                break;
            default:
                break;
        }
        state++;
    }
    if (state > 0) {
        resumes[num_resumes++] = resume;
    }
    fclose(fp);
}

void print_resume(int index) {
    Resume resume = resumes[index];
    printf("- Name:     %s\n", resume.name);
    printf("  Email:    %s\n", resume.email);
    printf("  Phone:    %s\n", resume.phone);
    printf("  Education:%s\n", resume.education);
    printf("  Experience:%s\n", resume.experience);
}