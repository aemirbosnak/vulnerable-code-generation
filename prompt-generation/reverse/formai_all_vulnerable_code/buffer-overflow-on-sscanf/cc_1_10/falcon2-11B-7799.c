//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_EDUCATION_LEN 100
#define MAX_EXPERIENCE_LEN 200

struct Resume {
    char name[MAX_NAME_LEN];
    char education[MAX_EDUCATION_LEN];
    char experience[MAX_EXPERIENCE_LEN];
};

int parseResume(struct Resume* resume, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name: %s", resume->name);
        } else if (strncmp(line, "Education:", 9) == 0) {
            sscanf(line, "Education: %s", resume->education);
        } else if (strncmp(line, "Experience:", 10) == 0) {
            sscanf(line, "Experience: %s", resume->experience);
        }
    }

    fclose(file);
    return 0;
}

int main() {
    struct Resume resume;
    const char* filename = "resume.txt";

    if (parseResume(&resume, filename) < 0) {
        return 1;
    }

    printf("Name: %s\n", resume.name);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}