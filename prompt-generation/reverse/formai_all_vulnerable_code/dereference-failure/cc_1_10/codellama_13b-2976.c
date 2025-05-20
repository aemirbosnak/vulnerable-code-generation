//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: excited
/*
 * A unique C Resume Parsing System example program in an excited style
 */
#include <stdio.h>
#include <string.h>

// Structure to represent a resume
typedef struct {
    char name[100];
    char email[100];
    char phone[10];
    char address[100];
    char experience[100];
    char education[100];
    char skills[100];
} Resume;

// Function to parse a resume
void parseResume(Resume *resume) {
    // Read a line from the file
    char line[100];
    if (fgets(line, 100, stdin) == NULL) {
        printf("Error reading from file.\n");
        return;
    }

    // Check if the line is empty or a comment
    if (line[0] == '\n' || line[0] == '#') {
        return;
    }

    // Split the line into fields
    char *field = strtok(line, " ");
    if (field == NULL) {
        printf("Error parsing resume.\n");
        return;
    }

    // Assign the field to the corresponding member of the resume structure
    if (strcmp(field, "Name:") == 0) {
        strcpy(resume->name, strtok(NULL, "\n"));
    } else if (strcmp(field, "Email:") == 0) {
        strcpy(resume->email, strtok(NULL, "\n"));
    } else if (strcmp(field, "Phone:") == 0) {
        strcpy(resume->phone, strtok(NULL, "\n"));
    } else if (strcmp(field, "Address:") == 0) {
        strcpy(resume->address, strtok(NULL, "\n"));
    } else if (strcmp(field, "Experience:") == 0) {
        strcpy(resume->experience, strtok(NULL, "\n"));
    } else if (strcmp(field, "Education:") == 0) {
        strcpy(resume->education, strtok(NULL, "\n"));
    } else if (strcmp(field, "Skills:") == 0) {
        strcpy(resume->skills, strtok(NULL, "\n"));
    } else {
        printf("Unknown field: %s\n", field);
        return;
    }
}

// Main function
int main() {
    // Create a new resume structure
    Resume resume;

    // Parse the resume file
    parseResume(&resume);

    // Print the resume
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);

    return 0;
}