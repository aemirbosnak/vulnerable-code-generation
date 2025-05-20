//FormAI DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void error_handler(int error_code) {
    switch (error_code) {
        case 1:
            printf("Error: Division by zero not allowed.\n");
            break;
        case 2:
            printf("Error: Invalid input detected.\n");
            break;
        case 3:
            printf("Error: File not found.\n");
            break;
        case 4:
            printf("Error: Memory allocation failed.\n");
            break;
        default:
            printf("Unknown error occurred.\n");
            break;
    }
}

int main() {
    int num1, num2;
    char str[50];
    FILE *fp;

    printf("Enter two numbers separated by a space: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        error_handler(2);
        return 1;
    }

    if (num2 == 0) {
        error_handler(1);
        return 1;
    }

    printf("%d divided by %d is %d\n", num1, num2, num1 / num2);

    printf("Enter a file name: ");
    if (scanf("%s", str) != 1) {
        error_handler(2);
        return 1;
    }

    fp = fopen(str, "r");
    if (fp == NULL) {
        error_handler(3);
        return 1;
    }

    char *text = malloc(25 * sizeof(char));
    if (text == NULL) {
        error_handler(4);
        return 1;
    }

    fscanf(fp, "%s", text);
    printf("Contents of file: %s\n", text);

    free(text);
    fclose(fp);

    return 0;
}