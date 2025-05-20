//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUSES 100

struct virus {
    char name[50];
    char signature[100];
};

int load_viruses(struct virus viruses[]) {
    FILE *file = fopen("viruses.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Error: could not open viruses file.\n");
        return -1;
    }

    while (fscanf(file, "%s %s\n", viruses[count].name, viruses[count].signature)!= EOF) {
        count++;
        if (count >= MAX_VIRUSES) {
            printf("Error: too many viruses in file.\n");
            fclose(file);
            return -1;
        }
    }

    fclose(file);
    return count;
}

int scan_file(char *filename, struct virus viruses[], int count) {
    FILE *file = fopen(filename, "r");
    char buffer[1024];
    int length, i;

    if (file == NULL) {
        printf("Error: could not open file %s.\n", filename);
        return -1;
    }

    while ((length = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (i = 0; i < count; i++) {
            if (strstr(buffer, viruses[i].signature)!= NULL) {
                printf("Virus found: %s\n", viruses[i].name);
                return 1;
            }
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct virus viruses[MAX_VIRUSES];
    int count = load_viruses(viruses);

    if (count <= 0) {
        return 1;
    }

    int result = scan_file(argv[1], viruses, count);

    if (result == 0) {
        printf("No viruses found.\n");
    }

    return 0;
}