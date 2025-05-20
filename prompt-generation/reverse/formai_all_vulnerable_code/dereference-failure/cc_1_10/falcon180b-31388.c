//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1 MB

typedef struct {
    char *name;
    char *signature;
    int length;
} virus_t;

virus_t viruses[] = {
    { "WannaCry", "FC", 5 },
    { "Locky", "7F454C460201010046000300", 17 },
    { "Petya", "8A89C1E8", 8 }
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    if (ferror(file)) {
        printf("Error: Could not read file %s.\n", filename);
        fclose(file);
        return;
    }

    for (int i = 0; i < num_viruses; i++) {
        virus_t virus = viruses[i];
        char *haystack = buffer;
        int haystack_len = bytes_read;
        int needle_len = virus.length;

        while ((haystack_len - needle_len + 1) >= 0) {
            if (memcmp(haystack, virus.signature, needle_len) == 0) {
                printf("Virus detected: %s\n", virus.name);
                fclose(file);
                return;
            }
            haystack++;
            haystack_len--;
        }
    }

    printf("No viruses found in %s.\n", filename);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);
    return 0;
}