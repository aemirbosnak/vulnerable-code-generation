#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 128

void readLine(char *buffer, int size) {
    fgets(buffer, size, stdin);
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    int lineLength = 0;
    
    printf("Simple Text Editor\n");
    printf("-----------------\n");

    while (1) {
        printf("> ");
        readLine(buffer, sizeof(buffer));
        
        if (buffer[0] == '\n') {
            continue;
        }
        
        if (buffer[0] == 'q' && buffer[1] == '\n') {
            break;
        }
        
        // Intentionally overflow the buffer by adding an extra character
        buffer[sizeof(buffer) - 1] = buffer[sizeof(buffer) - 2];
        
        // Print the modified buffer to show overwriting
        printf("Modified: %s", buffer);
    }
    
    return 0;
}
