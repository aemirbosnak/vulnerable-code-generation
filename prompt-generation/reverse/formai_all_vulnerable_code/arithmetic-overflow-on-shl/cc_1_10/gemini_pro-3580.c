//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

#define PRU_H_ELEMENT(i) (1 << (2 * (i)))
#define PRU_H_BIT(i) (1 << (i))

struct metadata {
        uint32_t magic;
        uint16_t version_major;
        uint16_t version_minor;
        uint32_t num_elements;
        uint64_t elements[];
};

struct element {
        uint64_t value;
        uint32_t flags;
};

int main() {
        // Open metadata file
        FILE *f = fopen("metadata.bin", "rb");
        if (f == NULL) {
                perror("fopen");
                return EXIT_FAILURE;
        }

        // Read metadata header
        struct metadata header;
        fread(&header, sizeof(header), 1, f);

        // Check magic number
        if (header.magic != 0xDEADBEEF) {
                fprintf(stderr, "Invalid magic number\n");
                fclose(f);
                return EXIT_FAILURE;
        }

        // Check version
        if (header.version_major != 1 || header.version_minor != 0) {
                fprintf(stderr, "Unsupported version\n");
                fclose(f);
                return EXIT_FAILURE;
        }

        // Allocate memory for elements
        struct element *elements = malloc(sizeof(struct element) * header.num_elements);
        if (elements == NULL) {
                perror("malloc");
                fclose(f);
                return EXIT_FAILURE;
        }

        // Read elements
        fread(elements, sizeof(struct element), header.num_elements, f);

        // Close file
        fclose(f);

        // Print elements
        for (int i = 0; i < header.num_elements; i++) {
                printf("Element %d:\n", i);
                printf("    Value: 0x%" PRIx64 "\n", elements[i].value);
                printf("    Flags: 0x%" PRIx32 "\n", elements[i].flags);

                // Print flags
                for (int j = 0; j < 32; j++) {
                        if (elements[i].flags & PRU_H_BIT(j)) {
                                printf("        Flag %d: set\n", j);
                        }
                }
        }

        // Free memory
        free(elements);

        return EXIT_SUCCESS;
}