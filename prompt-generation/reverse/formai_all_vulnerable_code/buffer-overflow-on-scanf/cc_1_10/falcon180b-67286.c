//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "X5O!P%@AP[4\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"

int is_virus(const char* file_data, int file_size) {
    const char* virus_signature = VIRUS_SIGNATURE;
    int signature_size = strlen(virus_signature);

    for (int i = 0; i < file_size - signature_size; i++) {
        if (memcmp(file_data + i, virus_signature, signature_size) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char file_data[1024];
    FILE* file;
    int file_size;

    printf("Enter filename: ");
    scanf("%s", file_data);

    file = fopen(file_data, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    if (fread(file_data, 1, file_size, file)!= file_size) {
        printf("Error reading file.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    if (is_virus(file_data, file_size)) {
        printf("Virus detected!\n");
    } else {
        printf("No virus detected.\n");
    }

    return 0;
}