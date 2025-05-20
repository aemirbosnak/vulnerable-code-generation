//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1024
#define MAX_FILE_NAME 256
#define MAX_VIRUS_NAME 256
#define MAX_VIRUS_SIGNATURES 1000
#define MAX_FILE_EXTENSION 10

typedef struct {
    char name[MAX_VIRUS_NAME];
    char signature[MAX_VIRUS_SIGNATURES];
} virus;

typedef struct {
    char extension[MAX_FILE_EXTENSION];
    virus* virus;
} file_type;

typedef struct {
    char name[MAX_FILE_NAME];
    file_type* type;
} file;

void load_virus_signatures(virus* virus) {
    FILE* file = fopen("virus_signatures.txt", "r");
    char line[MAX_VIRUS_SIGNATURES];
    char* token;

    while (fgets(line, MAX_VIRUS_SIGNATURES, file)!= NULL) {
        token = strtok(line, ":");
        strcpy(virus->name, token);

        token = strtok(NULL, ":");
        strcpy(virus->signature, token);

        virus++;
    }

    fclose(file);
}

void load_file_types(file_type* file_type) {
    FILE* file = fopen("file_types.txt", "r");
    char line[MAX_FILE_EXTENSION];
    char* token;

    while (fgets(line, MAX_FILE_EXTENSION, file)!= NULL) {
        token = strtok(line, ":");
        strcpy(file_type->extension, token);

        file_type->virus = malloc(sizeof(virus));
        load_virus_signatures(file_type->virus);

        file_type++;
    }

    fclose(file);
}

int scan_file(file* file, file_type* file_type) {
    FILE* fp = fopen(file->name, "rb");
    char buffer[MAX_SIZE];
    int size;
    int i;
    int j;
    int match = 0;

    while ((size = fread(buffer, sizeof(char), MAX_SIZE, fp)) > 0) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < strlen(file_type->virus->signature); j++) {
                if (tolower(buffer[i]) == tolower(file_type->virus->signature[j])) {
                    match++;
                }
            }
        }
    }

    fclose(fp);

    if (match > 0) {
        printf("Virus found in %s\n", file->name);
        return 1;
    }

    return 0;
}

int main(int argc, char** argv) {
    file* files = malloc(sizeof(file));
    file_type* file_types = malloc(sizeof(file_type));

    load_file_types(file_types);

    while (scanf("%s", files->name)!= EOF) {
        strcpy(files->type->extension, "");

        for (int i = 0; i < strlen(files->name); i++) {
            if (files->name[i] == '.') {
                strcat(files->type->extension, &files->name[i+1]);
                break;
            }
        }

        for (int i = 0; i < strlen(files->type->extension); i++) {
            files->type->extension[i] = tolower(files->type->extension[i]);
        }

        int match = scan_file(files, file_types);

        if (match == 0) {
            printf("No virus found in %s\n", files->name);
        }
    }

    return 0;
}