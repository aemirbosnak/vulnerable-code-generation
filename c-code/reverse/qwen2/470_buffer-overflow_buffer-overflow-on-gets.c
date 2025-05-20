#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
    char input[MAX_LEN];
    char search[MAX_LEN];
    char replace[MAX_LEN];
    char output[MAX_LEN] = "";
    int i, j, k;

    printf("Enter the text: ");
    gets(input);
    printf("Enter the word to search: ");
    gets(search);
    printf("Enter the word to replace: ");
    gets(replace);

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == search[0]) {
            int match = 1;
            for (j = 1; search[j] != '\0'; j++) {
                if (input[i + j] != search[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                strcat(output, replace);
                i += strlen(search) - 1;
            } else {
                strncat(output, &input[i], 1);
            }
        } else {
            strncat(output, &input[i], 1);
        }
    }

    printf("Modified text: %s\n", output);

    return 0;
}
