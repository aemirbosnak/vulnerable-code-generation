//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUSES 100
#define MAX_VIRUS_NAME_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_FILE_NAME_LENGTH];
} virus;

void read_viruses(virus* viruses) {
    FILE* file = fopen("viruses.txt", "r");
    if (file == NULL) {
        printf("Error: could not open viruses.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", viruses[count].name, viruses[count].signature) == 2) {
        count++;
        if (count >= MAX_VIRUSES) {
            printf("Error: too many viruses in viruses.txt\n");
            exit(1);
        }
    }

    fclose(file);
}

int scan_file(const char* file_name, virus* viruses) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: could not open %s\n", file_name);
        return -1;
    }

    unsigned char buffer[1024];
    int buffer_size = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    int count = 0;
    for (int i = 0; i < buffer_size; i++) {
        for (int j = 0; j < count; j++) {
            int k = 0;
            while (i + k < buffer_size && viruses[j].signature[k] == buffer[i + k]) {
                k++;
            }
            if (k == strlen(viruses[j].signature)) {
                printf("Virus found: %s\n", viruses[j].name);
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    virus viruses[MAX_VIRUSES];
    read_viruses(viruses);

    char file_name[MAX_FILE_NAME_LENGTH];
    while (1) {
        printf("Enter file name to scan: ");
        scanf("%s", file_name);

        int result = scan_file(file_name, viruses);
        if (result == -1) {
            continue;
        } else if (result == 1) {
            break;
        }
    }

    return 0;
}