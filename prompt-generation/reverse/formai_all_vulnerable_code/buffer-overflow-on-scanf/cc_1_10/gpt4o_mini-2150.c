//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_SKILLS_LENGTH 300

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    struct Resume* next;
} Resume;

Resume* head = NULL;

void addResume(char* name, char* email, char* phone, char* skills) {
    Resume* newResume = (Resume*)malloc(sizeof(Resume));
    if (!newResume) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    strncpy(newResume->name, name, MAX_NAME_LENGTH);
    strncpy(newResume->email, email, MAX_EMAIL_LENGTH);
    strncpy(newResume->phone, phone, MAX_PHONE_LENGTH);
    strncpy(newResume->skills, skills, MAX_SKILLS_LENGTH);
    newResume->next = head; // Insert at beginning
    head = newResume;

    printf("Resume added for %s\n", name);
}

void displayResumes() {
    Resume* current = head;
    printf("\nResumes:\n");
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        printf("Phone: %s\n", current->phone);
        printf("Skills: %s\n", current->skills);
        printf("-------------------------\n");
        current = current->next;
    }
}

void freeResumes() {
    Resume* current = head;
    Resume* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All resumes have been freed.\n");
}

void parseResume() {
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH], phone[MAX_PHONE_LENGTH], skills[MAX_SKILLS_LENGTH];

    printf("Enter Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    printf("Enter Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline character

    printf("Enter Phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = 0; // Remove newline character

    printf("Enter Skills (comma-separated): ");
    fgets(skills, sizeof(skills), stdin);
    skills[strcspn(skills, "\n")] = 0; // Remove newline character

    addResume(name, email, phone, skills);
}

int main() {
    int choice;

    do {
        printf("Resume Parsing System\n");
        printf("1. Add Resume\n");
        printf("2. Display Resumes\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from the buffer

        switch (choice) {
            case 1:
                parseResume();
                break;
            case 2:
                displayResumes();
                break;
            case 3:
                freeResumes();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}