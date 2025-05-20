//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 100

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void reverse_string(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void process_file(const char *filename, int option) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        switch (option) {
            case 1:
                to_uppercase(line);
                printf("Uppercase: %s", line);
                break;
            case 2:
                to_lowercase(line);
                printf("Lowercase: %s", line);
                break;
            case 3:
                reverse_string(line);
                printf("Reversed: %s", line);
                break;
            default:
                fprintf(stderr, "Invalid option.\n");
                fclose(file);
                return;
        }
    }

    fclose(file);
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    int option;

    printf("Enter the name of the file to process: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // Remove newline character

    printf("Choose an option:\n");
    printf("1. Convert to uppercase\n");
    printf("2. Convert to lowercase\n");
    printf("3. Reverse strings\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &option);

    process_file(filename, option);

    return 0;
}