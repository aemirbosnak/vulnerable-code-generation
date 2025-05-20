//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_KEY_LENGTH 50

// Function to generate a random key
void generate_key(char* key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

int main() {
    char file_name[MAX_LINE_LENGTH];
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    char key[MAX_KEY_LENGTH];
    generate_key(key, strlen(key));

    printf("Encrypting file...\n");
    FILE* encrypted_file = fopen("encrypted.txt", "w");
    if (encrypted_file == NULL) {
        printf("Error: Could not create encrypted file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int line_length = strlen(line);
        for (int i = 0; i < line_length; i++) {
            if (isalpha(line[i])) {
                int letter_index = tolower(line[i]) - 'a';
                letter_index = (letter_index + key[i % strlen(key)] - 'a') % 26;
                line[i] = letter_index + 'a';
            }
        }
        fprintf(encrypted_file, "%s", line);
    }

    fclose(file);
    fclose(encrypted_file);

    printf("File encrypted successfully!\n");
    return 0;
}