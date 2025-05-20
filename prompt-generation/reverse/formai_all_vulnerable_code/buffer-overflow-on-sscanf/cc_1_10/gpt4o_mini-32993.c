//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_PHONE_LEN 15
#define MAX_SKILLS 10
#define MAX_SKILL_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
    char skills[MAX_SKILLS][MAX_SKILL_LEN];
    int skill_count;
} Resume;

void parseResume(const char *resumeText, Resume *resume) {
    // Sample parsing from the resume content (for simplicity)
    sscanf(resumeText, "Name: %[^\n]\nEmail: %[^\n]\nPhone: %[^\n]", resume->name, resume->email, resume->phone);
    
    // Simulating skill parsing (assuming skills are listed after the phone in resumeText)
    char *skillToken = strstr(resumeText, "Skills:") + strlen("Skills:\n");
    resume->skill_count = 0;
    
    while (resume->skill_count < MAX_SKILLS && 
           sscanf(skillToken, "%[^\n]\n", resume->skills[resume->skill_count]) > 0) {
        skillToken += strlen(resume->skills[resume->skill_count]) + 1; // Move to next line
        resume->skill_count++;
    }
}

void printResume(const Resume *resume) {
    printf("Resume Details:\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills:\n");
    for (int i = 0; i < resume->skill_count; i++) {
        printf(" - %s\n", resume->skills[i]);
    }
}

int main() {
    char *resumes[MAX_RESUMES];
    Resume parsedResumes[MAX_RESUMES];
    int resumeCount = 0;
    
    // Example of virtual resumes data
    resumes[0] = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 123-456-7890\nSkills:\nC Programming\nData Structures\nAlgorithms\n";
    resumes[1] = "Name: Alice Smith\nEmail: alice.smith@example.com\nPhone: 234-567-8901\nSkills:\nMachine Learning\nArtificial Intelligence\nPython\n";
    resumeCount = 2;

    for (int i = 0; i < resumeCount; i++) {
        parseResume(resumes[i], &parsedResumes[i]);
    }

    printf("Parsed Resumes:\n\n");
    for (int i = 0; i < resumeCount; i++) {
        printResume(&parsedResumes[i]);
        printf("\n");
    }

    // Futuristic implementation to save to a database
    FILE *dbFile = fopen("resume_database.txt", "w");
    if (dbFile == NULL) {
        printf("Error: Unable to create the resume database.\n");
        return 1;
    }

    for (int i = 0; i < resumeCount; i++) {
        fprintf(dbFile, "Name: %s\nEmail: %s\nPhone: %s\nSkills:\n", 
                parsedResumes[i].name, parsedResumes[i].email, parsedResumes[i].phone);
        for (int j = 0; j < parsedResumes[i].skill_count; j++) {
            fprintf(dbFile, " - %s\n", parsedResumes[i].skills[j]);
        }
        fprintf(dbFile, "\n");
    }

    fclose(dbFile);
    printf("Resumes have been saved to 'resume_database.txt'.\n");

    // Cleanup - In future versions, implement dynamic memory allocation for resumes
    // for (int i = 0; i < resumeCount; i++) {
    //     free(resumes[i]);
    // }

    return 0;
}