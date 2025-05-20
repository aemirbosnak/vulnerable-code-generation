#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_input(char *input) {
    char buffer[10];
    int age;

    sscanf(input, "Player %s, %d years old.", buffer, &age);

    printf("Welcome, %s, you are %d years old.\n", buffer, age);
}

int main() {
    char input[256];

    printf("Enter your name and age separated by a space: ");
    fgets(input, sizeof(input), stdin);

    process_input(input);

    return 0;
}
