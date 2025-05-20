//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_LENGTH 1024
#define MAX_FILE_SIZE (1024 * 1024)
#define MAX_VIRUSES 10

typedef struct {
    char name[MAX_VIRUS_LENGTH];
    char signature[MAX_VIRUS_LENGTH];
} virus;

virus viruses[MAX_VIRUSES] = {
    {"Cascade", "Cascade.1701"},
    {"CIH", "CIH.1010"},
    {"CodeRed", "CodeRed.404"},
    {"ExploreZip", "ExploreZip.4096"},
    {"I Love You", "ILoveYou.vbs"},
    {"Melissa", "Melissa.a"},
    {"Mydoom", "Mydoom.a"},
    {"Sasser", "Sasser.a"},
    {"Stuxnet", "Stuxnet.a"},
    {"WannaCry", "WannaCry.a"}
};

int num_viruses = sizeof(viruses) / sizeof(viruses[0]);

void scan_file(char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    int virus_found = 0;
    for (int i = 0; i < num_viruses; i++) {
        char* virus_buffer = malloc(MAX_FILE_SIZE);
        fread(virus_buffer, file_size, 1, file);
        fclose(file);

        if (strstr(virus_buffer, viruses[i].signature)!= NULL) {
            printf("Virus found: %s\n", viruses[i].name);
            virus_found = 1;
            break;
        }

        free(virus_buffer);
        file = fopen(file_name, "rb");
    }

    if (!virus_found) {
        printf("File is clean\n");
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file]\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}