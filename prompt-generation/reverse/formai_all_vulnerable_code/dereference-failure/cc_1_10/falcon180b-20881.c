//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_SIZE 1024
#define MAX_FILE_SIZE 1000000

// Function to read a file into memory
void read_file(FILE *file, char *buffer) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large to scan.\n");
        exit(1);
    }

    fread(buffer, file_size, 1, file);
    buffer[file_size] = '\0';
}

// Function to scan for viruses
int scan_for_viruses(char *file_buffer, char *virus_buffer) {
    int virus_count = 0;
    char *ptr = strstr(file_buffer, virus_buffer);

    while (ptr!= NULL) {
        virus_count++;
        printf("Virus found at position %d\n", ptr - file_buffer);
        ptr = strstr(ptr + 1, virus_buffer);
    }

    return virus_count;
}

// Function to print usage instructions
void print_usage() {
    printf("Usage:./antivirus <filename> <virus>\n");
    printf("Example:./antivirus test.txt EICAR-AV-Test-File\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    char file_buffer[MAX_FILE_SIZE];
    read_file(file, file_buffer);

    char virus_buffer[MAX_VIRUS_SIZE];
    strncpy(virus_buffer, argv[3], MAX_VIRUS_SIZE);

    int virus_count = scan_for_viruses(file_buffer, virus_buffer);

    if (virus_count == 0) {
        printf("No viruses found.\n");
    } else {
        printf("Total viruses found: %d\n", virus_count);
    }

    fclose(file);
    return 0;
}