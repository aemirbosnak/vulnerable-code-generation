#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define SIZE 5

int main() {
    char name[SIZE];
    printf("Enter your name: ");
    gets(name);
    printf("Welcome, %s!\n", name);
    return 0;
}
