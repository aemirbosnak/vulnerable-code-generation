//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256
#define MAX_SKILLS 10
#define MAX_EXPERIENCE 5

typedef struct {
    char name[MAX_LEN];
    char skills[MAX_SKILLS][MAX_LEN];
    int skill_count;
    char experience[MAX_EXPERIENCE][MAX_LEN];
    int experience_count;
} Resume;

void extract_data(Resume *resume) {
    // Lovingly extract the details from the resume
    printf("Please enter your name: ");
    fgets(resume->name, MAX_LEN, stdin);
    resume->name[strcspn(resume->name, "\n")] = 0; // Remove newline char

    printf("How many skills do you want to share? (Max %d): ", MAX_SKILLS);
    scanf("%d", &resume->skill_count);
    getchar(); // consume newline

    for (int i = 0; i < resume->skill_count; i++) {
        printf("Enter skill %d: ", i + 1);
        fgets(resume->skills[i], MAX_LEN, stdin);
        resume->skills[i][strcspn(resume->skills[i], "\n")] = 0; // Remove newline char
    }

    printf("How many past experiences do you wish to woo us with? (Max %d): ", MAX_EXPERIENCE);
    scanf("%d", &resume->experience_count);
    getchar(); // consume newline

    for (int i = 0; i < resume->experience_count; i++) {
        printf("Enter experience %d: ", i + 1);
        fgets(resume->experience[i], MAX_LEN, stdin);
        resume->experience[i][strcspn(resume->experience[i], "\n")] = 0; // Remove newline char
    }
}

void display_resume(const Resume *resume) {
    // Dashing display of the romantic resume
    printf("\n--- Love Letter of Qualifications ---\n");
    printf("Name: %s\n", resume->name);
    
    printf("Skills that make my heart flutter:\n");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("  - %s\n", resume->skills[i]);
    }
    
    printf("Experiences that sing sweet songs of achievement:\n");
    for (int i = 0; i < resume->experience_count; i++) {
        printf("  - %s\n", resume->experience[i]);
    }
    
    printf("----------------------------------------\n");
}

int main() {
    Resume my_resume;
    my_resume.skill_count = 0;
    my_resume.experience_count = 0;

    extract_data(&my_resume);
    display_resume(&my_resume);

    return 0;
}