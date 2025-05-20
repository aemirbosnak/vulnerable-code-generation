//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define MAX_VIRUS_NAME 64
#define MAX_VIRUSES 100

struct virus {
    char name[MAX_VIRUS_NAME];
    char signature[MAX_FILE_NAME];
};

int load_viruses(struct virus *viruses, int count) {
    FILE *file = fopen("viruses.txt", "r");
    if (file == NULL) {
        printf("Error: couldn't open viruses file.\n");
        return 1;
    }

    int i = 0;
    while (fscanf(file, "%s %s\n", viruses[i].name, viruses[i].signature) == 2 && i < count) {
        i++;
    }

    fclose(file);
    return i;
}

int scan_file(const char *file_name, struct virus *viruses, int count) {
    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: couldn't open file '%s'.\n", file_name);
        return 1;
    }

    char buffer[MAX_FILE_NAME];
    int file_size = 0;

    while (fread(buffer, 1, MAX_FILE_NAME, file) > 0) {
        file_size += fwrite(buffer, 1, MAX_FILE_NAME, stdout);

        int j;
        for (j = 0; j < count; j++) {
            if (strstr(buffer, viruses[j].signature)) {
                printf("Virus found: %s\n", viruses[j].name);
                return 1;
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    struct virus viruses[MAX_VIRUSES];
    int virus_count = load_viruses(viruses, MAX_VIRUSES);

    if (scan_file(argv[1], viruses, virus_count) == 0) {
        printf("No viruses found.\n");
    }

    return 0;
}