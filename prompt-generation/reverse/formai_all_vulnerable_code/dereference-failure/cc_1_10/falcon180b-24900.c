//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* address;
    char* education;
    char* experience;
} Resume;

Resume parse_resume(char* input) {
    Resume resume = {0};
    char* token;
    char* delimiters = " \t\n\r\f\v";
    char* line;
    int line_num = 1;
    FILE* file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", input);
        exit(1);
    }
    while ((line = fgets(line, MAX_WORD_LEN, file))!= NULL) {
        if (line_num == 1) {
            token = strtok(line, delimiters);
            while (token!= NULL) {
                if (strcasecmp(token, "Name") == 0) {
                    resume.name = strtok(NULL, delimiters);
                } else if (strcasecmp(token, "Email") == 0) {
                    resume.email = strtok(NULL, delimiters);
                } else if (strcasecmp(token, "Phone") == 0) {
                    resume.phone = strtok(NULL, delimiters);
                } else if (strcasecmp(token, "Address") == 0) {
                    resume.address = strtok(NULL, delimiters);
                } else if (strcasecmp(token, "Education") == 0) {
                    resume.education = strtok(NULL, delimiters);
                } else if (strcasecmp(token, "Experience") == 0) {
                    resume.experience = strtok(NULL, delimiters);
                }
                token = strtok(NULL, delimiters);
            }
        } else {
            if (strlen(line) > MAX_WORD_LEN) {
                printf("Line %d is too long\n", line_num);
            }
            if (strlen(line) == 0) {
                printf("Blank line found on line %d\n", line_num);
            }
        }
        line_num++;
    }
    fclose(file);
    return resume;
}

void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        exit(1);
    }
    Resume resume = parse_resume(argv[1]);
    print_resume(resume);
    return 0;
}