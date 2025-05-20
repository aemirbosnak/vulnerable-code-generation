//FormAI DATASET v1.0 Category: Text processing ; Style: puzzling
#include <stdio.h>
#include <string.h>

char* remove_repeats(char* str) {
    int i, j, k;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len;) {
            if (str[j] == str[i]) {
                for (k = j; k < len; k++) {
                    str[k] = str[k + 1];
                }
                len--;
            } else {
                j++;
            }
        }
    }
    return str;
}

char* apply_cipher(char* str, int shift) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (str[i] - 'a' + shift) % 26 + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (str[i] - 'A' + shift) % 26 + 'A';
        }
    }
    return str;
}

int main() {
    char str[100];
    int shift;
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    getchar();
    printf("Enter a shift value: ");
    scanf("%d", &shift);
    
    // Puzzle 1
    char* new_str = remove_repeats(str);
    printf("Original string: %s\n", str);
    printf("Modified string 1: %s\n\n", new_str);

    // Puzzle 2
    new_str = apply_cipher(str, shift);
    printf("Original string: %s\n", str);
    printf("Modified string 2: %s\n\n", new_str);

    return 0;
}