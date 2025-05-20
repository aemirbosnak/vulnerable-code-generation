//FormAI DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void encrypt(char *text, int shift);

int main() {
    char file_name[MAX_LENGTH];
    int shift;
    char text[MAX_LENGTH];
    FILE *fp_in, *fp_out;
    
    printf("Enter the name of file to encrypt: ");
    scanf("%s", file_name);
    
    fp_in = fopen(file_name, "r");
    fp_out = fopen("encrypted.txt", "w");
    
    if (fp_in == NULL || fp_out == NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    
    printf("Enter the encryption shift: ");
    scanf("%d", &shift);
    
    while (fgets(text, MAX_LENGTH, fp_in)) {
        encrypt(text, shift);
        fputs(text, fp_out);
    }
    
    fclose(fp_in);
    fclose(fp_out);
    
    printf("File encrypted successfully.\n");
    
    return 0;
}

void encrypt(char *text, int shift) {
    int i;
    char ch;
    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
        }
        text[i] = ch;
    }
}