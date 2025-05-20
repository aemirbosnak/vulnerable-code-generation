//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 64

typedef struct Node {
    char data[BLOCK_SIZE];
    struct Node* next;
} Node;

Node* createNode() {
    return malloc(sizeof(Node));
}

void encryptFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return;
    }

    char key[KEY_LENGTH];
    printf("Enter key: ");
    scanf("%s", key);

    Node* head = NULL;
    char block[BLOCK_SIZE];

    while (fread(block, 1, BLOCK_SIZE, file) != 0) {
        block[0] = (block[0] ^ key[0]) & 0xFF;
        block[1] = (block[1] ^ key[1]) & 0xFF;
        block[2] = (block[2] ^ key[2]) & 0xFF;

        Node* newNode = createNode();
        memcpy(newNode->data, block, BLOCK_SIZE);
        newNode->next = head;
        head = newNode;
    }

    fclose(file);

    // Print encrypted data
    printf("Encrypted data:\n");
    for (Node* node = head; node; node = node->next) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            printf("%02x ", node->data[i]);
        }
        printf("\n");
    }
}

int main() {
    encryptFile("my_file.txt");

    return 0;
}