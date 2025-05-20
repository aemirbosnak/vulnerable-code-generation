//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

char *trim(char *str) {
    char *end;
    if (isspace(str[0])) {
        while (isspace(str[0])) {
            str++;
        }
    }
    end = str + strlen(str) - 1;
    if (isspace(end[0])) {
        while (isspace(end[0])) {
            end--;
        }
        end[1] = '\0';
    }
    return str;
}

int is_palindrome(char *word) {
    int i, j;
    for (i = 0, j = strlen(word) - 1; i < j; i++, j--) {
        if (tolower(word[i])!= tolower(word[j])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: word is too long.\n");
                return 1;
            }
            if (is_palindrome(word)) {
                printf("%s\n", word);
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
    return 0;
}