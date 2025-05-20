//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESUME_SIZE 100000

// function to check if a character is a valid alphanumeric character
int isValidChar(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

// function to convert all the characters in a string to lower case
void strToLower(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

// function to parse the resume and count the number of occurrences of each keyword
void parseResume(char* resume, int* keywordCount, char** keywords, int numKeywords) {
    int resumeLen = strlen(resume);
    char currentWord[MAX_RESUME_SIZE];
    int wordLength = 0;

    for (int i = 0; i <= resumeLen; i++) {
        if (isValidChar(resume[i])) {
            currentWord[wordLength++] = resume[i];
        } else {
            currentWord[wordLength] = '\0';
            wordLength = 0;
            strToLower(currentWord);

            for (int j = 0; j < numKeywords; j++) {
                if (strcmp(currentWord, keywords[j]) == 0) {
                    keywordCount[j]++;
                }
            }
        }
    }
}

int main() {
    char resume[MAX_RESUME_SIZE];
    char* keywords[] = {"c", "python", "java", "php", "html", "css", "javascript", "mysql", "mongodb", "bootstrap"};
    int numKeywords = 10;
    int keywordCount[numKeywords];
    memset(keywordCount, 0, numKeywords * sizeof(int));

    printf("Enter your resume:\n");
    scanf("%[^\n]s", resume);

    parseResume(resume, keywordCount, keywords, numKeywords);

    printf("\nKeyword counts:\n");
    for (int i = 0; i < numKeywords; i++) {
        printf("%s: %d\n", keywords[i], keywordCount[i]);
    }

    return 0;
}