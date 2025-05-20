//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
/* Let's benchmark our favorite function! */
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_STRING 1000000

/* Our favorite function */
void string_reverse(char* str, int len) {
    int i, j;
    char ch;
    for(i = 0, j = len - 1; i < j; i++, j--) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
}

int main() {
    char str[MAX_STRING];
    int n, len, i;
    clock_t start, end;
    double cpu_time_used;

    printf("Welcome to String Reverse Benchmarking Program!\n");

    /* Get input from user */
    do {
        printf("Enter the number of strings (between 1 and 10): ");
        scanf("%d", &n);
    } while(n < 1 || n > 10);

    for(i = 0; i < n; i++) {
        printf("Enter string %d: ", i+1);
        scanf("%s", &str);
        len = strlen(str);

        /* Benchmarking */
        start = clock();
        string_reverse(str, len);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("The reversed string is: %s\n", str);
        printf("Time taken to reverse the string: %f seconds\n", cpu_time_used);
    }

    printf("Thank you for benchmarking with us!");
    return 0;
}