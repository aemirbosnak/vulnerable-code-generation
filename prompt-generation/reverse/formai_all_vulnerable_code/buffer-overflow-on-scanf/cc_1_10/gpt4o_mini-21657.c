//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define MAX_SECTIONS 5

// Structure to hold parsed resume information
typedef struct Resume {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char education[MAX_LENGTH];
    char experience[MAX_LENGTH];
    char skills[MAX_LENGTH];
} Resume;

// Function to initialize the Resume structure
void initialize_resume(Resume *resume) {
    memset(resume->name, 0, sizeof(resume->name));
    memset(resume->email, 0, sizeof(resume->email));
    memset(resume->phone, 0, sizeof(resume->phone));
    memset(resume->education, 0, sizeof(resume->education));
    memset(resume->experience, 0, sizeof(resume->experience));
    memset(resume->skills, 0, sizeof(resume->skills));
}

// Function to print the parsed resume
void print_resume(const Resume *resume) {
    printf("----- Parsed Resume -----\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
    printf("------------------------\n");
}

// Function to parse the resume from a text file
void parse_resume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    char line[MAX_LENGTH];
    int section = 0;

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        // Simple section detection based on key headers
        if (strstr(line, "Name:")) {
            section = 0;
            sscanf(line, "Name: %[^\n]", resume->name);
        } else if (strstr(line, "Email:")) {
            section = 1;
            sscanf(line, "Email: %[^\n]", resume->email);
        } else if (strstr(line, "Phone:")) {
            section = 2;
            sscanf(line, "Phone: %[^\n]", resume->phone);
        } else if (strstr(line, "Education:")) {
            section = 3;
            sscanf(line, "Education: %[^\n]", resume->education);
        } else if (strstr(line, "Experience:")) {
            section = 4;
            sscanf(line, "Experience: %[^\n]", resume->experience);
        } else if (strstr(line, "Skills:")) {
            section = 5;
            sscanf(line, "Skills: %[^\n]", resume->skills);
        }
    }

    fclose(file);
}

// Function to display menu
void display_menu() {
    printf("Welcome to the Resume Parsing System!\n");
    printf("1. Parse Resume\n");
    printf("2. Exit\n");
    printf("Select an option: ");
}

// Main function
int main() {
    Resume resume;
    initialize_resume(&resume);
    char filename[MAX_LENGTH];

    while (1) {
        display_menu();
        int option;
        scanf("%d", &option);
        getchar(); // Consume newline
        
        if (option == 1) {
            printf("Enter the filename of the resume: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = 0; // Remove newline

            parse_resume(filename, &resume);
            print_resume(&resume);
        } else if (option == 2) {
            printf("Exiting the Resume Parsing System. Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Please select again.\n");
        }
    }

    return 0;
}