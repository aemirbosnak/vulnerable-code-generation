#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_MSG_LEN 100
#define BUFFER_SIZE 200

void process_message(char *message) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, "Received message: ");
    strcat(buffer, message);
    printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
    char input[MAX_MSG_LEN];
    printf("Enter chat message (up to %d characters):\n", MAX_MSG_LEN);
    fgets(input, MAX_MSG_LEN, stdin);

    process_message(input);

    char *extra_data = "Secret sauce";
    strcpy(input + strlen(input), extra_data); // Write beyond the bounds of input
    process_message(input); // Print the corrupted input

    return 0;
}
