//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void reverse_string(char *str) {
    int len = strlen(str);
    char temp[MAX_SIZE];
    strcpy(temp, str);
    for (int i = 0; i < len / 2; i++) {
        char c = temp[i];
        temp[i] = temp[len - i - 1];
        temp[len - i - 1] = c;
    }
    strcpy(str, temp);
}

void remove_vowels(char *str) {
    int len = strlen(str);
    char temp[MAX_SIZE];
    strcpy(temp, str);
    for (int i = 0; i < len; i++) {
        if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') {
            temp[i] = '\0';
        }
    }
    strcpy(str, temp);
}

void replace_string(char *str, char old, char new) {
    int len = strlen(str);
    char temp[MAX_SIZE];
    strcpy(temp, str);
    for (int i = 0; i < len; i++) {
        if (temp[i] == old) {
            temp[i] = new;
        }
    }
    strcpy(str, temp);
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Original string: %s\n", str);

    reverse_string(str);
    printf("Reversed string: %s\n", str);

    remove_vowels(str);
    printf("String without vowels: %s\n", str);

    char old = 'a';
    char new = 'x';
    replace_string(str, old, new);
    printf("String with %c replaced by %c: %s\n", old, new, str);

    return 0;
}