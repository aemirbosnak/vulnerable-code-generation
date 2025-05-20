//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

struct Resume {
    char name[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
    struct Word skills[MAX_WORDS];
    int numSkills;
};

void readResume(FILE *fp, struct Resume *resume) {
    char line[MAX_WORD_LENGTH];
    char *word;
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, fp)) {
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            if (i >= MAX_WORDS) {
                break;
            }
            strcpy(resume->skills[i].word, word);
            resume->skills[i].count = 1;
            i++;
            word = strtok(NULL, ",.!?;:");
        }
    }

    resume->numSkills = i;
}

void printResume(struct Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Skills:\n");
    for (int i = 0; i < resume->numSkills; i++) {
        printf("%s: %d\n", resume->skills[i].word, resume->skills[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    struct Resume resume;

    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    readResume(fp, &resume);
    fclose(fp);

    printResume(&resume);

    return 0;
}