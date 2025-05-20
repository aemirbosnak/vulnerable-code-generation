//FormAI DATASET v1.0 Category: Compression algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

/* Compression function */
void compress(char *data)
{
    int len = strlen(data);
    char compressed[MAX_SIZE];
    int consecutive_count = 1;
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (i + 1 < len && data[i] == data[i+1]) {
            consecutive_count++;
        } else {
            compressed[j++] = data[i];
            compressed[j++] = (char) (consecutive_count + '0');
            consecutive_count = 1;
        }
    }

    compressed[j] = '\0';

    printf("Compressed Data: %s\n", compressed);
}

/* Decompression function */
void decompress(char *data)
{
    int len = strlen(data);
    char decompressed[MAX_SIZE];
    int j = 0;

    for (int i = 0; i < len; i += 2) {
        int count = data[i+1] - '0';
        for (int k = 0; k < count; k++) {
            decompressed[j++] = data[i];
        }
    }

    decompressed[j] = '\0';

    printf("Decompressed Data: %s\n", decompressed);
}

int main()
{
    char data[MAX_SIZE];
    int choice;

    printf("Enter the data to be compressed: ");
    fgets(data, MAX_SIZE, stdin);
    data[strcspn(data, "\n")] = 0;

    printf("\nChoose an option:\n");
    printf("1. Compress Data\n");
    printf("2. Decompress Data\n");
    printf("Option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            compress(data);
            break;
        case 2:
            decompress(data);
            break;
        default:
            printf("Invalid Option\n");
            break;
    }

    return 0;
}