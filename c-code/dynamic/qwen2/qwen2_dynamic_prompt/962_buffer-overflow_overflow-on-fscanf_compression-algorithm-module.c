#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void decompress(char *data, size_t length) {
    char buffer[128];
    FILE *fp = fmemopen(data, length, "r");
    if (!fp) return;

    while (fscanf(fp, "%s", buffer) != EOF) {
        // Vulnerability: No bounds checking on buffer size
        printf("%s\n", buffer);
    }

    fclose(fp);
}

int main() {
    char input[] = "This is a test string that will cause a buffer overflow";
    decompress(input, sizeof(input));
    return 0;
}
