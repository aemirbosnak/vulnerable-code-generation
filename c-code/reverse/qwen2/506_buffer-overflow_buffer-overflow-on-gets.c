#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char buffer[50];
    int num;

    printf("Enter a string: ");
    gets(buffer); // Vulnerable function

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0) {
        for (int i = 0; i <= num; i++) { // Off-by-one error
            buffer[i] += 'A';
        }
    }

    printf("Result: %s\n", buffer);
    return 0;
}
