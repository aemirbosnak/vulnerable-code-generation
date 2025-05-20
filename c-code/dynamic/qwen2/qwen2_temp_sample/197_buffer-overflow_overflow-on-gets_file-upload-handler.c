#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void handle_file_upload(char *filename) {
    char buffer[BUFFER_SIZE];
    
    // Simulate reading filename into buffer using gets (vulnerable function)
    printf("Enter filename: ");
    gets(buffer); // Vulnerable to buffer overflow
    
    FILE *file = fopen(buffer, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    
    printf("File contents:\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);
}

int main() {
    printf("Welcome to File Upload Handler\n");
    handle_file_upload(NULL);
    return 0;
}
