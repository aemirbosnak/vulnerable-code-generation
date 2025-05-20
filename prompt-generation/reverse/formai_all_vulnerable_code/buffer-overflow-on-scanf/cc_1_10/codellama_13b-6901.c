//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: optimized
// Resume Parsing System in C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct for Resume Information
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char address[50];
    char experience[100];
    char education[100];
    char skills[100];
} Resume;

// Function to read and parse a resume file
void read_resume(Resume *resume, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read and store the resume information
    fscanf(file, "%s %s %s %s %s %s %s", resume->name, resume->email, resume->phone, resume->address, resume->experience, resume->education, resume->skills);

    fclose(file);
}

// Function to display the resume information
void display_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
}

int main() {
    Resume resume;
    char filename[50];

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Read and parse the resume file
    read_resume(&resume, filename);

    // Display the resume information
    display_resume(&resume);

    return 0;
}