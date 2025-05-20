#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char text[1000], search[100], replace[100];
    int len_search, len_replace, i, j, k;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the word to search: ");
    fgets(search, sizeof(search), stdin);
    len_search = strlen(search);

    printf("Enter the replacement word: ");
    fgets(replace, sizeof(replace), stdin);
    len_replace = strlen(replace);

    for (i = 0; text[i] != '\0'; i++) {
        for (j = i, k = 0; j < i + len_search && text[j] != '\0'; j++, k++) {
            if (text[j] != search[k]) break;
        }
        if (k == len_search) {
            for (; k < len_replace; k++) {
                if (k + i >= sizeof(text)) {
                    printf("Error: Text string too small for replacement.\n");
                    return 1;
                }
                text[i + k] = replace[k];
            }
            for (; i + len_replace < sizeof(text) && text[i + len_replace] != '\0'; i++) {}
        }
    }

    printf("Modified text: %s\n", text);
    return 0;
}
