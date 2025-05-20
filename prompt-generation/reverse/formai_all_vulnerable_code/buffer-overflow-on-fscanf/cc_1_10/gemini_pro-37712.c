//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of skills and experiences
#define MAX_SKILLS 10
#define MAX_EXPERIENCES 10

// Define the structure of a skill
typedef struct skill {
    char* name;
    int level;
} skill_t;

// Define the structure of an experience
typedef struct experience {
    char* company;
    char* position;
    int years;
} experience_t;

// Define the structure of a resume
typedef struct resume {
    char* name;
    char* email;
    char* phone;
    skill_t skills[MAX_SKILLS];
    int num_skills;
    experience_t experiences[MAX_EXPERIENCES];
    int num_experiences;
} resume_t;

// Create a new resume
resume_t* create_resume() {
    resume_t* resume = (resume_t*)malloc(sizeof(resume_t));
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->num_skills = 0;
    resume->num_experiences = 0;
    return resume;
}

// Parse a resume from a file
resume_t* parse_resume(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    resume_t* resume = create_resume();

    // Parse the name
    char name[100];
    fscanf(file, "%s", name);
    resume->name = strdup(name);

    // Parse the email
    char email[100];
    fscanf(file, "%s", email);
    resume->email = strdup(email);

    // Parse the phone
    char phone[100];
    fscanf(file, "%s", phone);
    resume->phone = strdup(phone);

    // Parse the skills
    int num_skills;
    fscanf(file, "%d", &num_skills);
    for (int i = 0; i < num_skills; i++) {
        char skill_name[100];
        int skill_level;
        fscanf(file, "%s %d", skill_name, &skill_level);
        skill_t skill;
        skill.name = strdup(skill_name);
        skill.level = skill_level;
        resume->skills[i] = skill;
        resume->num_skills++;
    }

    // Parse the experiences
    int num_experiences;
    fscanf(file, "%d", &num_experiences);
    for (int i = 0; i < num_experiences; i++) {
        char company[100];
        char position[100];
        int years;
        fscanf(file, "%s %s %d", company, position, &years);
        experience_t experience;
        experience.company = strdup(company);
        experience.position = strdup(position);
        experience.years = years;
        resume->experiences[i] = experience;
        resume->num_experiences++;
    }

    fclose(file);

    return resume;
}

// Print a resume
void print_resume(resume_t* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);

    printf("Skills:\n");
    for (int i = 0; i < resume->num_skills; i++) {
        printf("  %s: %d\n", resume->skills[i].name, resume->skills[i].level);
    }

    printf("Experiences:\n");
    for (int i = 0; i < resume->num_experiences; i++) {
        printf("  %s, %s, %d years\n", resume->experiences[i].company, resume->experiences[i].position, resume->experiences[i].years);
    }
}

// Free the memory allocated for a resume
void free_resume(resume_t* resume) {
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    for (int i = 0; i < resume->num_skills; i++) {
        free(resume->skills[i].name);
    }
    for (int i = 0; i < resume->num_experiences; i++) {
        free(resume->experiences[i].company);
        free(resume->experiences[i].position);
    }
    free(resume);
}

// Main function
int main() {
    // Parse a resume from a file
    resume_t* resume = parse_resume("resume.txt");

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free_resume(resume);

    return 0;
}