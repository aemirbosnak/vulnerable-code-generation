#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }
    char buffer[10];
    while (fscanf(file, "%s", buffer) != EOF) {
        printf("%s\n", buffer);
    }
    fclose(file);
}

int main() {
    int choice;
    char filename[MAX_FILENAME_LENGTH];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Read File\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%255s", filename); // Vulnerable line
                readFile(filename);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
