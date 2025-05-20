#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main() {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen("sensitive_data.txt", "r");
    
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    
    printf("Reading data from file...\n");
    
    // Intentional buffer overflow vulnerability
    while (fscanf(file, "%s", buffer) != EOF) {
        printf("%s\n", buffer);
    }
    
    fclose(file);
    return EXIT_SUCCESS;
}
