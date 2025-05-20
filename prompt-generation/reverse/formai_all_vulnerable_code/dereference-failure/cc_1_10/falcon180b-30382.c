//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: creative
/* This is a simple C Antivirus scanner example program. It will scan a directory for files and check them for viruses. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct {
    char *name;
    char *signature;
    int length;
} virus_t;

virus_t viruses[] = {
    {"MyDoom", "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!", 68},
    {"Slammer", "SLAMMER.EXE", 8},
    {"CodeRed", "C:\\WINNT\\SYSTEM32\\MSADC\\MSADC.DLL", 23}
};

void scan_file(char *path) {
    FILE *file;
    char buffer[4096];
    int i, j, k, found = 0;

    file = fopen(path, "rb");

    if (!file) {
        printf("Error opening file %s\n", path);
        return;
    }

    for (i = 0; i < sizeof(viruses) / sizeof(virus_t); i++) {
        for (j = 0; j < strlen(viruses[i].signature); j++) {
            if (viruses[i].signature[j] == '?') {
                for (k = 0; k < viruses[i].length; k++) {
                    if (fread(&buffer[k], 1, 1, file)!= 1) {
                        break;
                    }
                }

                if (k == viruses[i].length && memcmp(buffer, viruses[i].signature, viruses[i].length) == 0) {
                    printf("Virus found: %s\n", viruses[i].name);
                    found = 1;
                    break;
                }
            } else if (buffer[j]!= viruses[i].signature[j]) {
                break;
            }
        }

        if (found) {
            break;
        }
    }

    fclose(file);
}

void scan_directory(char *path) {
    DIR *dir;
    struct dirent *ent;

    dir = opendir(path);

    if (!dir) {
        printf("Error opening directory %s\n", path);
        return;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            scan_file(ent->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1]);

    return 0;
}