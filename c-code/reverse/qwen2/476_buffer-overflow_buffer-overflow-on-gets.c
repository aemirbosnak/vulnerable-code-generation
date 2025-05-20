#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void replace(char *str, const char *old, const char *new) {
    char buffer[1024];
    int pos = 0;
    while (*str) {
        if (strncmp(str, old, strlen(old)) == 0) {
            strcpy(buffer + pos, new);
            pos += strlen(new);
            str += strlen(old);
        } else {
            buffer[pos++] = *str++;
        }
    }
    buffer[pos] = '\0';
    strcpy(str - strlen(old), buffer);
}

int main() {
    char str[1024];
    printf("Enter a string: ");
    gets(str); // Vulnerable to buffer overflow
    printf("Enter the substring to replace: ");
    char old[100];
    gets(old); // Vulnerable to buffer overflow
    printf("Enter the replacement substring: ");
    char new[100];
    gets(new); // Vulnerable to buffer overflow
    replace(str, old, new);
    printf("Modified string: %s\n", str);
    return 0;
}
