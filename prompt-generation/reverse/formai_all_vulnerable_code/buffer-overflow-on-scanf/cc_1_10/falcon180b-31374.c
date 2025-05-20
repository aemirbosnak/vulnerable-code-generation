//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void reverse_string(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    int j = 0;
    for (int i = len - 1; i >= 0; i--) {
        reversed[j++] = str[i];
    }
    reversed[j] = '\0';
    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

void remove_duplicates(char* str) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i]!= str[i+1]) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    printf("String with duplicates removed: %s\n", str);
}

void replace_substring(char* str, char* substring, char* replacement) {
    int len1 = strlen(str);
    int len2 = strlen(substring);
    int len3 = strlen(replacement);
    char* new_str = malloc(len1 + len3 - len2 + 1);
    int j = 0;
    for (int i = 0; i < len1; i++) {
        if (str[i] == substring[0]) {
            int k = 0;
            while (str[i+k] == substring[k] && i+k < len1) {
                k++;
            }
            if (k == len2) {
                for (int l = 0; l < len3; l++) {
                    new_str[j++] = replacement[l];
                }
                i += len2 - 1;
            } else {
                new_str[j++] = str[i];
            }
        } else {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
    printf("String with substring replaced: %s\n", new_str);
    free(new_str);
}

int main() {
    char string1[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", string1);

    reverse_string(string1);

    printf("Enter a string: ");
    scanf("%s", string1);

    remove_duplicates(string1);

    printf("Enter a string: ");
    scanf("%s", string1);

    printf("Enter a substring to replace: ");
    scanf("%s", string1);

    printf("Enter a replacement string: ");
    scanf("%s", string1);

    replace_substring(string1, string1, string1);

    return 0;
}