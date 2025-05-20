//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a resume
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} resume;

// Define the function to parse a resume from a file
resume *parse_resume(char *filename) {
    // Allocate memory for the resume
    resume *r = malloc(sizeof(resume));

    // Open the file
    FILE *file = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // Read the name from the file
    char name[100];
    fscanf(file, "%s", name);

    // Allocate memory for the name
    r->name = malloc(strlen(name) + 1);

    // Copy the name to the resume
    strcpy(r->name, name);

    // Read the email from the file
    char email[100];
    fscanf(file, "%s", email);

    // Allocate memory for the email
    r->email = malloc(strlen(email) + 1);

    // Copy the email to the resume
    strcpy(r->email, email);

    // Read the phone from the file
    char phone[100];
    fscanf(file, "%s", phone);

    // Allocate memory for the phone
    r->phone = malloc(strlen(phone) + 1);

    // Copy the phone to the resume
    strcpy(r->phone, phone);

    // Read the skills from the file
    char skills[1000];
    fscanf(file, "%s", skills);

    // Allocate memory for the skills
    r->skills = malloc(strlen(skills) + 1);

    // Copy the skills to the resume
    strcpy(r->skills, skills);

    // Read the experience from the file
    char experience[1000];
    fscanf(file, "%s", experience);

    // Allocate memory for the experience
    r->experience = malloc(strlen(experience) + 1);

    // Copy the experience to the resume
    strcpy(r->experience, experience);

    // Read the education from the file
    char education[1000];
    fscanf(file, "%s", education);

    // Allocate memory for the education
    r->education = malloc(strlen(education) + 1);

    // Copy the education to the resume
    strcpy(r->education, education);

    // Close the file
    fclose(file);

    // Return the resume
    return r;
}

// Define the function to print a resume
void print_resume(resume *r) {
    // Print the name
    printf("Name: %s\n", r->name);

    // Print the email
    printf("Email: %s\n", r->email);

    // Print the phone
    printf("Phone: %s\n", r->phone);

    // Print the skills
    printf("Skills: %s\n", r->skills);

    // Print the experience
    printf("Experience: %s\n", r->experience);

    // Print the education
    printf("Education: %s\n", r->education);
}

// Define the main function
int main() {
    // Parse the resume from the file
    resume *r = parse_resume("resume.txt");

    // Print the resume
    print_resume(r);

    // Free the memory allocated for the resume
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r);

    return 0;
}