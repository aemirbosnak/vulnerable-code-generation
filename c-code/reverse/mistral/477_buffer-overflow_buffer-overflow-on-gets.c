#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int str_replace(char *str, const char *search, const char *replace) {
    char *new_str = malloc(strlen(str) + strlen(replace) - strlen(search) + 1);
    int count = 0, i = 0, j = 0;
    if (!new_str) return -1;

    for (; str[i] || j < strlen(search); i++) {
        if (i >= strlen(str) || str[i] == search[j]) {
            new_str[count++] = (i < strlen(str) && str[i] == search[j]) ? replace[j] : str[i];
            j++;
        }
    }

    for (; *replace; count++) new_str[count] = *replace++;
    new_str[count] = '\0';

    free(str);
    str = new_str;

    return 0;
}

int main() {
    char str[100], search[50], replace[50];
    printf("Enter the original string: ");
    scanf("%s", str);
    printf("Enter the string to search: ");
    scanf("%s", search);
    printf("Enter the replacement string: ");
    scanf("%s", replace);

    str_replace(str, search, replace);
    printf("Modified string: %s\n", str);

    return 0;
}
