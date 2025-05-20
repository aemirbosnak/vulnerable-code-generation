#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void handle_message(char *buffer) {
    char name[20];
    int age;

    sscanf(buffer, "%s %d", name, &age);

    printf("Received message from %s (age: %d)\n", name, age);
}

int main() {
    char input_buffer[BUFFER_SIZE];
    char malicious_input[] = "EvilAttackerAgeIs18290848372908487";

    printf("Chat Message Manager v1.0\n");
    printf("Enter a chat message in the format: name age\n");

    while (1) {
        printf("\nEnter message: ");
        fgets(input_buffer, BUFFER_SIZE, stdin);
        handle_message(input_buffer);
    }

    return 0;
}
