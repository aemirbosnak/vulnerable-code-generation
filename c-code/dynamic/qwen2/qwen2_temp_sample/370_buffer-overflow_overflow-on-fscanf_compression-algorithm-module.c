#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void decompress(char *input_buffer, size_t input_size, char *output_buffer, size_t output_size) {
    FILE *fp = fopen(input_buffer, "r");
    if (!fp) {
        return;
    }
    
    fscanf(fp, "%s", output_buffer);
    fclose(fp);
}

int main() {
    char input_buffer[10];
    char output_buffer[2];

    printf("Enter filename to read: ");
    scanf("%s", input_buffer);

    decompress(input_buffer, sizeof(input_buffer), output_buffer, sizeof(output_buffer));

    printf("Decompressed content: %s\n", output_buffer);

    return 0;
}
