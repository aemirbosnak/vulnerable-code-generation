#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void send_message(char *message) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, message);
}

int main() {
    char malicious_message[20] = "This is a very long message that will overflow the buffer!";
    send_message(malicious_message);
    return 0;
}
