//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int count_bits(int num);

int main() {
    char str[MAX_LEN];
    int len, i, j, k, num;

    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);

    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (isspace(str[i])) {
            str[i] = '\0';
            len = i;
            break;
        }
    }

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Number of bits in %d is: %d\n", num, count_bits(num));
    printf("Binary representation of %d is: ", num);
    for (i = 0; i < 32; i++) {
        if ((num & (1 << i))!= 0) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");

    return 0;
}

int count_bits(int num) {
    int count = 0;
    while (num!= 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    return count;
}