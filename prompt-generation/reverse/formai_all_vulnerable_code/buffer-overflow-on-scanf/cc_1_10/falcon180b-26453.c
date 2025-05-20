//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

char *reverse_string(char *str) {
    int length = strlen(str);
    char *reverse = malloc(length + 1);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        reverse[i] = str[j];
        reverse[j] = str[i];
    }
    reverse[i] = '\0';
    return reverse;
}

int is_palindrome(char *str) {
    char *reverse = reverse_string(str);
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i]!= reverse[i]) {
            free(reverse);
            return 0;
        }
    }
    free(reverse);
    return 1;
}

char *random_string(int length) {
    char *str = malloc(length + 1);
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        str[i] = rand() % 26 + 'a';
    }
    str[length] = '\0';
    return str;
}

int main() {
    int length;
    printf("Enter the length of the string: ");
    scanf("%d", &length);
    char *str = random_string(length);
    printf("Random string: %s\n", str);
    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }
    free(str);
    return 0;
}