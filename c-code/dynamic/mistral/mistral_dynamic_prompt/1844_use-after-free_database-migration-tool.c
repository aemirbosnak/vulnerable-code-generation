#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char *data;
    struct Record *next;
} Record;

Record *head = NULL;

void allocate_and_push(char *data) {
    Record *new_record = (Record *)malloc(sizeof(Record));
    new_record->data = data;
    new_record->next = head;
    head = new_record;
}

void free_records() {
    Record *current = head;
    Record *next;

    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    head = NULL;
}

int main() {
    const int N = 100000;
    char *buffer = (char *)malloc(N * sizeof(char));
    memset(buffer, 'A', N);

    for (int i = 0; i < N; ++i) {
        allocate_and_push(buffer + i * sizeof(char));
    }

    // Simulate database operations here...

    free_records();

    // Accessing freed memory deliberately here:
    for (int i = 0; i < N; ++i) {
        printf("%c", *(buffer + i * sizeof(char)));
    }

    free(buffer);

    return 0;
}
