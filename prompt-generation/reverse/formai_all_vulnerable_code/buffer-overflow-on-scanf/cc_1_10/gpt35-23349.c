//FormAI DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function prototype
void encrypt(char* filename);

int main()
{
    // Get user input for filename
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Call the encrypt function
    encrypt(filename);

    return 0;
}

void encrypt(char* filename)
{
    // Open the file in read mode
    FILE* fp = fopen(filename, "rb");

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the file content
    char* content = (char*) malloc(size * sizeof(char));
    fread(content, size, 1, fp);

    // Close the file
    fclose(fp);

    // XOR each character of the content with 13
    for(int i=0; i<size; i++)
    {
        content[i] = content[i] ^ 13;
    }

    // Create a new file with encrypted content
    char* extension = ".enc";
    char* new_filename = (char*) malloc(strlen(filename)+strlen(extension)+1);
    strcpy(new_filename, filename);
    strcat(new_filename, extension);
    fp = fopen(new_filename, "wb");
    fwrite(content, size, 1, fp);
    fclose(fp);

    // Free the memory
    free(content);
    free(new_filename);

    printf("File Encrypted Successfully!\n");
}