//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ADDR_LEN 100
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDR_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
} Resume;

Resume parseResume(char *resumeText) {
    Resume result;
    char *token;
    char *saveptr;

    result.name[0] = '\0';
    result.address[0] = '\0';
    result.phone[0] = '\0';
    result.email[0] = '\0';

    token = strtok_r(resumeText, "\n", &saveptr);
    while (token!= NULL) {
        if (strncmp(token, "Name:", 5) == 0) {
            strncat(result.name, token + 5, MAX_NAME_LEN - strlen(result.name) - 1);
        } else if (strncmp(token, "Address:", 8) == 0) {
            strncat(result.address, token + 8, MAX_ADDR_LEN - strlen(result.address) - 1);
        } else if (strncmp(token, "Phone:", 6) == 0) {
            strncat(result.phone, token + 6, MAX_PHONE_LEN - strlen(result.phone) - 1);
        } else if (strncmp(token, "Email:", 6) == 0) {
            strncat(result.email, token + 6, MAX_EMAIL_LEN - strlen(result.email) - 1);
        }
        token = strtok_r(NULL, "\n", &saveptr);
    }

    return result;
}

void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
}

int main() {
    char resumeText[] = "Name: John Doe\n"
                        "Address: 123 Main St\n"
                        "Phone: 555-1234\n"
                        "Email: johndoe@example.com\n";

    Resume resume = parseResume(resumeText);
    printResume(resume);

    return 0;
}