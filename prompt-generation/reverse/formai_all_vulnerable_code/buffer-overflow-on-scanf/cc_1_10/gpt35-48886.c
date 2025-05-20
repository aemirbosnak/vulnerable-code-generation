//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the parsed resume data
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[200];
};

int main() {
    // Prompt the user to input the resume file path
    printf("Please input the file path of the resume: ");
    char file_path[100];
    scanf("%s", file_path);
    
    // Open the resume file
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    }
    
    // Define an array of relevant keywords
    const char *keywords[5] = {"Name", "Email", "Phone", "Education", "Experience"};
    
    // Initialize the Resume object
    struct Resume resume;
    memset(&resume, 0, sizeof(resume));
    
    // Parse the resume file line by line
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        // Check if each line contains any of the relevant keywords
        for (int i = 0; i < 5; i++) {
            if (strstr(line, keywords[i]) != NULL) {
                char *value = strchr(line, ':') + 2; // Extract the value after the colon
                switch(i) {
                    case 0:
                        strcpy(resume.name, value);
                        break;
                    case 1:
                        strcpy(resume.email, value);
                        break;
                    case 2:
                        strcpy(resume.phone, value);
                        break;
                    case 3:
                        strcpy(resume.education, value);
                        break;
                    case 4:
                        strcpy(resume.experience, value);
                        break;
                }
                break; // Once a relevant keyword is found, break out of the for loop
            }
        }
    }
    fclose(fp);
    
    // Print out the parsed resume data
    printf("==============================\n");
    printf("Resume\n");
    printf("==============================\n");
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Education: %s", resume.education);
    printf("Experience: %s", resume.experience);
    printf("==============================\n");
    
    return 0;
}