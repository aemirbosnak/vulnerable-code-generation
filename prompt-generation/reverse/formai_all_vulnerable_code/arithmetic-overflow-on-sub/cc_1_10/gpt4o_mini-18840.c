//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Structure to hold parsed resume data
typedef struct Resume {
    char name[100];
    char email[100];
    char phone[20];
    char skills[500];
} Resume;

// Function prototypes
void parseResume(const char *filename, Resume *resume);
void extractInfo(const char *line, Resume *resume);
void displayResume(const Resume *resume);
void trimWhitespace(char *str);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume_file1.txt> <resume_file2.txt> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        Resume resume;
        memset(&resume, 0, sizeof(Resume)); // Initialize the resume structure

        parseResume(argv[i], &resume);
        displayResume(&resume);
    }

    return EXIT_SUCCESS;
}

void parseResume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        trimWhitespace(line);
        extractInfo(line, resume);
    }

    fclose(file);
}

void extractInfo(const char *line, Resume *resume) {
    regex_t regex;
    regmatch_t pmatch[1];

    // Extract name
    if (regcomp(&regex, "Name:\\s*(.*)", REG_EXTENDED) == 0) {
        if (regexec(&regex, line, 1, pmatch, 0) == 0) {
            strncpy(resume->name, line + pmatch[0].rm_so + 5, pmatch[0].rm_eo - pmatch[0].rm_so - 5);
            trimWhitespace(resume->name);
        }
    }

    // Extract email
    if (regcomp(&regex, "Email:\\s*([^ ]+)", REG_EXTENDED) == 0) {
        if (regexec(&regex, line, 1, pmatch, 0) == 0) {
            strncpy(resume->email, line + pmatch[0].rm_so + 7, pmatch[0].rm_eo - pmatch[0].rm_so - 7);
            trimWhitespace(resume->email);
        }
    }

    // Extract phone
    if (regcomp(&regex, "Phone:\\s*([^ ]+)", REG_EXTENDED) == 0) {
        if (regexec(&regex, line, 1, pmatch, 0) == 0) {
            strncpy(resume->phone, line + pmatch[0].rm_so + 7, pmatch[0].rm_eo - pmatch[0].rm_so - 7);
            trimWhitespace(resume->phone);
        }
    }

    // Extract skills
    if (regcomp(&regex, "Skills:\\s*(.*)", REG_EXTENDED) == 0) {
        if (regexec(&regex, line, 1, pmatch, 0) == 0) {
            strncpy(resume->skills, line + pmatch[0].rm_so + 8, pmatch[0].rm_eo - pmatch[0].rm_so - 8);
            trimWhitespace(resume->skills);
        }
    }

    regfree(&regex);
}

void displayResume(const Resume *resume) {
    printf("Parsed Resume:\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n\n", resume->skills);
}

void trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null-terminate after trimming
    *(end + 1) = '\0';
}