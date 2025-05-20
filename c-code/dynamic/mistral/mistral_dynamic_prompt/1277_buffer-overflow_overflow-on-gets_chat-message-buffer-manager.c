#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void display_chat_messages(char** messages) {
    int i;
    for (i = 0; messages[i] != NULL; i++) {
        printf("%s\n", messages[i]);
    }
}

int main(int argc, char* argv[]) {
    char messages[10][BUFFER_SIZE];
    int count = 0;
    char input[BUFFER_SIZE];

    printf("Welcome to the Insecure Chat Application!\n");

    while (1) {
        printf("Enter message %d or type 'exit' to quit: ", count + 1);
        gets(input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        strcpy(messages[count], input);
        count++;
    }

    printf("\nMessages:\n");
    display_chat_messages(messages);

    return 0;
}
