//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

int main() {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int count = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found.\n");
        return 0;
    }

    while ((word[j] = fgetc(fp))!= EOF) {
        if (isalpha(word[j])) {
            if (k == MAX_WORD_LENGTH - 1) {
                printf("Error: Word length exceeds maximum limit.\n");
                return 0;
            }
            word[k++] = tolower(word[j]);
        } else if (k > 0) {
            if (l == MAX_WORDS - 1) {
                printf("Error: Maximum number of words reached.\n");
                return 0;
            }
            strcpy(filename[l], word);
            l++;
            k = 0;
        }
    }

    if (k > 0) {
        strcpy(filename[l], word);
        l++;
    }

    for (m = 0; m < l; m++) {
        count += strlen(filename[m]);
    }

    printf("Total word count: %d\n", count);

    for (i = 0; i < l; i++) {
        printf("%s ", filename[i]);
    }

    printf("\n");

    fclose(fp);

    return 0;
}