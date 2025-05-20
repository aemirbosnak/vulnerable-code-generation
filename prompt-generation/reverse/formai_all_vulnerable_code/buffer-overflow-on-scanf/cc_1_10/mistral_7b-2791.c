//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define KEY_SIZE 32
#define DATA_SIZE 1024

typedef struct {
    int id;
    char name[20];
    char key[KEY_SIZE];
} Node;

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = (rand() % 256);
    }
}

int hash(char *str, int len) {
    int hash = 0;
    int i;

    for (i = 0; i < len; i++) {
        hash = ((hash << 5) + hash) + str[i];
    }

    return hash % DATA_SIZE;
}

void compress(char *data, int size, char *compressed_data, int *compressed_size) {
    int i, j;
    char run_length[256];
    char *ptr = compressed_data;

    for (i = 0; i < size; i++) {
        if (i > 0 && data[i] == data[i - 1]) {
            if (run_length[data[i]]++)
                continue;
            *ptr++ = data[i];
            sprintf(ptr, "%d", run_length[data[i]]);
            ptr += strlen(ptr);
        } else {
            *ptr++ = data[i];
        }
    }

    *compressed_size = ptr - compressed_data;
}

int main() {
    int i, j;
    char data[DATA_SIZE];
    char compressed_data[DATA_SIZE];
    int compressed_size;
    Node nodes[10];

    srand(time(NULL));

    for (i = 0; i < 10; i++) {
        printf("Enter node name: ");
        scanf("%s", nodes[i].name);

        generate_key(&nodes[i].key);

        printf("Node %s key: ", nodes[i].name);
        for (j = 0; j < KEY_SIZE; j++) {
            printf("%02x ", nodes[i].key[j]);
        }
        printf("\n");
    }

    printf("\nEnter data to compress: ");
    scanf("%s", data);

    compress(data, strlen(data), compressed_data, &compressed_size);

    printf("\nCompressed data size: %d", compressed_size);

    return 0;
}