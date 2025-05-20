//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_SIZE 1000

void init() {
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}

int main() {
    init();
    int size = 0;
    char *buffer = NULL;

    while (1) {
        printf("\nEnter the size of the buffer (in bytes): ");
        scanf("%d", &size);

        if (size > MAX_SIZE) {
            printf("\nError: Buffer size is too large.\n");
            continue;
        }

        buffer = (char *)malloc(size);

        if (buffer == NULL) {
            printf("\nError: Memory allocation failed.\n");
            continue;
        }

        printf("\nEnter the data to be stored in the buffer: ");
        scanf("%s", buffer);

        printf("\nData stored in the buffer:\n%s\n", buffer);

        printf("\nEnter 1 to free the buffer, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        free(buffer);
        buffer = NULL;
        size = 0;
    }

    return 0;
}