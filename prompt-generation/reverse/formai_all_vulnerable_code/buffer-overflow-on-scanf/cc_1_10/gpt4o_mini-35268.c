//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 1024

typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char education[100];
    char experience[200];
} Resume;

Resume resumes[MAX_RESUMES];
int resumeCount = 0;

void parseResume(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        printf("ERROR: Cannot open file %s!\n", filePath);
        return;
    }
    char buffer[MAX_LENGTH];

    printf("Parsing resume from: %s\n", filePath);
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, "Name:")) {
            sscanf(buffer, "Name: %49[^\n]", resumes[resumeCount].name);
        } else if (strstr(buffer, "Email:")) {
            sscanf(buffer, "Email: %49[^\n]", resumes[resumeCount].email);
        } else if (strstr(buffer, "Phone:")) {
            sscanf(buffer, "Phone: %14[^\n]", resumes[resumeCount].phone);
        } else if (strstr(buffer, "Education:")) {
            sscanf(buffer, "Education: %99[^\n]", resumes[resumeCount].education);
        } else if (strstr(buffer, "Experience:")) {
            sscanf(buffer, "Experience: %199[^\n]", resumes[resumeCount].experience);
        }
    }

    resumeCount++;
    fclose(file);
}

void displayResumes() {
    for (int i = 0; i < resumeCount; i++) {
        printf("===== Resume %d =====\n", i + 1);
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Phone: %s\n", resumes[i].phone);
        printf("Education: %s\n", resumes[i].education);
        printf("Experience: %s\n\n", resumes[i].experience);
    }
}

void displayMenu() {
    printf("~~~ Resume Parsing System ~~~\n");
    printf("1. Parse a new resume\n");
    printf("2. Display all parsed resumes\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

int main() {
    int choice;
    char filePath[100];

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter the resume file path: ");
                fgets(filePath, sizeof(filePath), stdin);
                filePath[strcspn(filePath, "\n")] = 0; // Remove newline
                parseResume(filePath);
                break;
            case 2:
                printf("Displaying all resumes...\n");
                displayResumes();
                break;
            case 3:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("ERROR: Invalid selection! Please choose between 1 and 3.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}