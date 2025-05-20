//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PATH_LENGTH 100
#define MAX_FILE_SIZE 1000

struct file
{
    char filename[MAX_PATH_LENGTH];
    int file_size;
    char data[MAX_FILE_SIZE];
};

int main()
{
    struct file files[10];

    int index = 0;
    int num_files = 0;

    printf("Enter the number of files to create: ");
    scanf("%d", &num_files);

    for(int i=0; i<num_files; i++)
    {
        printf("Enter the filename: ");
        scanf("%s", files[i].filename);
        printf("Enter the file size: ");
        scanf("%d", &files[i].file_size);
        files[i].data[0] = 'a';
        files[i].data[1] = 'b';
        files[i].data[2] = 'c';
        files[i].data[3] = 'd';
        files[i].data[4] = 'e';
        files[i].data[5] = 'f';
        files[i].data[6] = 'g';
        files[i].data[7] = 'h';
        files[i].data[8] = 'i';
        files[i].data[9] = 'j';
    }

    printf("Here are your files:\n");
    for(int i=0; i<num_files; i++)
    {
        printf("%s - %d bytes\n", files[i].filename, files[i].file_size);
    }

    return 0;
}