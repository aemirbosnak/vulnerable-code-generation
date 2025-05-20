//FormAI DATASET v1.0 Category: Compression algorithms ; Style: medieval
// A C program to compress and decompress files using Run-Length Encoding.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_LEN 1024

// Function prototypes
void compress(char *src_file_path, char *dest_file_path);
void decompress(char *src_file_path, char *dest_file_path);

int main()
{
    int choice;
    char src_file_path[MAX_BUF_LEN], dest_file_path[MAX_BUF_LEN];
    
    printf("1. Compress file\n2. Decompress file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter source file path: ");
    scanf("%s", src_file_path);
    
    printf("Enter destination file path: ");
    scanf("%s", dest_file_path);
    
    switch (choice)
    {
        case 1: compress(src_file_path, dest_file_path); break;
        case 2: decompress(src_file_path, dest_file_path); break;
        default: printf("Invalid choice!\n");
    }
    
    return 0;
}

void compress(char *src_file_path, char *dest_file_path)
{
    FILE *src_file, *dest_file;
    int count, i;
    char curr, prev;
    
    src_file = fopen(src_file_path, "rb");
    if (src_file == NULL)
    {
        printf("Cannot open source file!\n");
        exit(1);
    }
    
    dest_file = fopen(dest_file_path, "wb");
    if (dest_file == NULL)
    {
        printf("Cannot create destination file!\n");
        exit(1);
    }
    
    fread(&prev, sizeof(char), 1, src_file);
    count = 1;
    
    while (fread(&curr, sizeof(char), 1, src_file))
    {
        if (curr != prev || count == 255)
        {
            fwrite(&count, sizeof(char), 1, dest_file);
            fwrite(&prev, sizeof(char), 1, dest_file);
            count = 1;
            prev = curr;
        }
        else
        {
            count++;
        }
    }
    
    fwrite(&count, sizeof(char), 1, dest_file);
    fwrite(&prev, sizeof(char), 1, dest_file);
    
    fclose(src_file);
    fclose(dest_file);
    
    printf("File compressed successfully!\n");
}

void decompress(char *src_file_path, char *dest_file_path)
{
    FILE *src_file, *dest_file;
    int count, i;
    char curr;
    
    src_file = fopen(src_file_path, "rb");
    if (src_file == NULL)
    {
        printf("Cannot open source file!\n");
        exit(1);
    }
    
    dest_file = fopen(dest_file_path, "wb");
    if (dest_file == NULL)
    {
        printf("Cannot create destination file!\n");
        exit(1);
    }
    
    while (fread(&count, sizeof(char), 1, src_file))
    {
        fread(&curr, sizeof(char), 1, src_file);
        
        for (i = 0; i < count; i++)
        {
            fwrite(&curr, sizeof(char), 1, dest_file);
        }
    }
    
    fclose(src_file);
    fclose(dest_file);
    
    printf("File decompressed successfully!\n");
}