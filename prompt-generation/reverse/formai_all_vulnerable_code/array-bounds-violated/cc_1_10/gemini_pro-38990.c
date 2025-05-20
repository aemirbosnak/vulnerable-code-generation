//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIGS 100
#define MAX_SIG_LEN 100

// Virus signature database
char *sigs[MAX_SIGS][MAX_SIG_LEN];
int num_sigs = 0;

// Function to load virus signatures from a file
void load_sigs(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening signature file");
        exit(1);
    }

    char line[MAX_SIG_LEN];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Add the signature to the database
        strcpy(sigs[num_sigs], line);
        num_sigs++;
    }

    fclose(fp);
}

// Function to scan a file for viruses
bool scan_file(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return false;
    }

    // Read the file into memory
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buf = malloc(fsize);
    fread(buf, 1, fsize, fp);
    fclose(fp);

    // Scan the file for viruses
    bool found = false;
    for (int i = 0; i < num_sigs; i++) {
        if (strstr(buf, sigs[i]) != NULL) {
            found = true;
            break;
        }
    }

    // Free the memory
    free(buf);

    return found;
}

// Function to print the help message
void print_help() {
    printf("Usage: antivirus <options> <file>\n");
    printf("Options:\n");
    printf("  -l: List virus signatures\n");
    printf("  -s: Scan a file for viruses\n");
    printf("  -h: Print this help message\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Load virus signatures from the file
    load_sigs("sigs.txt");

    // Check the command-line arguments
    if (argc < 2) {
        print_help();
        return 1;
    }

    // Get the option and the file name
    char *option = argv[1];
    char *filename = argv[2];

    // List virus signatures
    if (strcmp(option, "-l") == 0) {
        for (int i = 0; i < num_sigs; i++) {
            printf("%s\n", sigs[i]);
        }
        return 0;
    }

    // Scan a file for viruses
    if (strcmp(option, "-s") == 0) {
        bool found = scan_file(filename);
        if (found) {
            printf("Virus found in %s\n", filename);
        } else {
            printf("No virus found in %s\n", filename);
        }
        return 0;
    }

    // Print the help message
    if (strcmp(option, "-h") == 0) {
        print_help();
        return 0;
    }

    // Invalid option
    printf("Invalid option\n");
    print_help();
    return 1;
}