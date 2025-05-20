//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *email;
    char *phone_number;
    char *address;
    char *education;
    char *experience;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "Name") == 0) {
            resume->name = strdup(strtok(NULL, ":"));
        } else if (strcmp(token, "Email") == 0) {
            resume->email = strdup(strtok(NULL, ":"));
        } else if (strcmp(token, "Phone Number") == 0) {
            resume->phone_number = strdup(strtok(NULL, ":"));
        } else if (strcmp(token, "Address") == 0) {
            resume->address = strdup(strtok(NULL, ":"));
        } else if (strcmp(token, "Education") == 0) {
            resume->education = strdup(strtok(NULL, ":"));
        } else if (strcmp(token, "Experience") == 0) {
            resume->experience = strdup(strtok(NULL, ":"));
        }
    }

    fclose(file);
    return resume;
}

void print_resume(Resume *resume) {
    if (resume == NULL) {
        printf("No resume found\n");
        return;
    }

    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone Number: %s\n", resume->phone_number);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    Resume *resume = parse_resume(argv[1]);
    if (resume!= NULL) {
        print_resume(resume);
        free(resume->name);
        free(resume->email);
        free(resume->phone_number);
        free(resume->address);
        free(resume->education);
        free(resume->experience);
        free(resume);
    }

    return 0;
}