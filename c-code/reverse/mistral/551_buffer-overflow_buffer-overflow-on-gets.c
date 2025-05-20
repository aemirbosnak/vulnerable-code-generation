#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int count_smileys(char *str) {
    int count = 0;
    int i, j;
    for (i = 0; i < strlen(str) && i + 3 <= strlen(str); i++) {
        if (str[i] == ':' && str[i + 1] == '-' && (str[i + 2] == ')' || str[i + 2] == '~')) {
            if (i + 3 < strlen(str) && (str[i + 3] == ' ' || str[i + 3] == '\0')) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    char input[MAX_LENGTH];
    printf("Enter a statement: ");
    fgets(input, MAX_LENGTH, stdin);
    int count = count_smileys(input);
    if (count > 0) {
        printf("Happy\n");
    } else if (count == 0) {
        printf("Neutral\n");
    } else {
        printf("Sad\n");
    }
    return 0;
}
