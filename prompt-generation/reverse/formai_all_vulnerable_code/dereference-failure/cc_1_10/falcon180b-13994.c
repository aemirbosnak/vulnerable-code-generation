//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a field in a resume
#define MAX_FIELD_LEN 100

// Define the number of fields in a resume
#define NUM_FIELDS 5

// Define the structure of a resume
typedef struct {
    char name[MAX_FIELD_LEN];
    char education[MAX_FIELD_LEN];
    char experience[MAX_FIELD_LEN];
    char skills[MAX_FIELD_LEN];
    char contact[MAX_FIELD_LEN];
} Resume;

// Function to parse a resume from a file
Resume* parseResume(FILE* file) {
    Resume* resume = (Resume*) malloc(sizeof(Resume));
    char line[MAX_FIELD_LEN];

    // Read the first line, which contains the name
    fgets(line, MAX_FIELD_LEN, file);
    strcpy(resume->name, line);

    // Read the remaining lines and store them in the appropriate fields
    for (int i = 1; i <= NUM_FIELDS - 1; i++) {
        fgets(line, MAX_FIELD_LEN, file);
        switch (i) {
            case 0:
                strcpy(resume->education, line);
                break;
            case 1:
                strcpy(resume->experience, line);
                break;
            case 2:
                strcpy(resume->skills, line);
                break;
            case 3:
                strcpy(resume->contact, line);
                break;
            default:
                break;
        }
    }

    return resume;
}

// Function to print a resume
void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
    printf("Contact: %s\n", resume->contact);
}

// Main function
int main() {
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    Resume* resume = parseResume(file);
    if (resume == NULL) {
        printf("Error: could not parse resume.\n");
        return 1;
    }

    printResume(resume);

    free(resume);
    fclose(file);

    return 0;
}