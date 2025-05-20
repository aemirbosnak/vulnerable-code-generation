//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256
#define MAX_NAME 50

void capitalizeFirstLetter(char *str) {
    int i = 0;
    if (isalpha(*str)) {
        *str -= 32;
    }
    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            str[i] = toupper(str[i]);
        }
        i++;
    }
}

int main() {
    char name[MAX_NAME], line[MAX_LINE], fileName[MAX_NAME];
    FILE *fp;

    printf("Enter your beloved's name: ");
    scanf("%s", name);
    capitalizeFirstLetter(name);

    printf("Enter the name of the text file containing the letter template: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("\n--- Beginning of Love Letter ---\n\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        int i = 0;

        while (line[i] != '\0') {
            if (line[i] == '%' && line[i + 1] == 'n') {
                int j = 0;
                while (name[j] != '\0') {
                    line[i] = name[j];
                    i++;
                    j++;
                }
                line[i] = ' ';
                i++;
            }
            putchar(line[i]);
            i++;
        }

        printf("%s", line);
    }

    fclose(fp);

    printf("\n--- End of Love Letter ---\n");

    return 0;
}