//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_EXPERIENCE 10
#define MAX_SKILLS 20

typedef struct {
    char *company;
    char *title;
    char *start_date;
    char *end_date;
} experience;

typedef struct {
    char *name;
    int years_of_experience;
    char *highest_degree_earned;
    char *phone_number;
    char *email;
    char *address_line1;
    char *address_line2;
    char *city;
    char *state;
    char *zip;
    experience experience_list[MAX_EXPERIENCE];
    char *skill_list[MAX_SKILLS];
} resume;

void parse_resume(char *path, resume *r) {
    // Code to parse resume file at given path and populate resume struct
    printf("Parsing resume at path: %s\n", path);
}

void display_resume(resume *r) {
    printf("Resume of %s\n", r->name);
    printf("------------------------------------\n");
    printf("Years of experience: %d\n", r->years_of_experience);
    printf("Highest degree earned: %s\n", r->highest_degree_earned);
    printf("Phone number: %s\n", r->phone_number);
    printf("Email: %s\n", r->email);
    printf("Address: %s, %s, %s, %s %s\n", r->address_line1, r->address_line2, r->city, r->state, r->zip);
    printf("------------------------------------\n");
    printf("Experience:\n");
    for (int i = 0; i < MAX_EXPERIENCE; i++) {
        if (r->experience_list[i].company != NULL) {
            printf("- %s, %s to %s\n", r->experience_list[i].title, r->experience_list[i].start_date, r->experience_list[i].end_date);
        }
    }
    printf("------------------------------------\n");
    printf("Skills:\n");
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (r->skill_list[i] != NULL) {
            printf("- %s\n", r->skill_list[i]);
        }
    }
}

int main() {
    resume resume_list[MAX_RESUMES];
    int num_resumes = 0;
    bool done = false;
    int choice;

    while (!done) {
        printf("\nEnter choice:\n");
        printf("1) Parse a resume\n");
        printf("2) Display all resumes\n");
        printf("3) Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char path[100];
                printf("\nEnter path to resume file: ");
                scanf("%s", path);
                parse_resume(path, &resume_list[num_resumes]);
                num_resumes++;
                break;
            }
            case 2: {
                for (int i = 0; i < num_resumes; i++) {
                    display_resume(&resume_list[i]);
                }
                break;
            }
            case 3: {
                done = true;
                break;
            }
            default: {
                printf("\nInvalid choice");
                break;
            }
        }
    }

    return 0;
}