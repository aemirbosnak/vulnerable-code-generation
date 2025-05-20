#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_input(char *input) {
    char name[10];
    int age;

    printf("Enter your name (max 10 chars): ");
    sscanf(input, "%s %d", name, &age);

    // Assuming the name is always less than 10 characters, which is not the case in a real-world scenario
    printf("Welcome, %s! You are %d years old.\n", name, age);
}

int main() {
    char buffer[256];
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name and age (format: name age): ");
    fgets(buffer, sizeof(buffer), stdin);

    process_input(buffer);

    return 0;
}
