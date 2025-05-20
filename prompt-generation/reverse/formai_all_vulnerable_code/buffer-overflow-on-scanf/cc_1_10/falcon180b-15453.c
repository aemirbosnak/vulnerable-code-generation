//Falcon-180B DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 100
#define MAX_WORD 20

char *token = " \t\r\n\a";
char *delim = " \t\r\n\a";

int is_delimiter(char c) {
    char *p;
    for (p = delim; *p!= '\0'; p++) {
        if (c == *p) {
            return 1;
        }
    }
    return 0;
}

int is_token(char c) {
    char *p;
    for (p = token; *p!= '\0'; p++) {
        if (c == *p) {
            return 1;
        }
    }
    return 0;
}

void read_file(char *filename, char *buffer) {
    FILE *fp;
    int c, i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((c = fgetc(fp))!= EOF) {
        if (is_delimiter(c)) {
            buffer[i] = '\0';
            i = 0;
        } else {
            if (i < MAX_LINE - 1) {
                buffer[i++] = c;
            }
        }
    }

    if (i > 0) {
        buffer[i] = '\0';
    }

    fclose(fp);
}

void write_file(char *filename, char *buffer) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fprintf(fp, "%s", buffer);

    fclose(fp);
}

int main() {
    char filename[MAX_LINE], buffer[MAX_LINE];
    char word[MAX_WORD];
    char *p;

    printf("Enter filename: ");
    scanf("%s", filename);

    read_file(filename, buffer);

    p = strtok(buffer, " \t\r\n\a");
    while (p!= NULL) {
        strcpy(word, p);
        p = strtok(NULL, " \t\r\n\a");

        if (strlen(word) > 0) {
            printf("%s\n", word);
        }
    }

    printf("Enter new filename: ");
    scanf("%s", filename);

    write_file(filename, buffer);

    return 0;
}