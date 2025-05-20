//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_RESUMES 100
#define NAME_LENGTH 100
#define EMAIL_LENGTH 100
#define PHONE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char phone[PHONE_LENGTH];
    char skills[MAX_BUFFER];
    int experienceYears;
} Resume;

void parseResume(const char *data, Resume *resume) {
    // Assuming data is provided in a specific format
    sscanf(data, "Name: %[^\n]\nEmail: %[^\n]\nPhone: %[^\n]\nExperience: %d\nSkills: %[^\n]\n",
           resume->name, resume->email, resume->phone, &resume->experienceYears, resume->skills);
}

void displayResume(const Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Years of Experience: %d\n", resume->experienceYears);
    printf("Skills: %s\n", resume->skills);
    printf("------------------------\n");
}

void saveResumes(const Resume *resumes, int count) {
    FILE *file = fopen("resumes.txt", "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Name: %s\nEmail: %s\nPhone: %s\nExperience: %d\nSkills: %s\n\n",
                resumes[i].name, resumes[i].email, resumes[i].phone, resumes[i].experienceYears, resumes[i].skills);
    }

    fclose(file);
}

void loadResumes(Resume *resumes, int *count) {
    FILE *file = fopen("resumes.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_BUFFER];
    *count = 0;
    while (fgets(buffer, sizeof(buffer), file) && *count < MAX_RESUMES) {
        parseResume(buffer, &resumes[*count]);
        (*count)++;
    }

    fclose(file);
}

int main() {
    Resume resumes[MAX_RESUMES];
    int resumeCount = 0;
    char input[MAX_BUFFER];
    
    printf("Welcome to the Resume Parsing System!\n");

    char choice;
    do {
        printf("Options:\n");
        printf("1. Enter a new resume\n");
        printf("2. Display all resumes\n");
        printf("3. Save resumes to file\n");
        printf("4. Load resumes from file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        getchar(); // consume trailing newline

        switch (choice) {
            case '1':
                printf("Enter resume information:\n");
                printf("Name: ");
                fgets(input, NAME_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // remove newline
                strcpy(resumes[resumeCount].name, input);

                printf("Email: ");
                fgets(input, EMAIL_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;
                strcpy(resumes[resumeCount].email, input);

                printf("Phone: ");
                fgets(input, PHONE_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;
                strcpy(resumes[resumeCount].phone, input);

                printf("Years of Experience: ");
                scanf("%d", &resumes[resumeCount].experienceYears);
                getchar(); // consume trailing newline

                printf("Skills: ");
                fgets(resumes[resumeCount].skills, MAX_BUFFER, stdin);
                resumes[resumeCount].skills[strcspn(resumes[resumeCount].skills, "\n")] = 0;

                resumeCount++;
                printf("Resume added successfully!\n");
                break;

            case '2':
                printf("Displaying all resumes:\n");
                for (int i = 0; i < resumeCount; i++) {
                    displayResume(&resumes[i]);
                }
                break;

            case '3':
                saveResumes(resumes, resumeCount);
                printf("Resumes saved to file successfully!\n");
                break;

            case '4':
                loadResumes(resumes, &resumeCount);
                printf("Resumes loaded from file successfully!\n");
                break;

            case '5':
                printf("Exiting the system. Thank you!\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != '5');

    return 0;
}