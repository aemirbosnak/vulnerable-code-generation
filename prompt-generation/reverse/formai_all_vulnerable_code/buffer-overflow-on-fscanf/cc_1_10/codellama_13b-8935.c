//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
// C Resume Parsing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store resume data
struct Resume {
    char name[50];
    char email[50];
    char phone[50];
    char skills[50];
    char experience[50];
};

// Function to read resume data from file
void read_resume(struct Resume *resume, FILE *file) {
    fscanf(file, "%s %s %s %s %s", resume->name, resume->email, resume->phone, resume->skills, resume->experience);
}

// Function to print resume data
void print_resume(struct Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);
}

// Main function
int main() {
    // Open resume file
    FILE *file = fopen("resume.txt", "r");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read resume data
    struct Resume resume;
    read_resume(&resume, file);

    // Print resume data
    print_resume(resume);

    // Close file
    fclose(file);

    return 0;
}