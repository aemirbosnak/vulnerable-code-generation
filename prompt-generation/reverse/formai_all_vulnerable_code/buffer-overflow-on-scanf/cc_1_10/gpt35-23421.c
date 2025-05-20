//FormAI DATASET v1.0 Category: Binary Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char* s);
char* convert(char num[], int baseFrom, int baseTo);

int main() {
    int baseFrom, baseTo;
    char num[1000];

    printf("Enter the number you want to convert: ");
    scanf("%s", num);

    printf("Enter the base of the number you want to convert (2-10): ");
    scanf("%d", &baseFrom);

    printf("Enter the base you want to convert to (2-10): ");
    scanf("%d", &baseTo);

    char* result = convert(num, baseFrom, baseTo);

    printf("The converted number is: %s\n", result);

    free(result);
    result = NULL;

    return 0;
}

char* convert(char num[], int baseFrom, int baseTo) {
    // Convert the number to base 10 first
    int numInBase10 = 0;
    int multiplier = 1;
    int i;

    for(i = strlen(num) - 1; i >= 0; i--) {
        if(num[i] >= '0' && num[i] <= '9') {
            numInBase10 += (num[i] - '0') * multiplier;
        }
        else {
            numInBase10 += (num[i] - 'a' + 10) * multiplier;
        }

        multiplier *= baseFrom;
    }

    // Convert the number to the desired base
    char* result = (char*) malloc(1000 * sizeof(char));
    int resultIndex = 0;

    while(numInBase10 > 0) {
        int remainder = numInBase10 % baseTo;
        numInBase10 /= baseTo;

        if(remainder >= 0 && remainder <= 9) {
            result[resultIndex++] = remainder + '0';
        }
        else {
            result[resultIndex++] = remainder - 10 + 'a';
        }
    }

    result = reverse(result);

    return result;
}

char* reverse(char* s) {
    char* result = (char*) malloc(strlen(s) + 1);
    int i;
    
    for(i = 0; i < strlen(s); i++) {
        result[i] = s[strlen(s) - i - 1];
    }

    result[i] = '\0';

    return result;
}