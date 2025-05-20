//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#define MAX_RESUMES 50

struct resume {
    char name[30];
    int age;
    char university[50];
    float gpa;
    char skills[100];
};

void print_resumes(struct resume[], int);
float calculate_gpa(char[]);

int main() {
    printf("Welcome to the Resume Parsing System\n\n");

    // Initialize resumes array
    struct resume resumes[MAX_RESUMES];
    int num_resumes = 0;

    // Get user input
    char input;
    do {
        printf("Enter new resume? (y/n): ");
        scanf("%c", &input);

        if (input == 'y') {
            // Prompt for resume details
            struct resume new_resume;
            printf("Enter name: ");
            scanf("%s", new_resume.name);
            printf("Enter age: ");
            scanf("%d", &new_resume.age);
            printf("Enter university: ");
            scanf("%s", new_resume.university);
            printf("Enter GPA: ");
            scanf("%f", &new_resume.gpa);
            printf("Enter skills: ");
            scanf("%s", new_resume.skills);

            // Add new resume to array
            resumes[num_resumes] = new_resume;
            num_resumes++;
        }
    } while (input == 'y');

    // Print all resumes
    printf("\nAll resumes:\n");
    print_resumes(resumes, num_resumes);

    return 0;
}

// Function to print all resumes in the array
void print_resumes(struct resume resumes[], int num_resumes) {
    for (int i = 0; i < num_resumes; i++) {
        printf("\nResume %d:\n", i+1);
        printf("Name: %s\n", resumes[i].name);
        printf("Age: %d\n", resumes[i].age);
        printf("University: %s\n", resumes[i].university);
        printf("GPA: %.2f\n", resumes[i].gpa);
        printf("Skills: %s\n", resumes[i].skills);
    }
}

// Function to calculate GPA on a 4.0 scale
float calculate_gpa(char transcript[]) {
    float total_grade_points = 0.0;
    int total_credits = 0;

    // Parse transcript to get grade points and credits for each course
    // ...

    float gpa = total_grade_points / total_credits * 4.0;
    return gpa;
}