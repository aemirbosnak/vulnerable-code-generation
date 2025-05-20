//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 16

typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block* next;
} Block;

Block* encrypt(char* message) {
    Block* head = NULL;
    char key[KEY_LENGTH];
    scanf("Enter the key: ", key);
    // Key preparation
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] ^= 0x1F;
    }

    // Message processing
    char* ptr = message;
    while (*ptr) {
        Block* newBlock = malloc(sizeof(Block));
        newBlock->next = head;
        head = newBlock;

        // Block filling
        for (int i = 0; i < BLOCK_SIZE; i++) {
            if (*ptr) {
                newBlock->data[i] = (*ptr) ^ key[i % KEY_LENGTH];
            } else {
                newBlock->data[i] = 0;
            }
            ptr++;
        }
    }

    return head;
}

int main() {
    char message[1024];
    printf("Enter your message: ");
    scanf("%s", message);

    Block* head = encrypt(message);

    printf("Encrypted message:\n");
    for (Block* ptr = head; ptr; ptr = ptr->next) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            printf("%02x ", ptr->data[i]);
        }
        printf("\n");
    }

    return 0;
}