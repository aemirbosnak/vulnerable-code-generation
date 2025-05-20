//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_VIRUS_NAME_LENGTH 50
#define MAX_VIRUS_SIGNATURE_LENGTH 100
#define MAX_NUM_OF_VIRUSES 10

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_VIRUS_SIGNATURE_LENGTH];
} Virus;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_scan>\n", argv[0]);
        return 1;
    }

    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    strcpy(file_name, argv[1]);
    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return 1;
    }

    int num_of_viruses = 0;
    Virus viruses[MAX_NUM_OF_VIRUSES];

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int i;
        for (i = 0; i < num_of_viruses; i++) {
            if (strstr(line, viruses[i].signature)!= NULL) {
                printf("Virus found: %s\n", viruses[i].name);
                break;
            }
        }

        if (i == num_of_viruses) {
            num_of_viruses++;
            printf("Enter virus name (max %d characters): ", MAX_VIRUS_NAME_LENGTH - 1);
            scanf("%s", viruses[num_of_viruses - 1].name);
            printf("Enter virus signature (max %d characters): ", MAX_VIRUS_SIGNATURE_LENGTH - 1);
            scanf("%s", viruses[num_of_viruses - 1].signature);
        }
    }

    fclose(fp);

    if (num_of_viruses == 0) {
        printf("No viruses found in file %s\n", file_name);
    }

    return 0;
}