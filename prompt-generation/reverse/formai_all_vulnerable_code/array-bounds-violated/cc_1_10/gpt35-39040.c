//FormAI DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void paranoid_strcpy(char *dest, const char *src, size_t num) {
    if (num > MAX_LENGTH) {
        printf("Warning: String length exceeds maximum length.\n");
        num = MAX_LENGTH;
    }

    char *pos = strpbrk(src, "<>&\"\'"); // Check for special characters
    if (pos != NULL) {
        printf("Error: Detected special character '%c'\n", *pos);
        return;
    }

    strncpy(dest, src, num);

    printf("Copied string: %s\n", dest);
}

void replace_special_characters(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case '<':
                str[i] = '(';
                break;
            case '>':
                str[i] = ')';
                break;
            case '&':
                str[i] = '+';
                break;
            case '\"':
                str[i] = '#';
                break;
            case '\'':
                str[i] = '/';
                break;
        }
    }

    printf("Replaced string: %s\n", str);
}

int main() {
    char orig_str[MAX_LENGTH], new_str[MAX_LENGTH];
    int num_chars;

    printf("Enter a string: ");
    fgets(orig_str, MAX_LENGTH, stdin);
    num_chars = strnlen(orig_str, MAX_LENGTH);
    if (num_chars > 0 && orig_str[num_chars - 1] == '\n') {
        orig_str[num_chars - 1] = '\0'; // Remove newline character
    }

    paranoid_strcpy(new_str, orig_str, MAX_LENGTH);
    replace_special_characters(new_str);

    return 0;
}