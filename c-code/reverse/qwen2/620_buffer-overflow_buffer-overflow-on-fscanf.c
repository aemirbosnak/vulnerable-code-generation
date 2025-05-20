#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PATH 256

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char word[10];
    while (fscanf(file, "%s", word) != EOF) {
        printf("%s\n", word);
    }

    fclose(file);
}

int main() {
    int choice;
    char filename[MAX_PATH];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Read file\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                readFile(filename);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
