//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_SIGNATURES 100

struct File {
    char *name;
    char *content;
    int size;
};

struct Signature {
    char *pattern;
    int length;
};

struct Antivirus {
    struct Signature *signatures;
    int num_signatures;
};

int load_files(struct File *files, char *filenames[], int num_files) {
    for (int i = 0; i < num_files; i++) {
        FILE *fp = fopen(filenames[i], "rb");
        if (!fp) {
            return -1;
        }
        fseek(fp, 0, SEEK_END);
        int size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        char *content = malloc(size + 1);
        fread(content, 1, size, fp);
        content[size] = '\0';
        fclose(fp);
        files[i].name = filenames[i];
        files[i].content = content;
        files[i].size = size;
    }
    return 0;
}

int load_signatures(struct Signature *signatures, char *signatures_file) {
    FILE *fp = fopen(signatures_file, "r");
    if (!fp) {
        return -1;
    }
    int num_signatures;
    fscanf(fp, "%d", &num_signatures);
    for (int i = 0; i < num_signatures; i++) {
        char pattern[1024];
        fscanf(fp, "%s", pattern);
        signatures[i].pattern = strdup(pattern);
        signatures[i].length = strlen(pattern);
    }
    fclose(fp);
    return num_signatures;
}

int scan_files(struct Antivirus *av, struct File *files, int num_files) {
    int num_infected = 0;
    for (int i = 0; i < num_files; i++) {
        for (int j = 0; j < av->num_signatures; j++) {
            if (strstr(files[i].content, av->signatures[j].pattern)) {
                printf("File %s is infected with signature %s\n", files[i].name, av->signatures[j].pattern);
                num_infected++;
            }
        }
    }
    return num_infected;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <signatures_file> <files...>\n", argv[0]);
        return -1;
    }
    struct Antivirus av;
    av.num_signatures = load_signatures(av.signatures, argv[1]);
    if (av.num_signatures < 0) {
        fprintf(stderr, "Could not load signatures file: %s\n", argv[1]);
        return -1;
    }
    struct File files[MAX_FILES];
    if (load_files(files, argv + 2, argc - 2) < 0) {
        fprintf(stderr, "Could not load files\n");
        return -1;
    }
    int num_infected = scan_files(&av, files, argc - 2);
    printf("Found %d infected files\n", num_infected);
    return 0;
}