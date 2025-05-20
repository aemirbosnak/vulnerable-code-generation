//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: immersive
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void print_string_left_right(char *str, int times) {
    int len = strlen(str);
    for (int i = 0; i < times; i++) {
        printf("%s\n", str);
        for (int j = len - 1; j >= 0; j--) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

void print_string_middle_out(char *str, int times) {
    int len = strlen(str);
    for (int i = 0; i < times; i++) {
        for (int j = len / 2; j >= 0; j--) {
            printf("%c", str[len - j]);
        }
        printf("%s\n", str);
        for (int k = 0; k < len / 2; k++) {
            printf("%c", str[k]);
        }
        printf("\n");
    }
}

int main() {
    char str[MAX_STR_LEN];
    int times;

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Enter the number of times to print the string: ");
    scanf("%d", &times);

    printf("\nOriginal string:\n");
    printf("%s\n", str);

    reverse_string(str);
    printf("\nReversed string:\n");
    printf("%s\n", str);

    print_string_left_right(str, times);

    printf("\n");

    print_string_middle_out(str, times);

    return 0;
}