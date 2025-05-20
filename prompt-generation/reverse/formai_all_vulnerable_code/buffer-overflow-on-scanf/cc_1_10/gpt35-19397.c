//FormAI DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
/* Romeo and Juliet C Memory Management Example */
/* Act I */

#include <stdio.h>
#include <stdlib.h>

#define LOVE 100

struct Memory {
    int size;
    char* data;
};

typedef struct Memory Memory;

typedef enum {
    SUCCESS = 0,
    FAILURE = -1
} status;


int main() {
    Memory* romeos_memory = (Memory*)malloc(sizeof(Memory));
    if (romeos_memory == NULL) {
        printf("Romeo's memory allocation failed!");
        exit(FAILURE);
    }
    romeos_memory->size = LOVE;
    romeos_memory->data = (char*)malloc(LOVE * sizeof(char));
    if (romeos_memory->data == NULL) {
        printf("Romeo's memory allocation failed!");
        exit(FAILURE);
    }
    printf("Romeo has allocated %d bytes of memory and filled it with %d love.\n", romeos_memory->size, romeos_memory->size);

    Memory* juliet_memory = (Memory*)malloc(sizeof(Memory));
    if (juliet_memory == NULL) {
        printf("Juliet's memory allocation failed!");
        exit(FAILURE);
    }
    juliet_memory->size = 0;
    juliet_memory->data = NULL;

    printf("\n");

/* Act II */

    printf("Enter the size of memory Juliet needs: ");
    scanf("%d", &(juliet_memory->size));

    juliet_memory->data = (char*)malloc(juliet_memory->size * sizeof(char));
    if (juliet_memory->data == NULL) {
        printf("Juliet's memory allocation failed!");
        exit(FAILURE);
    }
    printf("\nEnter the message for Juliet: ");
    scanf(" %[^\n]", juliet_memory->data);

    printf("\n");

/* Act III */

    printf("Juliet's memory: %s\n", juliet_memory->data);

    printf("\n");

/* Act IV */

    free(romeos_memory->data);
    free(romeos_memory);
    free(juliet_memory->data);
    free(juliet_memory);

    printf("Romeo and Juliet's memory has been freed.");

    return SUCCESS;
}
/* End of Play */