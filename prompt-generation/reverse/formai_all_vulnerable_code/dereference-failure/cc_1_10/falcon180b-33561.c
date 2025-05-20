//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // 1MB

typedef struct {
    char *name;
    char *signature;
} virus_t;

virus_t viruses[] = {
    {"Happy Virus", "HV"},
    {"Joyful Worm", "JW"},
    {"Cheerful Trojan", "CT"},
    {"Merry Malware", "MM"},
    {"Delightful Ransomware", "DR"}
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

bool is_infected(char *file_content, virus_t virus) {
    char *pos = strstr(file_content, virus.signature);
    while (pos!= NULL) {
        if (isupper(pos[0]) && isupper(pos[strlen(virus.signature) - 1])) {
            return true;
        }
        pos = strstr(pos + 1, virus.signature);
    }
    return false;
}

void scan_file(char *filename) {
    FILE *fp;
    char ch;
    int count = 0;
    char *file_content = malloc(MAX_FILE_SIZE);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    while ((ch = fgetc(fp))!= EOF) {
        file_content[count++] = ch;
        if (count == MAX_FILE_SIZE) {
            printf("File %s is too large to scan.\n", filename);
            free(file_content);
            fclose(fp);
            return;
        }
    }

    fclose(fp);

    for (int i = 0; i < num_viruses; i++) {
        if (is_infected(file_content, viruses[i])) {
            printf("File %s is infected with %s.\n", filename, viruses[i].name);
        }
    }

    free(file_content);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}