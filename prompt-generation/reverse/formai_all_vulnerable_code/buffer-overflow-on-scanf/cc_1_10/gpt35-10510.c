//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_FILE_NAME 20
#define MAX_VIRUS_NAME 20
#define MAX_SCAN_SIZE 1000

typedef enum {false, true} bool;

typedef struct {
    char virus_name[MAX_VIRUS_NAME];
    char virus_signature[MAX_SCAN_SIZE];
    unsigned int signature_length;
} virus_signature_t;

bool is_file_infected(const char* file_name, const virus_signature_t* virus_signatures, const int num_virus_signatures);

int main() {
    virus_signature_t virus_signatures[5] = { 
        {"VirusOne", "This is the signature for VirusOne", 32},
        {"VirusTwo", "This is the signature for VirusTwo", 32},
        {"VirusThree", "This is the signature for VirusThree", 34},
        {"VirusFour", "This is the signature for VirusFour", 33},
        {"VirusFive", "This is the signature for VirusFive", 33}
    };

    const int num_virus_signatures = sizeof(virus_signatures)/sizeof(virus_signatures[0]);
    char file_name[MAX_FILE_NAME];

    printf("Enter the name of the file to scan: ");
    scanf("%s", file_name);

    if(is_file_infected(file_name, virus_signatures, num_virus_signatures)) {
        printf("Found virus!\n");
    } else {
        printf("File is not infected.\n");
    }

    return 0;
}

bool is_file_infected(const char* file_name, const virus_signature_t* virus_signatures, const int num_virus_signatures) {
    FILE* fp = fopen(file_name, "r");

    if(fp == NULL) {
        printf("Error: Cannot open file '%s'\n", file_name);
        return false;
    }

    char scan_buffer[MAX_SCAN_SIZE];
    unsigned int bytes_read;
    bool is_infected = false;

    while((bytes_read = fread(scan_buffer, 1, MAX_SCAN_SIZE, fp)) > 0) {
        for(int i = 0; i < num_virus_signatures; i++) {
            if(strstr(scan_buffer, virus_signatures[i].virus_signature) != NULL) {
                printf("Virus signature match found: %s\n", virus_signatures[i].virus_name);
                is_infected = true;
                break;
            }
        }
        if(is_infected) {
            break;
        }
    }
    
    fclose(fp);
    return is_infected;
}