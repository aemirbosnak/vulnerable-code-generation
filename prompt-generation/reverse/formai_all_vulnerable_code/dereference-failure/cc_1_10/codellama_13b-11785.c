//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
/*
 * C Resume Parsing System
 *
 * This program takes a resume in plain text format as input and extracts the relevant information.
 *
 * Usage:
 * 1. Open the resume file in a text editor.
 * 2. Copy the text from the editor and paste it into the program.
 * 3. Press enter to start the parsing process.
 *
 * The program will output the parsed information in a structured format.
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_SKILLS_LENGTH 100

struct Resume {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
};

int main() {
    // Get the resume text from the user
    char resume_text[MAX_LINE_LENGTH];
    printf("Enter the resume text: ");
    fgets(resume_text, MAX_LINE_LENGTH, stdin);

    // Initialize the resume structure
    struct Resume resume = {0};

    // Parse the resume text and populate the structure
    char *name = strtok(resume_text, "\n");
    strncpy(resume.name, name, MAX_NAME_LENGTH);

    char *address = strtok(NULL, "\n");
    strncpy(resume.address, address, MAX_ADDRESS_LENGTH);

    char *phone = strtok(NULL, "\n");
    strncpy(resume.phone, phone, MAX_PHONE_LENGTH);

    char *email = strtok(NULL, "\n");
    strncpy(resume.email, email, MAX_EMAIL_LENGTH);

    char *skills = strtok(NULL, "\n");
    strncpy(resume.skills, skills, MAX_SKILLS_LENGTH);

    // Print the parsed information
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Skills: %s\n", resume.skills);

    return 0;
}