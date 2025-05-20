//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 10
#define MAX_COLOR_CODES 10

typedef struct {
    char *name;
    char *code;
} Color;

Color color_list[MAX_COLOR_NAMES] = {
    {"Black", "\033[0;30m"},
    {"Red", "\033[0;31m"},
    {"Green", "\033[0;32m"},
    {"Yellow", "\033[0;33m"},
    {"Blue", "\033[0;34m"},
    {"Magenta", "\033[0;35m"},
    {"Cyan", "\033[0;36m"},
    {"White", "\033[0;37m"},
    {"Gray", "\033[1;30m"},
    {"Light Red", "\033[1;31m"}
};

int main() {
    FILE *fp;
    char filename[100];
    char line[1000];
    char *token;
    int i;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            for (i = 0; i < MAX_COLOR_NAMES; i++) {
                if (strcmp(token, color_list[i].name) == 0) {
                    printf("%s", color_list[i].code);
                    printf("%s", token);
                    printf("\033[0m");
                }
            }
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}