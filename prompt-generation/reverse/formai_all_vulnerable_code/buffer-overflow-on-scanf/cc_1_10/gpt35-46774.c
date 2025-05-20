//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100   // Maximum number of resumes allowed

typedef struct {
    char name[50];
    char email[50];
    char skills[200];
    char education[100];
} Resume;   // Resume struct to store information

int main() {
    Resume resumes[MAX_RESUMES];   // Array of resumes
    int numResumes = 0;   // Number of resumes currently stored
    char searchName[50];   // Name of applicant being searched
    int resumeIndex = -1;   // Index of found resume (-1 = not found)

    while (1) {   // Loop until user chooses to exit
        int choice;
        printf("\nResume Parsing System\n");
        printf("1. Add new resume\n");
        printf("2. View all resumes\n");
        printf("3. Search for a resume\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();   // Clear buffer

        switch (choice) {
            case 1: {
                Resume newResume;
                printf("\nEnter candidate name: ");
                fgets(newResume.name, 50, stdin);
                newResume.name[strcspn(newResume.name, "\n")] = '\0';  // Remove newline from string
                printf("Enter candidate email: ");
                fgets(newResume.email, 50, stdin);
                newResume.email[strcspn(newResume.email, "\n")] = '\0';
                printf("Enter candidate skills (separated by commas): ");
                fgets(newResume.skills, 200, stdin);
                newResume.skills[strcspn(newResume.skills, "\n")] = '\0';
                printf("Enter candidate education: ");
                fgets(newResume.education, 100, stdin);
                newResume.education[strcspn(newResume.education, "\n")] = '\0';

                resumes[numResumes] = newResume;
                numResumes++;
                printf("\nResume added!\n");
                break;
            }
            case 2: {
                printf("\nAll Resumes:\n");
                for (int i = 0; i < numResumes; i++) {
                    printf("Name: %s\n", resumes[i].name);
                    printf("Email: %s\n", resumes[i].email);
                    printf("Skills: %s\n", resumes[i].skills);
                    printf("Education: %s\n", resumes[i].education);
                    printf("\n");
                }
                break;
            }
            case 3: {
                printf("\nEnter name of applicant: ");
                fgets(searchName, 50, stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                for (int i = 0; i < numResumes; i++) {
                    if (strcmp(resumes[i].name, searchName) == 0) {
                        resumeIndex = i;
                        break;
                    }
                }

                if (resumeIndex == -1) {
                    printf("\nResume not found.\n");
                } else {
                    printf("\nResume found!\n");
                    printf("Name: %s\n", resumes[resumeIndex].name);
                    printf("Email: %s\n", resumes[resumeIndex].email);
                    printf("Skills: %s\n", resumes[resumeIndex].skills);
                    printf("Education: %s\n", resumes[resumeIndex].education);
                }
                break;
            }
            case 4: {
                printf("\nExiting program...\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice.\n");
                break;
            }
        }
    }

    return 0;
}