#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void load_dataset(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    // Simulate loading data from file
    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter dataset filename: ");
    scanf("%s", filename); // Vulnerable to buffer overflow
    load_dataset(filename);
    return 0;
}
