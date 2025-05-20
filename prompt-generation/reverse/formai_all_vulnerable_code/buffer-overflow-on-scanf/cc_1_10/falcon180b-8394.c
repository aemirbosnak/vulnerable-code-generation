//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 1000
#define MAX_VIRUS_NAME 100
#define MAX_VIRUS_SIZE 500

typedef struct {
    char file_name[MAX_FILE_NAME];
    char virus_name[MAX_VIRUS_NAME];
    int virus_size;
} virus;

void scan_file(FILE *file, virus *virus_list, int num_viruses) {
    char line[MAX_FILE_NAME];
    char *token;
    int i;
    while (fgets(line, MAX_FILE_NAME, file)!= NULL) {
        for (i = 0; i < num_viruses; i++) {
            token = strtok(line, " ");
            while (token!= NULL) {
                if (strcasecmp(token, virus_list[i].virus_name) == 0) {
                    printf("Virus found in file %s\n", virus_list[i].file_name);
                    printf("Virus name: %s\n", virus_list[i].virus_name);
                    printf("Virus size: %d bytes\n", virus_list[i].virus_size);
                    exit(0);
                }
                token = strtok(NULL, " ");
            }
        }
    }
}

int main() {
    FILE *file;
    virus virus_list[10];
    int num_viruses = 0;
    char input[MAX_FILE_NAME];
    printf("Enter the name of the file to scan: ");
    scanf("%s", input);
    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    while (num_viruses < 10) {
        printf("Enter the name of a virus to scan for (or press enter to stop): ");
        scanf("%s", input);
        if (input[0]!= '\0') {
            strcpy(virus_list[num_viruses].virus_name, input);
            printf("Enter the size of the virus (in bytes): ");
            scanf("%d", &virus_list[num_viruses].virus_size);
            num_viruses++;
        }
    }
    fclose(file);
    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    scan_file(file, virus_list, num_viruses);
    fclose(file);
    printf("No viruses found\n");
    exit(0);
}