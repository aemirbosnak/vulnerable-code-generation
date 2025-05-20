//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100
#define MAX_STRING 100

typedef struct {
    char str[MAX_STRING];
    int len;
} StringRuins;

StringRuins char_apocalypse(StringRuins src, char c) {
    StringRuins dest;
    int i = 0;

    dest.len = 0;

    while (src.str[i] != '\0') {
        if (src.str[i] != c) {
            dest.str[dest.len++] = src.str[i];
        }
        i++;
    }

    return dest;
}

StringRuins string_merge(StringRuins str1, StringRuins str2) {
    StringRuins result;
    int len1 = str1.len, len2 = str2.len, i = 0, j = 0;

    result.len = len1 + len2;

    for (i = 0; i < len1; i++) {
        result.str[i] = str1.str[i];
    }

    for (j = 0; j < len2; j++) {
        result.str[len1 + j] = str2.str[j];
    }

    return result;
}

StringRuins random_string_generator(int length) {
    StringRuins str;
    int i, random_char;

    str.len = length;

    for (i = 0; i < length; i++) {
        random_char = rand() % 26 + 'a';
        str.str[i] = random_char;
    }

    str.str[length] = '\0';

    return str;
}

void print_string_ruins(StringRuins str) {
    int i;

    printf("Ruins of Language: ");

    for (i = 0; i < str.len; i++) {
        printf("%c", str.str[i]);
    }

    printf("\n");
}

int main() {
    StringRuins str1, str2, str3;
    char c;
    int length;

    srand(time(NULL));

    str1 = random_string_generator(10);
    print_string_ruins(str1);

    printf("Enter a character to remove from the first string: ");
    scanf("%c", &c);

    str2 = char_apocalypse(str1, c);
    print_string_ruins(str2);

    printf("Enter the length of the second string: ");
    scanf("%d", &length);

    str3 = random_string_generator(length);
    print_string_ruins(str3);

    str1 = string_merge(str2, str3);
    print_string_ruins(str1);

    return 0;
}