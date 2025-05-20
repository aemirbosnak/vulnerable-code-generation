//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, j;
    unsigned int addr;
    char *filename;
    FILE *fp;
    char line[1024];
    char *token;
    unsigned long memsize = 0;
    unsigned long totalsize = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    fgets(line, 1024, stdin);
    filename = strtok(line, "\n");

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    // Read file line by line
    while (fgets(line, 1024, fp)!= NULL) {
        // Extract address from line
        token = strtok(line, " ");
        if (token!= NULL) {
            addr = strtoul(token, NULL, 16);
            //printf("Address: %x\n", addr);
        }
        else {
            continue;
        }

        // Extract size from line
        token = strtok(NULL, " ");
        if (token!= NULL) {
            memsize = strtoul(token, NULL, 10);
            //printf("Size: %lu\n", memsize);
        }
        else {
            continue;
        }

        // Check if address is valid
        if (addr < 0 || addr >= 0xffffffff) {
            printf("Error: Invalid address %x\n", addr);
            exit(1);
        }

        // Add memory size to total
        totalsize += memsize;

        // Print memory usage
        for (j = 0; j < memsize; j++) {
            printf("%c", '.');
        }
        printf("\n");
    }

    // Close file
    fclose(fp);

    // Print total memory usage
    printf("\nTotal memory usage: %lu bytes\n", totalsize);

    return 0;
}