#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void main() {
    char name[10];
    printf("Welcome to the Adventure Game!\n");
    printf("Enter your name: ");
    scanf("%s", name);

    printf("\nHello, %s! You have embarked on a perilous journey...\n", name);

    // Buffer overflow vulnerability
    char buffer[5];
    strcpy(buffer, name);
    printf("Your name has been stored in a secret location: %s\n", buffer);
}
