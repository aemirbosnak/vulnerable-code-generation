//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_ADDRESS_LENGTH 100
#define MAX_EDUCATION_LENGTH 50
#define MAX_EXPERIENCE_LENGTH 50

struct Resume {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
};

int main() {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    struct Resume resume;
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        // Skip empty lines
        if (line[0] == '\n' || line[0] == '\r') {
            continue;
        }

        // Parse the line into individual fields
        sscanf(line, "%s %s %s %s %s %s", resume.name, resume.email, resume.phone, resume.address, resume.education, resume.experience);
    }

    fclose(file);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}