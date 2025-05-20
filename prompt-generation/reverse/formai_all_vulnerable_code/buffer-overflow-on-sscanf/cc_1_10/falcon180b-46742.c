//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 30
#define MAX_SENTENCE_LENGTH 80

typedef struct {
    char name[MAX_WORD_LENGTH];
    char address[MAX_WORD_LENGTH];
    char phone[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
} Contact;

typedef struct {
    char firstName[MAX_WORD_LENGTH];
    char lastName[MAX_WORD_LENGTH];
    char education[MAX_WORD_LENGTH];
    int experience;
    char skills[MAX_WORD_LENGTH];
} Resume;

int readResume(Resume* resume) {
    FILE* file = fopen("resume.txt", "r");
    char line[MAX_SENTENCE_LENGTH];

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_SENTENCE_LENGTH, file)!= NULL) {
        if (sscanf(line, "First name: %s\n", resume->firstName) == 1) {
            printf("First name: %s\n", resume->firstName);
        } else if (sscanf(line, "Last name: %s\n", resume->lastName) == 1) {
            printf("Last name: %s\n", resume->lastName);
        } else if (sscanf(line, "Education: %s\n", resume->education) == 1) {
            printf("Education: %s\n", resume->education);
        } else if (sscanf(line, "Experience: %d\n", &resume->experience) == 1) {
            printf("Experience: %d\n", resume->experience);
        } else if (sscanf(line, "Skills: %s\n", resume->skills) == 1) {
            printf("Skills: %s\n", resume->skills);
        }
    }

    fclose(file);
    return 0;
}

int main() {
    Resume resume;
    Contact contact;

    readResume(&resume);

    printf("Name: %s %s\n", resume.firstName, resume.lastName);
    printf("Education: %s\n", resume.education);
    printf("Experience: %d\n", resume.experience);
    printf("Skills: %s\n", resume.skills);

    return 0;
}