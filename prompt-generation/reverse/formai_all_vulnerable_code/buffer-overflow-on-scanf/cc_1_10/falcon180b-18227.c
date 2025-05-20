//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 1000000
#define MAX_STRING_LENGTH 100

void paranoid_string_copy(char* dest, char* src) {
    int i = 0;
    while (src[i]!= '\0') {
        if (i >= MAX_STRING_LENGTH) {
            printf("Error: String too long\n");
            exit(1);
        }
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void paranoid_array_copy(int* dest, int* src, int n) {
    int i = 0;
    while (i < n) {
        if (i >= MAX_ITERATIONS) {
            printf("Error: Array too large\n");
            exit(1);
        }
        dest[i] = src[i];
        i++;
    }
}

int main() {
    char string1[MAX_STRING_LENGTH];
    char string2[MAX_STRING_LENGTH];
    int array1[MAX_ITERATIONS];
    int array2[MAX_ITERATIONS];

    printf("Enter a string: ");
    scanf("%s", string1);

    printf("Enter another string: ");
    scanf("%s", string2);

    paranoid_string_copy(string1, string2);

    printf("Enter an array of integers: ");
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Enter another array of integers: ");
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        scanf("%d", &array2[i]);
    }

    paranoid_array_copy(array1, array2, MAX_ITERATIONS);

    return 0;
}