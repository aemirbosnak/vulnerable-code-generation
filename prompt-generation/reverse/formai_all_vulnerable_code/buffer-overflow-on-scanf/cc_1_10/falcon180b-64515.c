//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_SIZE 1000

struct virus {
    char name[50];
    char signature[MAX_VIRUS_SIZE];
};

int main() {
    FILE *fp;
    char filename[100];
    char line[1000];
    struct virus viruses[] = {
        {"WannaCry", "wcry"},
        {"Petya", "petrwrap"},
        {"Locky", "locky"},
        {"CryptoLocker", "cryptolocker"}
    };
    int num_viruses = sizeof(viruses) / sizeof(struct virus);
    int i, j;

    printf("Welcome to the C Antivirus Scanner!\n");
    printf("Enter the file name to scan: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        for (i = 0; i < num_viruses; i++) {
            for (j = 0; j < strlen(viruses[i].signature); j++) {
                if (!isalpha(line[j])) {
                    line[j] = tolower(line[j]);
                }
            }
            if (strcmp(line, viruses[i].signature) == 0) {
                printf("Virus detected: %s\n", viruses[i].name);
                exit(1);
            }
        }
    }

    printf("No viruses detected.\n");
    fclose(fp);
    return 0;
}