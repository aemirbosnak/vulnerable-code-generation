//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int is_palindrome(char *str, int left, int right);
int main(void) {
    char input[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strlen(input) > MAX_LENGTH) {
        printf("String is too long.\n");
        return 1;
    }
    if (is_palindrome(input, 0, strlen(input) - 1)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }
    return 0;
}

int is_palindrome(char *str, int left, int right) {
    if (left >= right) {
        return 1;
    }
    if (tolower(str[left]) != tolower(str[right])) {
        return 0;
    }
    char arr[256] = {0};
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (arr[tolower(str[i])] > 0) {
            return 0;
        }
        arr[tolower(str[i])]++;
        len++;
    }
    int *char_arr = (int *)malloc(len * sizeof(int));
    int index1 = 0, index2 = len - 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z') {
            char_arr[index1++] = left++;
            char_arr[index2--] = right--;
        } else {
            left++;
            right--;
        }
    }
    for (int i = 0; i < len / 2; i++) {
        if (char_arr[i] != char_arr[len - i - 1]) {
            free(char_arr);
            return 0;
        }
    }
    free(char_arr);
    return 1;
}