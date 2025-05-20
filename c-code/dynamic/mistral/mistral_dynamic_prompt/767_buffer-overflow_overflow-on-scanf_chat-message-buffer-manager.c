#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void echo_message(char *message) {
    write(STDOUT_FILENO, message, strlen(message));
}

void process_message() {
    char input[10];
    fgets(input, sizeof(input), stdin);
    printf("You said: ");
    echo_message(input);
}

int main() {
    printf("Welcome to Chat Buffer!\n");
    printf("Please enter your message and hit enter:\n");

    char buffer[5];
    char attack_msg[500] = "A" ; // Attacker's malicious payload

    while (1) {
        process_message();

        strncat(buffer, attack_msg, sizeof(attack_msg));

        if (strstr(buffer, "exit")) {
            break;
        }
    }

    printf("Closing Chat Buffer...\n");
    return 0;
}
