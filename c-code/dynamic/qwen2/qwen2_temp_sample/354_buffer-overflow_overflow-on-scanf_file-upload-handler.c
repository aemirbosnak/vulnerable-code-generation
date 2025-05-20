#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 20

int main() {
    char filename[BUFFER_SIZE];
    printf("Enter the filename to upload: ");
    // Deliberate buffer overflow vulnerability
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    
    fclose(file);
    printf("File '%s' created successfully.\n", filename);
    
    return EXIT_SUCCESS;
}
