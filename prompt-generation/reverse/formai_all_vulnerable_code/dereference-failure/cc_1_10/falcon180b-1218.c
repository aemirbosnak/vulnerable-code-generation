//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_TOKEN_SIZE 1024
#define MAX_VIRUSES 100

typedef struct {
    char *name;
    char *signature;
} virus_t;

char buffer[MAX_FILE_SIZE];
char token[MAX_TOKEN_SIZE];
int num_viruses = 0;
virus_t viruses[MAX_VIRUSES];

void load_viruses() {
    FILE *fp;
    char line[MAX_TOKEN_SIZE];
    fp = fopen("viruses.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open viruses.txt\n");
        exit(1);
    }
    while (fgets(line, MAX_TOKEN_SIZE, fp)!= NULL) {
        char *name = strtok(line, ",");
        char *signature = strtok(NULL, ",");
        if (name == NULL || signature == NULL) {
            printf("Error: invalid virus entry in viruses.txt\n");
            exit(1);
        }
        viruses[num_viruses].name = strdup(name);
        viruses[num_viruses].signature = strdup(signature);
        num_viruses++;
    }
    fclose(fp);
}

int compare_signatures(const void *a, const void *b) {
    virus_t *va = (virus_t *)a;
    virus_t *vb = (virus_t *)b;
    return strcmp(va->signature, vb->signature);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    load_viruses();
    FILE *fp;
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: could not open %s\n", argv[1]);
        exit(1);
    }
    int file_size = 0;
    while (fread(buffer + file_size, 1, MAX_FILE_SIZE - file_size, fp) > 0) {
        file_size += fread(buffer + file_size, 1, MAX_FILE_SIZE - file_size, fp);
    }
    fclose(fp);
    int i, j;
    qsort(viruses, num_viruses, sizeof(virus_t), compare_signatures);
    for (i = 0; i < num_viruses; i++) {
        virus_t *v = &viruses[i];
        j = 0;
        while (j < file_size - strlen(v->signature)) {
            strncpy(token, &buffer[j], strlen(v->signature));
            if (strcasecmp(token, v->signature) == 0) {
                printf("%s found in %s\n", v->name, argv[1]);
                exit(1);
            }
            j += strlen(v->signature);
        }
    }
    printf("%s is clean\n", argv[1]);
    return 0;
}