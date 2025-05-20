//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_COUNT 100
#define MAX_VIRUS_NAME_LENGTH 100

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    int count;
} virus_t;

void add_virus(virus_t *viruses, int count, char *name) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(viruses[i].name, name) == 0) {
            viruses[i].count++;
            return;
        }
    }
    strcpy(viruses[count].name, name);
    viruses[count].count = 1;
}

int main() {
    char filename[100];
    FILE *fp;
    char line[1000];
    virus_t viruses[MAX_VIRUS_COUNT];
    int virus_count = 0;

    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        int i;
        char *token = strtok(line, " ");
        while (token!= NULL) {
            for (i = 0; i < virus_count; i++) {
                if (strcmp(token, viruses[i].name) == 0) {
                    viruses[i].count++;
                    break;
                }
            }
            if (i == virus_count) {
                add_virus(viruses, virus_count, token);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Scan complete.\n");
    printf("Number of viruses found: %d\n", virus_count);

    for (int i = 0; i < virus_count; i++) {
        printf("%s: %d\n", viruses[i].name, viruses[i].count);
    }

    return 0;
}