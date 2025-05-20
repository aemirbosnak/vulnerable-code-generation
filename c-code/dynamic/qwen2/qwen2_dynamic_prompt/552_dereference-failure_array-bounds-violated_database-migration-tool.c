#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrate_data(int* data, int size) {
    int new_size = size * 2;
    int* new_data = (int*)malloc(new_size * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Intentional array bounds violation
    for (int i = 0; i <= new_size; i++) { // One element out of bounds
        new_data[i] = data[i];
    }

    free(data);
    data = new_data;
}

int main() {
    int original_size = 10;
    int* old_data = (int*)malloc(original_size * sizeof(int));
    if (old_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < original_size; i++) {
        old_data[i] = i + 1;
    }

    printf("Original data: ");
    for (int i = 0; i < original_size; i++) {
        printf("%d ", old_data[i]);
    }
    printf("\n");

    migrate_data(old_data, original_size);

    printf("Migrated data: ");
    for (int i = 0; i < original_size * 2; i++) {
        printf("%d ", old_data[i]);
    }
    printf("\n");

    free(old_data);
    return 0;
}
