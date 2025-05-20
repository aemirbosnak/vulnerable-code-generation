#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void handle_message(char *buffer, int len) {
    if (len <= 0) {
        printf("Invalid message length\n");
        return;
    }

    printf("Received message:\n");
    printf("%s\n", buffer);

    // Assuming the message contains user data and could contain malicious data
    char *username = strtok(buffer, ": ");
    char *message = strtok(NULL, "\n");

    // Out of bounds write vulnerability starts here
    if (message && strlen(message) + strlen(username) + 2 < len) {
        // Write the username and the message back with some garbage at the end
        snprintf(buffer, len, "%s: %s%s\0xef\0xbf\0xbd", username, message, "\0");
    } else {
        printf("Message is too long\n");
    }

    printf("Sending message back to client:\n");
    printf("%s\n", buffer);
}

int main() {
    char buffer[100];
    int len;

    while (1) {
        printf("Enter message length: ");
        scanf("%d", &len);

        printf("Enter message: ");
        fflush(stdin);
        gets(buffer);

        handle_message(buffer, len);
    }

    return 0;
}
