#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 20

int main() {
    char name[MAX_NAME_LENGTH];
    int age;

    printf("Enter your name: ");
    fscanf(stdin, "%s", name);

    printf("Enter your age: ");
    fscanf(stdin, "%d", &age);

    printf("Name: %s\nAge: %d\n", name, age);

    return 0;
}
