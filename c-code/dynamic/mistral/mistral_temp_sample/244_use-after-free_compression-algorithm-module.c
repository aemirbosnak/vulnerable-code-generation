#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024

typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block* next;
} Block;

Block* head = NULL;

void compress(char* input) {
    Block* current = head;
    int index = 0;

    while (input[index] != '\0') {
        if (!head) {
            head = (Block*)malloc(sizeof(Block));
            head->next = NULL;
            strncpy(head->data, &input[index], BLOCK_SIZE - 1);
            head->data[BLOCK_SIZE - 1] = '\0';
            index += BLOCK_SIZE;
        } else {
            while (current->next) {
                current = current->next;
            }

            current->next = (Block*)malloc(sizeof(Block));
            current = current->next;
            current->next = NULL;
            strncpy(current->data, &input[index], BLOCK_SIZE - 1);
            current->data[BLOCK_SIZE - 1] = '\0';
            index += BLOCK_SIZE;
        }
    }
}

void decompress(void) {
    Block* current = head;

    while (current) {
        printf("%s", current->data);
        current = current->next;
        free(head);
        head = current;
    }
}

int main() {
    char input[1024] = "This is a test for a pseudo compression algorithm.";
    compress(input);
    decompress();
    return 0;
}
