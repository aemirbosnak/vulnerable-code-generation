#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void apply_filter(char *input) {
    char filename[256];
    int width, height;
    
    // Vulnerable to buffer overflow if input is too large
    sscanf(input, "%s %d %d", filename, &width, &height);
    
    printf("Applying filter to: %s\n", filename);
    printf("Width: %d, Height: %d\n", width, height);
}

int main() {
    char buffer[1024];
    
    printf("Enter filter parameters (filename width height): ");
    fgets(buffer, sizeof(buffer), stdin);
    
    apply_filter(buffer);
    
    return 0;
}
