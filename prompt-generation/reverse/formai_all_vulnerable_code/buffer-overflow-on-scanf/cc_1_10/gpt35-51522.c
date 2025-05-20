//FormAI DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void create_file(char *filename, int size);
void read_file(char *filename, int size);
void write_file(char *filename, int size);

int main()
{
    char filename[20];
    int size;
    
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter size: ");
    scanf("%d", &size);
    
    create_file(filename, size);
    read_file(filename, size);
    write_file(filename, size);
    
    return 0;
}

void create_file(char *filename, int size)
{
    FILE *fp;
    fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("Error creating file.\n");
        exit(1);
    }
    if(size > 0)
    {
        fwrite("hello world", sizeof(char), 11, fp);
        create_file(filename, size-1);
    }
    fclose(fp);
}

void read_file(char *filename, int size)
{
    FILE *fp;
    char c;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    while((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }
    fclose(fp);
}

void write_file(char *filename, int size)
{
    FILE *fp;
    fp = fopen(filename, "a");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    if(size > 0)
    {
        fwrite("how are you", sizeof(char), 11, fp);
        write_file(filename, size-1);
    }
    fclose(fp);
}