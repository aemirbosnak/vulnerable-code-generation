//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUSES 100

typedef struct {
    char name[64];
    char signature[64];
} Virus;

Virus viruses[MAX_VIRUSES];
int num_viruses;

void load_viruses() {
    FILE *file = fopen("viruses.txt", "r");
    if (file == NULL) {
        printf("Error loading viruses file\n");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        char *signature = strtok(NULL, ",");

        strcpy(viruses[num_viruses].name, name);
        strcpy(viruses[num_viruses].signature, signature);

        num_viruses++;
    }

    fclose(file);
}

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (int i = 0; i < num_viruses; i++) {
            Virus *virus = &viruses[i];

            char *ptr = strstr(buffer, virus->signature);
            while (ptr!= NULL) {
                printf("Virus found: %s\n", virus->name);
                ptr += strlen(virus->signature);
                ptr = strstr(ptr, virus->signature);
            }
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    load_viruses();

    scan_file(argv[1]);

    return 0;
}