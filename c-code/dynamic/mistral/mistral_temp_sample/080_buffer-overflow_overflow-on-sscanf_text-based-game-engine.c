#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_input(char *user_input) {
    int num;
    char name[10];

    printf("Enter your character's name (up to 10 characters): ");
    sscanf(user_input, "%s %d", name, &num);

    printf("Welcome, %s! Your character level is set to %d.\n", name, num);
}

int main() {
    char input[256];

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name and character level (e.g. 'Alice 12'):\n");

    fgets(input, sizeof(input), stdin);
    process_input(input);

    return 0;
}
