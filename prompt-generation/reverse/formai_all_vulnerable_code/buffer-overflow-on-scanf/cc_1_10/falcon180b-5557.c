//Falcon-180B DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function prototypes */
void shapeShift(char *word);
char* copyString(char *str);
char* concatenateStrings(char *str1, char *str2);
int compareStrings(char *str1, char *str2);

/* Main function */
int main() {
    char input[100];
    char shifted[200];
    int i, j, k;

    printf("Enter a word to shape shift: ");
    scanf("%s", input);

    shapeShift(input);
    printf("\nShifted word: %s\n", shifted);

    return 0;
}

/* Recursive function to shape shift a word */
void shapeShift(char *word) {
    int len = strlen(word);
    char *temp = NULL;

    /* Base case */
    if (len <= 1) {
        return;
    }

    /* Recursive case */
    temp = copyString(word);
    for (int i = 0; i < len; i++) {
        if (isalpha(temp[i])) {
            if (isupper(temp[i])) {
                temp[i] = tolower(temp[i]);
            } else {
                temp[i] = toupper(temp[i]);
            }
        }
    }
    strcat(word, temp);
    free(temp);

    /* Recursive call */
    shapeShift(word);
}

/* Function to copy a string */
char* copyString(char *str) {
    int len = strlen(str);
    char *temp = (char*) malloc(len + 1);

    if (temp == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    strcpy(temp, str);
    return temp;
}

/* Function to concatenate two strings */
char* concatenateStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *temp = (char*) malloc(len1 + len2 + 1);

    if (temp == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    strcpy(temp, str1);
    strcat(temp, str2);
    return temp;
}

/* Function to compare two strings */
int compareStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (str1[i]!= str2[i]) {
            return 0;
        }
    }

    return 1;
}