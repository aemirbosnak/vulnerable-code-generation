//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_LENGTH 100

typedef struct {
    char virus_name[MAX_VIRUS_LENGTH];
    int virus_length;
} virus_t;

virus_t viruses[] = {
    {"CodeRed", 8},
    {"Sasser", 7},
    {"MyDoom", 7},
    {"Nimda", 5},
    {"Stuxnet", 8},
    {"WannaCry", 9},
};

int num_viruses = sizeof(viruses) / sizeof(virus_t);

int is_virus(char *filename) {
    int i;
    for (i = 0; i < num_viruses; i++) {
        if (strstr(filename, viruses[i].virus_name)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char directory[256];
    printf("Enter directory to scan: ");
    scanf("%s", directory);

    char command[512];
    sprintf(command, "dir %s /s /b > filelist.txt", directory);
    system(command);

    FILE *filelist = fopen("filelist.txt", "r");
    if (filelist == NULL) {
        printf("Error opening filelist.txt\n");
        return 1;
    }

    char filename[256];
    while (fscanf(filelist, "%s", filename)!= EOF) {
        if (is_virus(filename)) {
            printf("%s is infected with %s\n", filename, viruses[0].virus_name);
        }
    }

    fclose(filelist);
    return 0;
}