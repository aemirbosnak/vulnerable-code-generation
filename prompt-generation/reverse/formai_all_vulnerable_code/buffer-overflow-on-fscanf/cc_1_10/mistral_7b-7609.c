//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIGNATURES 100
#define MAX_SIGNATURE_LENGTH 50

struct Signature {
    char name[MAX_SIGNATURE_LENGTH];
    char signature[MAX_SIGNATURE_LENGTH];
};

int main(int argc, char *argv[]) {
    int fd_signatures, i, j;
    struct Signature signatures[MAX_SIGNATURES];
    char filepath[256];
    char file_contents[1024];
    int signatures_count = 0;

    if (argc < 2) {
        printf("Usage: %s <path_to_signatures_file>\n", argv[0]);
        return 1;
    }

    fd_signatures = open(argv[1], O_RDONLY);
    if (fd_signatures == -1) {
        perror("Error opening signatures file");
        return 1;
    }

    while (signatures_count < MAX_SIGNATURES && fscanf(fd_signatures, "%s %s", signatures[signatures_count].name, signatures[signatures_count].signature) == 2) {
        signatures_count++;
    }

    fclose(fd_signatures);

    for (i = 0; i < argc - 2; i++) {
        snprintf(filepath, sizeof(filepath), "%s/%s", argv[0], argv[i + 2]);
        fd_signatures = open(filepath, O_RDONLY);
        if (fd_signatures == -1) {
            perror("Error opening file for scanning");
            continue;
        }

        read(fd_signatures, file_contents, sizeof(file_contents));
        close(fd_signatures);

        for (j = 0; j < signatures_count; j++) {
            if (strstr(file_contents, signatures[j].signature) != NULL) {
                printf("%s is infected with %s\n", argv[i + 2], signatures[j].name);
                break;
            }
        }
    }

    return 0;
}