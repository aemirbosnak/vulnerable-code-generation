//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to be scanned
#define MAX_VIRUS_COUNT 50 // Maximum number of viruses to be detected

typedef struct {
    char *virus_name;
    char *signature;
} Virus;

int main() {
    FILE *file;
    char buffer[MAX_FILE_SIZE];
    int file_size = 0;
    int virus_count = 0;
    Virus viruses[] = {
        {"WannaCry", "fc3d6b1a0f8c5e6e5c1e9b5d3a"},
        {"Petya", "5c1e9b5d3a"},
        {"Locky", "fc3d6b1a0f8c5e6e5c1e9b5d3a"},
        {"TeslaCrypt", "fc3d6b1a0f8c5e6e5c1e9b5d3a"},
        {"Cerber", "fc3d6b1a0f8c5e6e5c1e9b5d3a"}
    };

    printf("Antivirus Scanner\n");
    printf("=================\n");

    while (1) {
        printf("Enter file path (or 'q' to quit): ");
        scanf("%s", buffer);

        if (strcmp(buffer, "q") == 0) {
            break;
        }

        file = fopen(buffer, "rb");
        if (file == NULL) {
            printf("Error: File not found.\n");
            continue;
        }

        while (!feof(file)) {
            fseek(file, 0, SEEK_END);
            file_size = ftell(file);
            fseek(file, 0, SEEK_SET);

            if (file_size > MAX_FILE_SIZE) {
                printf("Error: File too large.\n");
                fclose(file);
                break;
            }

            fread(buffer, file_size, 1, file);

            for (int i = 0; i < MAX_VIRUS_COUNT; i++) {
                if (strstr(buffer, viruses[i].signature)!= NULL) {
                    virus_count++;
                    printf("Virus detected: %s\n", viruses[i].virus_name);
                }
            }
        }

        fclose(file);
    }

    if (virus_count > 0) {
        printf("Total viruses found: %d\n", virus_count);
    } else {
        printf("No viruses found.\n");
    }

    return 0;
}