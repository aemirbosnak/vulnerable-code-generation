//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

void paranoid_trim(char *str) {
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (!isspace(str[i])) {
            i++;
        } else if (!isspace(str[j])) {
            j--;
        } else {
            str[i] = '\0';
            j--;
        }
    }
}

int paranoid_strcmp(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (tolower(str1[i])!= tolower(str2[i])) {
            return 0;
        }
    }

    return 1;
}

int paranoid_is_palindrome(const char *sentence) {
    char *word = NULL;
    char *token = strtok(sentence, " ");

    while (token!= NULL) {
        paranoid_trim(token);

        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(1);
        }

        if (paranoid_strcmp(token, "racecar") || paranoid_strcmp(token, "level") || paranoid_strcmp(token, "deified")) {
            printf("Palindrome found!\n");
            exit(0);
        }

        word = realloc(word, strlen(word) + strlen(token) + 2);
        strcat(word, " ");
        strcat(word, token);

        token = strtok(NULL, " ");
    }

    paranoid_trim(word);

    if (strlen(word) > MAX_SENTENCE_LENGTH) {
        printf("Error: Sentence is too long.\n");
        exit(1);
    }

    if (paranoid_is_palindrome(word)) {
        printf("Palindrome found!\n");
        exit(0);
    } else {
        printf("No palindrome found.\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        exit(1);
    }

    paranoid_is_palindrome(argv[1]);

    return 0;
}