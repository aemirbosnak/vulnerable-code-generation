#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_input(const char *input) {
    char name[50], id[20];
    int age;

    if (strlen(input) > 100) {
        printf("Input too long\n");
        return;
    }

    if (sscanf(input, "%s %d", name, &age) != 2) {
        printf("Invalid input format\n");
        return;
    }

    if (age < 0 || age > 120) {
        printf("Age out of range\n");
        return;
    }

    if (strlen(name) > 49) {
        printf("Name too long\n");
        return;
    }

    if (sscanf(input, "%[^ ] %d", name, &age) != 2) {
        printf("Invalid input format\n");
        return;
    }

    if (age < 0 || age > 120) {
        printf("Age out of range\n");
        return;
    }

    if (strlen(name) > 49) {
        printf("Name too long\n");
        return;
    }

    if (sscanf(input, "%s %d", name, &age) != 2) {
        printf("Invalid input format\n");
        return;
    }

    if (age < 0 || age > 120) {
        printf("Age out of range\n");
        return;
    }

    if (strlen(name) > 49) {
        printf("Name too long\n");
        return;
    }

    printf("Name: %s, Age: %d\n", name, age);
}

int main() {
    char input[101];

    printf("Enter name and age: ");
    fgets(input, sizeof(input), stdin);

    process_input(input);

    return 0;
}
