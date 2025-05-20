#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void parse_input(const char *input) {
    char name[20];
    int age;
    if (sscanf(input, "%s %d", name, &age) != 2) {
        printf("Invalid input format.\n");
        return;
    }
    printf("Name: %s\nAge: %d\n", name, age);
}

int main() {
    char input[100];
    printf("Enter your name and age: ");
    fgets(input, sizeof(input), stdin);
    parse_input(input);
    return 0;
}
