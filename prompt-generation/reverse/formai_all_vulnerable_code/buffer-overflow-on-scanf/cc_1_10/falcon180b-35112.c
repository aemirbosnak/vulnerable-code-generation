//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct Word {
    char word[MAX_WORD_LEN];
    int count;
};

struct Resume {
    char name[MAX_WORD_LEN];
    char email[MAX_WORD_LEN];
    int numSkills;
    struct Word skills[MAX_WORDS];
};

void extractWords(char* text, struct Word words[MAX_WORDS]) {
    int numWords = 0;
    char* word = strtok(text, " ");
    while (word!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words in input text.\n");
            exit(1);
        }
        strcpy(words[numWords].word, word);
        words[numWords].count = 1;
        numWords++;
        word = strtok(NULL, " ");
    }
}

int main() {
    char name[MAX_WORD_LEN], email[MAX_WORD_LEN], text[10000];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your email: ");
    scanf("%s", email);
    printf("Enter your resume text:\n");
    fgets(text, 10000, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character
    struct Resume resume;
    strcpy(resume.name, name);
    strcpy(resume.email, email);
    extractWords(text, resume.skills);
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Number of skills: %d\n", resume.numSkills);
    for (int i = 0; i < resume.numSkills; i++) {
        printf("Skill %d: %s (%d)\n", i+1, resume.skills[i].word, resume.skills[i].count);
    }
    return 0;
}