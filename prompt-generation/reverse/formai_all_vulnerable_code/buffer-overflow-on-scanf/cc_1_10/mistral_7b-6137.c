//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct squid {
    char data[256];
    int length;
    struct squid *next;
} squid;

squid *head = NULL;

void compress(char *input, int size) {
    squid *new_squid = (squid *)malloc(sizeof(squid));

    strncpy(new_squid->data, input, size);
    new_squid->length = size;
    new_squid->next = head;
    head = new_squid;
}

int find_squid(char *input, int size) {
    squid *current = head;

    while (current != NULL) {
        if (strlen(current->data) >= size && strncmp(current->data, input, size) == 0) {
            return current->length;
        }
        current = current->next;
    }

    return -1;
}

void decompress(char *output, int offset, int length) {
    squid *current = head;
    int index = 0;

    while (current != NULL && index < offset) {
        index += current->length;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Invalid offset.\n");
        return;
    }

    strncpy(output, current->data + offset - length, length);
}

int main() {
    char input[1024];
    char output[1024];
    int size, offset, length;

    while (1) {
        printf("Enter the data to compress (type 'decompress' to decompress): ");
        scanf("%s", input);

        if (strcmp(input, "decompress") == 0) {
            printf("Enter the offset: ");
            scanf("%d", &offset);
            printf("Enter the length: ");
            scanf("%d", &length);

            decompress(output, offset, length);
            printf("Decompressed data: %s\n", output);
        } else {
            size = strlen(input);
            compress(input, size);
            printf("Compressed data size: %d\n", size);
        }
    }

    squid *temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Squishy the Squid, the lovable compression algorithm
// Gobbles up your data and keeps it safe in his big, stretchy tentacles
// Whenever you need to decompress, just feed him the right offset and length
// He'll squirt out the compressed data for you!