//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_LINE_LEN 2048
#define MAX_VIRUS_SIGNATURES 100

// virus signature structure
typedef struct {
    char name[MAX_FILE_NAME_LEN];
    char signature[MAX_LINE_LEN];
} virus_signature_t;

// function prototypes
int is_valid_signature(char* signature);
int load_virus_signatures(virus_signature_t* signatures, int max_signatures);
int scan_file_for_viruses(FILE* file, virus_signature_t* signatures, int num_signatures);

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file_to_scan>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    virus_signature_t signatures[MAX_VIRUS_SIGNATURES];
    int num_signatures = 0;

    if (!load_virus_signatures(signatures, MAX_VIRUS_SIGNATURES)) {
        printf("Error: could not load virus signatures.\n");
        fclose(file);
        return 1;
    }

    int result = scan_file_for_viruses(file, signatures, num_signatures);

    fclose(file);

    if (result == 0) {
        printf("File is clean.\n");
    } else {
        printf("File is infected with %d virus(es).\n", result);
    }

    return 0;
}

int is_valid_signature(char* signature) {
    int len = strlen(signature);
    if (len == 0 || len > MAX_LINE_LEN) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isprint(signature[i])) {
            return 0;
        }
    }

    return 1;
}

int load_virus_signatures(virus_signature_t* signatures, int max_signatures) {
    FILE* file = fopen("virus_signatures.txt", "r");
    if (file == NULL) {
        return 0;
    }

    int num_signatures = 0;

    while (fscanf(file, "%s %s\n", signatures[num_signatures].name, signatures[num_signatures].signature) == 2) {
        num_signatures++;

        if (num_signatures >= max_signatures) {
            break;
        }
    }

    fclose(file);

    return (num_signatures > 0);
}

int scan_file_for_viruses(FILE* file, virus_signature_t* signatures, int num_signatures) {
    int result = 0;

    char buffer[MAX_LINE_LEN];
    int buffer_len = 0;

    while (fgets(buffer + buffer_len, MAX_LINE_LEN - buffer_len, file)!= NULL) {
        buffer_len += strlen(buffer);

        if (buffer_len > MAX_LINE_LEN) {
            buffer_len = 0;
        }

        int i;
        for (i = 0; i < num_signatures; i++) {
            if (strstr(buffer, signatures[i].signature)!= NULL) {
                result++;
                break;
            }
        }

        if (i == num_signatures) {
            buffer_len = 0;
        }
    }

    return result;
}