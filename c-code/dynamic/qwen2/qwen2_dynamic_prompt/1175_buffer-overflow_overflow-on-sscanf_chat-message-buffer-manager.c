#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_message(char *buffer) {
    char name[20];
    int age;
    if (sscanf(buffer, "%s %d", name, &age) == 2) {
        printf("Name: %s, Age: %d\n", name, age);
    } else {
        printf("Invalid input format.\n");
    }
}

int main() {
    char buffer[BUFFER_SIZE];

    while (1) {
        printf("Enter a message (name age): ");
        fgets(buffer, sizeof(buffer), stdin);

        // Remove newline character if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        process_message(buffer);
    }

    return 0;
}
