//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a field in the resume
#define MAX_FIELD_LENGTH 100

// Define the maximum number of fields in the resume
#define MAX_FIELDS 10

// Define the structure of a field in the resume
typedef struct {
    char name[MAX_FIELD_LENGTH];
    char value[MAX_FIELD_LENGTH];
} Field;

// Define the structure of the resume
typedef struct {
    int num_fields;
    Field fields[MAX_FIELDS];
} Resume;

// Function to parse the resume and extract the fields
Resume parse_resume(char* resume_text) {
    Resume result;
    int num_fields = 0;
    char* curr_line = strtok(resume_text, "\n");
    while (curr_line!= NULL && num_fields < MAX_FIELDS) {
        char* name = strtok(curr_line, ":");
        if (name == NULL) {
            break;
        }
        char* value = strtok(NULL, ":");
        if (value == NULL) {
            break;
        }
        strncpy(result.fields[num_fields].name, name, MAX_FIELD_LENGTH);
        strncpy(result.fields[num_fields].value, value, MAX_FIELD_LENGTH);
        num_fields++;
        curr_line = strtok(NULL, "\n");
    }
    result.num_fields = num_fields;
    return result;
}

// Function to print the fields in the resume
void print_resume(Resume resume) {
    printf("Name\tValue\n");
    for (int i = 0; i < resume.num_fields; i++) {
        printf("%s\t%s\n", resume.fields[i].name, resume.fields[i].value);
    }
}

// Function to search for a specific field in the resume
int search_resume(Resume resume, char* name) {
    for (int i = 0; i < resume.num_fields; i++) {
        if (strcmp(resume.fields[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char resume_text[1000];
    printf("Enter the resume text:\n");
    fgets(resume_text, 1000, stdin);
    Resume resume = parse_resume(resume_text);
    print_resume(resume);
    printf("Enter the field name to search for:\n");
    scanf("%s", resume_text);
    int index = search_resume(resume, resume_text);
    if (index!= -1) {
        printf("Field found at index %d\n", index);
    } else {
        printf("Field not found\n");
    }
    return 0;
}