//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a virus
int is_virus(char* str) {
    char* viruses[] = {"trojan", "worm", "malware", "ransomware"};
    int num_viruses = sizeof(viruses)/sizeof(viruses[0]);

    // Check if string contains any of the viruses
    for (int i = 0; i < num_viruses; i++) {
        if (strstr(str, viruses[i])) {
            return 1;
        }
    }

    return 0;
}

// Function to scan a file for viruses
int scan_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int is_virus_in_line = is_virus(line);
        if (is_virus_in_line) {
            printf("Virus found in line: %s\n", line);
        }
    }

    fclose(file);
    return 0;
}

int main() {
    char filename[1024];
    printf("Enter filename to scan: ");
    scanf("%s", filename);

    int result = scan_file(filename);
    if (result == 0) {
        printf("No viruses found in file.\n");
    }

    return 0;
}