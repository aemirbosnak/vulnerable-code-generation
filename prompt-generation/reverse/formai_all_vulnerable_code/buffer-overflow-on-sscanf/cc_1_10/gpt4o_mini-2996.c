//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 1024

typedef struct {
    char name[100];
    char email[100];
    char phone[15];
    char skills[5][50];  // Assume maximum 5 skills
    int skill_count;
} Resume;

Resume resumes[MAX_RESUMES];
int resume_count = 0;

void parse_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n') continue; // skip empty lines

        Resume resume;
        sscanf(line, "Name: %[^\n]", resume.name);
        fgets(line, sizeof(line), file);
        sscanf(line, "Email: %[^\n]", resume.email);
        fgets(line, sizeof(line), file);
        sscanf(line, "Phone: %[^\n]", resume.phone);
        
        resume.skill_count = 0;
        while (resume.skill_count < 5 && fgets(line, sizeof(line), file)) {
            if (strlen(line) < 2) break; // Empty line indicates end of skills
            sscanf(line, "Skill: %[^\n]", resume.skills[resume.skill_count++]);
        }

        resumes[resume_count++] = resume;
    }

    fclose(file);
}

void display_resumes() {
    for (int i = 0; i < resume_count; i++) {
        printf("Resume #%d\n", i + 1);
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Phone: %s\n", resumes[i].phone);
        printf("Skills:\n");
        for (int j = 0; j < resumes[i].skill_count; j++) {
            printf("  - %s\n", resumes[i].skills[j]);
        }
        printf("-----------\n");
    }
}

void save_to_file(const char *output_filename) {
    FILE *file = fopen(output_filename, "w");
    if (!file) {
        perror("Could not open output file");
        return;
    }
    for (int i = 0; i < resume_count; i++) {
        fprintf(file, "Name: %s\n", resumes[i].name);
        fprintf(file, "Email: %s\n", resumes[i].email);
        fprintf(file, "Phone: %s\n", resumes[i].phone);
        for (int j = 0; j < resumes[i].skill_count; j++) {
            fprintf(file, "Skill: %s\n", resumes[i].skills[j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    const char *filename = "resumes.txt";
    const char *output_filename = "parsed_resumes.txt";

    parse_file(filename);
    display_resumes();
    save_to_file(output_filename);

    printf("Resumes have been parsed and saved to %s\n", output_filename);
    return 0;
}