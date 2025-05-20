#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct ChatMessage {
    char message[1024];
    char username[32];
    char timestamp[32];
} ChatMessage;

void read_message(ChatMessage* msg, FILE* fp) {
    fscanf(fp, "%s %s %s", msg->username, msg->message, msg->timestamp);
}

void write_message(const ChatMessage* msg, FILE* fp) {
    fprintf(fp, "%s: %s (%s)\n", msg->username, msg->message, msg->timestamp);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening log file");
        return 1;
    }

    ChatMessage messages[1000];
    int num_messages = 0;

    while (1) {
        ChatMessage msg;
        read_message(&msg, fp);

        // Assume that the input file contains a maximum of 1000 messages
        if (num_messages >= 1000) {
            printf("Too many messages! File corrupted.\n");
            break;
        }

        messages[num_messages++] = msg;
    }

    // Now, read one more message and access it out of bounds to demonstrate the issue
    ChatMessage extra_msg;
    read_message(&extra_msg, fp);
    printf("Accessing out of bounds message: %s\n", extra_msg.message[1024]);

    for (int i = 0; i < num_messages; ++i) {
        write_message(&messages[i], stdout);
    }

    fclose(fp);
    return 0;
}
