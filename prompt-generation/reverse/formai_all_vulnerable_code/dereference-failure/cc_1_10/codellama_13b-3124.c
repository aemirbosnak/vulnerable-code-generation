//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: random
// C Resume Parsing System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for resume data
typedef struct {
    char name[100];
    char email[100];
    char phone[100];
    char address[100];
} Resume;

typedef struct {
    Resume *resumes;
    int num_resumes;
} ResumeDatabase;

// Function to read resume data from file
void read_resumes(ResumeDatabase *db) {
    FILE *file = fopen("resumes.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, file)) {
        Resume resume;
        char *token = strtok(line, " ");
        int i = 0;
        while (token != NULL) {
            switch (i) {
                case 0:
                    strcpy(resume.name, token);
                    break;
                case 1:
                    strcpy(resume.email, token);
                    break;
                case 2:
                    strcpy(resume.phone, token);
                    break;
                case 3:
                    strcpy(resume.address, token);
                    break;
                default:
                    break;
            }
            i++;
            token = strtok(NULL, " ");
        }
        db->resumes[db->num_resumes++] = resume;
    }
    fclose(file);
}

// Function to print resume data
void print_resumes(ResumeDatabase *db) {
    for (int i = 0; i < db->num_resumes; i++) {
        printf("Resume %d:\n", i + 1);
        printf("Name: %s\n", db->resumes[i].name);
        printf("Email: %s\n", db->resumes[i].email);
        printf("Phone: %s\n", db->resumes[i].phone);
        printf("Address: %s\n", db->resumes[i].address);
    }
}

// Main function
int main() {
    ResumeDatabase db;
    db.num_resumes = 0;
    read_resumes(&db);
    print_resumes(&db);
    return 0;
}