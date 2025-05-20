//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void convert(char str[], int length, int base) {
    int i, j, k, remainder;
    char *result = malloc(length * 2 + 1);
    char *temp = malloc(length * 2 + 1);
    strcpy(temp, str);

    for (i = 0, j = strlen(temp) - 1; i < j; i++, j--) {
        str[i] = temp[j];
        str[j] = temp[i];
    }

    str[length] = '\0';

    for (i = 0; i < length; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }

    for (i = 0, j = strlen(str) - 1, k = 0; i <= j; i++, j--) {
        if (str[i] == '0') {
            str[i] = '1';
        } else if (str[i] == '1') {
            str[i] = '0';
        }

        remainder = str[i] - '0';
        result[k++] = (char) ((remainder * base) + str[j] - '0');
    }

    result[k] = '\0';

    printf("Binary: %s\n", result);

    free(temp);
    free(result);
}

int main() {
    char str[MAX_LENGTH];
    int length, base;

    printf("Enter a decimal number: ");
    scanf("%s", str);

    length = strlen(str);

    if (length == 0) {
        printf("Invalid input!\n");
        return 1;
    }

    if (str[0] == '0' && length > 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (length > 10) {
        printf("Number too large!\n");
        return 1;
    }

    printf("Enter the base (2-16): ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Invalid base!\n");
        return 1;
    }

    convert(str, length, base);

    return 0;
}