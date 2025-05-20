//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_NAME_LEN 50
#define MAX_SKILL_LEN 20
#define MAX_RESUME_LEN 1000
char resume[MAX_RESUME_LEN];
int pos = 0;
void parse_name() {
    int i = 0;
    while (i < MAX_NAME_LEN && resume[pos] != '\n') {
        putchar(toupper(resume[pos]));
        pos++;
        i++;
    }
    putchar(' ');
    putchar('\n');
}
void parse_skills() {
    int i = 0, j = 0;
    char skill[MAX_SKILL_LEN];
    while (i < MAX_SKILL_LEN && resume[pos] != ':') {
        skill[i] = resume[pos];
        i++;
        pos++;
    }
    skill[i] = '\0';
    putchar('Skill: ');
    while (j < strlen(skill)) {
        putchar(tolower(skill[j]));
        j++;
    }
    putchar(' ');
    while (resume[pos] != ',' && resume[pos] != '\n') {
        putchar(resume[pos]);
        pos++;
    }
    putchar('\n');
}
void parse_resume() {
    while (resume[pos] != '\0') {
        if (resume[pos] == '\n') {
            if (pos > 0 && resume[pos-1] != ':') {
                parse_name();
                parse_skills();
                pos += 2;
            }
            else {
                pos++;
            }
        }
        else {
            pos++;
        }
    }
}
int main() {
    FILE *file;
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fgets(resume, MAX_RESUME_LEN, file);
    parse_resume();
    fclose(file);
    return 0;
}