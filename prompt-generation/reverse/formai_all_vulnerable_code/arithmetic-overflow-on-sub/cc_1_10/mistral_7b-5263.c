//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256
#define MAX_LINE 1024

void print_array(char arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%c", arr[i]);
    printf("\n");
}

void transform(char *str, int len) {
    int i, j, k;
    char temp;

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void shift_left(char *str, int len, int num) {
    int i;
    char temp;

    for (i = 0; i < num; i++) {
        if (len - i > 0) {
            temp = str[0];
            for (int j = 0; j < len - i - 1; j++) {
                str[j] = str[j + 1];
            }
            str[len - i] = temp;
        }
    }
}

void shift_right(char *str, int len, int num) {
    int i;
    char temp;

    for (i = len - num; i < len; i++) {
        if (i < len) {
            temp = str[i];
            for (int j = i + 1; j < len; j++) {
                str[j - 1] = str[j];
            }
            str[0] = temp;
        }
    }
}

int main() {
    char input[MAX_LINE];
    char operation, char_array[MAX_CHAR];
    int len, num;

    printf("Enter a string: ");
    fgets(input, MAX_LINE, stdin);

    len = strlen(input);
    print_array(input, len);

    printf("\nEnter an operation:\n1. Transform to lowest case.\n2. Shift left.\n3. Shift right.\n");
    scanf(" %c", &operation);

    switch (operation) {
        case '1':
            for (int i = 0; i < len; i++) {
                if (isalpha(input[i])) {
                    input[i] = tolower(input[i]);
                }
            }
            print_array(input, len);
            break;
        case '2':
            printf("Enter the number of shifts: ");
            scanf("%d", &num);
            shift_left(input, len, num);
            print_array(input, len);
            break;
        case '3':
            printf("Enter the number of shifts: ");
            scanf("%d", &num);
            shift_right(input, len, num);
            print_array(input, len);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }

    transform(input, len);
    printf("Transformed string: ");
    print_array(input, len);

    return 0;
}