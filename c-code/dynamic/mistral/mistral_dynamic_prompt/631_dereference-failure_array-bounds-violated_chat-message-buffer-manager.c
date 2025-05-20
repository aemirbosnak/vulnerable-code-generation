#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    char message[100];
} ChatMessage;

int main() {
    ChatMessage *messages = (ChatMessage*) malloc(5 * sizeof(ChatMessage));
    int num_messages = 0;

    while (1) {
        printf("Enter name: ");
        fgets(messages[num_messages].name, sizeof(messages[num_messages].name), stdin);
        printf("Enter message: ");
        fgets(messages[num_messages].message, sizeof(messages[num_messages].message), stdin);

        num_messages++;
        if (num_messages == 5) break;
        messages = realloc(messages, (num_messages + 1) * sizeof(ChatMessage));
    }

    int i;
    for (i = 0; i < num_messages; i++) {
        printf("\nName: %s\nMessage: %s\n", messages[i].name, messages[i].message);
        printf("Length of message: %ld\n", strlen(messages[i].message));
        printf("Index of newline: %d\n", strcspn(messages[i].message, "\n"));
        printf("Address of name: 0x%p\n", &messages[i].name);
        printf("Address of message: 0x%p\n", &messages[i].message);
        printf("Size of messages[%d]: %zu\n", i, sizeof(messages[i]));
    }

    // Intentional buffer overflow exploit
    printf("Enter extra input to trigger buffer overflow: ");
    fgets(messages[num_messages].name, sizeof(messages[num_messages].name), stdin);
    printf("Name buffer: %s\n", messages[num_messages].name);

    return 0;
}
