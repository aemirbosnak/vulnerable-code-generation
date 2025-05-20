//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_VIRUS_LENGTH 100

typedef struct {
    char *name;
    char *signature;
} virus_t;

virus_t viruses[] = {
    {"MyDoom", "mydoom.exe"},
    {"Sasser", "sasser.exe"},
    {"Stuxnet", "stuxnet.exe"}
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

int is_virus(char *file_content, virus_t *virus) {
    int i, j;
    for (i = 0; i < strlen(file_content) - strlen(virus->signature) + 1; i++) {
        for (j = 0; j < strlen(virus->signature); j++) {
            if (tolower(file_content[i + j])!= tolower(virus->signature[j])) {
                break;
            }
        }
        if (j == strlen(virus->signature)) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *file_content = NULL;
    size_t file_size = 0;
    int is_infected = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        fclose(file);
        return 1;
    }

    rewind(file);
    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Memory error.\n");
        fclose(file);
        return 1;
    }

    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';
    fclose(file);

    for (i = 0; i < num_viruses; i++) {
        if (is_virus(file_content, &viruses[i])) {
            printf("Infected with %s\n", viruses[i].name);
            is_infected = 1;
            break;
        }
    }

    if (!is_infected) {
        printf("No virus found.\n");
    }

    free(file_content);
    return 0;
}