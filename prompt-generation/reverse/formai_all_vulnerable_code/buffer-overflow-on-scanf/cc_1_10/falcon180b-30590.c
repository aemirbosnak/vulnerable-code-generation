//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB
#define MAX_VIRUS_NAME_LENGTH 50

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    int is_infected;
} Virus;

int is_virus(const char *filename)
{
    FILE *fp;
    char magic_number[4] = {0x55, 0xAA, 0x0D, 0x0A};
    Virus viruses[] = {{"WannaCry", 1}, {"Petya", 1}, {"Locky", 1}};
    int num_viruses = sizeof(viruses) / sizeof(Virus);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 0;
    }

    fseek(fp, 0, SEEK_SET);
    fread(magic_number, 1, 4, fp);

    for (int i = 0; i < num_viruses; i++) {
        if (memcmp(magic_number, viruses[i].name, 4) == 0) {
            printf("Virus detected: %s\n", viruses[i].name);
            viruses[i].is_infected = 1;
            break;
        }
    }

    fclose(fp);

    return viruses[0].is_infected;
}

int main()
{
    char filename[MAX_FILE_SIZE];
    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    int is_infected = is_virus(filename);

    if (is_infected) {
        printf("The file %s is infected with a virus.\n", filename);
    } else {
        printf("The file %s is clean.\n", filename);
    }

    return 0;
}