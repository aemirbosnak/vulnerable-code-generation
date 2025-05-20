//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LEN 20

typedef struct {
    char *keyword;
    int count;
} Keyword;

Keyword keywords[MAX_KEYWORDS];
int num_keywords;

void keyword_detection(char *buffer) {
    int i, j;
    char *token;

    for (i = 0; i < num_keywords; i++) {
        for (j = 0; j < strlen(keywords[i].keyword); j++) {
            if (buffer[j]!= keywords[i].keyword[j]) {
                break;
            }
        }
        if (j == strlen(keywords[i].keyword)) {
            keywords[i].count++;
            printf("Keyword '%s' detected at position %d\n", keywords[i].keyword, j+1);
        }
    }
}

int main() {
    FILE *fp;
    char buffer[BUF_SIZE];
    char filename[MAX_KEYWORD_LEN];
    int i, j, keyword_len;

    printf("Enter the name of the file to be scanned: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    num_keywords = 0;

    printf("Enter the number of keywords to be detected (max %d): ", MAX_KEYWORDS);
    scanf("%d", &num_keywords);

    for (i = 0; i < num_keywords; i++) {
        printf("Enter keyword %d: ", i+1);
        scanf("%s", keywords[i].keyword);
    }

    while (fgets(buffer, BUF_SIZE, fp)!= NULL) {
        keyword_detection(buffer);
    }

    fclose(fp);

    return 0;
}