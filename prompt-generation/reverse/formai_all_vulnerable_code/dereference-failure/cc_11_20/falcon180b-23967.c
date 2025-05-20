//Falcon-180B DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000
#define MAX_WORD 100

char *line = NULL;
char *word = NULL;

int main(int argc, char *argv[]) {
    FILE *fp;
    int i, j;
    char c;
    char *email = NULL;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    line = malloc(MAX_LINE * sizeof(char));
    word = malloc(MAX_WORD * sizeof(char));

    while ((c = fgetc(fp))!= EOF) {
        if (isalpha(c) || c == '@' || c == '.' || c == '-') {
            if (email == NULL) {
                email = malloc(MAX_LINE * sizeof(char));
                strcpy(email, "");
            }
            strncat(email, &c, 1);
        }
        else if (c == '\n' || c == '\r') {
            if (email!= NULL) {
                printf("%s\n", email);
                email = NULL;
            }
        }
    }

    if (email!= NULL) {
        printf("%s\n", email);
    }

    free(line);
    free(word);
    fclose(fp);

    return 0;
}