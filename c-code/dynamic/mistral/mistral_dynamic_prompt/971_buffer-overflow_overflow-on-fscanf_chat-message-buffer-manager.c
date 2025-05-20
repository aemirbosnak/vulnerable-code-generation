#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void read_message(char *buffer, int size) {
    printf("Enter your chat message (max %d characters):\n", size);
    fscanf(stdin, "%s", buffer);
}

void print_messages(char *messages[], int num_messages) {
    for (int i = 0; i < num_messages; ++i) {
        printf("%s\n", messages[i]);
    }
}

int main() {
    char messages[3][256];
    int num_messages = 0;

    while (num_messages < 3) {
        read_message(messages[num_messages], sizeof(messages[num_messages]));
        num_messages++;
    }

    print_messages(messages, num_messages);

    return 0;
}
