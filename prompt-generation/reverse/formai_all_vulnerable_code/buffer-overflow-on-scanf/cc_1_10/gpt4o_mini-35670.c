//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_SKILL_LEN 30
#define MAX_SKILLS 10

typedef struct Resume {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char skills[MAX_SKILLS][MAX_SKILL_LEN];
    int skill_count;
} Resume;

void neon_lights(const char *msg) {
    printf("\033[1;32m%s\033[0m\n", msg); // Print in neon green
}

void cyberpunk_intro() {
    neon_lights("Initializing the Cyberpunk Resume Parsing System...");
    neon_lights("A data-drenched metropolis where dreams are woven through wires.");
    neon_lights("Parsing resumes in the digital void, connecting the dots of ambition.");
}

void capture_resume(Resume *resume) {
    printf("Enter Candidate's Name: ");
    fgets(resume->name, MAX_NAME_LEN, stdin);
    resume->name[strcspn(resume->name, "\n")] = 0; // Remove trailing newline

    printf("Enter Candidate's Email: ");
    fgets(resume->email, MAX_EMAIL_LEN, stdin);
    resume->email[strcspn(resume->email, "\n")] = 0; // Remove trailing newline

    printf("Enter number of skills (max %d): ", MAX_SKILLS);
    scanf("%d", &resume->skill_count);
    getchar(); // Consume newline

    for (int i = 0; i < resume->skill_count; i++) {
        printf("Enter skill %d: ", i + 1);
        fgets(resume->skills[i], MAX_SKILL_LEN, stdin);
        resume->skills[i][strcspn(resume->skills[i], "\n")] = 0; // Remove trailing newline
    }

    neon_lights("Resume captured in the cyber data banks.");
}

void display_resume(const Resume *resume) {
    printf("\n----- Resume -----\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Skills: ");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("%s%s", resume->skills[i], (i < resume->skill_count - 1) ? ", " : "");
    }
    printf("\n------------------\n");
}

void search_skills(Resume resumes[], int count, const char *skill) {
    neon_lights("Searching for candidates with desired skill...");

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < resumes[i].skill_count; j++) {
            if (strcmp(resumes[i].skills[j], skill) == 0) {
                printf("Found match!\n");
                printf("Candidate: %s\n", resumes[i].name);
                printf("Email: %s\n", resumes[i].email);
            }
        }
    }
}

int main() {
    Resume resumes[MAX_RESUMES];
    int resume_count = 0;
    int choice;
    char search_skill[MAX_SKILL_LEN];

    cyberpunk_intro();

    while (1) {
        printf("1. Capture Resume\n2. Display Resumes\n3. Search by Skill\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                if (resume_count < MAX_RESUMES) {
                    capture_resume(&resumes[resume_count]);
                    resume_count++;
                } else {
                    neon_lights("Resume storage is full, delete some to continue.");
                }
                break;
            case 2:
                printf("\n--- Displaying All Resumes ---\n");
                for (int i = 0; i < resume_count; i++) {
                    display_resume(&resumes[i]);
                }
                break;
            case 3:
                printf("Enter skill to search: ");
                fgets(search_skill, MAX_SKILL_LEN, stdin);
                search_skill[strcspn(search_skill, "\n")] = 0; // Remove trailing newline

                search_skills(resumes, resume_count, search_skill);
                break;
            case 4:
                neon_lights("Exiting the system, navigating the neon-lit paths...");
                exit(0);
            default:
                neon_lights("Invalid option, please try again.");
        }
    }

    return 0;
}