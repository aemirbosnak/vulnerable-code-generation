//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

struct candidate {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    int experience;
    char skills[MAX_LENGTH];
};

struct candidate parse_resume(char* resume_text) {
    struct candidate candidate;
    char* token = strtok(resume_text, "\n");
    int i = 0;

    while (token!= NULL) {
        if (i == 0) { // name
            strcpy(candidate.name, token);
        } else if (i == 1) { // email
            strcpy(candidate.email, token);
        } else if (i == 2) { // experience
            sscanf(token, "%d", &candidate.experience);
        } else if (i == 3) { // skills
            strcpy(candidate.skills, token);
        }

        i++;
        token = strtok(NULL, "\n");
    }

    return candidate;
}

int main() {
    char* resume_text = "John Doe\n"
                        "johndoe@example.com\n"
                        "5\n"
                        "C++, Java, Python\n";

    struct candidate candidate = parse_resume(resume_text);

    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Experience: %d\n", candidate.experience);
    printf("Skills: %s\n", candidate.skills);

    return 0;
}