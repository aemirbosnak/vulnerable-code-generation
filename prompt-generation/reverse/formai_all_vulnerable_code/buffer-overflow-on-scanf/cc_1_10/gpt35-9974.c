//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scan_directory(char *path) {
    FILE *fptr;
    char command[200];
    char result[1024];
    char virus_signature[] = "malware";
    char filename[100];
    strcpy(command, "ls -1 ");
    strcat(command, path);
    strcat(command, " > temp.txt");
    system(command);

    fptr = fopen("temp.txt", "r");

    if (fptr == NULL) {
        printf("Error opening directory\n");
        return 1;
    }

    while (fgets(filename, 100, fptr)) {
        strtok(filename, "\n");
        char file_path[200];
        strcpy(file_path, path);
        strcat(file_path, "/");
        strcat(file_path, filename);

        FILE *fp = fopen(file_path, "r");
        if (fp == NULL) continue;

        int is_infected = 0;
        char line[1024];

        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, virus_signature) != NULL) {
                printf("%s is infected!", file_path);
                is_infected = 1;
                break;
            }
        }
        if (!is_infected) printf("%s is clean\n", file_path);

        fclose(fp);
    }

    fclose(fptr);
    remove("temp.txt");
    return 0;
}

int main() {
    char path[200];
    printf("Please provide the path of the directory to scan: ");
    scanf("%s", path);
    printf("Scanning directory: %s\n", path);
    scan_directory(path);
    return 0;
}