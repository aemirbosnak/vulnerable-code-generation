//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_SIGNATURES 1000
#define MAX_VIRUS_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *signature;
    int length;
} virus_signature_t;

virus_signature_t virus_signatures[MAX_VIRUS_SIGNATURES];
int num_virus_signatures;

void load_virus_signatures() {
    FILE *fp;
    char line[MAX_VIRUS_LENGTH];
    char *token;

    fp = fopen("virus_signatures.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open virus_signatures.txt\n");
        exit(1);
    }

    num_virus_signatures = 0;
    while (fgets(line, MAX_VIRUS_LENGTH, fp)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }
        virus_signatures[num_virus_signatures].signature = strdup(token);
        virus_signatures[num_virus_signatures].length = strlen(virus_signatures[num_virus_signatures].signature);
        num_virus_signatures++;
    }

    fclose(fp);
}

int is_virus(char *filename) {
    FILE *fp;
    char line[MAX_FILE_NAME_LENGTH];
    char *token;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_FILE_NAME_LENGTH, fp)!= NULL) {
        token = strtok(line, "\n");
        if (token == NULL) {
            continue;
        }
        for (i = 0; i < num_virus_signatures; i++) {
            if (strstr(token, virus_signatures[i].signature)!= NULL) {
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    load_virus_signatures();

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    if (is_virus(argv[1])) {
        printf("%s is infected with a virus!\n", argv[1]);
    } else {
        printf("%s is clean.\n", argv[1]);
    }

    return 0;
}