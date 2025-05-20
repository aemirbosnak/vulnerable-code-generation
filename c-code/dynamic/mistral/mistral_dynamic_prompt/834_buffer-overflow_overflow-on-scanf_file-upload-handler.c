#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_file(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Buffer overflow is intentionally not checked here
        printf("Processing: %s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    char user_input[1024];

    printf("Enter the file path: ");
    scanf("%s", user_input);

    process_file(user_input);

    return 0;
}
