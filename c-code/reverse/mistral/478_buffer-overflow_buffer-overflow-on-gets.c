#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void strReplace(char *str, char *search, char *replace) {
    char temp[1000];
    int i, j, len_search = strlen(search), len_replace = strlen(replace), len_str = strlen(str);

    for (i = j = 0; i < len_str; ++i) {
        if (i + len_search <= len_str && strncmp(str + i, search, len_search) == 0) {
            strncpy(temp + j, str + i + len_search, len_str - (i + len_search));
            j += len_str - (i + len_search);
            strncpy(temp + j, replace, len_replace);
            j += len_replace;
            i += len_search - 1;
        } else {
            temp[j++] = str[i];
        }
    }

    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char str[1000], search[100], replace[100];

    printf("Enter the string: ");
    gets(str);
    printf("Enter the search string: ");
    gets(search);
    printf("Enter the replacement string: ");
    gets(replace);

    strReplace(str, search, replace);
    printf("Modified string: %s\n", str);

    return 0;
}
