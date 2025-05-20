//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 50
#define MAX_KEYWORDS 20
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    char skills[MAX_KEYWORDS][MAX_LENGTH];
    int num_skills;
} Resume;

int num_resumes = 0;
Resume resumes[MAX_RESUMES];

void read_resume() {
    char name[MAX_LENGTH];
    char skills[MAX_LENGTH];
    char* token;
    int i;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter skills (comma-separated): ");
    scanf("%s", skills);

    token = strtok(skills, ",");

    for (i = 0; i < MAX_KEYWORDS && token != NULL; i++) {
        strcpy(resumes[num_resumes].skills[i], token);
        token = strtok(NULL, ",");
    }

    resumes[num_resumes].num_skills = i;
    strcpy(resumes[num_resumes].name, name);
    num_resumes++;
}

void print_resume(Resume r) {
    int i;
    printf("Name: %s\n", r.name);
    printf("Skills: ");
    for (i = 0; i < r.num_skills; i++) {
        printf("%s ", r.skills[i]);
    }
    printf("\n");
}

int check_keyword(char* keyword, char* text) {
    char* token = strtok(text, " ");

    while (token != NULL) {
        if (strcmp(token, keyword) == 0) {
            return 1;
        }
        token = strtok(NULL, " ");
    }

    return 0;
}

void search_resumes() {
    char keyword[MAX_LENGTH];
    int i, j, k, match;

    printf("Enter keyword to search: ");
    scanf("%s", keyword);

    for (i = 0; i < num_resumes; i++) {
        match = 0;
        for (j = 0; j < resumes[i].num_skills; j++) {
            if (check_keyword(keyword, resumes[i].skills[j])) {
                match = 1;
            }
        }

        if (match) {
            print_resume(resumes[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add resume\n");
        printf("2. Search resumes\n");
        printf("3. Exit\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_resume();
                break;
            case 2:
                search_resumes();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}