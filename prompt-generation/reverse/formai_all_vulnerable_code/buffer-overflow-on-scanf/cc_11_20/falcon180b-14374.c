//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_NUM_SIZE 1000
#define BASE 2

int main() {
    char num[MAX_NUM_SIZE];
    printf("Enter a number: ");
    scanf("%s", num);

    int len = strlen(num);
    int i = 0;
    while (len--) {
        if (num[len] == '.') {
            break;
        }
        if (num[len] == '-') {
            continue;
        }
        if (num[len] >= '0' && num[len] <= '9') {
            continue;
        } else {
            printf("Invalid character '%c' at position %d\n", num[len], i);
            exit(1);
        }
    }

    if (len == 0) {
        printf("Invalid number\n");
        exit(1);
    }

    printf("Binary representation: ");
    for (int j = 0; j <= len; j++) {
        if (j == len) {
            printf(".");
        } else if (j == 0) {
            printf("0");
        } else if (num[j] == '.') {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");

    return 0;
}