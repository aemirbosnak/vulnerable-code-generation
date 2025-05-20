//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VIRUS_LENGTH 50
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1048576 //1 MB
#define NUM_VIRUSES 5

typedef struct virus_info {
    char name[MAX_VIRUS_LENGTH];
    char signature[MAX_VIRUS_LENGTH];
} virus_info;

virus_info viruses[NUM_VIRUSES] = {
    {"WannaCry", "FCF74E4E1A5F8E2F0A1E7D0D7D8D2E"},
    {"Locky", "7F250E0F49E1D7E1A0F4E1D0D1E7E0"},
    {"Petya", "3E7F450E0F49E1D7E1A0F4E1D0D1E7E0"},
    {"Cerber", "1E1D7E1A0F4E1D0D1E7E0F49E1D7E1"},
    {"Dridex", "0F4E1D0D1E7E0F49E1D7E1A0F4E1D0"}
};

void scan_file(FILE* file, virus_info viruses[], int num_viruses) {
    char buffer[MAX_FILE_SIZE];
    int buffer_size = fread(buffer, 1, MAX_FILE_SIZE, file);
    buffer[buffer_size] = '\0';

    for(int i = 0; i < num_viruses; i++) {
        char* virus_buffer = strstr(buffer, viruses[i].signature);
        while(virus_buffer!= NULL) {
            printf("Virus detected: %s\n", viruses[i].name);
            virus_buffer = strstr(virus_buffer + 1, viruses[i].signature);
        }
    }
}

int main() {
    printf("Enter the name of the file to scan: ");
    char file_name[MAX_FILE_NAME_LENGTH];
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "rb");
    if(file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    scan_file(file, viruses, NUM_VIRUSES);

    fclose(file);
    return 0;
}