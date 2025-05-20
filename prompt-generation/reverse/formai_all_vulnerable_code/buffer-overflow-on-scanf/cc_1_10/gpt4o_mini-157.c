//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_SKILLS 5
#define MAX_EXPERIENCE 3
#define MAX_EDUCATION 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS][MAX_NAME_LENGTH];
    int skill_count;
    char experience[MAX_EXPERIENCE][MAX_NAME_LENGTH];
    int experience_count;
    char education[MAX_EDUCATION][MAX_NAME_LENGTH];
    int education_count;
} Resume;

void parse_resume(Resume* r) {
    printf("Enter name: ");
    fgets(r->name, MAX_NAME_LENGTH, stdin);
    r->name[strcspn(r->name, "\n")] = '\0'; // Remove newline

    printf("Enter email: ");
    fgets(r->email, MAX_EMAIL_LENGTH, stdin);
    r->email[strcspn(r->email, "\n")] = '\0'; // Remove newline

    printf("Enter phone: ");
    fgets(r->phone, MAX_PHONE_LENGTH, stdin);
    r->phone[strcspn(r->phone, "\n")] = '\0'; // Remove newline

    printf("Enter number of skills: ");
    scanf("%d", &r->skill_count);
    getchar(); // Consume newline character
    for (int i = 0; i < r->skill_count; i++) {
        printf("Enter skill %d: ", i + 1);
        fgets(r->skills[i], MAX_NAME_LENGTH, stdin);
        r->skills[i][strcspn(r->skills[i], "\n")] = '\0'; // Remove newline
    }

    printf("Enter number of experiences: ");
    scanf("%d", &r->experience_count);
    getchar(); // Consume newline character
    for (int i = 0; i < r->experience_count; i++) {
        printf("Enter experience %d: ", i + 1);
        fgets(r->experience[i], MAX_NAME_LENGTH, stdin);
        r->experience[i][strcspn(r->experience[i], "\n")] = '\0'; // Remove newline
    }

    printf("Enter number of education entries: ");
    scanf("%d", &r->education_count);
    getchar(); // Consume newline character
    for (int i = 0; i < r->education_count; i++) {
        printf("Enter education %d: ", i + 1);
        fgets(r->education[i], MAX_NAME_LENGTH, stdin);
        r->education[i][strcspn(r->education[i], "\n")] = '\0'; // Remove newline
    }
}

void display_resume(const Resume* r) {
    printf("\n--- Resume ---\n");
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);

    printf("Skills: ");
    for (int i = 0; i < r->skill_count; i++) {
        printf("\n- %s", r->skills[i]);
    }

    printf("\nExperience: ");
    for (int i = 0; i < r->experience_count; i++) {
        printf("\n- %s", r->experience[i]);
    }

    printf("\nEducation: ");
    for (int i = 0; i < r->education_count; i++) {
        printf("\n- %s", r->education[i]);
    }
    printf("\n");
}

int main() {
    Resume my_resume;
    my_resume.skill_count = 0;
    my_resume.experience_count = 0;
    my_resume.education_count = 0;

    parse_resume(&my_resume);
    display_resume(&my_resume);

    return 0;
}