#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void replaceSubstring(char *str, const char *search, const char *replace) {
    char buffer[1024];
    int pos = 0;
    while (*str) {
        if (strncmp(str, search, strlen(search)) == 0) {
            strcpy(buffer + pos, replace);
            pos += strlen(replace);
            str += strlen(search);
        } else {
            buffer[pos++] = *str++;
        }
    }
    buffer[pos] = '\0';
    strcpy(str, buffer);
}

int main() {
    char input[1024], search[100], replace[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    printf("Enter the substring to search: ");
    scanf("%s", search);

    printf("Enter the substring to replace with: ");
    scanf("%s", replace);

    replaceSubstring(input, search, replace);

    printf("Modified string: %s\n", input);

    return 0;
}
