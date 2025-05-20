//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000
#define MAX_CODES 100

typedef struct {
    char ch;
    int code;
} Code;

Code alphabet[26] = {
    {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9},
    {'k', 10}, {'l', 11}, {'m', 12}, {'n', 13}, {'o', 14}, {'p', 15}, {'q', 16}, {'r', 17}, {'s', 18},
    {'t', 19}, {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23}, {'y', 24}, {'z', 25}
};

void buildTable(char text[], int freq[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        freq[i] = 0;
    }
    for (i = 0; i < strlen(text); i++) {
        freq[text[i]]++;
    }
    for (i = 1; i < n; i++) {
        freq[i] += freq[i - 1];
    }
}

void encode(char text[], int freq[], int n) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        printf("%c", alphabet[text[i] - 'a'].ch);
    }
}

void decode(char code[], int freq[], int n) {
    int i, j;
    for (i = 0; i < strlen(code); i++) {
        for (j = 0; j < n; j++) {
            if (code[i] == alphabet[j].ch) {
                printf("%c", j + 'a');
                break;
            }
        }
    }
}

int main() {
    char text[MAX_CHARS];
    char code[MAX_CHARS];
    int freq[MAX_CHARS];
    int i, n;
    printf("Enter the text: ");
    scanf("%s", text);
    n = strlen(text);
    buildTable(text, freq, n);
    encode(text, freq, n);
    printf("\nEncoded text: %s\n", code);
    printf("Decoded text: ");
    decode(code, freq, n);
    printf("\n");
    return 0;
}