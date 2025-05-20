//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
/*
 * C Resume Parsing System
 *
 * This program takes a resume as input and extracts relevant information
 * such as name, email, phone number, and skills.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to hold resume data
struct Resume {
    char name[100];
    char email[100];
    char phone[100];
    char skills[100];
};

struct ResumeData {
    struct Resume resume;
    int num_skills;
    char **skills;
};

// Function to parse resume data
void parse_resume(struct ResumeData *data) {
    // Extract name, email, and phone number
    sscanf(data->resume.name, "%s", data->resume.name);
    sscanf(data->resume.email, "%s", data->resume.email);
    sscanf(data->resume.phone, "%s", data->resume.phone);

    // Extract skills
    data->num_skills = 0;
    char *token = strtok(data->resume.skills, ",");
    while (token != NULL) {
        data->skills[data->num_skills] = token;
        data->num_skills++;
        token = strtok(NULL, ",");
    }
}

// Function to print resume data
void print_resume(struct ResumeData *data) {
    printf("Name: %s\n", data->resume.name);
    printf("Email: %s\n", data->resume.email);
    printf("Phone: %s\n", data->resume.phone);
    printf("Skills: ");
    for (int i = 0; i < data->num_skills; i++) {
        printf("%s ", data->skills[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Declare resume data structure
    struct ResumeData data;

    // Read resume data from file
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fscanf(fp, "%s", data.resume.name);
    fscanf(fp, "%s", data.resume.email);
    fscanf(fp, "%s", data.resume.phone);
    fscanf(fp, "%s", data.resume.skills);
    fclose(fp);

    // Parse resume data
    parse_resume(&data);

    // Print resume data
    print_resume(&data);

    return 0;
}