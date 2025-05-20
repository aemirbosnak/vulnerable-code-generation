//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 50
#define MAX_SKILLS_LENGTH 200
#define MAX_EXPERIENCE_LENGTH 200

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char skills[MAX_SKILLS_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
} Resume;

Resume resumes[MAX_RESUMES];
int resume_count = 0;

void addResume() {
    if (resume_count >= MAX_RESUMES) {
        printf("Resume limit reached. Cannot add more resumes.\n");
        return;
    }

    Resume new_resume;
    new_resume.id = resume_count + 1;

    printf("Enter name: ");
    scanf(" %[^\n]s", new_resume.name);
    printf("Enter age: ");
    scanf("%d", &new_resume.age);
    printf("Enter skills (comma separated): ");
    scanf(" %[^\n]s", new_resume.skills);
    printf("Enter experience: ");
    scanf(" %[^\n]s", new_resume.experience);

    resumes[resume_count] = new_resume;
    resume_count++;
    printf("Resume added successfully with ID %d!\n", new_resume.id);
}

void displayResumes() {
    if (resume_count == 0) {
        printf("No resumes available to display.\n");
        return;
    }

    printf("\n--- Resumes ---\n");
    for (int i = 0; i < resume_count; i++) {
        printf("ID: %d\n", resumes[i].id);
        printf("Name: %s\n", resumes[i].name);
        printf("Age: %d\n", resumes[i].age);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Experience: %s\n\n", resumes[i].experience);
    }
}

void searchResume() {
    int search_id;
    printf("Enter the ID of the resume to search: ");
    scanf("%d", &search_id);

    if (search_id > 0 && search_id <= resume_count) {
        printf("\n--- Resume Details ---\n");
        printf("ID: %d\n", resumes[search_id - 1].id);
        printf("Name: %s\n", resumes[search_id - 1].name);
        printf("Age: %d\n", resumes[search_id - 1].age);
        printf("Skills: %s\n", resumes[search_id - 1].skills);
        printf("Experience: %s\n\n", resumes[search_id - 1].experience);
    } else {
        printf("No resume found with ID %d.\n", search_id);
    }
}

void saveResumesToFile() {
    FILE *file = fopen("resumes.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < resume_count; i++) {
        fprintf(file, "ID: %d\n", resumes[i].id);
        fprintf(file, "Name: %s\n", resumes[i].name);
        fprintf(file, "Age: %d\n", resumes[i].age);
        fprintf(file, "Skills: %s\n", resumes[i].skills);
        fprintf(file, "Experience: %s\n\n", resumes[i].experience);
    }

    fclose(file);
    printf("Resumes saved to file successfully.\n");
}

void loadResumesFromFile() {
    FILE *file = fopen("resumes.txt", "r");
    if (file == NULL) {
        printf("No saved resumes found.\n");
        return;
    }

    while (fscanf(file, "ID: %d\n", &resumes[resume_count].id) != EOF) {
        fscanf(file, "Name: %[^\n]s\n", resumes[resume_count].name);
        fscanf(file, "Age: %d\n", &resumes[resume_count].age);
        fscanf(file, "Skills: %[^\n]s\n", resumes[resume_count].skills);
        fscanf(file, "Experience: %[^\n]s\n\n", resumes[resume_count].experience);
        resume_count++;
    }

    fclose(file);
    printf("Resumes loaded from file successfully.\n");
}

int main() {
    int choice;
    loadResumesFromFile();

    do {
        printf("\n--- Resume Parsing System ---\n");
        printf("1. Add Resume\n");
        printf("2. Display Resumes\n");
        printf("3. Search Resume by ID\n");
        printf("4. Save Resumes to File\n");
        printf("5. Load Resumes from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addResume();
                break;
            case 2:
                displayResumes();
                break;
            case 3:
                searchResume();
                break;
            case 4:
                saveResumesToFile();
                break;
            case 5:
                loadResumesFromFile();
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}