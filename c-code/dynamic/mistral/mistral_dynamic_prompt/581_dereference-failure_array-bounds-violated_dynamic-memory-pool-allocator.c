#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJECTS 1024
#define OBJECT_SIZE 64

typedef struct PoolObject {
    char data[OBJECT_SIZE];
    struct PoolObject *next;
} PoolObject;

PoolObject *poolHead = NULL;
PoolObject *poolTail = NULL;

void allocate(size_t size) {
    PoolObject *newObject = (PoolObject *)malloc(sizeof(PoolObject) + size);
    if (!newObject) {
        fprintf(stderr, "Out of memory\n");
        return;
    }

    newObject->next = NULL;
    if (!poolHead) {
        poolHead = newObject;
        poolTail = newObject;
    } else {
        poolTail->next = newObject;
        poolTail = newObject;
    }
}

void* getMemory(size_t size) {
    if (!poolHead) {
        fprintf(stderr, "No available memory\n");
        return NULL;
    }

    PoolObject *obj = poolHead;
    poolHead = obj->next;

    if (poolHead == NULL) {
        poolTail = NULL;
    }

    return obj->data + OBJECT_SIZE;
}

int main() {
    allocate(4);
    char *buffer = (char *)getMemory(10);
    strcpy(buffer, "This is a test string.");

    // Violating bounds by accessing an element beyond the allocated size.
    printf("%c\n", buffer[OBJECT_SIZE]);

    return 0;
}
