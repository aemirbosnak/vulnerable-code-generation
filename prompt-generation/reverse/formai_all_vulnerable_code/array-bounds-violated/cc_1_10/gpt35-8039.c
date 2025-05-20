//FormAI DATASET v1.0 Category: Image Editor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption
#define KEY "mysecretkey"

// Encrypt/Decrypt function
char *crypt_string(char *str) {
    int i, j = 0, k = strlen(KEY);
    char *result = malloc(strlen(str) + 1);
    
    for(i = 0; i < strlen(str); i++) {
      
        // Encrypt or decrypt depending on position and key length
        if(j == k) {
            j = 0;
        }
        
        if(i % 2 == 0) {
            result[i] = str[i] + KEY[j];
        } else {
            result[i] = str[i] - KEY[j];
            j++;
        }
    }
    
    result[strlen(str)] = '\0';
    return result;
}

int main() {
    char filename[100], option[10];
    FILE *file;
    
    // Get filename and option from user
    printf("Enter filename:\n");
    scanf("%s", filename);
    printf("Enter option: [encrypt/decrypt]\n");
    scanf("%s", option);
    
    // Open file and read contents
    file = fopen(filename, "r+");
    if(file != NULL) {
        char ch, contents[500];
        int i = 0;
        
        while(!feof(file)) {
            ch = fgetc(file);
            contents[i] = ch;
            i++;
        }
        contents[i-1] = '\0';
        
        // Close file
        fclose(file);
        
        // Encrypt or decrypt depending on user choice
        if(strcmp(option, "encrypt") == 0) {
            char *encrypted = crypt_string(contents);
            file = fopen(filename, "w+");
            fprintf(file, "%s", encrypted);
            printf("File encrypted successfully!\n");
        } else if(strcmp(option, "decrypt") == 0) {
            char *decrypted = crypt_string(contents);
            file = fopen(filename, "w+");
            fprintf(file, "%s", decrypted);
            printf("File decrypted successfully!\n");
        } else {
            printf("Invalid option selected!\n");
        }
    } else {
        printf("Unable to open file %s\n", filename);
    }
    
    return 0;
}