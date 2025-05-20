//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 1000

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char skills[200];
    int experience;
} Resume;

void initializeResumes(Resume resumes[], int *count);
void addResume(Resume resumes[], int *count);
void parseResume(const char *data, Resume *resume);
void displayResumes(const Resume resumes[], int count);
void searchBySkill(const Resume resumes[], int count, const char *skill);
void displayMenu();
int getChoice();

int main() {
    Resume resumes[MAX_RESUMES];
    int count = 0;
    initializeResumes(resumes, &count);

    int choice;
    while (1) {
        displayMenu();
        choice = getChoice();

        switch (choice) {
            case 1:
                addResume(resumes, &count);
                break;
            case 2:
                displayResumes(resumes, count);
                break;
            case 3: {
                char skill[100];
                printf("Enter skill to search: ");
                scanf("%s", skill);
                searchBySkill(resumes, count, skill);
                break;
            }
            case 4:
                printf("Exiting the Resume Parser. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void initializeResumes(Resume resumes[], int *count) {
    *count = 0;
}

void addResume(Resume resumes[], int *count) {
    if (*count >= MAX_RESUMES) {
        printf("Cannot add more resumes, limit reached!\n");
        return;
    }

    char data[MAX_LENGTH];
    
    printf("Enter name: ");
    scanf(" %[^\n]", resumes[*count].name);
    printf("Enter email: ");
    scanf(" %[^\n]", resumes[*count].email);
    printf("Enter phone: ");
    scanf(" %[^\n]", resumes[*count].phone);
    printf("Enter skills (comma separated): ");
    scanf(" %[^\n]", resumes[*count].skills);
    printf("Enter years of experience: ");
    scanf("%d", &resumes[*count].experience);

    (*count)++;
    printf("Resume added successfully!\n");
}

void parseResume(const char *data, Resume *resume) {
    // Dummy implementation, real parsing would be more complex
    sscanf(data, "%[^,],%[^,],%[^,],%[^,],%d",
           resume->name, resume->email, resume->phone, resume->skills,
           &resume->experience);
}

void displayResumes(const Resume resumes[], int count) {
    if (count == 0) {
        printf("No resumes to display.\n");
        return;
    }

    printf("\nDisplaying All Resumes:\n");
    for (int i = 0; i < count; i++) {
        printf("Resume %d:\n", i + 1);
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Phone: %s\n", resumes[i].phone);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Experience: %d years\n\n", resumes[i].experience);
    }
}

void searchBySkill(const Resume resumes[], int count, const char *skill) {
    printf("\nSearching for resumes with skill: %s\n", skill);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(resumes[i].skills, skill) != NULL) {
            printf("Match found in Resume %d:\n", i + 1);
            printf("Name: %s\n", resumes[i].name);
            printf("Email: %s\n", resumes[i].email);
            printf("Phone: %s\n", resumes[i].phone);
            printf("Skills: %s\n", resumes[i].skills);
            printf("Experience: %d years\n\n", resumes[i].experience);
            found = 1;
        }
    }

    if (!found) {
        printf("No resumes found with skill: %s\n", skill);
    }
}

void displayMenu() {
    printf("\n=== Resume Parser Menu ===\n");
    printf("1. Add Resume\n");
    printf("2. Display Resumes\n");
    printf("3. Search by Skill\n");
    printf("4. Exit\n");
}

int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}