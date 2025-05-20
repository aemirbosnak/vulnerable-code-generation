//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main() {
    char buf[BUF_SIZE];
    char *p;
    char *q;
    char *r;
    char *s;
    char *t;

    while (1) {
        // Read a line from the file
        if (fgets(buf, BUF_SIZE, stdin) == NULL) {
            break;
        }

        // Remove leading and trailing whitespace
        p = buf;
        while (*p == ' ' || *p == '\t' || *p == '\n') {
            p++;
        }
        q = p + strlen(p) - 1;
        while (q >= p && (*q == ' ' || *q == '\t' || *q == '\n')) {
            *q = '\0';
            q--;
        }

        // Check if the line is a metadata entry
        if (strncmp(p, "metadata", 8) == 0) {
            // Extract the key and value from the metadata entry
            r = p + 9;
            s = r + strlen(r) - 1;
            while (s >= r && (*s == ' ' || *s == '\t' || *s == '\n')) {
                *s = '\0';
                s--;
            }
            t = r;
            while (*t != '=' && *t != '\0') {
                t++;
            }
            if (*t == '=') {
                *t = '\0';
                t++;
                printf("Metadata: %s=%s\n", r, t);
            }
        }
    }

    return 0;
}