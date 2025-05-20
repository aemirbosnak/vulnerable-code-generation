//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<time.h>

#define MAX_VIRUSES 100
#define MAX_VIRUS_NAME_LENGTH 50
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_VIRUS_NAME_LENGTH];
    char signature[MAX_FILE_NAME_LENGTH];
} virus;

virus viruses[MAX_VIRUSES] = {
    {"Creeper Virus", "creeper"},
    {"Brain Virus", "brain"},
    {"Melissa Virus", "melissa"},
    {"I LOVE YOU Virus", "iloveyou"},
    {"Code Red Virus", "codered"},
    {"Sasser Virus", "sasser"},
    {"MyDoom Virus", "mydoom"},
    {"Slammer Virus", "slammer"},
    {"Blaster Virus", "blaster"},
    {"Nimda Virus", "nimda"}
};

int num_viruses = sizeof(viruses) / sizeof(viruses[0]);

void scan_file(char* file_name) {
    FILE* file;
    char buffer[MAX_FILE_NAME_LENGTH];
    int i;

    file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    while (fgets(buffer, MAX_FILE_NAME_LENGTH, file)!= NULL) {
        for (i = 0; i < num_viruses; i++) {
            if (strstr(buffer, viruses[i].signature)!= NULL) {
                printf("Virus found: %s\n", viruses[i].name);
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
    printf("No viruses found in %s\n", file_name);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    int choice;

    do {
        printf("\nAntivirus Scanner\n");
        printf("1. Scan file\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to scan: ");
                scanf("%s", file_name);
                scan_file(file_name);
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= 2);

    return 0;
}