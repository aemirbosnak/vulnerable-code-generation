//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_LINE_LEN 1024

typedef struct virus {
    unsigned char signature[16];
    char name[MAX_FILENAME_LEN];
    int size;
} Virus;

int main(int argc, char* argv[]) {
    // check arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>...\n", argv[0]);
        exit(1);
    }

    // read viruses from file
    Virus* viruses = NULL;
    int num_viruses = 0;
    for (int i = 1; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        if (!file) {
            fprintf(stderr, "Error: couldn't open file %s\n", argv[i]);
            continue;
        }

        char line[MAX_LINE_LEN];
        while (fgets(line, MAX_LINE_LEN, file)) {
            if (line[0] == '#') continue;

            Virus virus;
            if (sscanf(line, "%s %s %d", virus.name, virus.signature, &virus.size) != 3) {
                fprintf(stderr, "Error: invalid virus in file %s\n", argv[i]);
                continue;
            }

            viruses = realloc(viruses, sizeof(Virus) * (num_viruses + 1));
            memcpy(&viruses[num_viruses], &virus, sizeof(Virus));
            num_viruses++;
        }

        fclose(file);
    }

    // scan files for viruses
    char filename[MAX_FILENAME_LEN];
    for (int i = 0; i < num_viruses; i++) {
        for (int j = 1; j < argc; j++) {
            FILE* file = fopen(argv[j], "r");
            if (!file) {
                fprintf(stderr, "Error: couldn't open file %s\n", argv[j]);
                continue;
            }

            while (fread(filename, sizeof(char), MAX_FILENAME_LEN, file) > 0) {
                if (memcmp(filename, viruses[i].signature, sizeof(viruses[i].signature)) == 0) {
                    printf("Virus detected in file %s: %s\n", argv[j], viruses[i].name);
                }
            }

            fclose(file);
        }
    }

    // free memory
    free(viruses);

    return 0;
}