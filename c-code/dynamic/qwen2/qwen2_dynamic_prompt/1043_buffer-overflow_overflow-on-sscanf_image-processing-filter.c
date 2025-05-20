#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void apply_filter(char *input) {
    char filename[256];
    int width, height;
    
    // Vulnerability: No bounds checking on input length
    if (sscanf(input, "%s %d %d", filename, &width, &height) != 3) {
        printf("Error parsing input\n");
        return;
    }
    
    // Simulate applying a filter to an image
    printf("Applying filter to %s with dimensions %dx%d\n", filename, width, height);
}

int main() {
    char input[1024];
    
    printf("Enter image file name and dimensions (filename width height): ");
    fgets(input, sizeof(input), stdin);
    
    apply_filter(input);
    
    return 0;
}
