#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void process_message(char *message) {
    char user[BUFFER_SIZE];
    char msg[BUFFER_SIZE];

    printf("Enter your username: ");
    fgets(user, BUFFER_SIZE, stdin);
    printf("Enter your message: ");
    fgets(msg, BUFFER_SIZE, stdin);

    // Concatenate user and message
    char *result = malloc((strlen(user) + strlen(msg) + 1) * sizeof(char));
    strcpy(result, user);
    strcat(result, msg);

    // Print the combined message for demonstration
    printf("You said: %s\n", result);

    // Intentionally out-of-bounds read for demonstration
    printf("The %dth character in the combined message is: %c\n", BUFFER_SIZE + 1, *(result + BUFFER_SIZE));
}

int main() {
    process_message(NULL);
    return 0;
}
