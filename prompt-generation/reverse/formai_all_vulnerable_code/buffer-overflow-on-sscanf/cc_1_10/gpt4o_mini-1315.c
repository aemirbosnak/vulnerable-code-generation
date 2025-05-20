//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 1024

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char skills[MAX_LENGTH];
    int experience;
} Resume;

Resume resumes[MAX_RESUMES];
int resume_count = 0;

void initialize() {
    resume_count = 0;
}

void addResume(const char *name, const char *email, const char *phone, const char *skills, int experience) {
    if (resume_count >= MAX_RESUMES) {
        printf("Error: Maximum number of resumes reached.\n");
        return;
    }
    
    strcpy(resumes[resume_count].name, name);
    strcpy(resumes[resume_count].email, email);
    strcpy(resumes[resume_count].phone, phone);
    strcpy(resumes[resume_count].skills, skills);
    resumes[resume_count].experience = experience;
    resume_count++;
    
    printf("Resume for %s added successfully.\n", name);
}

void listResumes() {
    printf("\nList of Resumes:\n");
    for (int i = 0; i < resume_count; i++) {
        printf("Resume %d:\n", i + 1);
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Phone: %s\n", resumes[i].phone);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Experience: %d years\n", resumes[i].experience);
        printf("-------------------------\n");
    }
}

void searchResume(const char *keyword) {
    printf("\nSearching for resumes containing: %s\n", keyword);
    for (int i = 0; i < resume_count; i++) {
        if (strstr(resumes[i].name, keyword) || strstr(resumes[i].skills, keyword)) {
            printf("Found Resume %d:\n", i + 1);
            printf("Name: %s\n", resumes[i].name);
            printf("Email: %s\n", resumes[i].email);
            printf("Phone: %s\n", resumes[i].phone);
            printf("Skills: %s\n", resumes[i].skills);
            printf("Experience: %d years\n", resumes[i].experience);
            printf("-------------------------\n");
        }
    }
}

void saveResumesToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < resume_count; i++) {
        fprintf(file, "%s,%s,%s,%s,%d\n", resumes[i].name, resumes[i].email, resumes[i].phone, resumes[i].skills, resumes[i].experience);
    }
    
    fclose(file);
    printf("Resumes saved to %s successfully.\n", filename);
}

void loadResumesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    initialize();
    
    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char name[MAX_LENGTH], email[MAX_LENGTH], phone[MAX_LENGTH], skills[MAX_LENGTH];
        int experience;
        
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%d", name, email, phone, skills, &experience);
        addResume(name, email, phone, skills, experience);
    }
    
    fclose(file);
}

int main() {
    initialize();
    
    int choice;
    do {
        printf("\n=== Resume Parsing System ===\n");
        printf("1. Add Resume\n");
        printf("2. List Resumes\n");
        printf("3. Search Resume\n");
        printf("4. Save Resumes to File\n");
        printf("5. Load Resumes from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char name[MAX_LENGTH], email[MAX_LENGTH], phone[MAX_LENGTH], skills[MAX_LENGTH];
            int experience;
            printf("Enter Name: ");
            getchar(); // Clear input buffer
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;  // Remove newline character
            printf("Enter Email: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = 0;
            printf("Enter Phone: ");
            fgets(phone, sizeof(phone), stdin);
            phone[strcspn(phone, "\n")] = 0;
            printf("Enter Skills: ");
            fgets(skills, sizeof(skills), stdin);
            skills[strcspn(skills, "\n")] = 0;
            printf("Enter Experience in years: ");
            scanf("%d", &experience);
            addResume(name, email, phone, skills, experience);
        } else if (choice == 2) {
            listResumes();
        } else if (choice == 3) {
            char keyword[MAX_LENGTH];
            printf("Enter keyword to search: ");
            getchar(); // Clear input buffer
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = 0;
            searchResume(keyword);
        } else if (choice == 4) {
            char filename[MAX_LENGTH];
            printf("Enter filename to save resumes: ");
            getchar(); // Clear input buffer
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0;
            saveResumesToFile(filename);
        } else if (choice == 5) {
            char filename[MAX_LENGTH];
            printf("Enter filename to load resumes: ");
            getchar(); // Clear input buffer
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0;
            loadResumesFromFile(filename);
        }
    } while (choice != 6);

    printf("Exiting the Resume Parsing System. Goodbye!\n");
    return 0;
}