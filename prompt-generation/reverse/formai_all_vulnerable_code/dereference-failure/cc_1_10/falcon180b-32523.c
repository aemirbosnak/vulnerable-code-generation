//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} file_t;

int is_infected(unsigned char *data, size_t size) {
    static unsigned char virus_signature[] = {0x4D, 0x5A, 0x90, 0x00}; // MZ header
    for (int i = 0; i < size - 3; i++) {
        if (memcmp(data + i, virus_signature, sizeof(virus_signature)) == 0) {
            return 1;
        }
    }
    return 0;
}

int scan_file(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    size_t filesize = ftell(fp);
    if (filesize > MAX_FILE_SIZE) {
        printf("File is too large: %s\n", filename);
        fclose(fp);
        return 1;
    }

    rewind(fp);
    unsigned char *data = malloc(filesize);
    if (!data) {
        printf("Memory error\n");
        fclose(fp);
        return 1;
    }

    size_t readsize = fread(data, 1, filesize, fp);
    if (readsize!= filesize) {
        printf("Error reading file: %s\n", filename);
        free(data);
        fclose(fp);
        return 1;
    }

    int infected = is_infected(data, filesize);
    if (infected) {
        printf("File is infected with a virus: %s\n", filename);
    } else {
        printf("File is clean: %s\n", filename);
    }

    free(data);
    fclose(fp);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int ret = scan_file(filename);

    return ret;
}