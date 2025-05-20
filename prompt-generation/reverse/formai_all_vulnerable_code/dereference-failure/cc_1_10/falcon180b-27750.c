//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *name;
    int experience;
    char *skills[10];
    int num_skills;
} resume;

void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Experience: %d years\n", r->experience);
    printf("Skills:\n");
    for (int i = 0; i < r->num_skills; i++) {
        printf("\t%s\n", r->skills[i]);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    int num_resumes = 0;
    resume *resumes = NULL;

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (line[0] == '@') {
            if (num_resumes == 0) {
                printf("Error: No resumes found.\n");
                exit(1);
            }
            break;
        }
        if (num_resumes >= MAX_LINE_LENGTH) {
            printf("Error: Too many resumes.\n");
            exit(1);
        }
        resume *r = malloc(sizeof(resume));
        r->name = strdup(line);
        r->experience = 0;
        r->num_skills = 0;
        resumes = realloc(resumes, sizeof(resume) * ++num_resumes);
        resumes[num_resumes - 1] = *r;
    }

    for (int i = 0; i < num_resumes; i++) {
        int j = 0;
        char *word = strtok(resumes[i].name, " ");
        while (word!= NULL) {
            if (j >= MAX_WORD_LENGTH) {
                printf("Error: Name too long.\n");
                exit(1);
            }
            strcpy(resumes[i].name, word);
            word = strtok(NULL, " ");
            j++;
        }
        word = strtok(NULL, " ");
        while (word!= NULL) {
            if (resumes[i].num_skills >= 10) {
                printf("Error: Too many skills.\n");
                exit(1);
            }
            strcpy(resumes[i].skills[resumes[i].num_skills++], word);
            word = strtok(NULL, " ");
        }
        int k = 0;
        while (k < resumes[i].num_skills) {
            int l = 0;
            while (l < strlen(resumes[i].skills[k])) {
                if (!isalpha(resumes[i].skills[k][l])) {
                    printf("Error: Invalid skill.\n");
                    exit(1);
                }
                l++;
            }
            k++;
        }
        resumes[i].experience = atoi(strtok(NULL, " "));
    }

    for (int i = 0; i < num_resumes; i++) {
        print_resume(&resumes[i]);
    }

    free(resumes);
    return 0;
}