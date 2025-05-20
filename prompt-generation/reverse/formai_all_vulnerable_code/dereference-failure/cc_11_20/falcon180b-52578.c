//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    bool is_palindrome = true;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int start = 0, end = strlen(line) - 1;
        while (start < end) {
            if (!isalnum(line[start]) &&!isspace(line[start])) {
                start++;
            } else if (!isalnum(line[end]) &&!isspace(line[end])) {
                end--;
            } else if (tolower(line[start])!= tolower(line[end])) {
                is_palindrome = false;
                break;
            } else {
                start++;
                end--;
            }
        }
    }

    fclose(file);

    if (is_palindrome) {
        printf("The file contains palindromes.\n");
    } else {
        printf("The file does not contain palindromes.\n");
    }

    return 0;
}