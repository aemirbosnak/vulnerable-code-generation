#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100
#define MESSAGE_SIZE 200

char buffer[BUFFER_SIZE];
int capacity = BUFFER_SIZE;
int head = 0;
int tail = 0;

void write_message(char* msg) {
    int len = strlen(msg);
    if ((tail - head + len) > capacity) {
        printf("Error: Buffer overflow.\n");
        return;
    }

    memcpy(&buffer[head], msg, len);
    tail = (tail + len) % capacity;
}

void read_message() {
    if (head == tail) {
        printf("No messages in the buffer.\n");
        return;
    }

    int len = tail - head;
    if (len > capacity) {
        len = capacity;
    }

    printf("Message: %s\n", &buffer[head]);
    head = (head + len) % capacity;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: chat_buffer <message>\n");
        return 1;
    }

    write_message(argv[1]);
    read_message();

    while (1) {
        char msg[MESSAGE_SIZE];
        fgets(msg, MESSAGE_SIZE, stdin);
        write_message(msg);
        read_message();
    }

    return 0;
}
